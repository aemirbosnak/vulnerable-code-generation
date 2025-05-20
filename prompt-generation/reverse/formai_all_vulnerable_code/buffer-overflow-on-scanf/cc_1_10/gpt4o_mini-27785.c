//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void decimalToHexadecimal(int decimal, char hexResult[]);
void displayIntro();
void displayInstructions();
void convertAndDisplay(int decimal);

// Constants for conversions
#define MAX_HEX_LENGTH 20

int main() {
    int decimalNumber;
    char hexRepresentation[MAX_HEX_LENGTH];

    // Display Introduction
    displayIntro();
    displayInstructions();

    // User input loop
    while (1) {
        printf("\nEnter a decimal number (or type -1 to exit): ");
        scanf("%d", &decimalNumber);

        if (decimalNumber == -1) {
            printf("Exiting the Hexadecimal Converter. Goodbye!\n");
            break;
        } else if (decimalNumber < 0) {
            printf("Please enter a non-negative integer.\n");
            continue;
        }

        // Convert to Hexadecimal
        decimalToHexadecimal(decimalNumber, hexRepresentation);
        convertAndDisplay(decimalNumber);
        printf("Hexadecimal Representation: %s\n", hexRepresentation);
    }
    return 0;
}

// Function to display the introduction
void displayIntro() {
    printf("--------------------------------------------------\n");
    printf("           Welcome to the Hexadecimal Converter\n");
    printf("--------------------------------------------------\n");
}

// Function to display instructions
void displayInstructions() {
    printf("Instructions:\n");
    printf("1. Input a non-negative decimal integer.\n");
    printf("2. The program will convert it to its hexadecimal form.\n");
    printf("3. Type -1 to exit the program.\n");
    printf("--------------------------------------------------\n");
}

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal, char hexResult[]) {
    int remainder;
    int index = 0;
    char temp[MAX_HEX_LENGTH];

    // Handle the zero case
    if (decimal == 0) {
        strcpy(hexResult, "0");
        return;
    }

    // Converting to hexadecimal
    while (decimal > 0) {
        remainder = decimal % 16;

        // Convert integer remainder to hexadecimal character
        if (remainder < 10) {
            temp[index++] = remainder + '0'; // Adding char '0' for numbers 0-9
        } else {
            temp[index++] = (remainder - 10) + 'A'; // Adding char 'A' for 10-15
        }
        decimal /= 16; // Move to the next higher digit
    }

    // Reverse the array to get the final hexadecimal result
    for (int i = 0; i < index; i++) {
        hexResult[i] = temp[index - 1 - i];
    }
    hexResult[index] = '\0'; // Null-terminate the string
}

// Function to display conversion result
void convertAndDisplay(int decimal) {
    printf("Converting %d to hexadecimal...\n", decimal);
}