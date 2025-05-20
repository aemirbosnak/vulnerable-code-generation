//Falcon-180B DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold information about a person
typedef struct {
    char* first_name;
    char* last_name;
    int age;
} Person;

// Function to create a new person with default values
Person* create_person() {
    Person* new_person = (Person*) malloc(sizeof(Person));
    if (new_person == NULL) {
        printf("Error: Unable to allocate memory for new person.\n");
        return NULL;
    }
    
    new_person->first_name = strdup("Unknown");
    new_person->last_name = strdup("Unknown");
    new_person->age = 0;
    
    return new_person;
}

// Function to copy an existing person
Person* copy_person(Person* original) {
    Person* copy = (Person*) malloc(sizeof(Person));
    if (copy == NULL) {
        printf("Error: Unable to allocate memory for new person.\n");
        return NULL;
    }
    
    copy->first_name = strdup(original->first_name);
    copy->last_name = strdup(original->last_name);
    copy->age = original->age;
    
    return copy;
}

// Function to free memory used by a person
void free_person(Person* person) {
    free(person->first_name);
    free(person->last_name);
    free(person);
}

// Main function to test the memory management functions
int main() {
    Person* person1 = create_person();
    Person* person2 = copy_person(person1);
    
    printf("Original person:\n");
    printf("First name: %s\n", person1->first_name);
    printf("Last name: %s\n", person1->last_name);
    printf("Age: %d\n", person1->age);
    
    printf("\nCopied person:\n");
    printf("First name: %s\n", person2->first_name);
    printf("Last name: %s\n", person2->last_name);
    printf("Age: %d\n", person2->age);
    
    free_person(person1);
    free_person(person2);
    
    return 0;
}