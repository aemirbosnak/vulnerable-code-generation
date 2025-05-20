//LLAMA2-13B DATASET v1.0 Category: Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

struct person {
    char name[MAX_NAME_LENGTH];
    int age;
};

int main() {
    struct person person1, person2, person3;
    int choice;

    // Initialize person1's name and age
    strcpy(person1.name, "John");
    person1.age = 25;

    // Initialize person2's name and age
    strcpy(person2.name, "Jane");
    person2.age = 30;

    // Initialize person3's name and age
    strcpy(person3.name, "Bob");
    person3.age = 35;

    // Print a menu to ask the user to choose an action
    printf("Welcome to the Person Manager!\n");
    printf("Choose an action:\n");
    printf("1. Print information about person 1\n");
    printf("2. Print information about person 2\n");
    printf("3. Print information about person 3\n");
    printf("4. Add a new person\n");
    printf("5. Remove a person\n");
    printf("6. Exit\n");

    // Get the user's choice
    scanf("%d", &choice);

    // Handle the user's choice
    switch (choice) {
        case 1:
            printf("Person 1's name is %s and their age is %d\n", person1.name, person1.age);
            break;
        case 2:
            printf("Person 2's name is %s and their age is %d\n", person2.name, person2.age);
            break;
        case 3:
            printf("Person 3's name is %s and their age is %d\n", person3.name, person3.age);
            break;
        case 4:
            // Prompt the user for the new person's name and age
            printf("Enter the new person's name: ");
            fgets(person1.name, MAX_NAME_LENGTH, stdin);
            printf("Enter the new person's age: ");
            scanf("%d", &person1.age);
            printf("New person added: %s (%d)\n", person1.name, person1.age);
            break;
        case 5:
            // Prompt the user to remove a person
            printf("Enter the name of the person to remove: ");
            fgets(person2.name, MAX_NAME_LENGTH, stdin);
            printf("Are you sure you want to remove %s? (y/n)\n", person2.name);
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'y') {
                printf("Person %s removed\n", person2.name);
                person2.name[0] = '\0';
                person2.age = 0;
            }
            break;
        case 6:
            printf("Goodbye!\n");
            return 0;
    }

    return 0;
}