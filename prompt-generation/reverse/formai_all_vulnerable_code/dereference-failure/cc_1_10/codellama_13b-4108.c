//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure for a node in the linked list
typedef struct Node {
    char key[100];
    char value[100];
    struct Node* next;
} Node;

// Structure for the database
typedef struct Database {
    Node* head;
    Node* tail;
    int length;
} Database;

// Function to create a new node
Node* newNode(char* key, char* value) {
    Node* node = malloc(sizeof(Node));
    strcpy(node->key, key);
    strcpy(node->value, value);
    node->next = NULL;
    return node;
}

// Function to create a new database
Database* newDatabase() {
    Database* database = malloc(sizeof(Database));
    database->head = NULL;
    database->tail = NULL;
    database->length = 0;
    return database;
}

// Function to insert a node into the database
void insertNode(Database* database, char* key, char* value) {
    Node* node = newNode(key, value);
    if (database->head == NULL) {
        database->head = node;
        database->tail = node;
    } else {
        database->tail->next = node;
        database->tail = node;
    }
    database->length++;
}

// Function to retrieve a node from the database
char* retrieveNode(Database* database, char* key) {
    Node* node = database->head;
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

// Function to delete a node from the database
void deleteNode(Database* database, char* key) {
    Node* node = database->head;
    Node* prev = NULL;
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            if (prev == NULL) {
                database->head = node->next;
            } else {
                prev->next = node->next;
            }
            free(node);
            database->length--;
            return;
        }
        prev = node;
        node = node->next;
    }
}

// Function to print all nodes in the database
void printDatabase(Database* database) {
    Node* node = database->head;
    while (node != NULL) {
        printf("%s -> %s\n", node->key, node->value);
        node = node->next;
    }
}

int main() {
    Database* database = newDatabase();

    insertNode(database, "name", "John");
    insertNode(database, "age", "30");
    insertNode(database, "city", "New York");

    char* value = retrieveNode(database, "name");
    printf("Value for key 'name' is: %s\n", value);

    deleteNode(database, "age");

    printDatabase(database);

    return 0;
}