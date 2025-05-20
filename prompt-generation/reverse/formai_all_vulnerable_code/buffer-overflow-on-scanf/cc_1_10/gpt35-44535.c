//FormAI DATASET v1.0 Category: Database querying ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_EMAIL_LEN 50
#define MAX_PHONE_LEN 15
#define MAX_ENTRIES 100

// Define the structure for records
typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char phone[MAX_PHONE_LEN];
} Record;

// Define the database as an array of records
Record db[MAX_ENTRIES];

// Define a variable to keep track of the number of entries in the database
int num_entries = 0;

// Function to add a new record to the database
void add_record() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Database is full.\n");
        return;
    }

    // Prompt user for input
    printf("Enter name: ");
    fgets(db[num_entries].name, MAX_NAME_LEN, stdin);
    db[num_entries].name[strcspn(db[num_entries].name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter email: ");
    fgets(db[num_entries].email, MAX_EMAIL_LEN, stdin);
    db[num_entries].email[strcspn(db[num_entries].email, "\n")] = '\0'; // Remove trailing newline

    printf("Enter phone number: ");
    fgets(db[num_entries].phone, MAX_PHONE_LEN, stdin);
    db[num_entries].phone[strcspn(db[num_entries].phone, "\n")] = '\0'; // Remove trailing newline

    num_entries++;
}

// Function to query the database
void query_database() {
    char field[MAX_NAME_LEN];
    char value[MAX_NAME_LEN];

    // Prompt user for input
    printf("Enter field to search: ");
    fgets(field, MAX_NAME_LEN, stdin);
    field[strcspn(field, "\n")] = '\0'; // Remove trailing newline

    printf("Enter value to search for: ");
    fgets(value, MAX_NAME_LEN, stdin);
    value[strcspn(value, "\n")] = '\0'; // Remove trailing newline

    // Search for matching records
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(field, "name") == 0 && strcmp(value, db[i].name) == 0) {
            printf("%s %s %s\n", db[i].name, db[i].email, db[i].phone);
        } else if (strcmp(field, "email") == 0 && strcmp(value, db[i].email) == 0) {
            printf("%s %s %s\n", db[i].name, db[i].email, db[i].phone);
        } else if (strcmp(field, "phone") == 0 && strcmp(value, db[i].phone) == 0) {
            printf("%s %s %s\n", db[i].name, db[i].email, db[i].phone);
        }
    }
}

// Function to print all records in the database
void print_database() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s %s\n", db[i].name, db[i].email, db[i].phone);
    }
}

int main() {
    int choice;

    while (1) {
        // Display menu
        printf("1. Add new record\n");
        printf("2. Query database\n");
        printf("3. Print all records\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar(); // Remove trailing newline

        switch (choice) {
            case 1:
                add_record();
                break;

            case 2:
                query_database();
                break;

            case 3:
                print_database();
                break;

            case 4:
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}