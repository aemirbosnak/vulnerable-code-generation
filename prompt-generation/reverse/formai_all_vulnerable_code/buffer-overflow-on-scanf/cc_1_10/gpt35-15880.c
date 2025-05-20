//FormAI DATASET v1.0 Category: Database Indexing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert string to lowercase
void toLower(char *s) {
    int i;
    for(i = 0; i < strlen(s); i++) {
        s[i] = tolower(s[i]);
    }
}

// Structure definition for the database
typedef struct {
    char name[50];
    char location[50];
    int age;
} Person;

// Function to add a person to the database
void addPerson(Person *people, int *count) {
    // Prompt user for person information
    printf("Enter name: ");
    scanf("%s", people[*count].name);
    printf("Enter location: ");
    scanf("%s", people[*count].location);
    printf("Enter age: ");
    scanf("%d", &people[*count].age);
    (*count)++;
    printf("Person added to database!\n");
}

// Function to search for a person
void searchPerson(Person *people, int count) {
    // Prompt user for name to search for
    char searchTerm[50];
    printf("Enter name to search for: ");
    scanf("%s", searchTerm);
    toLower(searchTerm); // convert to lowercase for case-insensitive search
    int found = 0; // flag to track if person was found
    // Search for person in database
    for(int i = 0; i < count; i++) {
        char lowerName[50];
        strcpy(lowerName, people[i].name);
        toLower(lowerName); // convert name to lowercase for case-insensitive search
        if(strcmp(lowerName, searchTerm) == 0) {
            printf("Person found!\n");
            printf("Name: %s\nLocation: %s\nAge: %d\n", people[i].name, people[i].location, people[i].age);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Person not found.\n");
    }
}

// Function to display all people in the database
void displayPeople(Person *people, int count) {
    if(count == 0) {
        printf("No people in the database.\n");
        return;
    }
    printf("People in the database:\n");
    for(int i = 0; i < count; i++) {
        printf("Name: %s\nLocation: %s\nAge: %d\n", people[i].name, people[i].location, people[i].age);
    }
}

int main() {
    Person *people = malloc(100 * sizeof(Person)); // initial capacity for 100 people
    int count = 0; // number of people currently in the database
    int choice;
    do {
        // Prompt user for menu selection
        printf("\nDatabase Menu:\n");
        printf("1. Add person\n");
        printf("2. Search for person\n");
        printf("3. Display all people\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addPerson(people, &count);
                break;
            case 2:
                searchPerson(people, count);
                break;
            case 3:
                displayPeople(people, count);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while(choice != 4);
    free(people);
    return 0;
}