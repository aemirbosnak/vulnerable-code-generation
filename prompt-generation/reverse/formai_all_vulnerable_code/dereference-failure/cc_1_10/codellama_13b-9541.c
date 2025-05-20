//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: dynamic
/// dynamic binary search tree example program in C

#include <stdio.h>
#include <stdlib.h>

/// structure to represent a node of a binary search tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/// function to create a new node
struct Node* create_node(int data) {
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/// function to insert a node in a binary search tree
void insert_node(struct Node **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }

    if ((*root)->data > data) {
        insert_node(&(*root)->left, data);
    } else if ((*root)->data < data) {
        insert_node(&(*root)->right, data);
    }
}

/// function to print the nodes of a binary search tree
void print_nodes(struct Node *root) {
    if (root == NULL) {
        return;
    }

    print_nodes(root->left);
    printf("%d ", root->data);
    print_nodes(root->right);
}

/// function to search for a node in a binary search tree
struct Node* search_node(struct Node *root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == data) {
        return root;
    } else if (root->data > data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

/// function to delete a node from a binary search tree
struct Node* delete_node(struct Node *root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == data) {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        } else {
            struct Node *temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
            return root;
        }
    } else if (root->data > data) {
        root->left = delete_node(root->left, data);
    } else {
        root->right = delete_node(root->right, data);
    }

    return root;
}

int main() {
    struct Node *root = NULL;

    insert_node(&root, 5);
    insert_node(&root, 3);
    insert_node(&root, 7);
    insert_node(&root, 2);
    insert_node(&root, 4);
    insert_node(&root, 6);
    insert_node(&root, 8);

    print_nodes(root);
    printf("\n");

    struct Node *node = search_node(root, 7);
    if (node != NULL) {
        printf("Node found: %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    delete_node(&root, 5);
    print_nodes(root);
    printf("\n");

    return 0;
}