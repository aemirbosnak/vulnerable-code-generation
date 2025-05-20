//FormAI DATASET v1.0 Category: Binary Converter ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BINARY_DIGITS 1000

/**
 * Function to convert decimal to binary
 *
 * @param decimalNumber The decimal number to be converted
 * @param binaryString The character array to save the binary string
 */
void decimalToBinary(int decimalNumber, char* binaryString) {
    int binaryDigits[MAX_BINARY_DIGITS];
    int index = 0;

    while (decimalNumber > 0) {
        binaryDigits[index] = decimalNumber % 2;
        decimalNumber /= 2;
        index++;
    }

    // Copying binary digits to char array in reverse order
    int binaryStringIndex = 0;
    for (int i = index - 1; i >= 0; i--) {
        binaryString[binaryStringIndex] = binaryDigits[i] + '0';
        binaryStringIndex++;
    }
    binaryString[binaryStringIndex] = '\0';
}

/**
 * Function to convert binary to decimal
 *
 * @param binaryString The character array of the binary string
 * @returns the decimal value of the binary string
 */
int binaryToDecimal(char* binaryString) {
    int stringLength = strlen(binaryString);
    int decimalNumber = 0;

    for (int i = 0; i < stringLength; i++) {
        if (binaryString[i] == '1') {
            decimalNumber += 1 << (stringLength - i - 1);
        }
    }
    return decimalNumber;
}

/**
 * Function to validate a binary string
 *
 * @param binaryString The character array of the binary string
 * @returns true if the binary string is valid, false otherwise
 */
bool isBinaryValid(char* binaryString) {
    int stringLength = strlen(binaryString);

    for (int i = 0; i < stringLength; i++) {
        if (binaryString[i] != '0' && binaryString[i] != '1') {
            return false;
        }
    }
    return true;
}

/**
 * Main function to run the binary converter program
 */
int main() {
    int choice;
    printf("Welcome to Binary Converter\n");

    do {
        printf("\nPlease select an option below:\n");
        printf("1. Decimal to Binary Converter\n");
        printf("2. Binary to Decimal Converter\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int decimalNumber;
                char binaryString[MAX_BINARY_DIGITS];

                printf("\nEnter decimal number to convert to binary: ");
                scanf("%d", &decimalNumber);

                decimalToBinary(decimalNumber, binaryString);
                printf("Binary equivalent: %s\n", binaryString);
                break;
            }
            case 2: {
                char binaryString[MAX_BINARY_DIGITS];

                printf("\nEnter binary number to convert to decimal: ");
                scanf("%s", binaryString);

                if (isBinaryValid(binaryString)) {
                    int decimalNumber = binaryToDecimal(binaryString);
                    printf("Decimal equivalent: %d\n", decimalNumber);
                }
                else {
                    printf("Invalid binary string. Please try again.\n");
                }

                break;
            }
            case 3: {
                printf("\nExiting binary converter program...\n");
                break;
            }
            default: {
                printf("\nInvalid choice. Please try again.\n");
                break;
            }
        }
    } while (choice != 3);

    return 0;
}