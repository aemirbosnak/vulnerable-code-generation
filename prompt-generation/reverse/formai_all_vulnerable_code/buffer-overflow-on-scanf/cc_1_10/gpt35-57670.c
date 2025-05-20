//FormAI DATASET v1.0 Category: Data structures visualization ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// structure to represent a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// function to create a new node in the binary tree
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// function to insert a new node in the binary tree
struct Node* insert(struct Node* node, int data)
{
    if (node == NULL) {
        return newNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        printf("Duplicate element %d not allowed\n", data);
    }

    return node;
}

// function to print the binary tree using inorder traversal
void printInorder(struct Node* node)
{
    if (node == NULL) {
        return;
    }
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

// main function
int main()
{
    struct Node* root = NULL;
    int choice, data;

    // loop until user terminates the program
    do {
        printf("\nBinary Tree Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Print Inorder\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;

        case 2:
            printf("Inorder Traversal of the Binary Tree: ");
            printInorder(root);
            printf("\n");
            break;

        case 3:
            printf("Terminating the program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}