//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_ATTEMPTS 5

// Define a struct to hold the error message and the line number
typedef struct {
    char message[50];
    int line;
} error_t;

// Function to handle errors and print the message
void handle_error(error_t *error) {
    printf("Oopsie! %s\n", error->message);
    if (error->line != -1) {
        printf("Error on line %d\n", error->line);
    }
}

int main() {
    // Variables to store the user input
    char name[MAX_LENGTH];
    int age;

    // Ask the user for their name and age
    printf("What's your name? ");
    fgets(name, MAX_LENGTH, stdin);
    printf("How old are you? ");
    scanf("%d", &age);

    // Check if the name is too long
    if (strlen(name) > MAX_LENGTH) {
        error_t error = { "Name too long!", __LINE__ };
        handle_error(&error);
        return 1;
    }

    // Check if the age is negative
    if (age < 0) {
        error_t error = { "Age can't be negative!", __LINE__ };
        handle_error(&error);
        return 1;
    }

    // Print a success message
    printf("Hello, %s! You are %d years old.\n", name, age);

    return 0;
}