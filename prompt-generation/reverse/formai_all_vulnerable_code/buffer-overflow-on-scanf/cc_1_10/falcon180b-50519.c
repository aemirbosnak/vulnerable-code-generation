//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

// Node structure for BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert data into BST
struct Node* insert(struct Node* root, int data) {
    // If the root is NULL, create a new node
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    // If the data is less than the root, insert into left subtree
    if (data < root->data)
        root->left = insert(root->left, data);

    // If the data is greater than the root, insert into right subtree
    else if (data > root->data)
        root->right = insert(root->right, data);

    // Return the unchanged node pointer
    return root;
}

// Function to print inorder traversal of BST
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Driver program to test above functions
int main() {
    struct Node* root = NULL;
    int choice, data;

    // Loop until user wants to exit
    while (1) {
        printf("\n1. Insert\n2. Inorder traversal\n3. Exit\n");
        scanf("%d", &choice);

        // If choice is to insert data
        if (choice == 1) {
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
        }

        // If choice is to print inorder traversal
        else if (choice == 2) {
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
        }

        // If choice is to exit
        else if (choice == 3)
            break;

        // If choice is invalid
        else
            printf("Invalid choice\n");
    }

    return 0;
}