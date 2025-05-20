//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: imaginative
/*
 * Unique C Binary Search Tree Example Program
 *
 * This program demonstrates the use of binary search trees in C.
 * It creates a binary search tree of integers, and then performs
 * various operations such as inserting, deleting, and searching
 * for elements in the tree.
 */

#include <stdio.h>
#include <stdlib.h>

/* Structure for a binary search tree node */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* Function to create a new node */
struct node *create_node(int data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Function to insert a new element in the tree */
void insert(struct node **root, int data) {
    /* If the tree is empty, create a new root */
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }

    /* Otherwise, find the correct location to insert the element */
    struct node *current = *root;
    while (current != NULL) {
        if (data < current->data) {
            if (current->left == NULL) {
                current->left = create_node(data);
                break;
            } else {
                current = current->left;
            }
        } else {
            if (current->right == NULL) {
                current->right = create_node(data);
                break;
            } else {
                current = current->right;
            }
        }
    }
}

/* Function to search for an element in the tree */
struct node *search(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

/* Function to delete an element from the tree */
void delete(struct node **root, int data) {
    /* If the tree is empty, return */
    if (*root == NULL) {
        return;
    }

    /* Find the node to be deleted */
    struct node *current = *root;
    struct node *parent = NULL;
    while (current != NULL) {
        if (data < current->data) {
            parent = current;
            current = current->left;
        } else if (data > current->data) {
            parent = current;
            current = current->right;
        } else {
            /* Node found, delete it */
            if (current->left == NULL) {
                /* Node has no left child, replace it with its right child */
                if (parent == NULL) {
                    *root = current->right;
                } else {
                    if (parent->left == current) {
                        parent->left = current->right;
                    } else {
                        parent->right = current->right;
                    }
                }
            } else if (current->right == NULL) {
                /* Node has no right child, replace it with its left child */
                if (parent == NULL) {
                    *root = current->left;
                } else {
                    if (parent->left == current) {
                        parent->left = current->left;
                    } else {
                        parent->right = current->left;
                    }
                }
            } else {
                /* Node has both children, replace it with its in-order successor */
                struct node *successor = current->right;
                while (successor->left != NULL) {
                    successor = successor->left;
                }
                current->data = successor->data;
                current = successor;
            }
            free(current);
            return;
        }
    }
}

/* Function to print the elements of the tree in sorted order */
void print_tree(struct node *root) {
    if (root == NULL) {
        return;
    }

    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

int main() {
    /* Create a new binary search tree */
    struct node *root = NULL;

    /* Insert some elements in the tree */
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 40);
    insert(&root, 50);

    /* Search for an element in the tree */
    struct node *node = search(root, 30);
    if (node != NULL) {
        printf("Found element %d\n", node->data);
    } else {
        printf("Element not found\n");
    }

    /* Delete an element from the tree */
    delete(&root, 40);

    /* Print the elements of the tree in sorted order */
    printf("Sorted elements: ");
    print_tree(root);
    printf("\n");

    /* Free the memory allocated for the tree */
    free(root);

    return 0;
}