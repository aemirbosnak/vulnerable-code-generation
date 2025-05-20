//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Custom error handling function
void handle_error(int error_code, const char *function_name) {
    const char *error_message = strerror(error_code);
    fprintf(stderr, "Error in function '%s': %s (%d)\n", function_name, error_message, error_code);
    exit(1);
}

// Function that may generate errors
int get_input(int *number) {
    char input[10];
    printf("Enter a number: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        handle_error(errno, "fgets");
        return -1;
    }

    // Check for input errors
    if (strlen(input) == 0) {
        fprintf(stderr, "Error: Input cannot be empty.\n");
        return -1;
    }

    // Convert the input to an integer
    *number = atoi(input);
    if (*number == 0 && strcmp(input, "0") != 0) {
        fprintf(stderr, "Error: '%s' is not a valid integer.\n", input);
        return -1;
    }

    return 0;
}

int main() {
    int number;

    // Get input from the user
    if (get_input(&number) != 0) {
        return 1;
    }

    // Perform some calculations using the input
    int result = number * number;

    // Print the result
    printf("The square of %d is %d\n", number, result);

    return 0;
}