//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <float.h>

#define MAX_LINE_LENGTH 1024

int main(void) {
    char input[MAX_LINE_LENGTH];
    int integer_input;
    float float_input;
    double double_input;

    // Get the input from the user.
    printf("Enter a string: ");
    if (fgets(input, MAX_LINE_LENGTH, stdin) == NULL) {
        perror("fgets");
        return EXIT_FAILURE;
    }

    // Validate the input.
    if (strlen(input) == 0) {
        fprintf(stderr, "Error: Empty string.\n");
        return EXIT_FAILURE;
    }
    if (input[strlen(input) - 1] != '\n') {
        fprintf(stderr, "Error: Input too long.\n");
        return EXIT_FAILURE;
    }

    // Convert the input to an integer.
    if (sscanf(input, "%d", &integer_input) != 1) {
        fprintf(stderr, "Error: Invalid integer.\n");
        return EXIT_FAILURE;
    }

    // Validate the integer.
    if (integer_input < INT_MIN || integer_input > INT_MAX) {
        fprintf(stderr, "Error: Integer out of range.\n");
        return EXIT_FAILURE;
    }

    // Convert the input to a float.
    if (sscanf(input, "%f", &float_input) != 1) {
        fprintf(stderr, "Error: Invalid float.\n");
        return EXIT_FAILURE;
    }

    // Validate the float.
    if (float_input < FLT_MIN || float_input > FLT_MAX) {
        fprintf(stderr, "Error: Float out of range.\n");
        return EXIT_FAILURE;
    }

    // Convert the input to a double.
    if (sscanf(input, "%lf", &double_input) != 1) {
        fprintf(stderr, "Error: Invalid double.\n");
        return EXIT_FAILURE;
    }

    // Validate the double.
    if (double_input < DBL_MIN || double_input > DBL_MAX) {
        fprintf(stderr, "Error: Double out of range.\n");
        return EXIT_FAILURE;
    }

    // Print the results.
    printf("String: %s\n", input);
    printf("Integer: %d\n", integer_input);
    printf("Float: %f\n", float_input);
    printf("Double: %lf\n", double_input);

    return EXIT_SUCCESS;
}