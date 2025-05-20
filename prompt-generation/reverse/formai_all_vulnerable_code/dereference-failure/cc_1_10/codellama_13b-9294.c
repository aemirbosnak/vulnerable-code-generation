//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold the data
typedef struct {
    char name[50];
    int age;
    float height;
} Person;

// Define a function to allocate memory for a Person
Person* createPerson() {
    Person* person = (Person*) malloc(sizeof(Person));
    return person;
}

// Define a function to free memory for a Person
void destroyPerson(Person* person) {
    free(person);
}

// Define a function to set the name of a Person
void setName(Person* person, char* name) {
    strcpy(person->name, name);
}

// Define a function to set the age of a Person
void setAge(Person* person, int age) {
    person->age = age;
}

// Define a function to set the height of a Person
void setHeight(Person* person, float height) {
    person->height = height;
}

// Define a function to print a Person's data
void printPerson(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %.2f\n", person->height);
}

int main() {
    // Allocate memory for a Person
    Person* person = createPerson();

    // Set the data for the Person
    setName(person, "John Doe");
    setAge(person, 30);
    setHeight(person, 1.75);

    // Print the data for the Person
    printPerson(person);

    // Free the memory for the Person
    destroyPerson(person);

    return 0;
}