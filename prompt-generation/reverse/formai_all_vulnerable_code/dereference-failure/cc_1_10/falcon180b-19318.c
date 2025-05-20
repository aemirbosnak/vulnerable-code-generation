//Falcon-180B DATASET v1.0 Category: Memory management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold our data
typedef struct {
    char *name;
    int age;
} Person;

// Function to create a new person
Person *create_person(char *name, int age) {
    Person *person = (Person *) malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    return person;
}

// Function to print a person's information
void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

// Main function to demonstrate memory management
int main() {
    // Create a new person
    Person *person1 = create_person("John", 30);

    // Print the person's information
    print_person(person1);

    // Modify the person's age
    person1->age = 31;

    // Print the person's updated information
    print_person(person1);

    // Create another person
    Person *person2 = create_person("Jane", 25);

    // Print the second person's information
    print_person(person2);

    // Free the memory used by the first person
    free(person1->name);
    free(person1);

    // Free the memory used by the second person
    free(person2->name);
    free(person2);

    return 0;
}