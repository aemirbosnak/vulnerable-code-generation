//FormAI DATASET v1.0 Category: Database simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program simulates a database using C. You can add, delete, and search for records.
 * It will also provide some humorous responses that might make you smile.
*/

typedef struct {
    char name[50];
    int age;
    char occupation[50];
} Person;

int numRecords = 0;
Person *database = NULL;

void displayMenu() {
    printf("Welcome to the worst database you've ever used!\n");
    printf("Please select an option:\n");
    printf("1. Add a record\n");
    printf("2. Delete a record\n");
    printf("3. Search for a record\n");
    printf("4. Exit the program\n");
}

void addRecord() {
    if (numRecords == 0) {
        database = (Person*) malloc(sizeof(Person));
    } else {
        database = (Person*) realloc(database, (numRecords + 1) * sizeof(Person));
    }

    printf("\nPlease enter the person's name: ");
    scanf("%s", database[numRecords].name);
    printf("Please enter the person's age: ");
    scanf("%d", &database[numRecords].age);
    printf("Please enter the person's occupation: ");
    scanf("%s", database[numRecords].occupation);

    printf("\nRecord added!\n");
    numRecords++;
}

void deleteRecord() {
    char searchName[50];
    int found = 0;

    printf("\nPlease enter the name of the record you with to delete: ");
    scanf("%s", searchName);

    for (int i = 0; i < numRecords; i++) {
        if (strcmp(database[i].name, searchName) == 0) {
            found = 1;

            for (int j = i; j < numRecords - 1; j++) {
                strcpy(database[j].name, database[j+1].name);
                database[j].age = database[j+1].age;
                strcpy(database[j].occupation, database[j+1].occupation);
            }
            numRecords--;
            database = (Person*) realloc(database, numRecords * sizeof(Person));
            printf("\nRecord deleted!\n");
            break;
        }
    }

    if (!found) {
        printf("\nRecord not found. Your search skills are about as good as a cat trying to solve a Rubik's cube.\n");
    }
}

void searchRecord() {
    char searchName[50];
    int found = 0;

    printf("\nPlease enter the name of the record you wish to search for: ");
    scanf("%s", searchName);

    for (int i = 0; i < numRecords; i++) {
        if (strcmp(database[i].name, searchName) == 0) {
            found = 1;
            printf("\nName: %s\nAge: %d\nOccupation: %s\n", database[i].name, database[i].age, database[i].occupation);
            break;
        }
    }

    if (!found) {
        printf("\nRecord not found. You might as well be searching for Bigfoot in your backyard.\n");
    }
}

int main() {
    int option;

    do {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addRecord();
                break;
            case 2:
                deleteRecord();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                printf("\nThanks for using this dumpster fire of a database. Have a mediocre day!\n");
                break;
            default:
                printf("\nInvalid option. You're about as good at selecting options as a monkey trying to use a computer.\n");
        }
    } while (option != 4);

    free(database);
    return 0;
}