//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_SIZE 50
#define EMAIL_SIZE 100

typedef struct {
    int id;
    char name[NAME_SIZE];
    char email[EMAIL_SIZE];
} Record;

Record database[MAX_RECORDS];
int record_count = 0;

void add_record() {
    if (record_count < MAX_RECORDS) {
        Record new_record;
        new_record.id = record_count + 1;

        printf("Enter Name: ");
        scanf(" %[^\n]", new_record.name);
        printf("Enter Email: ");
        scanf(" %[^\n]", new_record.email);

        database[record_count++] = new_record;
        printf("Record added successfully!\n");
    } else {
        printf("Database is full, cannot add new record.\n");
    }
}

void view_records() {
    if (record_count == 0) {
        printf("No records found.\n");
        return;
    }
    printf("\nID\tName\t\t\tEmail\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < record_count; i++) {
        printf("%d\t%-20s%-30s\n", database[i].id, database[i].name, database[i].email);
    }
}

void delete_record() {
    int id;
    printf("Enter the ID of the record to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > record_count) {
        printf("Invalid ID!\n");
        return;
    }

    for (int i = id - 1; i < record_count - 1; i++) {
        database[i] = database[i + 1];
    }
    record_count--;
    printf("Record deleted successfully!\n");
}

void search_record() {
    char email[EMAIL_SIZE];
    printf("Enter the email to search: ");
    scanf(" %[^\n]", email);

    int found = 0;
    for (int i = 0; i < record_count; i++) {
        if (strcmp(database[i].email, email) == 0) {
            printf("\nFound Record:\n");
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Email: %s\n", database[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No record found with the provided email.\n");
    }
}

void menu() {
    int choice;
    while (1) {
        printf("\nDatabase Menu:\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Delete Record\n");
        printf("4. Search Record\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                view_records();
                break;
            case 3:
                delete_record();
                break;
            case 4:
                search_record();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Simple Database Simulation\n");
    menu();
    return 0;
}