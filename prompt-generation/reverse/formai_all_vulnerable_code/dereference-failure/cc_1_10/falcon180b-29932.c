//Falcon-180B DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold a person's information
typedef struct {
    char* name;
    int age;
    char* gender;
    int height;
    int weight;
} Person;

// Function to create a new person with default values
Person* createPerson() {
    Person* person = (Person*)malloc(sizeof(Person));
    person->name = (char*)malloc(sizeof(char) * 20);
    strcpy(person->name, "John Doe");
    person->age = 25;
    person->gender = (char*)malloc(sizeof(char) * 10);
    strcpy(person->gender, "Male");
    person->height = 180;
    person->weight = 80;
    return person;
}

// Function to update a person's information
void updatePerson(Person* person, char* newName, int newAge, char* newGender, int newHeight, int newWeight) {
    free(person->name);
    person->name = (char*)malloc(sizeof(char) * strlen(newName) + 1);
    strcpy(person->name, newName);
    person->age = newAge;
    free(person->gender);
    person->gender = (char*)malloc(sizeof(char) * strlen(newGender) + 1);
    strcpy(person->gender, newGender);
    person->height = newHeight;
    person->weight = newWeight;
}

// Function to delete a person and all their information
void deletePerson(Person* person) {
    free(person->name);
    free(person->gender);
    free(person);
}

// Main function
int main() {
    Person* person = createPerson();
    printf("Name: %s\nAge: %d\nGender: %s\nHeight: %d cm\nWeight: %d kg\n", person->name, person->age, person->gender, person->height, person->weight);

    updatePerson(person, "Jane Doe", 30, "Female", 170, 65);
    printf("Name: %s\nAge: %d\nGender: %s\nHeight: %d cm\nWeight: %d kg\n", person->name, person->age, person->gender, person->height, person->weight);

    deletePerson(person);
    return 0;
}