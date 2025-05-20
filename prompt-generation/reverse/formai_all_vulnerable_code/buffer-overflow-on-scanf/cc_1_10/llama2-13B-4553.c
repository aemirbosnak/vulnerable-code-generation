//LLAMA2-13B DATASET v1.0 Category: Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

struct person {
    char name[MAX_NAME_LENGTH];
    int age;
};

int main() {
    struct person person1, person2;
    char name1[MAX_NAME_LENGTH], name2[MAX_NAME_LENGTH];
    int age1, age2;

    // Initialize person1 and person2 with random names and ages
    srand(time(NULL));
    strcpy(person1.name, "Alice");
    person1.age = rand() % MAX_AGE + 1;
    strcpy(person2.name, "Bob");
    person2.age = rand() % MAX_AGE + 1;

    // Print the names and ages of person1 and person2
    printf("Person 1: %s, age %d\n", person1.name, person1.age);
    printf("Person 2: %s, age %d\n", person2.name, person2.age);

    // Ask the user for their name and age
    printf("Please enter your name: ");
    fgets(name1, MAX_NAME_LENGTH, stdin);
    printf("Please enter your age: ");
    scanf("%d", &age1);

    // Check if the user's name and age are valid
    if (age1 > 0 && strlen(name1) < MAX_NAME_LENGTH) {
        // Add the user's name and age to the list of people
        strcpy(person1.name, name1);
        person1.age = age1;
        printf("You have been added to the list of people\n");
    } else {
        printf("Invalid name or age, try again\n");
    }

    // Print the updated list of people
    printf("List of people: \n");
    printf("Person 1: %s, age %d\n", person1.name, person1.age);
    printf("Person 2: %s, age %d\n", person2.name, person2.age);

    return 0;
}