//Falcon-180B DATASET v1.0 Category: Error handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a function to handle errors gracefully
void handle_error(const char* message) {
    printf("Error: %s\n", message);
    exit(1);
}

// Define a function to prompt the user for an integer input
int prompt_int(const char* prompt) {
    int value;
    printf("%s: ", prompt);
    if (scanf("%d", &value)!= 1) {
        handle_error("Invalid input");
    }
    return value;
}

// Define a function to prompt the user for a string input
char* prompt_string(const char* prompt) {
    char* value = NULL;
    printf("%s: ", prompt);
    if (fgets(value, 100, stdin) == NULL) {
        handle_error("Input too long");
    }
    return value;
}

// Define a function to calculate the factorial of a number
int factorial(int n) {
    if (n < 0) {
        handle_error("Negative input");
    }
    if (n == 0) {
        return 1;
    }
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Define the main function
int main() {
    int n;
    char* input;

    // Prompt the user for a number
    n = prompt_int("Enter a number: ");

    // Calculate the factorial of the number
    int result = factorial(n);

    // Prompt the user for a string
    printf("Enter a string: ");
    input = prompt_string("");

    // Print the result
    printf("The factorial of %d is %d\n", n, result);

    // Print the input string
    printf("You entered: %s\n", input);

    // Free the memory used by the input string
    free(input);

    return 0;
}