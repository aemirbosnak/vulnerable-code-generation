//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: invasive
/*
 * Binary Search Tree Example Program
 * Invasive style
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *new_node(int data) {
    struct node *node = malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(struct node **root, int data) {
    if (*root == NULL) {
        *root = new_node(data);
    } else if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

void inorder_traversal(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

void preorder_traversal(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(struct node *root) {
    if (root == NULL) {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

void delete_node(struct node **root, int data) {
    if (*root == NULL) {
        return;
    } else if (data < (*root)->data) {
        delete_node(&(*root)->left, data);
    } else if (data > (*root)->data) {
        delete_node(&(*root)->right, data);
    } else {
        struct node *temp = *root;
        if ((*root)->left == NULL) {
            *root = (*root)->right;
        } else if ((*root)->right == NULL) {
            *root = (*root)->left;
        } else {
            struct node *successor = (*root)->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            (*root)->data = successor->data;
            delete_node(&(*root)->right, successor->data);
        }
        free(temp);
    }
}

int main() {
    struct node *root = NULL;

    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 8);

    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    delete_node(&root, 7);

    printf("Inorder traversal after deletion: ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}