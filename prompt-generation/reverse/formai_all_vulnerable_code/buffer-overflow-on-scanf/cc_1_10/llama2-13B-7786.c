//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 256
#define MAX_AGE 120

// Function to validate user input
void validate_input(const char *name, int age) {
    if (name == NULL || strlen(name) > MAX_NAME_LENGTH) {
        fprintf(stderr, "Error: Name cannot be empty or exceed %d characters.\n", MAX_NAME_LENGTH);
        exit(1);
    }

    if (age < 0 || age > MAX_AGE) {
        fprintf(stderr, "Error: Age must be a positive integer less than or equal to %d.\n", MAX_AGE);
        exit(1);
    }
}

// Function to handle errors
void handle_error(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(2);
}

int main() {
    // Declare variables
    char name[MAX_NAME_LENGTH];
    int age;

    // Ask user for name and age
    printf("What is your name? ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    printf("How old are you? ");
    scanf("%d", &age);

    // Validate user input
    validate_input(name, age);

    // Do something if input is valid
    printf("Hello, %s! You are %d years old.\n", name, age);

    // Handle errors
    if (ferror(stdin)) {
        handle_error("Error reading input from stdin.");
    }

    return 0;
}