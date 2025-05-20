//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

int main() {
    // Declare variables to store user input
    char name[MAX_NAME_LEN];
    int age;

    // Print a welcome message
    printf("Welcome to the party! Please enter your name and age:\n");

    // Get the user's name and age
    printf("Enter your name (up to %d characters): ", MAX_NAME_LEN);
    fgets(name, MAX_NAME_LEN, stdin);
    printf("Enter your age: ");
    scanf("%d", &age);

    // Check for invalid input
    if (age < 0 || age > MAX_AGE) {
        printf("Error: Age must be between 0 and %d\n", MAX_AGE);
        return 1;
    }

    // Generate a random name for the user
    char *random_name = "Random User";
    int random_age = age + (rand() % 10) - 5;
    if (random_age < 0) {
        random_age = 0;
    }

    // Print the user's information
    printf("Welcome, %s! You are %d years old today.\n", name, age);

    // Print a fun message based on the user's age
    switch (random_age) {
        case 0:
            printf("Happy birthday!");
            break;
        case 1:
            printf("You're one year old today!");
            break;
        case 10:
            printf("You're now a big boy/girl!");
            break;
        default:
            printf("You're %d years old today!", random_age);
            break;
    }

    // Print a farewell message
    printf("It was nice meeting you! Goodbye!\n");

    return 0;
}