//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
/* This program simulates a basic database system */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum number of records */
#define MAX_RECORDS 100

/* Define the structure of a record */
typedef struct {
    char name[50];
    int age;
    char address[100];
} Record;

/* Declare the global variables */
Record database[MAX_RECORDS];
int num_records;

/* Function to add a record */
void add_record() {
    if (num_records == MAX_RECORDS) {
        printf("Database is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", database[num_records].name);

    printf("Enter age: ");
    scanf("%d", &database[num_records].age);

    printf("Enter address: ");
    scanf("%s", database[num_records].address);

    num_records++;
}

/* Function to search for a record by name */
void search_record() {
    char name[50];

    printf("Enter name to search: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Record found:\n");
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("Address: %s\n", database[i].address);
            return;
        }
    }

    printf("Record not found.\n");
}

/* Function to display all records */
void display_records() {
    int i;
    for (i = 0; i < num_records; i++) {
        printf("Record %d:\n", i+1);
        printf("Name: %s\n", database[i].name);
        printf("Age: %d\n", database[i].age);
        printf("Address: %s\n", database[i].address);
        printf("\n");
    }
}

int main() {
    int choice;

    /* Initialize the database */
    num_records = 0;

    while (1) {
        printf("\n");
        printf("1. Add record\n");
        printf("2. Search record\n");
        printf("3. Display all records\n");
        printf("4. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record();
                break;

            case 2:
                search_record();
                break;

            case 3:
                display_records();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}