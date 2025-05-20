//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a new node with the given data
struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if (!new_node) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a value into the tree
void insert(struct node* root, int data) {
    if (root == NULL) {
        root = create_node(data);
    } else if (data < root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

// Search for a value in the tree
struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Print the values in the tree in order
void inorder(struct node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct node* root = NULL;
    int choice, data;

    // Create the initial empty tree
    root = create_node(0);

    // Menu-driven program to insert, search, and print values
    do {
        printf("\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Print in order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                insert(root, data);
                break;
            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &data);
                struct node* result = search(root, data);
                if (result!= NULL) {
                    printf("Value found!\n");
                } else {
                    printf("Value not found.\n");
                }
                break;
            case 3:
                printf("The values in the tree in order are:\n");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}