//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 20

// Function to convert a decimal number to hexadecimal
void decimalToHexadecimal(int num, char *hex) {
    int i = 0;
    if (num == 0) {
        strcat(hex, "0");
        return;
    }
    while (num != 0) {
        int remainder = num % 16;
        if (remainder < 10) {
            hex[i++] = 48 + remainder; // ASCII for '0'-'9'
        } else {
            hex[i++] = 55 + remainder; // ASCII for 'A'-'F'
        }
        num /= 16;
    }
    hex[i] = '\0';

    // Reverse the string
    for (int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }
}

// Function to validate if the input is a valid decimal number
int isValidInput(char *input) {
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        if (input[i] < '0' || input[i] > '9') {
            return 0; // Invalid input
        }
    }
    return 1; // Valid input
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char hexOutput[MAX_INPUT_LENGTH];
    int decimalNumber;

    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    printf("Please enter a non-negative decimal number: ");
    
    while (1) {
        fgets(input, sizeof(input), stdin);
        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        if (isValidInput(input)) {
            decimalNumber = atoi(input);
            if (decimalNumber >= 0) {
                // Initializing hexOutput
                memset(hexOutput, 0, sizeof(hexOutput));
                decimalToHexadecimal(decimalNumber, hexOutput);
                printf("Decimal: %d | Hexadecimal: %s\n", decimalNumber, hexOutput);
                break; // Exit loop after valid conversion
            } else {
                printf("Please enter a non-negative decimal number: ");
            }
        } else {
            printf("Invalid input! Please enter a valid non-negative decimal number: ");
        }
    }

    // Extra functionality: Convert multiple numbers
    char anotherConversion;
    do {
        printf("Do you want to convert another number? (y/n): ");
        scanf(" %c", &anotherConversion);
        while(getchar() != '\n'); // clear buffer

        if (anotherConversion == 'y' || anotherConversion == 'Y') {
            printf("Please enter a non-negative decimal number: ");
            while (1) {
                fgets(input, sizeof(input), stdin);
                // Remove newline character
                input[strcspn(input, "\n")] = 0;

                if (isValidInput(input)) {
                    decimalNumber = atoi(input);
                    if (decimalNumber >= 0) {
                        // Initializing hexOutput
                        memset(hexOutput, 0, sizeof(hexOutput));
                        decimalToHexadecimal(decimalNumber, hexOutput);
                        printf("Decimal: %d | Hexadecimal: %s\n", decimalNumber, hexOutput);
                        break; // Exit loop after valid conversion
                    } else {
                        printf("Please enter a non-negative decimal number: ");
                    }
                } else {
                    printf("Invalid input! Please enter a valid non-negative decimal number: ");
                }
            }
        } else if (anotherConversion != 'n' && anotherConversion != 'N') {
            printf("Invalid choice! Please enter 'y' for yes or 'n' for no.\n");
        }
    } while (anotherConversion == 'y' || anotherConversion == 'Y');

    printf("Thank you for using the converter! Goodbye!\n");
    return 0;
}