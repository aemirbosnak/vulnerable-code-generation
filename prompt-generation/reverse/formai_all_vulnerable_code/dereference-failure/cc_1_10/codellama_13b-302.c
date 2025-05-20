//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: optimized
/*
 *  Database Simulation Example Program
 *
 *  This program simulates a database system by storing and retrieving data in a linked list.
 *  The program uses a simple linked list data structure to store the data, with each node
 *  representing a record in the database.
 *
 *  The program has the following functions:
 *  - insert(): adds a new record to the database
 *  - search(): searches for a record in the database
 *  - delete(): deletes a record from the database
 *  - display(): displays all the records in the database
 *
 *  The program uses a simple linked list data structure to store the data, with each node
 *  representing a record in the database.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for a record in the database
typedef struct record {
    int id;
    char name[50];
    char email[50];
    struct record *next;
} record;

// Function to create a new record
record* create_record(int id, char *name, char *email) {
    record *new_record = malloc(sizeof(record));
    new_record->id = id;
    strcpy(new_record->name, name);
    strcpy(new_record->email, email);
    new_record->next = NULL;
    return new_record;
}

// Function to insert a new record into the database
void insert(record *head, int id, char *name, char *email) {
    record *new_record = create_record(id, name, email);
    new_record->next = head->next;
    head->next = new_record;
}

// Function to search for a record in the database
record* search(record *head, int id) {
    record *current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a record from the database
void delete(record *head, int id) {
    record *current = head;
    record *prev = NULL;
    while (current != NULL) {
        if (current->id == id) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

// Function to display all the records in the database
void display(record *head) {
    record *current = head;
    while (current != NULL) {
        printf("ID: %d\nName: %s\nEmail: %s\n\n", current->id, current->name, current->email);
        current = current->next;
    }
}

int main() {
    // Create a new database
    record *head = create_record(0, "John", "john@example.com");

    // Insert some records into the database
    insert(head, 1, "Alice", "alice@example.com");
    insert(head, 2, "Bob", "bob@example.com");
    insert(head, 3, "Charlie", "charlie@example.com");

    // Search for a record in the database
    record *record1 = search(head, 2);
    printf("Record with ID 2:\n");
    printf("Name: %s\nEmail: %s\n\n", record1->name, record1->email);

    // Delete a record from the database
    delete(head, 1);

    // Display all the records in the database
    display(head);

    return 0;
}