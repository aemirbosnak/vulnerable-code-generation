//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: ephemeral
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct t_node {
    int val;
    struct t_node *left, *right;
} t_node;

t_node *insert_node(t_node *root, int val) {
    t_node *new_node = malloc(sizeof *new_node);
    new_node->val = val;
    new_node->left = new_node->right = NULL;
    if (root == NULL) return new_node;
    t_node *curr = root;
    while (1) {
        if (val < curr->val) {
            if (curr->left == NULL) {
                curr->left = new_node;
                return root;
            }
            curr = curr->left;
        } else {
            if (curr->right == NULL) {
                curr->right = new_node;
                return root;
            }
            curr = curr->right;
        }
    }
}

t_node *find_min(t_node *root) {
    if (root == NULL) return NULL;
    t_node *curr = root;
    while (curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

t_node *find_max(t_node *root) {
    if (root == NULL) return NULL;
    t_node *curr = root;
    while (curr->right != NULL) {
        curr = curr->right;
    }
    return curr;
}

t_node *delete_node(t_node *root, int val) {
    if (root == NULL) return NULL;
    if (val < root->val) {
        root->left = delete_node(root->left, val);
        return root;
    }
    if (val > root->val) {
        root->right = delete_node(root->right, val);
        return root;
    }
    if (root->left == NULL) {
        t_node *temp = root->right;
        free(root);
        return temp;
    }
    if (root->right == NULL) {
        t_node *temp = root->left;
        free(root);
        return temp;
    }
    t_node *temp = find_min(root->right);
    root->val = temp->val;
    root->right = delete_node(root->right, temp->val);
    return root;
}

void inorder_traversal(t_node *root) {
    if (root == NULL) return;
    inorder_traversal(root->left);
    printf("%d ", root->val);
    inorder_traversal(root->right);
}

int main() {
    int n, i, val;
    scanf("%d", &n);
    t_node *root = NULL;
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert_node(root, val);
    }
    inorder_traversal(root);
    printf("\n");
    int m, choice;
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &val);
            root = insert_node(root, val);
        } else if (choice == 2) {
            scanf("%d", &val);
            root = delete_node(root, val);
        } else if (choice == 3) {
            t_node *min = find_min(root);
            printf("Min: %d\n", min == NULL ? INT_MAX : min->val);
        } else if (choice == 4) {
            t_node *max = find_max(root);
            printf("Max: %d\n", max == NULL ? INT_MIN : max->val);
        } else {
            inorder_traversal(root);
            printf("\n");
        }
    }
    return 0;
}