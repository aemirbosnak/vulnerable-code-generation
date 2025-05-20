//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TREE_HEIGHT 100
#define MAX_TREE_WIDTH 100

typedef struct _TreeNode {
    int value;
    struct _TreeNode* left;
    struct _TreeNode* right;
} TreeNode;

void create_node(TreeNode* node, int value) {
    node->value = value;
    node->left = NULL;
    node->right = NULL;
}

void create_tree(TreeNode* root, int height, int width) {
    srand(time(NULL));
    int value = rand() % 100;
    create_node(root, value);

    if (height > 1) {
        int new_height = height - 1;
        int new_width = width / 2;
        TreeNode* left_child = (TreeNode*)malloc(sizeof(TreeNode));
        TreeNode* right_child = (TreeNode*)malloc(sizeof(TreeNode));
        create_tree(left_child, new_height, new_width);
        create_tree(right_child, new_height, new_width);
        root->left = left_child;
        root->right = right_child;
    }
}

void print_tree(TreeNode* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 10;
    print_tree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->value);

    space -= 10;
    print_tree(root->left, space);
}

int main() {
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    create_tree(root, MAX_TREE_HEIGHT, MAX_TREE_WIDTH);
    print_tree(root, 0);

    return 0;
}