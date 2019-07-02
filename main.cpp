#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    void preR(Node* r, vector<int>& v) {
        if (r) {
            v.push_back(r->val);
            for (auto& ch : r->children)
                preR(ch, v);
        }
    }
    vector<int> preorderRecursive(Node* root) {
        vector<int> v;
        preR(root, v);
        return v;
    }

    vector<int> preorder(Node* root) {
        vector<int> v;
        if (!root) return v;
        stack<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node *n = q.top();
            q.pop();
            v.push_back(n->val);
            for (int i = n->children.size() - 1; i >= 0 ; --i) {
                q.push(n->children[i]);
            }
        }
        return v;
    }
};

void test1() {
    vector<Node*> e;
    Node* n2 = new Node(2, e);
    Node* n4 = new Node(4, e);
    Node* n5 = new Node(5, e);
    Node* n6 = new Node(6, e);
    Node* n3 = new Node(3, vector<Node*>{n5, n6});
    Node* n1 = new Node(1, vector<Node*>{n3, n2, n4});

    cout << "[1,3,5,6,2,4] ? " << Solution().preorder(n1) << endl;

}

void test2() {

}

void test3() {

}