//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (root == NULL) {
        root = new_node;
        return;
    }

    struct node *temp = root;
    while (1) {
        if (data < temp->data) {
            if (temp->left == NULL) {
                temp->left = new_node;
                return;
            }
            temp = temp->left;
        } else {
            if (temp->right == NULL) {
                temp->right = new_node;
                return;
            }
            temp = temp->right;
        }
    }
}

void preorder(struct node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct node *root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    srand(time(0));
    int choice, data;

    while (1) {
        printf("1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            printf("Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 3:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}