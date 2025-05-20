//FormAI DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Defining the maximum number of records */
#define MAX_RECORDS 100

/* Defining the maximum length of each field */
#define MAX_FIELD_LENGTH 50

/* Defining the structure for a record */
struct Record {
    int id;
    char name[MAX_FIELD_LENGTH];
    char email[MAX_FIELD_LENGTH];
    int age;
};

/* Defining the global variable to store the records */
struct Record records[MAX_RECORDS];

/* Defining the current number of records in the database */
int num_records = 0;

/* Function to add a new record */
void addRecord() {
    /* Checking if the database is full */
    if (num_records >= MAX_RECORDS) {
        printf("Database is full. Cannot add a new record.\n");
        return;
    }
    
    /* Reading the user input for the new record */
    struct Record newRecord;
    printf("Enter the id: ");
    scanf("%d", &newRecord.id);
    printf("Enter the name: ");
    scanf("%s", newRecord.name);
    printf("Enter the email: ");
    scanf("%s", newRecord.email);
    printf("Enter the age: ");
    scanf("%d", &newRecord.age);
    
    /* Adding the new record to the database */
    records[num_records] = newRecord;
    num_records++;
    
    printf("Record added successfully.\n");
}

/* Function to search for a record by id */
void searchById() {
    /* Reading the user input for the id */
    int id;
    printf("Enter the id to search for: ");
    scanf("%d", &id);
    
    /* Searching for the record */
    bool found = false;
    for (int i = 0; i < num_records; i++) {
        if (records[i].id == id) {
            printf("Record found:\n");
            printf("id: %d\n", records[i].id);
            printf("name: %s\n", records[i].name);
            printf("email: %s\n", records[i].email);
            printf("age: %d\n", records[i].age);
            found = true;
            break;
        }
    }
    
    /* Printing message if record not found */
    if (!found) {
        printf("Record not found.\n");
    }
}

/* Function to search for a record by name */
void searchByName() {
    /* Reading the user input for the name */
    char name[MAX_FIELD_LENGTH];
    printf("Enter the name to search for: ");
    scanf("%s", name);
    
    /* Searching for the record */
    bool found = false;
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, name) == 0) {
            printf("Record found:\n");
            printf("id: %d\n", records[i].id);
            printf("name: %s\n", records[i].name);
            printf("email: %s\n", records[i].email);
            printf("age: %d\n", records[i].age);
            found = true;
        }
    }
    
    /* Printing message if record not found */
    if (!found) {
        printf("Record not found.\n");
    }
}

/* Function to print all records */
void printAll() {
    /* Checking if there are any records */
    if (num_records == 0) {
        printf("Database is empty.\n");
        return;
    }
    
    /* Printing all the records */
    printf("id\tname\temail\tage\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d\t%s\t%s\t%d\n", records[i].id, records[i].name, records[i].email, records[i].age);
    }
}

/* Main function to handle user input */
int main() {
    /* Looping to get user input */
    while (true) {
        printf("\n1. Add a record\n");
        printf("2. Search for a record by id\n");
        printf("3. Search for a record by name\n");
        printf("4. Print all records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        /* Reading the user choice */
        int choice;
        scanf("%d", &choice);
        
        /* Performing action based on the user choice */
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                searchById();
                break;
            case 3:
                searchByName();
                break;
            case 4:
                printAll();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}