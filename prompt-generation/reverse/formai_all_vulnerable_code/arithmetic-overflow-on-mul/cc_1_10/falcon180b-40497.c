//Falcon-180B DATASET v1.0 Category: Error handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    int result = 0;

    // Prompt user to enter a string
    printf("Enter a string: ");

    // Read user input
    if (fgets(input, MAX_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error: failed to read input.\n");
        exit(EXIT_FAILURE);
    }

    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';

    // Reverse the string
    int length = strlen(input);
    for (int i = 0; i < length / 2; i++) {
        char temp = input[i];
        input[i] = input[length - i - 1];
        input[length - i - 1] = temp;
    }

    // Convert the string to an integer
    result = atoi(input);

    // Check if the input is a valid integer
    if (result == 0 && input[0]!= '0') {
        fprintf(stderr, "Error: input is not a valid integer.\n");
        exit(EXIT_FAILURE);
    }

    // Calculate the factorial of the input
    int factorial = 1;
    for (int i = 1; i <= result; i++) {
        factorial *= i;
    }

    // Print the result
    printf("The factorial of %d is %d.\n", result, factorial);

    return 0;
}