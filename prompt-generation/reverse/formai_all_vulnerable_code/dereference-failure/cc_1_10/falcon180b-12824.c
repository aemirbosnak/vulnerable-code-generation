//Falcon-180B DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a person
typedef struct {
    char name[50];
    int age;
    float height;
} Person;

// Function prototypes
void createPerson(Person **person);
void displayPerson(Person *person);
void deletePerson(Person **person);

int main() {
    Person *person1 = NULL;
    Person *person2 = NULL;

    // Create a new person
    createPerson(&person1);
    createPerson(&person2);

    // Display the person's information
    printf("Person 1:\n");
    displayPerson(person1);
    printf("\n");

    printf("Person 2:\n");
    displayPerson(person2);
    printf("\n");

    // Delete the person
    deletePerson(&person1);
    deletePerson(&person2);

    return 0;
}

// Function to create a new person
void createPerson(Person **person) {
    *person = (Person *) malloc(sizeof(Person));
    if (*person == NULL) {
        printf("Memory error: Unable to allocate memory for person.\n");
        exit(1);
    }

    // Initialize the person's information
    (*person)->age = 25;
    (*person)->height = 1.8;
    strcpy((*person)->name, "John Doe");
}

// Function to display a person's information
void displayPerson(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %f\n", person->height);
}

// Function to delete a person
void deletePerson(Person **person) {
    free(*person);
    *person = NULL;
}