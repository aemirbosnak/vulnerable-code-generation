//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node with the given data into the binary search tree
void insert(struct Node* root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return;
    }
    if (data < root->data) {
        insert(root->left, data);
    } else if (data > root->data) {
        insert(root->right, data);
    }
}

// Function to search for a node with the given data in the binary search tree
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to display the binary search tree in order traversal
void display(struct Node* root) {
    if (root == NULL) {
        return;
    }
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}

// Main function to initialize the binary search tree and perform operations on it
int main() {
    struct Node* root = NULL;
    int choice, data;
    do {
        printf("\nEnter your choice:\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insert(root, data);
                break;
            case 2:
                printf("Enter the data to be searched: ");
                scanf("%d", &data);
                struct Node* result = search(root, data);
                if (result!= NULL) {
                    printf("\nData found!\n");
                } else {
                    printf("\nData not found!\n");
                }
                break;
            case 3:
                printf("\nBinary search tree in order traversal:\n");
                display(root);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice!= 4);
    return 0;
}