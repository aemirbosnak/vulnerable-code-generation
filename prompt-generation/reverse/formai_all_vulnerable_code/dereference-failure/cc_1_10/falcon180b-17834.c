//Falcon-180B DATASET v1.0 Category: Memory management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a person
typedef struct {
    char *name;
    int age;
} Person;

// Function prototypes
void createPerson(Person *person);
void printPerson(Person *person);
void deletePerson(Person *person);

// Main function
int main() {
    Person *person1 = NULL;
    Person *person2 = NULL;

    // Create a person
    person1 = (Person *) malloc(sizeof(Person));
    if (person1 == NULL) {
        printf("Error: could not allocate memory for person.\n");
        return 1;
    }
    createPerson(person1);

    // Create another person
    person2 = (Person *) malloc(sizeof(Person));
    if (person2 == NULL) {
        printf("Error: could not allocate memory for person.\n");
        return 1;
    }
    createPerson(person2);

    // Print the people
    printPerson(person1);
    printPerson(person2);

    // Delete the people
    deletePerson(person1);
    deletePerson(person2);

    // Free the memory
    free(person1);
    free(person2);

    return 0;
}

// Function to create a person
void createPerson(Person *person) {
    person->name = (char *) malloc(10 * sizeof(char));
    if (person->name == NULL) {
        printf("Error: could not allocate memory for name.\n");
        return;
    }
    strcpy(person->name, "John Doe");

    person->age = 30;
}

// Function to print a person
void printPerson(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

// Function to delete a person
void deletePerson(Person *person) {
    free(person->name);
    person->name = NULL;
}