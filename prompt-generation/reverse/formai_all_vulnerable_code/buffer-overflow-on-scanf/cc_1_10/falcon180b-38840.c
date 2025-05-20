//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data[MAX_SIZE];
    struct node* left;
    struct node* right;
} Node;

Node* create_node(char data[]) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->data, data);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert_node(Node* root, char data[]) {
    if (root == NULL) {
        return create_node(data);
    }

    if (strcmp(root->data, data) > 0) {
        root->left = insert_node(root->left, data);
    } else if (strcmp(root->data, data) < 0) {
        root->right = insert_node(root->right, data);
    }

    return root;
}

void preorder_traversal(Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%s ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder_traversal(root->left);
    printf("%s ", root->data);
    inorder_traversal(root->right);
}

void postorder_traversal(Node* root) {
    if (root == NULL) {
        return;
    }

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%s ", root->data);
}

int main() {
    Node* root = NULL;
    char data[MAX_SIZE];

    printf("Enter the data to be inserted in the binary search tree: ");
    scanf("%s", data);

    root = insert_node(root, data);

    printf("Preorder traversal of the binary search tree: ");
    preorder_traversal(root);
    printf("\n");

    printf("Inorder traversal of the binary search tree: ");
    inorder_traversal(root);
    printf("\n");

    printf("Postorder traversal of the binary search tree: ");
    postorder_traversal(root);
    printf("\n");

    return 0;
}