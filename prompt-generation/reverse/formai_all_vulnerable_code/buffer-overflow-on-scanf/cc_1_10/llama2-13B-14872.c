//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

int main() {
    // Declare variables to store user input
    char name[MAX_NAME_LENGTH];
    int age;

    // Print welcome message
    printf("Welcome to the party! Please enter your name and age:\n");

    // Get user input
    printf("Enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    printf("Enter your age: ");
    scanf("%d", &age);

    // Check if name is valid
    if (strlen(name) > MAX_NAME_LENGTH) {
        printf("Error: Name too long! Please enter a name with at most %d characters.\n", MAX_NAME_LENGTH);
        return 1;
    }

    // Check if age is valid
    if (age < 0 || age > MAX_AGE) {
        printf("Error: Age must be a positive integer between 0 and %d.\n", MAX_AGE);
        return 2;
    }

    // Print success message
    printf("Great, %s is coming to the party! The current age of the party is: %d\n", name, age);

    // Generate a random number between 1 and 100 (inclusive)
    int random_number = rand() % 100 + 1;

    // Print the result
    if (random_number > age) {
        printf("You're too young for this party! The minimum age is %d\n", age);
        return 3;
    } else if (random_number < age) {
        printf("You're too old for this party! The maximum age is %d\n", age);
        return 4;
    } else {
        printf("You're just the right age for this party! Congratulations!\n");
    }

    return 0;
}