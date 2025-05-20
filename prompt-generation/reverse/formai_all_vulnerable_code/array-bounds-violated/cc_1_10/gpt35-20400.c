//FormAI DATASET v1.0 Category: Database simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATABASE_SIZE 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Record;

Record database[MAX_DATABASE_SIZE];
int numRecords = 0;

void insertRecord() {
    printf("Enter name: ");
    scanf("%s", database[numRecords].name);
    printf("Enter email: ");
    scanf("%s", database[numRecords].email);
    printf("Enter phone number: ");
    scanf("%s", database[numRecords].phone);
    database[numRecords].id = numRecords + 1;
    numRecords++;
    printf("\nRecord added successfully.\n");
}

void deleteRecord() {
    int idToDelete, indexToDelete;
    printf("Enter id of record to delete: ");
    scanf("%d", &idToDelete);
    for (int i = 0; i < numRecords; i++) {
        if (database[i].id == idToDelete) {
            indexToDelete = i;
            break;
        }
    }
    if (indexToDelete == -1) {
        printf("\nRecord with id %d not found.\n", idToDelete);
        return;
    }
    for (int i = indexToDelete; i < numRecords - 1; i++) {
        database[i] = database[i + 1];
    }
    numRecords--;
    printf("\nRecord with id %d deleted successfully.\n", idToDelete);
}

void displayAllRecords() {
    printf("\n---------------------------------------------\n");
    printf("%-5s%-20s%-30s%-15s\n", "ID", "NAME", "EMAIL", "PHONE");
    printf("---------------------------------------------\n");
    for (int i = 0; i < numRecords; i++) {
        printf("%-5d%-20s%-30s%-15s\n", database[i].id, database[i].name,
               database[i].email, database[i].phone);
    }
    printf("---------------------------------------------\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert Record\n");
        printf("2. Delete Record\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insertRecord();
            break;
        case 2:
            deleteRecord();
            break;
        case 3:
            displayAllRecords();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}