//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 20

// Function prototypes
void displayMenu();
int getInput();
void convertToHex(int decimal, char *hexBuffer);
void printResult(int decimal, const char *hex);

// Main function
int main() {
    int decimalNumber;
    char hexBuffer[BUFFER_SIZE];

    while (1) {
        displayMenu();
        decimalNumber = getInput();

        // Exit condition
        if (decimalNumber < 0) {
            printf("Exiting the program. Thank you!\n");
            break;
        }

        convertToHex(decimalNumber, hexBuffer);
        printResult(decimalNumber, hexBuffer);
    }

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n=== Decimal to Hexadecimal Converter ===\n");
    printf("Enter a decimal number to convert (negative to exit): ");
}

// Function to get user input
int getInput() {
    int input;
    if (scanf("%d", &input) != 1) {
        while(getchar() != '\n'); // clear invalid input
        return 0; // return 0 on invalid input
    }
    return input;
}

// Function to convert decimal to hexadecimal
void convertToHex(int decimal, char *hexBuffer) {
    if (decimal == 0) {
        sprintf(hexBuffer, "0");
        return;
    }

    int index = 0;
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10)
            hexBuffer[index++] = '0' + remainder;
        else
            hexBuffer[index++] = 'A' + (remainder - 10);
        decimal /= 16;
    }

    // Add null terminator for the string
    hexBuffer[index] = '\0';

    // Reverse the string for correct order
    for (int i = 0; i < index / 2; i++) {
        char temp = hexBuffer[i];
        hexBuffer[i] = hexBuffer[index - i - 1];
        hexBuffer[index - i - 1] = temp;
    }
}

// Function to print the conversion result
void printResult(int decimal, const char *hex) {
    printf("Decimal: %d => Hexadecimal: %s\n", decimal, hex);
}