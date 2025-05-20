//FormAI DATASET v1.0 Category: Binary search trees ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

node_t *create_node(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(node_t **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
    }
    else if (data < (*root)->data) {
        insert(&((*root)->left), data);
    }
    else {
        insert(&((*root)->right), data);
    }
}

node_t *search(node_t *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    else if (root->data > data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

node_t *find_minimum(node_t *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

void remove_node(node_t **root, int data) {
    if (*root == NULL) {
        return;
    }
    if (data < (*root)->data) {
        remove_node(&((*root)->left), data);
    }
    else if (data > (*root)->data) {
        remove_node(&((*root)->right), data);
    }
    else {
        if ((*root)->left == NULL) {
            node_t *temp = (*root)->right;
            free(*root);
            *root = temp;
        }
        else if ((*root)->right == NULL) {
            node_t *temp = (*root)->left;
            free(*root);
            *root = temp;
        }
        else {
            node_t *temp = find_minimum((*root)->right);
            (*root)->data = temp->data;
            remove_node(&((*root)->right), temp->data);
        }
    }
}

void inorder_traversal(node_t *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main() {
    node_t *root = NULL;
    int choice, num;

    while(1) {
        printf("\nBinary Search Tree Menu\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &num);
                insert(&root, num);
                break;

            case 2:
                printf("Enter number to search: ");
                scanf("%d", &num);
                if (search(root, num) != NULL) {
                    printf("%d found in tree.\n", num);
                } else {
                    printf("%d not found in tree.\n", num);
                }
                break;

            case 3:
                printf("Enter number to delete: ");
                scanf("%d", &num);
                remove_node(&root, num);
                break;

            case 4:
                printf("Inorder traversal: ");
                inorder_traversal(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}