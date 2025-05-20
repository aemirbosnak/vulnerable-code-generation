//FormAI DATASET v1.0 Category: Binary search trees ; Style: creative
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

struct Node* searchNode(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (root->data < data) {
        return searchNode(root->right, data);
    }
    return searchNode(root->left, data);
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = NULL;
    int choice, data, searchData;
    while (1) {
        printf("\n1. Insert Node\n");
        printf("2. Search Node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Enter the data to be searched: ");
                scanf("%d", &searchData);
                if (searchNode(root, searchData) == NULL) {
                    printf("%d is not present in the tree.\n", searchData);
                }
                else {
                    printf("%d is present in the tree.\n", searchData);
                }
                break;
            case 3:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}