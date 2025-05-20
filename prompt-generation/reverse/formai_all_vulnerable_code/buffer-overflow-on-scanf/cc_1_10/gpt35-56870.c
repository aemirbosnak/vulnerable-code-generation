//FormAI DATASET v1.0 Category: Sorting ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Struct definition for person
typedef struct Person {
    char name[50];
    int age;
} Person;

// Function to swap two Person structs
void swapPersons(Person *person1, Person *person2) {
    Person temp = *person1;
    *person1 = *person2;
    *person2 = temp;
}

// Function to sort an array of Person structs in ascending order by age using bubble sort
void ageSort(Person *people, int numOfPeople) {
    int i, j;
    for (i = 0; i < numOfPeople-1; i++) {
        for (j = 0; j < numOfPeople-i-1; j++) {
            if (people[j].age > people[j+1].age) {
                swapPersons(&people[j], &people[j+1]);
            }
        }
    }
}

int main() {
    int numOfPeople = 5;
    Person *people = (Person *)malloc(numOfPeople * sizeof(Person)); // Dynamic allocation for array of Person structs
    int i;

    // Get user input for name and age of each person
    for (i = 0; i < numOfPeople; i++) {
        printf("Enter the name of person %d: ", i+1);
        scanf("%s", people[i].name);
        printf("Enter the age of person %d: ", i+1);
        scanf("%d", &people[i].age);
    }

    // Sort the array of Person structs in ascending order by age
    ageSort(people, numOfPeople);

    // Print the sorted array of Person structs
    printf("\nSorted by age (ascending):\n");
    for (i = 0; i < numOfPeople; i++) {
        printf("%s (%d)\n", people[i].name, people[i].age);
    }

    free(people); // Free memory allocated for array of Person structs

    return 0;
}