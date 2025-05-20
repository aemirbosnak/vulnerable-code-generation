//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: grateful
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int val) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insertNode(Node *root, int val) {
    if (root == NULL) {
        return createNode(val);
    } else if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

int searchNode(Node *root, int val) {
    if (root == NULL) {
        return 0;
    } else if (val == root->val) {
        return 1;
    } else if (val < root->val) {
        return searchNode(root->left, val);
    } else {
        return searchNode(root->right, val);
    }
}

void inorderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

void preorderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->val);
}

int main() {
    Node *root = NULL;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int i, val;
    for (i = 0; i < n; i++) {
        printf("Enter the value of node %d: ", i + 1);
        scanf("%d", &val);
        root = insertNode(root, val);
    }
    int ch;
    do {
        printf("\n1. Insert a node\n2. Search a node\n3. Inorder traversal\n4. Preorder traversal\n5. Postorder traversal\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the value of the node to be inserted: ");
                scanf("%d", &val);
                root = insertNode(root, val);
                break;
            case 2:
                printf("Enter the value of the node to be searched: ");
                scanf("%d", &val);
                if (searchNode(root, val)) {
                    printf("Node found\n");
                } else {
                    printf("Node not found\n");
                }
                break;
            case 3:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 6:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 6);
    return 0;
}