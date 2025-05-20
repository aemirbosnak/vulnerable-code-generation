//Falcon2-11B DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to handle errors
void handleError(char* message, int errorCode) {
    fprintf(stderr, "%s (error code: %d)\n", message, errorCode);
    exit(errorCode);
}

// Function to process input
int processInput(char* input) {
    int num1 = atoi(input);
    int num2 = atoi(input);

    // Handle error if input is not a number
    if (num1 == 0 || num2 == 0) {
        handleError("Input is not a number", 1);
        return 0;
    }

    // Perform addition
    int sum = num1 + num2;

    // Handle error if result is negative
    if (sum < 0) {
        handleError("Result is negative", 2);
        return 0;
    }

    // Print result
    printf("Result: %d\n", sum);

    return 1;
}

int main() {
    char input[100];

    // Read input from user
    printf("Enter two numbers (separated by space): ");
    fgets(input, sizeof(input), stdin);

    // Trim newline character from input
    char* token = strchr(input, '\n');
    if (token!= NULL) {
        *token = '\0';
    }

    // Process input
    int result = processInput(input);

    // Handle error if input is invalid
    if (!result) {
        handleError("Invalid input", 3);
        return 0;
    }

    return 0;
}