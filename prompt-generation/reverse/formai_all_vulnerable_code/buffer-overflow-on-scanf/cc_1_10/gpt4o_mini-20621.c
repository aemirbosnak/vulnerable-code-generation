//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

// Define a structure for each record
typedef struct Record {
    int id;
    char name[MAX_NAME_LENGTH];
    struct Record *next; // Pointer to the next record in the linked list
} Record;

// Head pointer for the linked list
Record *head = NULL;

// Function to create a new record
Record *create_record(int id, const char *name) {
    Record *new_record = (Record *)malloc(sizeof(Record));
    new_record->id = id;
    strncpy(new_record->name, name, MAX_NAME_LENGTH);
    new_record->next = NULL;
    return new_record;
}

// Function to add a record to the linked list
void add_record(int id, const char *name) {
    Record *new_record = create_record(id, name);
    if (head == NULL) {
        head = new_record;
    } else {
        Record *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_record;
    }
    printf("Record added: ID = %d, Name = %s\n", id, name);
}

// Function to search for a record by ID
Record *search_record(int id) {
    Record *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to display all records
void display_records() {
    Record *temp = head;
    printf("\nRecords:\n");
    while (temp != NULL) {
        printf("ID = %d, Name = %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

// Function to free all records
void free_records() {
    Record *temp = head;
    while (temp != NULL) {
        Record *next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
}

// Main function
int main() {
    int choice, id;
    char name[MAX_NAME_LENGTH];

    while (1) {
        printf("\nDatabase Indexing System:\n");
        printf("1. Add Record\n");
        printf("2. Search Record by ID\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf(" %[^\n]s", name);
                add_record(id, name);
                break;

            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Record *found = search_record(id);
                if (found) {
                    printf("Record Found: ID = %d, Name = %s\n", found->id, found->name);
                } else {
                    printf("Record with ID = %d not found.\n", id);
                }
                break;

            case 3:
                display_records();
                break;

            case 4:
                free_records();
                printf("Exiting the system. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}