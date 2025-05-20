//Falcon-180B DATASET v1.0 Category: Memory management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for our data
typedef struct {
    char *name;
    int age;
    float height;
} Person;

// Function to create a new person
Person *create_person(char *name, int age, float height) {
    // Allocate memory for the struct
    Person *person = (Person *) malloc(sizeof(Person));
    
    // Initialize the fields
    person->name = strdup(name);
    person->age = age;
    person->height = height;
    
    return person;
}

// Function to print a person's information
void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %.2f\n", person->height);
}

// Function to free a person's memory
void free_person(Person *person) {
    // Free the name string
    free(person->name);
    
    // Free the struct itself
    free(person);
}

int main() {
    // Create a new person
    Person *person = create_person("John Doe", 30, 1.8);
    
    // Print the person's information
    print_person(person);
    
    // Free the person's memory
    free_person(person);
    
    return 0;
}