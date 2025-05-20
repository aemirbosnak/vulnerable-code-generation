//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define node structure for binary search tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node with given data
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert data into binary search tree
void insertData(struct node* root, int data) {
    if (root == NULL) {
        root = newNode(data);
    } else if (data <= root->data) {
        insertData(root->left, data);
    } else {
        insertData(root->right, data);
    }
}

// Function to search for data in binary search tree
struct node* searchData(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data <= root->data) {
        return searchData(root->left, data);
    } else {
        return searchData(root->right, data);
    }
}

// Function to print binary search tree in order
void printTree(struct node* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

// Main function to test binary search tree operations
int main() {
    struct node* root = NULL;
    int choice, data;

    // Prompt user for choice of operation
    printf("Enter your choice:\n1. Insert data\n2. Search for data\n3. Print binary search tree\n4. Exit\n");
    scanf("%d", &choice);

    while (choice!= 4) {
        switch (choice) {
            case 1:
                // Prompt user for data to insert
                printf("Enter data to insert:\n");
                scanf("%d", &data);
                // Insert data into binary search tree
                insertData(root, data);
                break;
            case 2:
                // Prompt user for data to search
                printf("Enter data to search:\n");
                scanf("%d", &data);
                // Search for data in binary search tree
                struct node* result = searchData(root, data);
                if (result!= NULL) {
                    printf("Data found!\n");
                } else {
                    printf("Data not found.\n");
                }
                break;
            case 3:
                // Print binary search tree in order
                printf("Binary search tree in order:\n");
                printTree(root);
                break;
            default:
                printf("Invalid choice.\n");
        }
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);
    }

    return 0;
}