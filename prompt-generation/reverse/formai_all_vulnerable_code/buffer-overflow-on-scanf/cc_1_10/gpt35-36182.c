//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    int id;
    char name[50];
    float score;
};

struct node {
    struct record data;
    struct node *left_child;
    struct node *right_child;
};

struct node *insert(struct node *root, struct record data);
void inorder_traversal(struct node *root);
void search(struct node *root, int id);

int main() {
    struct node *root = NULL;
    struct record data;

    printf("Enter student ID, name, and score to add to the database:\n");

    // Read input from user to add new record to database
    scanf("%d %[^\n]s", &data.id, data.name);
    scanf("%f", &data.score);

    // Insert new record into database
    root = insert(root, data);

    // Print out all records in the database
    printf("Records in the database:\n");
    inorder_traversal(root);

    // Search for a specific record by ID
    int search_id;
    printf("Enter student ID to search for: ");
    scanf("%d", &search_id);
    search(root, search_id);

    return 0;
}

// Function to insert a new record into the database
struct node *insert(struct node *root, struct record data) {
    // Create a new node for the record
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;

    // If the root is empty, set the new node as the root
    if (root == NULL) {
        return new_node;
    }

    // Otherwise, traverse down the tree to find the proper location to insert the new node
    struct node *current_node = root;
    while (1) {
        // If the record ID is already in the database, return without inserting
        if (data.id == current_node->data.id) {
            return root;
        } else if (data.id < current_node->data.id) {
            // If the new record ID is less than the current node's ID, traverse left
            if (current_node->left_child == NULL) {
                // If the left child is empty, insert the new node as the left child
                current_node->left_child = new_node;
                return root;
            } else {
                // Otherwise, continue traversing left
                current_node = current_node->left_child;
            }
        } else {
            // If the new record ID is greater than the current node's ID, traverse right
            if (current_node->right_child == NULL) {
                // If the right child is empty, insert the new node as the right child
                current_node->right_child = new_node;
                return root;
            } else {
                // Otherwise, continue traversing right
                current_node = current_node->right_child;
            }
        }
    }
}

// Function to traverse the database in order and print out all records
void inorder_traversal(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left_child);
    printf("%d %s %.2f\n", root->data.id, root->data.name, root->data.score);
    inorder_traversal(root->right_child);
}

// Function to search for a specific record by ID
void search(struct node *root, int id) {
    if (root == NULL) {
        printf("Record not found.\n");
        return;
    }

    if (id == root->data.id) {
        printf("%d %s %.2f\n", root->data.id, root->data.name, root->data.score);
        return;
    } else if (id < root->data.id) {
        return search(root->left_child, id);
    } else {
        return search(root->right_child, id);
    }
}