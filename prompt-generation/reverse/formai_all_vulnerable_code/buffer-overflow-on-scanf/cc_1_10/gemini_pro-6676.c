//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *insert_node(node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

node *search_node(node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

void print_preorder(node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

void print_inorder(node *root) {
    if (root != NULL) {
        print_inorder(root->left);
        printf("%d ", root->data);
        print_inorder(root->right);
    }
}

void print_postorder(node *root) {
    if (root != NULL) {
        print_postorder(root->left);
        print_postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    node *root = NULL;
    int choice, data;
    while (1) {
        printf("1. Insert node\n");
        printf("2. Search node\n");
        printf("3. Print preorder\n");
        printf("4. Print inorder\n");
        printf("5. Print postorder\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert_node(root, data);
                break;
            case 2:
                printf("Enter data to search: ");
                scanf("%d", &data);
                node *found_node = search_node(root, data);
                if (found_node != NULL) {
                    printf("Node found with data %d\n", found_node->data);
                } else {
                    printf("Node not found\n");
                }
                break;
            case 3:
                printf("Preorder: ");
                print_preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Inorder: ");
                print_inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder: ");
                print_postorder(root);
                printf("\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}