//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 256
#define MAX_AGE 100

int main() {
    // Define variables to store user input
    char name[MAX_NAME_LEN];
    int age;

    // Print a friendly message to the user
    printf("Welcome to the party! Please enter your name and age:\n");

    // Get the user's name and age
    fgets(name, MAX_NAME_LEN, stdin);
    if (sscanf(name, "%d", &age) != 1) {
        // Handle invalid input
        printf("Invalid age input. Please enter a valid age.\n");
        return 1;
    }

    // Check if the age is valid
    if (age < 0 || age > MAX_AGE) {
        // Handle invalid age input
        printf("Invalid age input. The maximum age is %d.\n", MAX_AGE);
        return 1;
    }

    // Print a success message
    printf("Great, %s! You're eligible to attend the party.\n", name);

    // Simulate a party atmosphere
    printf("The clock strikes midnight, and the party begins! \n");
    printf("You're surrounded by confetti and balloons, and the music is loud and joyful.\n");

    // Generate a random error message
    if (rand() % 2 == 0) {
        // Handle a random error
        printf("Oh no! The party just encountered an unexpected error. Please try again later.\n");
        return 1;
    }

    // Print a final success message
    printf("Congratulations, %s! You've successfully attended the party!\n", name);

    return 0;
}