//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: Donald Knuth
// Donald Knuth-style Binary Search Tree example program

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node* create_node(int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(node **root, int data) {
    node *new_node = create_node(data);
    if (*root == NULL) {
        *root = new_node;
        return;
    }
    node *curr = *root;
    while (curr != NULL) {
        if (data < curr->data) {
            if (curr->left == NULL) {
                curr->left = new_node;
                return;
            }
            curr = curr->left;
        } else {
            if (curr->right == NULL) {
                curr->right = new_node;
                return;
            }
            curr = curr->right;
        }
    }
}

void delete(node **root, int data) {
    if (*root == NULL) {
        return;
    }
    node *curr = *root;
    node *parent = NULL;
    while (curr != NULL) {
        if (curr->data == data) {
            if (curr->left == NULL && curr->right == NULL) {
                if (parent == NULL) {
                    *root = NULL;
                } else if (parent->left == curr) {
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
                free(curr);
                return;
            } else if (curr->left != NULL && curr->right != NULL) {
                node *temp = curr->left;
                while (temp->right != NULL) {
                    temp = temp->right;
                }
                curr->data = temp->data;
                delete(&curr->left, temp->data);
                return;
            } else if (curr->left != NULL) {
                if (parent == NULL) {
                    *root = curr->left;
                } else if (parent->left == curr) {
                    parent->left = curr->left;
                } else {
                    parent->right = curr->left;
                }
                free(curr);
                return;
            } else {
                if (parent == NULL) {
                    *root = curr->right;
                } else if (parent->left == curr) {
                    parent->left = curr->right;
                } else {
                    parent->right = curr->right;
                }
                free(curr);
                return;
            }
        }
        parent = curr;
        if (data < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
}

void inorder(node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    node *root = NULL;
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 40);
    insert(&root, 50);
    inorder(root);
    printf("\n");
    delete(&root, 30);
    inorder(root);
    return 0;
}