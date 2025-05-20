//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATABASE_SIZE 100

typedef struct {
    char name[32];
    int age;
    char occupation[32];
} Person;

Person database[DATABASE_SIZE];

int main() {
    // Initialize the database with some sample data
    strcpy(database[0].name, "John Doe");
    database[0].age = 30;
    strcpy(database[0].occupation, "Software Engineer");

    strcpy(database[1].name, "Jane Doe");
    database[1].age = 25;
    strcpy(database[1].occupation, "Doctor");

    strcpy(database[2].name, "Peter Parker");
    database[2].age = 20;
    strcpy(database[2].occupation, "Student");

    // Get the user's input
    char name[32];
    printf("Enter the name of the person you want to search for: ");
    scanf("%s", name);

    // Search the database for the person
    int found = 0;
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (strcmp(database[i].name, name) == 0) {
            found = 1;

            // Print the person's information
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("Occupation: %s\n", database[i].occupation);

            break;
        }
    }

    // If the person was not found, print an error message
    if (!found) {
        printf("Person not found.\n");
    }

    return 0;
}