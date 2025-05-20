//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
#define ARRAY_SIZE 5

typedef struct {
    char name[MAX_STR_LEN];
    int age;
} Person;

void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

Person* createPerson(const char *name, int age) {
    Person *newPerson = (Person *)malloc(sizeof(Person));
    if (newPerson == NULL) {
        handleError("Failed to allocate memory for a new person");
    }
    strncpy(newPerson->name, name, MAX_STR_LEN);
    newPerson->age = age;
    return newPerson;
}

void displayPerson(const Person *person) {
    if (person != NULL) {
        printf("Name: %s, Age: %d\n", person->name, person->age);
    }
}

void cleanup(Person **person) {
    if (person != NULL && *person != NULL) {
        free(*person);
        *person = NULL; // Avoid dangling pointer
    }
}

void fillPeopleArray(Person **people, int size) {
    char name[MAX_STR_LEN];
    int age;
    
    for (int i = 0; i < size; ++i) {
        printf("Enter name for person %d: ", i + 1);
        scanf("%s", name);
        printf("Enter age for person %d: ", i + 1);
        scanf("%d", &age);
        
        people[i] = createPerson(name, age);
    }
}

void displayPeople(const Person **people, int size) {
    for (int i = 0; i < size; ++i) {
        displayPerson(people[i]);
    }
}

void freePeopleArray(Person **people, int size) {
    for (int i = 0; i < size; ++i) {
        cleanup(&people[i]);
    }
}

int main() {
    Person *people[ARRAY_SIZE];

    // Fill the people array with user data
    fillPeopleArray(people, ARRAY_SIZE);

    // Display the populated people
    printf("\nDisplaying all people:\n");
    displayPeople((const Person **)people, ARRAY_SIZE);

    // Clean up allocated memory
    freePeopleArray(people, ARRAY_SIZE);

    return 0;
}