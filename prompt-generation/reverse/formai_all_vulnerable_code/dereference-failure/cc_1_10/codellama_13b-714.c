//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: high level of detail
/*
 * A unique C Binary Search Tree example program
 */

#include <stdio.h>
#include <stdlib.h>

/* Node structure for the binary search tree */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* Function to create a new node */
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Function to insert a new node into the binary search tree */
void insert(struct node** root, int data) {
    if (*root == NULL) {
        *root = newNode(data);
        return;
    }

    if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else if (data > (*root)->data) {
        insert(&((*root)->right), data);
    }
}

/* Function to search for a node in the binary search tree */
struct node* search(struct node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

/* Function to delete a node from the binary search tree */
void delete(struct node** root, int data) {
    if (*root == NULL) {
        return;
    }

    if (data < (*root)->data) {
        delete(&((*root)->left), data);
    } else if (data > (*root)->data) {
        delete(&((*root)->right), data);
    } else {
        struct node* temp = *root;

        if ((*root)->left == NULL) {
            *root = (*root)->right;
        } else if ((*root)->right == NULL) {
            *root = (*root)->left;
        } else {
            struct node* temp = (*root)->right;

            while (temp->left != NULL) {
                temp = temp->left;
            }

            (*root)->data = temp->data;
            delete(&((*root)->right), temp->data);
        }

        free(temp);
    }
}

int main() {
    struct node* root = NULL;

    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);

    printf("Searching for 2: %s\n", search(root, 2) ? "Found" : "Not found");
    printf("Searching for 10: %s\n", search(root, 10) ? "Found" : "Not found");

    delete(&root, 4);
    printf("Searching for 4: %s\n", search(root, 4) ? "Found" : "Not found");

    return 0;
}