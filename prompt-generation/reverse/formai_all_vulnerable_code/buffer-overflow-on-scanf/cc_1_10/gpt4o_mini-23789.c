//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
    int age;
    float height;
} Person;

// Function prototypes
void addPerson(Person **people, int *count);
void displayPeople(Person *people, int count);
void freeMemory(Person *people);

int main() {
    Person *people = NULL; // Pointer to hold array of Person
    int count = 0; // Number of people added
    int choice;

    while (1) {
        printf("\n*** Person Manager ***\n");
        printf("1. Add Person\n");
        printf("2. Display All People\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPerson(&people, &count);
                break;
            case 2:
                displayPeople(people, count);
                break;
            case 3:
                freeMemory(people);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addPerson(Person **people, int *count) {
    // Increase the size of the memory block dynamically
    *people = realloc(*people, (*count + 1) * sizeof(Person));
    if (*people == NULL) {
        printf("Memory allocation failed! Exiting...\n");
        exit(1);
    }

    // Get input for new person
    printf("Enter name: ");
    scanf("%s", (*people)[*count].name);
    printf("Enter age: ");
    scanf("%d", &(*people)[*count].age);
    printf("Enter height: ");
    scanf("%f", &(*people)[*count].height);

    (*count)++;
    printf("Person added successfully!\n");
}

void displayPeople(Person *people, int count) {
    if (count == 0) {
        printf("No people to display.\n");
        return;
    }
    
    printf("\n*** List of People ***\n");
    for (int i = 0; i < count; i++) {
        printf("Person %d: Name: %s, Age: %d, Height: %.2f\n", 
               i + 1, people[i].name, people[i].age, people[i].height);
    }
}

void freeMemory(Person *people) {
    free(people);
    printf("Memory freed successfully. Exiting program.\n");
}