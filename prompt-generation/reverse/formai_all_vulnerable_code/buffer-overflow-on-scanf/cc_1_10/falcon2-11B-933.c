//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void insert(struct node **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else {
        if (data < (*root)->data) {
            insert(&((*root)->left), data);
        } else {
            insert(&((*root)->right), data);
        }
    }
}

void print_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

int main() {
    struct node *root = NULL;
    int choice, data;

    do {
        printf("\n1. Insert\n2. Print\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                print_tree(root);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}