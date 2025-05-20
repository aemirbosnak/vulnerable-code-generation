//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char city[50];
} Person;

void printPerson(const Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("City: %s\n", person->city);
}

void freePerson(Person* person) {
    free(person); // Free the allocated memory for the person
}

int main() {
    int n;
    printf("Enter the number of persons: ");
    scanf("%d", &n);
    getchar(); // to consume the newline character after entering N
    
    // Allocating memory for an array of Person
    Person* people = (Person*) malloc(n * sizeof(Person));
    if (people == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }
    
    // Input details of each person
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for person %d:\n", i + 1);
        
        printf("Name: ");
        fgets(people[i].name, sizeof(people[i].name), stdin);
        people[i].name[strcspn(people[i].name, "\n")] = '\0'; // remove newline
        
        printf("Age: ");
        scanf("%d", &people[i].age);
        getchar(); // to consume the newline character
        
        printf("City: ");
        fgets(people[i].city, sizeof(people[i].city), stdin);
        people[i].city[strcspn(people[i].city, "\n")] = '\0'; // remove newline
    }
    
    // Display all persons
    printf("\nDetails of persons entered:\n");
    for (int i = 0; i < n; i++) {
        printf("\nPerson %d:\n", i + 1);
        printPerson(&people[i]);
    }

    // Free the allocated memory
    free(people);
    
    return 0;
}