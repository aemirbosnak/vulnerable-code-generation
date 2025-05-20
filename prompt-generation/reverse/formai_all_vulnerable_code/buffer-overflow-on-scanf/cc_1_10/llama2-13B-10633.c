//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define MAGIC_NUMBER 42

// Function to handle errors gracefully
void handle_error(const char *message) {
    printf("😢 %s\n", message);
    // Free any memory allocated
    free(message);
    // Exit the program with a non-zero status
    exit(EXIT_FAILURE);
}

int main() {
    // Variables to store user input
    char name[MAX_LENGTH];
    int age;
    float height;

    // Get the user's name
    printf("What is your name? ");
    fgets(name, MAX_LENGTH, stdin);

    // Get the user's age
    printf("How old are you? ");
    scanf("%d", &age);

    // Get the user's height
    printf("How tall are you? ");
    scanf("%f", &height);

    // Check if the user's name is valid
    if (strlen(name) > MAX_LENGTH) {
        handle_error("Name too long!");
    }

    // Check if the user's age is valid
    if (age < 0 || age > 100) {
        handle_error("Age must be between 0 and 100!");
    }

    // Check if the user's height is valid
    if (height < 0 || height > 300) {
        handle_error("Height must be between 0 and 300!");
    }

    // Print a success message
    printf("Hello, %s! You are %d years old and %f meters tall.\n", name, age, height);

    // Print a random message
    printf("🐰 %s %d\n", "You have been randomly selected to receive a prize!", MAGIC_NUMBER);

    return 0;
}