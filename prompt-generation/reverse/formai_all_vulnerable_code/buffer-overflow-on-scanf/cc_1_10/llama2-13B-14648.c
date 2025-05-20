//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

// Function to create a new node with the given data
struct BSTNode* newNode(int data) {
    struct BSTNode* node = (struct BSTNode*) malloc(sizeof(struct BSTNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to add an element to the tree
void addElement(struct BSTNode** root, int data) {
    if (*root == NULL) {
        *root = newNode(data);
    } else if (data < (*root)->data) {
        addElement(&(*root)->left, data);
    } else {
        addElement(&(*root)->right, data);
    }
}

// Function to remove an element from the tree
void removeElement(struct BSTNode** root, int data) {
    if (*root == NULL) {
        return;
    } else if ((*root)->data == data) {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else if ((*root)->left == NULL) {
            (*root)->right = NULL;
        } else if ((*root)->right == NULL) {
            (*root)->left = NULL;
        } else {
            struct BSTNode* temp = (*root)->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            temp->right = (*root)->right;
            (*root)->right = NULL;
        }
    } else if (data < (*root)->data) {
        removeElement(&(*root)->left, data);
    } else {
        removeElement(&(*root)->right, data);
    }
}

// Function to search for an element in the tree
struct BSTNode* searchElement(struct BSTNode* root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else {
        return searchElement(root->left, data) != NULL ? searchElement(root->left, data) : searchElement(root->right, data);
    }
}

int main() {
    struct BSTNode* root = NULL;
    int choice, data;

    do {
        printf("Welcome to the binary search tree demo! \n");
        printf("Please choose an option (1-3): \n");
        printf("1. Add an element to the tree\n");
        printf("2. Remove an element from the tree\n");
        printf("3. Search for an element in the tree\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to add: ");
                scanf("%d", &data);
                addElement(&root, data);
                break;
            case 2:
                printf("Enter the data to remove: ");
                scanf("%d", &data);
                removeElement(&root, data);
                break;
            case 3:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                struct BSTNode* result = searchElement(root, data);
                if (result != NULL) {
                    printf("The element %d is found in the tree\n", result->data);
                } else {
                    printf("The element %d is not found in the tree\n", data);
                }
                break;
        }
    } while (choice != 3);

    return 0;
}