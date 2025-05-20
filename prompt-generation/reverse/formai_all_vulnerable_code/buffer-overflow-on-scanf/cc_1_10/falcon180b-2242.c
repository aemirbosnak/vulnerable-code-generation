//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert_node(struct node* root, int data) {
    if (root == NULL) {
        root = create_node(data);
        return root;
    }

    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }

    return root;
}

void inorder_traversal(struct node* root) {
    if (root == NULL) {
        return;
    }

    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

void preorder_traversal(struct node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(struct node* root) {
    if (root == NULL) {
        return;
    }

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

int main() {
    struct node* root = NULL;
    int data, choice;

    while (1) {
        printf("Enter 1 to insert data\n");
        printf("Enter 2 to display inorder traversal\n");
        printf("Enter 3 to display preorder traversal\n");
        printf("Enter 4 to display postorder traversal\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert_node(root, data);
            break;
        case 2:
            printf("Inorder traversal: ");
            inorder_traversal(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder traversal: ");
            preorder_traversal(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder traversal: ");
            postorder_traversal(root);
            printf("\n");
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}