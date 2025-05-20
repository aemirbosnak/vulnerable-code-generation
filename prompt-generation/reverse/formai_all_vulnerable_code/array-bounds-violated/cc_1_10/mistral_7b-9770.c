//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Database Structure Definition
typedef struct Record {
    int ID;
    char Name[50];
    float Price;
} Record;

typedef struct Node {
    Record data;
    struct Node *next;
} Node;

typedef struct Database {
    Node *head;
    int count;
} Database;

// Function Prototypes
void AddRecord(Database *db, Record newRecord);
Record SearchRecord(Database db, int id);
void DisplayDatabase(Database db);

int main() {
    Database db;
    db.head = NULL;
    db.count = 0;

    printf("\n***** WELCOME TO THE DATABASE SIMULATION *****\n");
    printf("----------------------------------------------\n");

    while (1) {
        printf("\n1. Add Record\n2. Search Record\n3. Display Database\n4. Quit\n");
        printf("Enter your choice: ");

        char choice;
        scanf("%c", &choice);

        switch (choice) {
            case '1': {
                Record newRecord;
                printf("Enter Record ID: ");
                scanf("%d", &newRecord.ID);
                printf("Enter Record Name: ");
                fgets(newRecord.Name, sizeof(newRecord.Name), stdin);
                newRecord.Name[strlen(newRecord.Name) - 1] = '\0'; // Remove newline character
                printf("Enter Record Price: ");
                scanf("%f", &newRecord.Price);

                AddRecord(&db, newRecord);
                printf("Record added successfully.\n");
                break;
            }

            case '2': {
                int id;
                printf("Enter ID to search: ");
                scanf("%d", &id);

                Record searchedRecord = SearchRecord(db, id);

                if (searchedRecord.ID != -1)
                    printf("Record found:\nID: %d\nName: %s\nPrice: %.2f\n", searchedRecord.ID, searchedRecord.Name, searchedRecord.Price);
                else
                    printf("Record not found.\n");

                break;
            }

            case '3': {
                printf("Displaying Database:\n");
                DisplayDatabase(db);
                break;
            }

            case '4': {
                printf("Exiting the Database Simulation...\n");
                exit(0);
            }

            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }

    return 0;
}

void AddRecord(Database *db, Record newRecord) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = newRecord;
    newNode->next = db->head;

    db->head = newNode;
    db->count++;
}

Record SearchRecord(Database db, int id) {
    Node *current = db.head;

    while (current != NULL) {
        if (current->data.ID == id)
            return current->data;

        current = current->next;
    }

    Record emptyRecord = {-1, "", 0.0};
    return emptyRecord;
}

void DisplayDatabase(Database db) {
    Node *current = db.head;

    while (current != NULL) {
        printf("ID: %d\nName: %s\nPrice: %.2f\n", current->data.ID, current->data.Name, current->data.Price);
        current = current->next;
    }
}