//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// Function declarations
void getInput(char *input);
int isValidDecimal(const char *input);
void convertDecimalToHex(int decimal, char *hexBuffer);
void printHexadecimal(const char *hex);
void handleConversion();

int main() {
    char choice;

    do {
        handleConversion();
        printf("Do you want to convert another number? (y/n): ");
        scanf(" %c", &choice);
        while (getchar() != '\n'); // Clear the input buffer
    } while (tolower(choice) == 'y');

    printf("Thank you for using the Decimal to Hexadecimal Converter!\n");
    return 0;
}

// Function to get user input
void getInput(char *input) {
    printf("Enter a decimal number: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character
}

// Function to validate decimal number
int isValidDecimal(const char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            return 0; // Invalid input if any character is not a digit
        }
    }
    return 1; // Valid input
}

// Function to convert decimal to hexadecimal
void convertDecimalToHex(int decimal, char *hexBuffer) {
    sprintf(hexBuffer, "%X", decimal); // Convert and store in hexBuffer
}

// Function to print hexadecimal representation
void printHexadecimal(const char *hex) {
    printf("The hexadecimal representation is: %s\n", hex);
}

// Function to handle conversion logic
void handleConversion() {
    char input[MAX_INPUT_LENGTH];
    int decimalValue;
    char hexBuffer[MAX_INPUT_LENGTH];

    getInput(input);

    // Validate the input
    if (isValidDecimal(input)) {
        decimalValue = atoi(input);
        convertDecimalToHex(decimalValue, hexBuffer);
        printHexadecimal(hexBuffer);
    } else {
        printf("Invalid input! Please enter a valid decimal number.\n");
    }
}