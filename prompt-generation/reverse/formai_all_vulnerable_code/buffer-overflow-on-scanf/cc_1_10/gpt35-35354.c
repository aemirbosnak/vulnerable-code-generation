//FormAI DATASET v1.0 Category: Data validation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program demonstrates a simple data validation routine using C.
 * It checks whether the provided input string is a valid floating point
 * number.
 */

// Function to validate the input string
int validateInput(char *inputString) {

    int decimalCount = 0;
    int i = 0;
    int stringLength = strlen(inputString);

    // Check if the first character is a sign character
    if (inputString[0] == '+' || inputString[0] == '-') {
        i++;
    }

    // Iterate through the remaining characters of the input string
    while (i < stringLength) {
        // Count the number of decimal points
        if (inputString[i] == '.') {
            decimalCount++;
            if (decimalCount > 1) {
                // If there is more than one decimal point, the input is invalid
                return 0;
            }
        }
        else if (inputString[i] < '0' || inputString[i] > '9') {
            // If the character is not a decimal point or a digit, the input is invalid
            return 0;
        }

        i++;
    }

    // Input is valid
    return 1;
}

int main() {
    char inputString[50];
    int validInput;

    // Get input from user
    printf("Please enter a floating point number: ");
    scanf("%s", inputString);

    // Validate the input
    validInput = validateInput(inputString);

    // Print the validation result
    if (validInput) {
        printf("Input is valid.\n");
    }
    else {
        printf("Input is invalid.\n");
    }

    return 0;
}