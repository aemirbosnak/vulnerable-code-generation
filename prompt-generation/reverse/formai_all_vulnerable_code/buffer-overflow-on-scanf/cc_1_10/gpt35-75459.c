//FormAI DATASET v1.0 Category: Binary search trees ; Style: Linus Torvalds
/*
* This is a C program for Binary search trees.
* It is inspired by the genius of Linus Torvalds.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert(node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert(root->left,data);
    } else if (data > root->data) {
        root->right = insert(root->right,data);
    }
    return root;
}

bool search(node* root, int data) {
    if (root == NULL) {
        return false;
    } else if (root->data == data) {
        return true;
    } else if (data < root->data) {
        return search(root->left,data);
    } else {
        return search(root->right,data);
    }
}

void inorder_traversal(node* root) {
    if (root == NULL) {
        return;
    } else {
        inorder_traversal(root->left);
        printf("%d ",root->data);
        inorder_traversal(root->right);
    }
}

int main() {

    node* root = NULL;
    int data, choice;
    while (true) {
        printf("\n1. Insert\n2. Search\n3. Inorder Traversal\n4. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("\nEnter data: ");
                scanf("%d",&data);
                root = insert(root,data);
                printf("\nNode inserted successfully!\n");
                break;
            case 2:
                printf("\nEnter data to search: ");
                scanf("%d",&data);
                if (search(root,data)) {
                    printf("\nData found!\n");
                } else {
                    printf("\nData not found!\n");
                }
                break;
            case 3:
                inorder_traversal(root);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}