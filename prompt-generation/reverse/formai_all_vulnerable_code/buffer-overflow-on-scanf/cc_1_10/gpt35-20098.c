//FormAI DATASET v1.0 Category: Database simulation ; Style: future-proof
// A database simulation program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for the database
typedef struct {
    int id;
    char name[50];
    int age;
    char email[50];
} Person;

// Define an array to store the data
Person people[100];

// Define a counter to keep track of the number of entries in the database
int count = 0;

// Prototypes for functions
void addPerson();
void displayAllPeople();
void searchByName();
void searchByEmail();
void removePerson();

int main() {
    int choice;

    // Loop through the menu until the user chooses to exit
    do {
        printf("\n-- Database Simulation --\n\n");
        printf("1. Add Person\n");
        printf("2. Display All People\n");
        printf("3. Search by Name\n");
        printf("4. Search by Email\n");
        printf("5. Remove Person\n");
        printf("6. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addPerson();
                break;
            case 2:
                displayAllPeople();
                break;
            case 3:
                searchByName();
                break;
            case 4:
                searchByEmail();
                break;
            case 5:
                removePerson();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while(choice != 6);

    return 0;
}

void addPerson() {
    if(count == 100) {
        printf("The database is full. No more entries can be added.\n");
        return;
    }

    Person newPerson;

    printf("\nEnter the following details:\n");
    printf("ID: ");
    scanf("%d", &newPerson.id);
    printf("Name: ");
    scanf("%s", newPerson.name);
    printf("Age: ");
    scanf("%d", &newPerson.age);
    printf("Email: ");
    scanf("%s", newPerson.email);

    people[count] = newPerson;
    count++;

    printf("Person added successfully.\n");
}

void displayAllPeople() {
    if(count == 0) {
        printf("The database is empty. No records to display.\n");
        return;
    }

    printf("\nID\tName\tAge\tEmail\n");

    for(int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%s\n", people[i].id, people[i].name, people[i].age, people[i].email);
    }
}

void searchByName() {
    if(count == 0) {
        printf("The database is empty. No records to search.\n");
        return;
    }

    char query[50];
    int resultsFound = 0;

    printf("\nEnter the name to search: ");
    scanf("%s", query);

    printf("\nResults:\n");

    // Loop through the database and search for the name
    for(int i = 0; i < count; i++) {
        if(strcmp(people[i].name, query) == 0) {
            printf("%d\t%s\t%d\t%s\n", people[i].id, people[i].name, people[i].age, people[i].email);
            resultsFound = 1;
        }
    }

    if(!resultsFound) {
        printf("No results found for '%s'.\n", query);
    }
}

void searchByEmail() {
    if(count == 0) {
        printf("The database is empty. No records to search.\n");
        return;
    }

    char query[50];
    int resultsFound = 0;

    printf("\nEnter the email to search: ");
    scanf("%s", query);

    printf("\nResults:\n");

    // Loop through the database and search for the email
    for(int i = 0; i < count; i++) {
        if(strcmp(people[i].email, query) == 0) {
            printf("%d\t%s\t%d\t%s\n", people[i].id, people[i].name, people[i].age, people[i].email);
            resultsFound = 1;
        }
    }

    if(!resultsFound) {
        printf("No results found for '%s'.\n", query);
    }
}

void removePerson() {
    if(count == 0) {
        printf("The database is empty. No records to remove.\n");
        return;
    }

    int idToRemove;
    int indexToRemove = -1;

    printf("\nEnter the ID of the person to remove: ");
    scanf("%d", &idToRemove);

    // Loop through the database and find the index of the person to remove
    for(int i = 0; i < count; i++) {
        if(people[i].id == idToRemove) {
            indexToRemove = i;
            break;
        }
    }

    if(indexToRemove == -1) {
        printf("No person found with ID %d.\n", idToRemove);
        return;
    }

    // Shift the entries after the removed entry up one index to fill the gap
    for(int i = indexToRemove; i < count - 1; i++) {
        people[i] = people[i + 1];
    }

    count--;

    printf("Person with ID %d removed successfully.\n", idToRemove);
}