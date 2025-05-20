//FormAI DATASET v1.0 Category: Database simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

// Structure definition for the database fields
typedef struct {
    int id;
    char name[20];
    int age;
} Database;

// Function to add new record in the database
void addRecord(Database *db[], int *count) {
    printf("Enter the details of the record:\n");
    db[*count] = (Database*) malloc(sizeof(Database));
    db[*count]->id = *count + 1; // Incremented by 1 to avoid id conflicts 
    printf("Name: ");
    scanf("%s", db[*count]->name);
    printf("Age: ");
    scanf("%d", &db[*count]->age);
    printf("Record added successfully!\n");
    (*count)++;
}

//Function to search a record in the database based on id
void searchRecord(Database *db[], int count) {
    int id, i;
    printf("Enter the id of the record you want to search: ");
    scanf("%d", &id);
    for (i = 0; i < count; i++) {
        if (db[i]->id == id) {
            printf("Record found:\nId: %d\nName: %s\nAge: %d\n", db[i]->id, db[i]->name, db[i]->age);
            return;
        }
    }
    printf("No record found with id %d.\n", id);
}

// Function to print all the records in the database
void printDatabase(Database *db[], int count) {
    int i;
    printf("ID\tName\tAge\n");
    for (i = 0; i < count; i++) {
        printf("%d\t%s\t%d\n", db[i]->id, db[i]->name, db[i]->age);
    }
}

// Function to free the dynamic memory allocated by the records
void freeMemory(Database *db[], int count) {
    int i;
    for (i = 0; i < count; i++) {
        free(db[i]);
    }
}

int main() {
    Database *db[MAX];
    int count = 0, choice;
    while(1) {
        printf("\n--------MENU--------\n");
        printf("1. Add Record\n2. Search Record by Id\n3. Print Database\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
                addRecord(db, &count);
                break;
            case 2:
                searchRecord(db, count);
                break;
            case 3:
                printDatabase(db, count);
                break;
            case 4:
                freeMemory(db, count);
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}