//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
/*
 * A simple C program to simulate a database using a linked list.
 */

#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node in the linked list
typedef struct node {
    int key;
    char value[256];
    struct node *next;
} node_t;

// Define a structure to represent the database
typedef struct database {
    node_t *head;
} database_t;

// Function to add a new node to the linked list
void add_node(database_t *db, int key, char *value) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->key = key;
    strcpy(new_node->value, value);
    new_node->next = NULL;

    if (db->head == NULL) {
        db->head = new_node;
    } else {
        node_t *current = db->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to search for a node in the linked list
node_t *search_node(database_t *db, int key) {
    node_t *current = db->head;
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print the contents of the linked list
void print_list(database_t *db) {
    node_t *current = db->head;
    while (current != NULL) {
        printf("%d: %s\n", current->key, current->value);
        current = current->next;
    }
}

// Function to delete a node from the linked list
void delete_node(database_t *db, int key) {
    node_t *current = db->head;
    if (current->key == key) {
        db->head = current->next;
        free(current);
    } else {
        while (current->next != NULL) {
            if (current->next->key == key) {
                node_t *temp = current->next;
                current->next = current->next->next;
                free(temp);
                break;
            }
            current = current->next;
        }
    }
}

int main() {
    // Create a new database
    database_t *db = malloc(sizeof(database_t));
    db->head = NULL;

    // Add some nodes to the database
    add_node(db, 1, "Hello");
    add_node(db, 2, "World");
    add_node(db, 3, "!");

    // Search for a node in the database
    node_t *node = search_node(db, 2);
    if (node != NULL) {
        printf("Found node with key %d and value %s\n", node->key, node->value);
    } else {
        printf("Node not found\n");
    }

    // Print the contents of the database
    print_list(db);

    // Delete a node from the database
    delete_node(db, 3);

    // Print the contents of the database again
    print_list(db);

    // Free the database
    free(db);

    return 0;
}