//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
void decimalToBinary(int n) {
    if (n > 1) {
        // Recursive call for higher digits
        decimalToBinary(n >> 1);
    }
    // Output the last digit
    printf("%d", n & 1);
}

// Function to convert binary to decimal
int binaryToDecimal(const char *binaryStr) {
    int decimal = 0;
    while (*binaryStr) {
        decimal = (decimal << 1) + (*binaryStr - '0'); // Shift and add the binary digit
        binaryStr++;
    }
    return decimal;
}

// Function to get user input until a valid decimal number is provided
int getValidDecimalInput() {
    int number;
    while (1) {
        printf("Enter a decimal number (0 - 255): ");
        if (scanf("%d", &number) != 1 || number < 0 || number > 255) {
            printf("Invalid input! Please enter a number between 0 and 255.\n");
            while(getchar() != '\n'); // Clear input buffer
        } else {
            break; // Input is valid
        }
    }
    return number;
}

// Function to get user input binary string
void getValidBinaryInput(char *binaryStr) {
    while (1) {
        printf("Enter a binary number (up to 8 bits): ");
        scanf("%s", binaryStr);
        int isValid = 1;
        for (int i = 0; binaryStr[i] != '\0'; i++) {
            if (binaryStr[i] != '0' && binaryStr[i] != '1') {
                isValid = 0; // Non-binary character found
                break;
            }
        }
        if (isValid && strlen(binaryStr) <= 8) {
            break; // Valid binary input
        } else {
            printf("Invalid input! Please use a binary number containing only 0s and 1s.\n");
        }
    }
}

// Main function
int main() {
    int option;
    int decimalNumber;
    char binaryStr[9]; // Extra character for the null terminator

    while (1) {
        printf("\nBinary Converter Menu:\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Choose an option (1-3): ");
        
        // Reading user choice
        if (scanf("%d", &option) != 1) {
            printf("Invalid input! Please enter a number between 1 and 3.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue; // Retry input
        }

        switch(option) {
            case 1:
                // Convert decimal to binary
                decimalNumber = getValidDecimalInput();
                printf("Decimal: %d => Binary: ", decimalNumber);
                decimalToBinary(decimalNumber);
                printf("\n");
                break;

            case 2:
                // Convert binary to decimal
                getValidBinaryInput(binaryStr);
                decimalNumber = binaryToDecimal(binaryStr);
                printf("Binary: %s => Decimal: %d\n", binaryStr, decimalNumber);
                break;

            case 3:
                // Exit the program
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option! Please choose a valid menu option.\n");
        }
    }

    return 0; // Should never reach here
}