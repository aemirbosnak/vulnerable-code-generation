//FormAI DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50 // maximum number of records

typedef struct {
    int id;
    char name[20];
    int age;
} Record;

// function prototypes
void insert_record(Record records[], int *size);
void delete_record(Record records[], int *size, int id);
void search_record(Record records[], int size, int id);
void display_records(Record records[], int size);

int main() {
    Record records[MAX_SIZE];
    int size = 0;
    int choice, id;

    // menu loop
    do {
        printf("\n----- Database Menu -----\n");
        printf("1. Insert Record\n");
        printf("2. Delete Record\n");
        printf("3. Search Record\n");
        printf("4. Display Records\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_record(records, &size);
                break;

            case 2:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                delete_record(records, &size, id);
                break;

            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                search_record(records, size, id);
                break;

            case 4:
                display_records(records, size);
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}

void insert_record(Record records[], int *size) {
    // check if database is full
    if (*size >= MAX_SIZE) {
        printf("Database is full!\n");
        return;
    }

    // add new record
    printf("Enter ID: ");
    scanf("%d", &records[*size].id);
    printf("Enter Name: ");
    scanf("%s", records[*size].name);
    printf("Enter Age: ");
    scanf("%d", &records[*size].age);

    // increment size
    (*size)++;

    printf("Record added!\n");
}

void delete_record(Record records[], int *size, int id) {
    int i, j, found = 0;

    for (i = 0; i < *size; i++) {
        if (records[i].id == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        // shift all records after deleted record to left
        for (j = i; j < *size - 1; j++) {
            records[j] = records[j+1];
        }

        // decrement size
        (*size)--;

        printf("Record deleted!\n");

    } else {
        printf("Record not found!\n");
    }
}

void search_record(Record records[], int size, int id) {
    int i, found = 0;

    for (i = 0; i < size; i++) {
        if (records[i].id == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("ID: %d\nName: %s\nAge: %d\n", records[i].id, records[i].name, records[i].age);
    } else {
        printf("Record not found!\n");
    }
}

void display_records(Record records[], int size) {
    int i;

    printf("\n--- Records ---\n");

    for (i = 0; i < size; i++) {
        printf("ID: %d\nName: %s\nAge: %d\n\n", records[i].id, records[i].name, records[i].age);
    }
}