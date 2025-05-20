//FormAI DATASET v1.0 Category: Database querying ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Defining struct to hold information about a person */
typedef struct {
    char name[50];
    int age;
    char occupation[50];
} Person;

int main() {
    int n = 5; // Number of persons in database
    Person people[n];

    strcpy(people[0].name, "John");
    people[0].age = 25;
    strcpy(people[0].occupation, "Teacher");

    strcpy(people[1].name, "Anna");
    people[1].age = 32;
    strcpy(people[1].occupation, "Engineer");

    strcpy(people[2].name, "David");
    people[2].age = 45;
    strcpy(people[2].occupation, "Doctor");

    strcpy(people[3].name, "Samantha");
    people[3].age = 29;
    strcpy(people[3].occupation, "Lawyer");

    strcpy(people[4].name, "Peter");
    people[4].age = 38;
    strcpy(people[4].occupation, "Accountant");

    printf("Welcome to the Person database. What would you like to do?\n");
    printf("1. Query by name\n");
    printf("2. Query by age range\n");
    printf("3. Query by occupation\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Query by name
            printf("Enter name to search for: ");
            char searchName[50];
            scanf("%s", searchName);
            for (int i = 0; i < n; i++) {
                if (strcmp(searchName, people[i].name) == 0) {
                    printf("%s, %d, %s\n", people[i].name, people[i].age, people[i].occupation);
                }
            }
            break;
        case 2: // Query by age range
            printf("Enter minimum age: ");
            int minAge;
            scanf("%d", &minAge);
            printf("Enter maximum age: ");
            int maxAge;
            scanf("%d", &maxAge);
            for (int i = 0; i < n; i++) {
                if (people[i].age >= minAge && people[i].age <= maxAge) {
                    printf("%s, %d, %s\n", people[i].name, people[i].age, people[i].occupation);
                }
            }
            break;
        case 3: // Query by occupation
            printf("Enter occupation to search for: ");
            char searchOccupation[50];
            scanf("%s", searchOccupation);
            for (int i = 0; i < n; i++) {
                if (strcmp(searchOccupation, people[i].occupation) == 0) {
                    printf("%s, %d, %s\n", people[i].name, people[i].age, people[i].occupation);
                }
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}