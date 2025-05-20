//FormAI DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_RECORDS 10 // maximum number of records in the database
#define MAX_NAME_LENGTH 100 // maximum length of a name
#define MAX_PHONE_LENGTH 10 // maximum length of a phone number

// structure to store a record in the database
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Record;

// global variables for the database
Record database[MAX_NUM_RECORDS]; // array to store records
int num_records = 0; // current number of records in the database

// function to add a record to the database
void add_record() {
    if (num_records == MAX_NUM_RECORDS) {
        printf("Database is full!\n");
        return;
    }
    printf("Enter name: ");
    fgets(database[num_records].name, MAX_NAME_LENGTH, stdin);
    database[num_records].name[strcspn(database[num_records].name, "\n")] = '\0'; // remove newline character
    printf("Enter phone number: ");
    fgets(database[num_records].phone, MAX_PHONE_LENGTH, stdin);
    database[num_records].phone[strcspn(database[num_records].phone, "\n")] = '\0'; // remove newline character
    num_records++;
    printf("Record added successfully!\n");
}

// function to display all records in the database
void display_records() {
    if (num_records == 0) {
        printf("Database is empty!\n");
        return;
    }
    printf("Name\tPhone\n");
    for (int i = 0; i < num_records; i++) {
        printf("%s\t%s\n", database[i].name, database[i].phone);
    }
}

// main function
int main() {
    int choice;
    do {
        printf("1. Add record\n");
        printf("2. Display records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
    return 0;
}