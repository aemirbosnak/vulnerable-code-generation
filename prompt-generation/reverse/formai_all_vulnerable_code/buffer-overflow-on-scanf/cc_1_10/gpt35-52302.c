//FormAI DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a database record
typedef struct Record {
    int id;
    char name[20];
    float gpa;
} Record;

// Define a struct to represent a node in a linked list of records
typedef struct Node {
    Record data;
    struct Node* next;
} Node;

// Define a struct to represent a database
typedef struct Database {
    Node* head;
} Database;

// Initialize an empty database
Database* initDatabase() {
    Database* db = (Database*) malloc(sizeof(Database));
    db->head = NULL;
    return db;
}

// Insert a new record into the database
void insertRecord(Database* db, Record record) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = record;
    newNode->next = db->head;
    db->head = newNode;
}

// Delete a record from the database
void deleteRecord(Database* db, int id) {
    Node* prevNode = NULL;
    Node* currNode = db->head;
    while (currNode != NULL && currNode->data.id != id) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (currNode != NULL) {
        if (prevNode == NULL) {
            // We are deleting the first node in the list
            db->head = currNode->next;
        } else {
            prevNode->next = currNode->next;
        }
        free(currNode);
    } else {
        printf("Record %d not found!\n", id);
    }
}

// Print the contents of the database
void printDatabase(Database* db) {
    Node* currNode = db->head;
    while (currNode != NULL) {
        printf("%d\t%s\t%.2f\n", currNode->data.id, currNode->data.name, currNode->data.gpa);
        currNode = currNode->next;
    }
}

int main() {
    Database* db = initDatabase();
    int choice, id;
    Record record;
    char name[20];
    float gpa;
    do {
        printf("1. Insert record\n");
        printf("2. Delete record\n");
        printf("3. Print database\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter id: ");
                scanf("%d", &record.id);
                printf("Enter name: ");
                scanf("%s", record.name);
                printf("Enter GPA: ");
                scanf("%f", &record.gpa);
                insertRecord(db, record);
                break;
            case 2:
                printf("Enter id of record to delete: ");
                scanf("%d", &id);
                deleteRecord(db, id);
                break;
            case 3:
                printf("ID\tName\tGPA\n");
                printDatabase(db);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);
    return 0;
}