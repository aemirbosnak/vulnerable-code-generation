//Falcon-180B DATASET v1.0 Category: Educational ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define a custom data type for a person
typedef struct {
    char name[50];
    int age;
    char gender[10];
} Person;

// Function prototypes
void createPerson(Person *person);
void printPerson(Person person);
void deletePerson(Person *person);

int main() {
    Person person;

    // Create a new person
    createPerson(&person);

    // Print the person's information
    printPerson(person);

    // Delete the person
    deletePerson(&person);

    return 0;
}

// Function to create a new person
void createPerson(Person *person) {
    printf("Enter the person's name: ");
    scanf("%s", person->name);

    printf("Enter the person's age: ");
    scanf("%d", &person->age);

    printf("Enter the person's gender: ");
    scanf("%s", person->gender);
}

// Function to print a person's information
void printPerson(Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Gender: %s\n", person.gender);
}

// Function to delete a person
void deletePerson(Person *person) {
    printf("Deleting person with name: %s\n", person->name);
}