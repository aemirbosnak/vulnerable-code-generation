//FormAI DATASET v1.0 Category: Database simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 // Maximum number of records in the database
#define MAX_NAME_LENGTH 20 // Maximum length of a name string
#define MAX_ADDRESS_LENGTH 50 // Maximum length of an address string

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char address[MAX_ADDRESS_LENGTH];
} Record;

Record database[MAX_RECORDS]; // Define the database as an array of Records
int num_records = 0; // Initialize the number of records to 0

// Function to add a new record to the database
void addRecord(char *name, int age, char *address) {
    if (num_records == MAX_RECORDS) {
        printf("\nSorry, the database is full. Cannot add a new record.\n");
        return;
    }
    strcpy(database[num_records].name, name);
    database[num_records].age = age;
    strcpy(database[num_records].address, address);
    num_records++;
    printf("\nRecord added successfully!\n");
}

// Function to display all records in the database
void displayRecords() {
    if (num_records == 0) {
        printf("\nNo records found in the database.\n");
        return;
    }
    printf("\n%-20s%-5s%-50s\n", "Name", "Age", "Address");
    for (int i = 0; i < num_records; i++) {
        printf("%-20s%-5d%-50s\n", database[i].name, database[i].age, database[i].address);
    }
}

int main() {
    char option;
    char name[MAX_NAME_LENGTH];
    int age;
    char address[MAX_ADDRESS_LENGTH];
    while (1) {
        printf("\nSelect an option and press enter:\n");
        printf("1. Add a new record\n");
        printf("2. Display all records\n");
        printf("3. Exit\n");
        scanf(" %c", &option);
        switch (option) {
            case '1':
                printf("\nEnter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                printf("Enter address: ");
                scanf(" %[^\n]s", address);
                addRecord(name, age, address);
                break;
            case '2':
                displayRecords();
                break;
            case '3':
                printf("\nExiting...\n");
                return 0;
            default:
                printf("\nInvalid option. Please try again.\n");
        }
    }
    return 0;
}