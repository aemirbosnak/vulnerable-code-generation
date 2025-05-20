//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME_LENGTH 256
#define MAX_AGE 120

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    int age;

    do {
        printf("Welcome to the party! Please enter your name: ");
        fgets(name, MAX_NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = 0; // ignore the newline character

        printf("Please enter your age: ");
        scanf("%d", &age);

        // check for invalid input
        if (age < 0 || age > MAX_AGE) {
            printf("Invalid age. Please enter a valid age between 0 and %d.\n", MAX_AGE);
            continue;
        }

        // check if the name is too long
        if (strlen(name) > MAX_NAME_LENGTH) {
            printf("Invalid name. Please enter a name with a maximum of %d characters.\n", MAX_NAME_LENGTH);
            continue;
        }

        choice = getchar(); // read a character from the user

        switch (choice) {
            case '1':
                printf("Great to have you here, %s! Enjoy the party!\n", name);
                break;
            case '2':
                printf("Sorry, we cannot allow that name. Please enter a valid name.\n");
                break;
            case '3':
                printf("Invalid age. Please enter a valid age between 0 and %d.\n", MAX_AGE);
                break;
            default:
                printf("Invalid input. Please enter a valid choice (1, 2, or 3).\n");
                break;
        }
    } while (choice != '4'); // loop until the user enters the correct choice

    return 0;
}