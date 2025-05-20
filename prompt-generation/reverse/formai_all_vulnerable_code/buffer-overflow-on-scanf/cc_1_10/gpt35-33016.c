//FormAI DATASET v1.0 Category: Data validation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to validate numeric input
int validateNumericInput(char input[]) {
    int i, len = strlen(input); // Get the length of input string
    for(i = 0; i < len; i++) {
        if(!isdigit(input[i])) { // Check if each character is a digit
            return 0; // Return false if any non-digit character is found
        }
    }
    return 1; // Return true if all characters are digits
}

// Function to validate alphabetic input
int validateAlphabeticInput(char input[]) {
    int i, len = strlen(input); // Get the length of input string
    for(i = 0; i < len; i++) {
        if(!isalpha(input[i])) { // Check if each character is an alphabet
            return 0; // Return false if any non-alphabetic character is found
        }
    }
    return 1; // Return true if all characters are alphabets
}

// Function to validate alphanumeric input
int validateAlphanumericInput(char input[]) {
    int i, len = strlen(input); // Get the length of input string
    for(i = 0; i < len; i++) {
        if(!isalnum(input[i])) { // Check if each character is alphanumeric
            return 0; // Return false if any non-alphanumeric character is found
        }
    }
    return 1; // Return true if all characters are alphanumeric
}

int main() {
    // Welcome message
    printf("Welcome to the Data Validation program!\n\n");

    char input[100];

    // Validate numeric input
    printf("Enter a numeric value: ");
    scanf("%s", input);
    if(validateNumericInput(input)) {
        printf("Valid input: %s\n", input);
    }
    else {
        printf("Invalid input: %s is not numeric!\n", input);
    }

    // Validate alphabetic input
    printf("Enter an alphabetic string: ");
    scanf("%s", input);
    if(validateAlphabeticInput(input)) {
        printf("Valid input: %s\n", input);
    }
    else {
        printf("Invalid input: %s contains non-alphabetic characters!\n", input);
    }

    // Validate alphanumeric input
    printf("Enter an alphanumeric string: ");
    scanf("%s", input);
    if(validateAlphanumericInput(input)) {
        printf("Valid input: %s\n", input);
    }
    else {
        printf("Invalid input: %s contains non-alphanumeric characters!\n", input);
    }

    return 0;
}