//FormAI DATASET v1.0 Category: Database simulation ; Style: modular
#include<stdio.h>
#include<stdlib.h>

#define MAX_RECORDS 1000 // maximum number of records

typedef struct {
    int id;
    char name[30];
    int age;
    char address[50];
} Record;

void menu(); // function to display menu options
void addRecord(Record[], int*); // function to add a record
void viewRecords(Record[], int); // function to view all records

int main() {
    Record records[MAX_RECORDS]; // array of record structures
    int numRecords = 0; // number of records in the array

    int choice;

    do {
        menu(); // display menu options

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addRecord(records, &numRecords); // add a new record
                break;

            case 2:
                viewRecords(records, numRecords); // view all records
                break;

            case 3:
                printf("Exiting program...\n");
                exit(0); // exit the program

            default:
                printf("Invalid choice, please try again.\n");
        }

        printf("\n");

    } while(1);

    return 0;
}

// function to display menu options
void menu() {
    printf("========= Database Simulation =========\n");
    printf("1. Add a record\n");
    printf("2. View all records\n");
    printf("3. Exit\n");
}

// function to add a new record
void addRecord(Record records[], int *numRecords) {
    if (*numRecords >= MAX_RECORDS) {
        printf("Maximum number of records reached.\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &records[*numRecords].id);

    printf("Enter name: ");
    scanf("%s", records[*numRecords].name);

    printf("Enter age: ");
    scanf("%d", &records[*numRecords].age);

    printf("Enter address: ");
    scanf("%s", records[*numRecords].address);

    (*numRecords)++;

    printf("Record added successfully.\n");
}

// function to view all records in the database
void viewRecords(Record records[], int numRecords) {
    if (numRecords <= 0) {
        printf("No records to display.\n");
        return;
    }

    printf("ID\tName\tAge\tAddress\n");

    for (int i = 0; i < numRecords; i++) {
        printf("%d\t%s\t%d\t%s\n", records[i].id, records[i].name, records[i].age, records[i].address);
    }
}