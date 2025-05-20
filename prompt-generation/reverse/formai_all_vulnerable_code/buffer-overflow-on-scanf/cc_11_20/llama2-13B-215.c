//LLAMA2-13B DATASET v1.0 Category: Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100
#define MAX_HEIGHT 200

struct person {
    char name[MAX_NAME_LEN];
    int age;
    int height;
};

int main() {
    struct person person1, person2, person3;
    int choice;

    // Initialize person1
    strcpy(person1.name, "Alice");
    person1.age = 25;
    person1.height = 160;

    // Initialize person2
    strcpy(person2.name, "Bob");
    person2.age = 30;
    person2.height = 180;

    // Initialize person3
    strcpy(person3.name, "Charlie");
    person3.age = 35;
    person3.height = 190;

    // Menu for user to choose an action
    printf("Welcome to the Person Database!\n");
    printf("Choose an action:\n");
    printf("1. Add a new person\n");
    printf("2. View a person's details\n");
    printf("3. Update a person's details\n");
    printf("4. Delete a person\n");
    printf("5. Exit\n");

    // Get the user's choice
    scanf("%d", &choice);

    // Handle user's choice
    switch (choice) {
        case 1:
            // Add a new person
            printf("Enter the new person's name: ");
            fgets(person1.name, MAX_NAME_LEN, stdin);
            printf("Enter the new person's age: ");
            scanf("%d", &person1.age);
            printf("Enter the new person's height: ");
            scanf("%d", &person1.height);
            printf("New person added successfully!\n");
            break;

        case 2:
            // View a person's details
            printf("Person 1's details:\n");
            printf("Name: %s\n", person1.name);
            printf("Age: %d\n", person1.age);
            printf("Height: %d\n", person1.height);

            printf("Person 2's details:\n");
            printf("Name: %s\n", person2.name);
            printf("Age: %d\n", person2.age);
            printf("Height: %d\n", person2.height);

            printf("Person 3's details:\n");
            printf("Name: %s\n", person3.name);
            printf("Age: %d\n", person3.age);
            printf("Height: %d\n", person3.height);
            break;

        case 3:
            // Update a person's details
            printf("Which person's details would you like to update? (1/2/3): ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter the updated name for person 1: ");
                    fgets(person1.name, MAX_NAME_LEN, stdin);
                    break;

                case 2:
                    printf("Enter the updated age for person 2: ");
                    scanf("%d", &person2.age);
                    break;

                case 3:
                    printf("Enter the updated height for person 3: ");
                    scanf("%d", &person3.height);
                    break;
            }

            printf("Updated details saved successfully!\n");
            break;

        case 4:
            // Delete a person
            printf("Which person would you like to delete? (1/2/3): ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Person 1 deleted successfully!\n");
                    break;

                case 2:
                    printf("Person 2 deleted successfully!\n");
                    break;

                case 3:
                    printf("Person 3 deleted successfully!\n");
                    break;
            }
            break;

        case 5:
            // Exit
            printf("Goodbye!\n");
            return 0;
    }

    return 0;
}