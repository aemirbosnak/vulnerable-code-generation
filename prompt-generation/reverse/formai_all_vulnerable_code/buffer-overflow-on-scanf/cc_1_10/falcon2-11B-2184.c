//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: expert-level
#include<stdio.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

void inOrder(struct node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main() {
    struct node* root = NULL;
    int choice, data;
    do {
        printf("\n1. Insert a new node\n2. Display the BST inorder\n0. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                if (root == NULL) {
                    printf("BST is empty\n");
                } else {
                    inOrder(root);
                }
                break;
            default:
                return 0;
        }
    } while (choice!= 0);
    return 0;
}