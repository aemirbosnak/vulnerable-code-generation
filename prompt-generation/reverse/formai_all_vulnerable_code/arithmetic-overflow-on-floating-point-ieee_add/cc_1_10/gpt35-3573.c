//FormAI DATASET v1.0 Category: Data validation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 20

int is_valid_number(char *input) {
    int decimal_point_count = 0;

    // Loop through each character in the input string
    for (int i = 0; i < strlen(input); i++) {

        // Check if the character is a digit or decimal point
        if (!isdigit(input[i]) && input[i] != '.') {
            return 0; // Invalid input
        }

        // Count the number of decimal points
        if (input[i] == '.') {
            decimal_point_count++;
        }

        // Check if there are more than one decimal points
        if (decimal_point_count > 1) {
            return 0; // Invalid input
        }
    }

    return 1; // Valid input
}

int main() {
    char input[MAX_INPUT_LENGTH];

    // Get the first number from the user
    printf("Enter the first number: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Validate the input
    while (!is_valid_number(input)) {
        printf("Invalid input, enter a valid number: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
    }

    // Convert the input to a float
    float num1 = atof(input);

    // Get the second number from the user
    printf("Enter the second number: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Validate the input
    while (!is_valid_number(input)) {
        printf("Invalid input, enter a valid number: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
    }

    // Convert the input to a float
    float num2 = atof(input);

    // Perform the calculation and print the result
    printf("%f + %f = %f\n", num1, num2, num1 + num2);

    return 0;
}