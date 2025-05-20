//Falcon-180B DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

int main() {
    Person *people = NULL;
    int num_people = 0;
    char input[MAX_SIZE];

    // Prompt user for number of people
    printf("How many people do you want to enter? ");
    fgets(input, MAX_SIZE, stdin);
    sscanf(input, "%d", &num_people);

    // Allocate memory for people array
    people = malloc(num_people * sizeof(Person));

    // Prompt user for each person's name and age
    for (int i = 0; i < num_people; i++) {
        printf("Enter person %d's name: ", i+1);
        fgets(input, MAX_SIZE, stdin);
        people[i].name = strdup(input);
        people[i].age = 0;

        while (people[i].age == 0) {
            printf("Invalid age for person %d. Please enter a valid age: ", i+1);
            fgets(input, MAX_SIZE, stdin);
            sscanf(input, "%d", &people[i].age);
        }
    }

    // Print out information about each person
    printf("\nPeople:\n");
    for (int i = 0; i < num_people; i++) {
        printf("Name: %s\nAge: %d\n", people[i].name, people[i].age);
    }

    // Free memory and exit program
    for (int i = 0; i < num_people; i++) {
        free(people[i].name);
    }
    free(people);
    return 0;
}