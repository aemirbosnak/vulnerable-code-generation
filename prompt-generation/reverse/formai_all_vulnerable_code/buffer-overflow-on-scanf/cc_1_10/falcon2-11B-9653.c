//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function declarations
void insert(struct Node** root, int data);
void preOrder(struct Node* node);

// Main function
int main() {
    struct Node* root = NULL;
    int choice, data;

    while(1) {
        printf("1. Insert\n");
        printf("2. Preorder\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                preOrder(root);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

// Insert function
void insert(struct Node** root, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if(*root == NULL) {
        *root = newNode;
    } else {
        struct Node* current = *root;

        while(1) {
            if(data < current->data) {
                if(current->left == NULL) {
                    current->left = newNode;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if(current->right == NULL) {
                    current->right = newNode;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

// Preorder function
void preOrder(struct Node* node) {
    if(node!= NULL) {
        printf("%d ", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}