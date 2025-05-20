//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: optimized
// Optimized C Database Indexing System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a record in the database
typedef struct {
    char name[20];
    int age;
    float height;
    char city[20];
} Record;

// Structure to represent a node in the linked list
typedef struct node {
    Record record;
    struct node *next;
} Node;

// Structure to represent the database
typedef struct {
    Node *head;
    Node *tail;
    int size;
} Database;

// Function to create a new database
Database* createDatabase() {
    Database *db = malloc(sizeof(Database));
    db->head = NULL;
    db->tail = NULL;
    db->size = 0;
    return db;
}

// Function to insert a record into the database
void insertRecord(Database *db, Record record) {
    Node *node = malloc(sizeof(Node));
    node->record = record;
    node->next = NULL;
    if (db->head == NULL) {
        db->head = node;
        db->tail = node;
    } else {
        db->tail->next = node;
        db->tail = node;
    }
    db->size++;
}

// Function to search for a record in the database
Record* searchRecord(Database *db, char *name) {
    Node *node = db->head;
    while (node != NULL) {
        if (strcmp(node->record.name, name) == 0) {
            return &node->record;
        }
        node = node->next;
    }
    return NULL;
}

// Function to print all records in the database
void printAllRecords(Database *db) {
    Node *node = db->head;
    while (node != NULL) {
        printf("%s, %d, %f, %s\n", node->record.name, node->record.age, node->record.height, node->record.city);
        node = node->next;
    }
}

int main() {
    // Create a new database
    Database *db = createDatabase();

    // Insert some records into the database
    Record record1 = {"John", 25, 1.75, "New York"};
    insertRecord(db, record1);
    Record record2 = {"Jane", 30, 1.6, "London"};
    insertRecord(db, record2);
    Record record3 = {"Bob", 35, 1.8, "Paris"};
    insertRecord(db, record3);

    // Search for a record in the database
    Record *record = searchRecord(db, "John");
    if (record != NULL) {
        printf("Found record: %s, %d, %f, %s\n", record->name, record->age, record->height, record->city);
    } else {
        printf("Record not found\n");
    }

    // Print all records in the database
    printAllRecords(db);

    return 0;
}