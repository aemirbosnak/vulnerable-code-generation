//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PEOPLE 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

typedef struct {
    Person *people;
    int count;
    int capacity;
} PeopleList;

// Function to create a new PeopleList
PeopleList* createPeopleList() {
    PeopleList *list = (PeopleList *)malloc(sizeof(PeopleList));
    if (list == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    list->capacity = 2;
    list->count = 0;
    list->people = (Person *)malloc(list->capacity * sizeof(Person));
    if (list->people == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(list);
        exit(EXIT_FAILURE);
    }
    return list;
}

// Function to add a new person to the list
void addPerson(PeopleList *list, const char *name, int age) {
    if (list->count >= list->capacity) {
        list->capacity *= 2;
        list->people = (Person *)realloc(list->people, list->capacity * sizeof(Person));
        if (list->people == NULL) {
            fprintf(stderr, "Memory reallocation failed!\n");
            exit(EXIT_FAILURE);
        }
    }
    strncpy(list->people[list->count].name, name, MAX_NAME_LENGTH);
    list->people[list->count].age = age;
    list->count++;
}

// Function to display the list of people
void displayPeople(const PeopleList *list) {
    printf("People List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("Name: %s, Age: %d\n", list->people[i].name, list->people[i].age);
    }
}

// Function to free the memory used by PeopleList
void freePeopleList(PeopleList *list) {
    free(list->people);
    free(list);
}

int main() {
    // Welcome message
    printf("Welcome to the Magical People List!\n");
    
    // Create a new list for people
    PeopleList *list = createPeopleList();
    
    char name[MAX_NAME_LENGTH];
    int age;
    char choice;

    do {
        // Get person's name
        printf("Enter name (or type 'exit' to stop): ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0; // Remove newline character

        if (strcmp(name, "exit") == 0) break;

        // Get person's age
        printf("Enter age: ");
        scanf("%d", &age);
        getchar(); // Clear the newline character from input buffer

        // Add person to the list
        addPerson(list, name, age);

        // Ask if the user wants to add another person
        printf("Do you want to add another person? (y/n): ");
        scanf("%c", &choice);
        getchar(); // Clear the newline character from input buffer
    } while (choice == 'y' || choice == 'Y');

    // Display all added people
    displayPeople(list);

    // Clean up memory
    freePeopleList(list);
    
    // Farewell message
    printf("Thank you for using the Magical People List! Goodbye!\n");

    return 0;
}