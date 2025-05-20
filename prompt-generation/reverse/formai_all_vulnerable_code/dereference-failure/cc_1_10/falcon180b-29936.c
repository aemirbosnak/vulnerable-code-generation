//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a new node with the given data
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert data into the BST
struct node* insert(struct node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    // Otherwise, recur down the tree
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    // Return the unchanged node pointer
    return root;
}

// In-order traversal of BST (left-root-right)
void inorder(struct node* temp) {
    if (temp!= NULL) {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

// Main function
int main() {
    int choice, data;

    // Start with an empty tree
    struct node* root = NULL;

    // Perform operations until user chooses to quit
    do {
        printf("\n1. Insert\n2. In-order traversal\n3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("\nData inserted successfully!\n");
                break;
            case 2:
                printf("In-order traversal:\n");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}