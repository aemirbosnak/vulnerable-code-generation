//Falcon-180B DATASET v1.0 Category: Memory management ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for our data
typedef struct {
    char* name;
    int age;
} Person;

// Function to create a new Person
Person* createPerson(char* name, int age) {
    Person* person = (Person*) malloc(sizeof(Person));
    if (person == NULL) {
        printf("Error: Out of memory\n");
        return NULL;
    }
    person->name = strdup(name);
    person->age = age;
    return person;
}

// Function to print a Person's information
void printPerson(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

// Function to free a Person's memory
void deletePerson(Person* person) {
    if (person == NULL) {
        return;
    }
    free(person->name);
    free(person);
}

// Main function
int main() {
    // Create some people
    Person* alice = createPerson("Alice", 25);
    Person* bob = createPerson("Bob", 30);
    Person* charlie = createPerson("Charlie", 35);

    // Print their information
    printPerson(alice);
    printPerson(bob);
    printPerson(charlie);

    // Delete the people
    deletePerson(alice);
    deletePerson(bob);
    deletePerson(charlie);

    return 0;
}