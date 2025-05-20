//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert(int key) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL) {
        root = temp;
        return;
    }

    struct node *curr = root;
    while (curr != NULL) {
        if (key < curr->key) {
            if (curr->left == NULL) {
                curr->left = temp;
                return;
            }
            curr = curr->left;
        } else {
            if (curr->right == NULL) {
                curr->right = temp;
                return;
            }
            curr = curr->right;
        }
    }
}

int search(int key) {
    struct node *curr = root;
    while (curr != NULL) {
        if (key == curr->key) {
            return 1;
        }
        if (key < curr->key) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return 0;
}

void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void postorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

void preorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int key;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &key);
        insert(key);
    }
    printf("Inorder traversal: ");
    inorder(root);
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);
    return 0;
}