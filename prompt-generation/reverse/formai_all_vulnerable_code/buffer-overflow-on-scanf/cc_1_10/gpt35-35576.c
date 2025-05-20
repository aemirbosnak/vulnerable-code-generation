//FormAI DATASET v1.0 Category: Binary search trees ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *insert_node(Node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

void inorder_traversal(Node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main() {
    Node *root = NULL;
    int choice, data;

    while (1) {
        printf("Player 1 - Enter 1 to insert a node, 2 to exit: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Player 1 - Enter the data of the node: ");
            scanf("%d", &data);
            root = insert_node(root, data);
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    while (1) {
        printf("Player 2 - Enter 1 to insert a node, 2 to exit: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Player 2 - Enter the data of the node: ");
            scanf("%d", &data);
            root = insert_node(root, data);
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    printf("Binary search tree after insertion:\n");
    inorder_traversal(root);

    return 0;
}