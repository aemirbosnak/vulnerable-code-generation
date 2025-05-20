//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insertNode(struct node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

struct node* searchNode(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

void deleteNode(struct node* root, int data) {
    if (root == NULL) {
        return;
    }

    if (data < root->data) {
        deleteNode(root->left, data);
    } else if (data > root->data) {
        deleteNode(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            *root = *root->right;
            free(root->right);
            root->right = NULL;
        } else if (root->right == NULL) {
            *root = *root->left;
            free(root->left);
            root->left = NULL;
        } else {
            struct node* temp = searchNode(root->right, root->data);
            root->data = temp->data;
            deleteNode(root->right, temp->data);
        }
    }
}

void inorder(struct node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct node* root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    root = insertNode(root, 8);
    root = insertNode(root, 12);
    root = insertNode(root, 17);

    printf("Inorder traversal of the given tree\n");
    inorder(root);

    printf("\n");

    int search;
    printf("Enter the value to search: ");
    scanf("%d", &search);

    struct node* result = searchNode(root, search);

    if (result!= NULL) {
        printf("Found the value %d in the tree\n", search);
    } else {
        printf("Value %d not found in the tree\n", search);
    }

    deleteNode(root, 5);
    deleteNode(root, 10);
    deleteNode(root, 15);
    deleteNode(root, 6);
    deleteNode(root, 2);
    deleteNode(root, 8);
    deleteNode(root, 12);
    deleteNode(root, 17);

    printf("\nInorder traversal of the modified tree\n");
    inorder(root);

    return 0;
}