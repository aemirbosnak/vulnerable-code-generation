//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: innovative
// Binary Search Tree Program
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} node;

node *create_node(int value) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node **root, int value) {
    if (*root == NULL) {
        *root = create_node(value);
        return;
    }
    if (value < (*root)->value) {
        insert_node(&(*root)->left, value);
    } else if (value > (*root)->value) {
        insert_node(&(*root)->right, value);
    }
}

void inorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->value);
    inorder_traversal(root->right);
}

void preorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->value);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->value);
}

void delete_node(node **root, int value) {
    if (*root == NULL) {
        return;
    }
    if (value < (*root)->value) {
        delete_node(&(*root)->left, value);
    } else if (value > (*root)->value) {
        delete_node(&(*root)->right, value);
    } else {
        node *temp = *root;
        if ((*root)->left == NULL) {
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            *root = (*root)->left;
            free(temp);
        } else {
            temp = (*root)->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            (*root)->value = temp->value;
            delete_node(&(*root)->right, temp->value);
        }
    }
}

int main() {
    node *root = NULL;
    insert_node(&root, 10);
    insert_node(&root, 15);
    insert_node(&root, 5);
    insert_node(&root, 7);
    insert_node(&root, 12);
    insert_node(&root, 17);
    insert_node(&root, 11);
    insert_node(&root, 9);
    printf("Inorder Traversal: ");
    inorder_traversal(root);
    printf("\nPreorder Traversal: ");
    preorder_traversal(root);
    printf("\nPostorder Traversal: ");
    postorder_traversal(root);
    delete_node(&root, 10);
    printf("\nInorder Traversal: ");
    inorder_traversal(root);
    return 0;
}