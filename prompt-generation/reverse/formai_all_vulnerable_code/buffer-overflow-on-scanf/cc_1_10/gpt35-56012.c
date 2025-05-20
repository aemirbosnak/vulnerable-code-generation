//FormAI DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the database record
typedef struct db_record {
    int id;
    char name[50];
    char address[100];
    struct db_record *next;
} DBRecord;

// Function prototypes
DBRecord* insertRecord(DBRecord *root, int id, char *name, char *address);
void displayRecords(DBRecord *root);
void deleteRecord(DBRecord *root, int id);

// Recursive implementation of inserting a record
DBRecord* insertRecord(DBRecord *root, int id, char *name, char *address) {
    // If root is null, create a new record and set as root
    if (root == NULL) {
        root = (DBRecord*) malloc(sizeof(DBRecord));
        root->id = id;
        strcpy(root->name, name);
        strcpy(root->address, address);
        root->next = NULL;
        return root;
    }
    // If given ID is already present in the database, do not insert record
    if (root->id == id) {
        printf("Record with ID %d already exists!\n", id);
        return root;
    }
    // Recursively insert record by comparing ids
    root->next = insertRecord(root->next, id, name, address);
    return root;
}

// Recursive implementation of displaying all records
void displayRecords(DBRecord *root) {
    if (root == NULL) {
        printf("No records found in database!\n");
        return;
    }
    printf("ID: %d\nName: %s\nAddress: %s\n\n", root->id, root->name, root->address);
    displayRecords(root->next);
}

// Recursive implementation of deleting a record
void deleteRecord(DBRecord *root, int id) {
    if (root == NULL) {
        printf("Record with ID %d not found!\n", id);
        return;
    }
    // If the root record has the given ID, delete the root record and set next record as root
    if (root->id == id) {
        DBRecord *temp = root->next;
        free(root);
        printf("Record with ID %d deleted!\n", id);
        root = temp;
    }
    else {
        // Recursively delete record by comparing IDs
        deleteRecord(root->next, id);
    }
}

int main() {
    DBRecord *root = NULL;
    int choice, id;
    char name[50], address[100];
    do {
        printf("\n1. Insert record\n2. Display all records\n3. Delete record\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter ID, Name, and Address: ");
                scanf("%d %s %[^\n]s", &id, name, address);
                root = insertRecord(root, id, name, address);
                break;
            case 2:
                displayRecords(root);
                break;
            case 3:
                printf("Enter ID of record to delete: ");
                scanf("%d", &id);
                deleteRecord(root, id);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}