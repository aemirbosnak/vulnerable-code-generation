//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node with the given data
struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node into the binary search tree
void insert_node(struct node* root, int data) {
    if (root == NULL) {
        root = create_node(data);
        return;
    }

    if (data < root->data) {
        insert_node(root->left, data);
    } else if (data > root->data) {
        insert_node(root->right, data);
    }
}

// Function to search for a node in the binary search tree
struct node* search_node(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

// Function to delete a node from the binary search tree
void delete_node(struct node* root, int data) {
    if (root == NULL) {
        return;
    }

    if (data < root->data) {
        delete_node(root->left, data);
    } else if (data > root->data) {
        delete_node(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            struct node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            struct node* temp = root;
            root = root->left;
            free(temp);
        } else {
            struct node* temp = search_node(root->right, root->data);
            root->data = temp->data;
            delete_node(root->right, temp->data);
        }
    }
}

// Function to print the binary search tree
void print_tree(struct node* root) {
    if (root == NULL) {
        return;
    }

    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

// Main function to test the binary search tree operations
int main() {
    struct node* root = NULL;

    // Insert nodes into the binary search tree
    insert_node(root, 10);
    insert_node(root, 5);
    insert_node(root, 15);
    insert_node(root, 2);
    insert_node(root, 7);
    insert_node(root, 12);
    insert_node(root, 17);

    // Print the binary search tree
    printf("Binary search tree:\n");
    print_tree(root);
    printf("\n");

    // Search for a node in the binary search tree
    struct node* search_result = search_node(root, 7);
    if (search_result!= NULL) {
        printf("Node found: %d\n", search_result->data);
    } else {
        printf("Node not found\n");
    }

    // Delete a node from the binary search tree
    delete_node(root, 7);

    // Print the binary search tree after deletion
    printf("Binary search tree after deleting node 7:\n");
    print_tree(root);
    printf("\n");

    return 0;
}