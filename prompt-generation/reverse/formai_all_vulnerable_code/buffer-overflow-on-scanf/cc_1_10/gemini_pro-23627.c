//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[50];
    int quantity;
    float price;
    struct node *left;
    struct node *right;
} node;

node *create_node(char *name, int quantity, float price) {
    node *new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->name, name);
    new_node->quantity = quantity;
    new_node->price = price;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *insert_node(node *root, char *name, int quantity, float price) {
    if (root == NULL) {
        return create_node(name, quantity, price);
    }
    if (strcmp(name, root->name) < 0) {
        root->left = insert_node(root->left, name, quantity, price);
    } else {
        root->right = insert_node(root->right, name, quantity, price);
    }
    return root;
}

void inorder_traversal(node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%s %d %f\n", root->name, root->quantity, root->price);
        inorder_traversal(root->right);
    }
}

node *search_node(node *root, char *name) {
    if (root == NULL) {
        return NULL;
    }
    if (strcmp(name, root->name) == 0) {
        return root;
    }
    if (strcmp(name, root->name) < 0) {
        return search_node(root->left, name);
    } else {
        return search_node(root->right, name);
    }
}

node *delete_node(node *root, char *name) {
    if (root == NULL) {
        return NULL;
    }
    if (strcmp(name, root->name) == 0) {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node *temp = root->left;
            free(root);
            return temp;
        } else {
            node *temp = root->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            strcpy(root->name, temp->name);
            root->quantity = temp->quantity;
            root->price = temp->price;
            root->left = delete_node(root->left, temp->name);
            return root;
        }
    }
    if (strcmp(name, root->name) < 0) {
        root->left = delete_node(root->left, name);
    } else {
        root->right = delete_node(root->right, name);
    }
    return root;
}

int main() {
    node *root = NULL;
    int choice;
    char name[50];
    int quantity;
    float price;

    while (1) {
        printf("\n1. Insert\n2. Inorder Traversal\n3. Search\n4. Delete\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter medicine name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                root = insert_node(root, name, quantity, price);
                break;

            case 2:
                inorder_traversal(root);
                break;

            case 3:
                printf("Enter medicine name: ");
                scanf("%s", name);
                node *found_node = search_node(root, name);
                if (found_node == NULL) {
                    printf("Medicine not found\n");
                } else {
                    printf("Medicine found: %s %d %f\n", found_node->name, found_node->quantity, found_node->price);
                }
                break;

            case 4:
                printf("Enter medicine name: ");
                scanf("%s", name);
                root = delete_node(root, name);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}