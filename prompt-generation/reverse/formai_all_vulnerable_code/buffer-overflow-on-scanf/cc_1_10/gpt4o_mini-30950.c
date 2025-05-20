//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal number to hexadecimal
void decimalToHexadecimal(int decimalNumber, char *hexadecimalNumber) {
    // Define a string containing all hexadecimal digits
    const char *hexDigits = "0123456789ABCDEF";
    int remainder, i = 0;

    // Handle the case for zero explicitly
    if (decimalNumber == 0) {
        hexadecimalNumber[i++] = '0';
        hexadecimalNumber[i] = '\0';
        return;
    }

    // Iterate until the decimal number is greater than 0
    while (decimalNumber != 0) {
        remainder = decimalNumber % 16; // Find remainder for hex representation
        hexadecimalNumber[i++] = hexDigits[remainder]; // Map the remainder to hex digit
        decimalNumber = decimalNumber / 16; // Reduce decimal number
    }

    // Append null terminator to end the string
    hexadecimalNumber[i] = '\0';

    // Reverse the hexadecimal string since we processed it backwards
    for (int j = 0; j < i / 2; j++) {
        char temp = hexadecimalNumber[j];
        hexadecimalNumber[j] = hexadecimalNumber[i - j - 1];
        hexadecimalNumber[i - j - 1] = temp;
    }
}

// Function to convert hexadecimal number to decimal
int hexadecimalToDecimal(const char *hexadecimalNumber) {
    int decimalNumber = 0;
    int base = 1; // Initialize base value to 1 (16^0)
    int length = 0;

    // Find the length of the hexadecimal string
    while (hexadecimalNumber[length] != '\0') {
        length++;
    }

    // Convert hex value to decimal
    for (int i = length - 1; i >= 0; i--) {
        char digit = hexadecimalNumber[i];
        if (digit >= '0' && digit <= '9') {
            decimalNumber += (digit - '0') * base; // Determine decimal value from numeric character
        } else if (digit >= 'A' && digit <= 'F') {
            decimalNumber += (10 + digit - 'A') * base; // Determine value for A-F
        }
        base *= 16; // Increase base value
    }

    return decimalNumber; // Return the calculated decimal value
}

int main() {
    int choice, number;
    char hexadecimalNumber[20]; // Array to hold hexadecimal representation

    do {
        printf("Mathematical Hexadecimal Converter\n");
        printf("1. Decimal to Hexadecimal\n");
        printf("2. Hexadecimal to Decimal\n");
        printf("3. Exit\n");
        printf("Select an option (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Decimal to Hexadecimal
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                decimalToHexadecimal(number, hexadecimalNumber);
                printf("Hexadecimal representation: %s\n", hexadecimalNumber);
                break;

            case 2: // Hexadecimal to Decimal
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexadecimalNumber);
                number = hexadecimalToDecimal(hexadecimalNumber);
                printf("Decimal representation: %d\n", number);
                break;

            case 3: // Exit
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please select again.\n");
        }

        printf("\n"); // Print a newline for better readability
    } while (choice != 3);

    // Successful termination
    return 0;
}