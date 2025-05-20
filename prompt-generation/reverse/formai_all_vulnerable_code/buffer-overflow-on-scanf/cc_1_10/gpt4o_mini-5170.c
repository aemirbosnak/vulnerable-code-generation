//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} Record;

void addRecord(Record records[], int *current_count) {
    if (*current_count >= MAX_RECORDS) {
        printf("Maximum record limit reached. Cannot add more records.\n");
        return;
    }
  
    Record new_record;
    new_record.id = *current_count + 1;

    printf("Enter name: ");
    scanf("%s", new_record.name);

    printf("Enter email: ");
    scanf("%s", new_record.email);
  
    records[*current_count] = new_record;
    (*current_count)++;

    printf("Record added successfully.\n");
}

void viewRecords(const Record records[], int current_count) {
    if (current_count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("ID\tName\t\tEmail\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < current_count; i++) {
        printf("%d\t%s\t%s\n", records[i].id, records[i].name, records[i].email);
    }
}

void searchRecord(const Record records[], int current_count) {
    char query[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", query);

    int found = 0;
    for (int i = 0; i < current_count; i++) {
        if (strcmp(records[i].name, query) == 0) {
            printf("Record found: ID: %d, Name: %s, Email: %s\n", records[i].id, records[i].name, records[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No record found with the name %s.\n", query);
    }
}

void deleteRecord(Record records[], int *current_count) {
    int id;
    printf("Enter the ID of the record to delete: ");
    scanf("%d", &id);
  
    if (id < 1 || id > *current_count) {
        printf("Invalid ID. No record deleted.\n");
        return;
    }

    for (int i = id - 1; i < *current_count - 1; i++) {
        records[i] = records[i + 1];
    }
  
    (*current_count)--;
    printf("Record with ID %d deleted successfully.\n", id);
}

void displayMenu() {
    printf("\nDatabase Management System\n");
    printf("1. Add Record\n");
    printf("2. View Records\n");
    printf("3. Search Record\n");
    printf("4. Delete Record\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Record records[MAX_RECORDS];
    int current_count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(records, &current_count);
                break;
            case 2:
                viewRecords(records, current_count);
                break;
            case 3:
                searchRecord(records, current_count);
                break;
            case 4:
                deleteRecord(records, &current_count);
                break;
            case 5:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}