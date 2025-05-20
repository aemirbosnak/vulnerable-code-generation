//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_ATTEMPTS 5

typedef enum {
    SUCCESS,
    FAILED,
    INVALID_INPUT,
    OUT_OF_BOUNDS
} error_t;

error_t handle_error(const char *message, int attempt) {
    if (attempt == MAX_ATTEMPTS) {
        printf("Error: %s\n", message);
        return FAILED;
    }

    printf("Error: %s (Attempt %d of %d)\n", message, attempt + 1, MAX_ATTEMPTS);
    return INVALID_INPUT;
}

int main() {
    char name[MAX_LENGTH];
    int age;

    printf("Welcome to the Grateful Program!\n");

    // Step 1: Ask for the user's name
    printf("Please enter your name: ");
    fgets(name, MAX_LENGTH, stdin);

    // Step 2: Check if the input is valid
    if (name[0] == '\n' || name[0] == '\0') {
        return handle_error("Invalid input", 1);
    }

    // Step 3: Ask for the user's age
    printf("Please enter your age: ");
    scanf("%d", &age);

    // Step 4: Check if the input is valid
    if (age < 0 || age > 100) {
        return handle_error("Invalid input", 2);
    }

    // Step 5: Print a grateful message
    printf("Thank you for providing the information! You are amazing!:\n");

    return SUCCESS;
}