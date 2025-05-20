//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 100

typedef struct {
    char name[MAX_STR_LEN];
    int age;
    int weight;
    int height;
} Person;

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Weight: %d\n", person->weight);
    printf("Height: %d\n", person->height);
}

int main() {
    Person *people = NULL;
    int num_people = 0;

    printf("Welcome to the Fitness Tracker!\n");

    // Prompt user for number of people to track
    printf("How many people would you like to track? ");
    scanf("%d", &num_people);

    // Allocate memory for people array
    people = (Person*) malloc(sizeof(Person) * num_people);

    if (people == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Prompt user for each person's information
    for (int i = 0; i < num_people; i++) {
        printf("Enter information for person #%d:\n", i+1);
        printf("Name: ");
        scanf("%s", people[i].name);

        printf("Age: ");
        scanf("%d", &people[i].age);

        printf("Weight: ");
        scanf("%d", &people[i].weight);

        printf("Height: ");
        scanf("%d", &people[i].height);
    }

    // Calculate BMI for each person
    for (int i = 0; i < num_people; i++) {
        double bmi = people[i].weight / (people[i].height * people[i].height);
        printf("BMI for %s: %.2f\n", people[i].name, bmi);
    }

    // Free memory
    free(people);

    return 0;
}