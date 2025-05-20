//FormAI DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // maximum size of database

// struct to store data points
typedef struct {
    int id;
    char name[20];
    char email[20];
} Data;

// global array to represent database
Data database[MAX_SIZE];
int length = 0; // current length of database

// function prototypes
void addData();
void deleteData();
void displayData();
void findData();

int main() {
    int choice;

    printf("***DATABASE SIMULATION PROGRAM***\n\n");

    // loop through menu options
    do {
        printf("\n1. Add Data\n");
        printf("2. Delete Data\n");
        printf("3. Display Data\n");
        printf("4. Find Data\n");
        printf("5. Quit\n\n");
        printf("What would you like to do? ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addData();
                break;
            case 2:
                deleteData();
                break;
            case 3:
                displayData();
                break;
            case 4:
                findData();
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// function to add data to database
void addData() {
    // check if database is full
    if (length >= MAX_SIZE) {
        printf("\nDatabase is full. Cannot add more data.\n");
        return;
    }

    printf("\nEnter data:\n");

    // get input from user
    Data newData;
    printf("ID: ");
    scanf("%d", &newData.id);
    printf("Name: ");
    scanf("%s", newData.name);
    printf("Email: ");
    scanf("%s", newData.email);

    // add data to database
    database[length] = newData;
    length++;

    printf("\nData added successfully.\n");
}

// function to delete data from database
void deleteData() {
    // check if database is empty
    if (length == 0) {
        printf("\nDatabase is empty. Cannot delete data.\n");
        return;
    }

    int idToDelete;
    printf("\nEnter ID of data to delete: ");
    scanf("%d", &idToDelete);

    int indexToDelete = -1; // initialize index to -1 (not found)
    for (int i = 0; i < length; i++) {
        if (database[i].id == idToDelete) {
            indexToDelete = i;
            break;
        }
    }

    // check if data was found
    if (indexToDelete == -1) {
        printf("\nData with ID %d not found.\n", idToDelete);
        return;
    }

    // shift all data after deleted data down by one index
    for (int i = indexToDelete; i < length - 1; i++) {
        database[i] = database[i + 1];
    }

    length--;

    printf("\nData with ID %d deleted successfully.\n", idToDelete);
}

// function to display all data in database
void displayData() {
    // check if database is empty
    if (length == 0) {
        printf("\nDatabase is empty. No data to display.\n");
        return;
    }

    printf("\n%-5s%-20s%-20s\n", "ID", "Name", "Email");
    for (int i = 0; i < length; i++) {
        printf("%-5d%-20s%-20s\n", database[i].id, database[i].name, database[i].email);
    }
}

// function to find data by ID
void findData() {
    // check if database is empty
    if (length == 0) {
        printf("\nDatabase is empty. No data to find.\n");
        return;
    }

    int idToFind;
    printf("\nEnter ID of data to find: ");
    scanf("%d", &idToFind);

    int indexToFind = -1; // initialize index to -1 (not found)
    for (int i = 0; i < length; i++) {
        if (database[i].id == idToFind) {
            indexToFind = i;
            break;
        }
    }

    // check if data was found
    if (indexToFind == -1) {
        printf("\nData with ID %d not found.\n", idToFind);
        return;
    }

    printf("\n%-5s%-20s%-20s\n", "ID", "Name", "Email");
    printf("%-5d%-20s%-20s\n", database[indexToFind].id, database[indexToFind].name, database[indexToFind].email);
}