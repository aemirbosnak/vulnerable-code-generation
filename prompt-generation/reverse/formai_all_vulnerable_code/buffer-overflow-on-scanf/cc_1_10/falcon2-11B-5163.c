//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct node* root, int data) {
    if (root == NULL) {
        root = newNode(data);
    } else if (data < root->data) {
        insert(root->left, data);
    } else if (data > root->data) {
        insert(root->right, data);
    }
}

void inorder(struct node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int choice, data;

    printf("Binary Search Tree Operations\n");
    printf("1. Insert\n");
    printf("2. Inorder Traversal\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice!= 3) {
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(root, data);
                break;
            case 2:
                if (root!= NULL) {
                    inorder(root);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &choice);
    }

    printf("Thank you for using this program.\n");
    return 0;
}