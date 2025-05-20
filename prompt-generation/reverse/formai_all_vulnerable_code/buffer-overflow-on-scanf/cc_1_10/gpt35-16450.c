//FormAI DATASET v1.0 Category: Binary search trees ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to insert a new node
struct node *insertNode(struct node *root, int value) {
    if (root == NULL)
        return newNode(value);
    if (value < root->value)
        root->left = insertNode(root->left, value);
    else if (value > root->value)
        root->right = insertNode(root->right, value);
    return root;
}

// Function to search for a node
struct node *searchNode(struct node *root, int value) {
    if (root == NULL || root->value == value)
        return root;
    if (root->value < value)
        return searchNode(root->right, value);
    return searchNode(root->left, value);
}

// Function to find the minimum value node
struct node *minValueNode(struct node *node) {
    struct node *temp = node;
    while (temp && temp->left != NULL)
        temp = temp->left;
    return temp;
}

// Function to delete a node
struct node *deleteNode(struct node *root, int key) {
    if (root == NULL)
        return root;
    if (key < root->value)
        root->left = deleteNode(root->left, key);
    else if (key > root->value)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

// Function to inorder traversal of BST
void inorderTraversal(struct node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}

// Main function
int main() {
    printf("Welcome to the Binary Search Tree Program!\n");
    struct node *root = NULL;
    int input = 0;
    while (input != 5) {
        printf("\nPlease select an option:\n");
        printf("1. Insert a new node\n");
        printf("2. Search for a node\n");
        printf("3. Delete a node\n");
        printf("4. Print inorder traversal\n");
        printf("5. Exit\n");
        scanf("%d", &input);
        if (input == 1) {
            printf("Enter the value to insert: ");
            int value;
            scanf("%d", &value);
            root = insertNode(root, value);
            printf("Node inserted successfully.\n");
        } else if (input == 2) {
            printf("Enter the value to search: ");
            int value;
            scanf("%d", &value);
            struct node *node = searchNode(root, value);
            if (node != NULL)
                printf("Node found!\n");
            else
                printf("Node not found.\n");
        } else if (input == 3) {
            printf("Enter the value to delete: ");
            int value;
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Node deleted successfully.\n");
        } else if (input == 4) {
            printf("Inorder traversal: ");
            inorderTraversal(root);
            printf("\n");
        }
    }
    printf("Goodbye!");
    return 0;
}