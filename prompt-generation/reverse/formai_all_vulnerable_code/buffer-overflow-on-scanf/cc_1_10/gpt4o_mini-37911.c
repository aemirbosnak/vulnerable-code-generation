//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal number to binary
void decimalToBinary(int n) {
    int binary[32]; // Array to store binary number
    int index = 0; // Index for binary array

    // If n is 0, print 0
    if (n == 0) {
        printf("Binary representation: 0\n");
        return;
    }

    // Convert decimal to binary
    while (n > 0) {
        binary[index] = n % 2; // Store the remainder in binary array
        n = n / 2; // Update n to its quotient
        index++; // Increment index
    }

    // Print binary representation in reverse order
    printf("Binary representation: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Function to convert binary number to decimal
int binaryToDecimal(const char* binaryStr) {
    int decimal = 0; // Variable to store decimal result
    int base = 1;    // Base value for binary representation

    int length = strlen(binaryStr); // Get the length of the binary string

    // Convert binary string to decimal
    for (int i = length - 1; i >= 0; i--) {
        if (binaryStr[i] == '1') {
            decimal += base; // Add base to result if bit is 1
        }
        base *= 2; // Update base to next position
    }
    return decimal; // Return the computed decimal value
}

int main() {
    int choice; 
    int number; 
    char binaryStr[33]; // Array to store binary string (maximum of 32 bits + null terminator)

    // User Menu
    do {
        printf("Choose an option:\n");
        printf("1. Convert Decimal to Binary\n");
        printf("2. Convert Binary to Decimal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                decimalToBinary(number); // Call conversion function
                break;

            case 2:
                printf("Enter a binary number: ");
                scanf("%s", binaryStr);
                // Validate input for binary number (only 0s and 1s)
                for (int i = 0; binaryStr[i] != '\0'; i++) {
                    if (binaryStr[i] != '0' && binaryStr[i] != '1') {
                        printf("Invalid binary number!\n");
                        break;
                    }
                }
                // If input is valid, convert to decimal
                printf("Decimal representation: %d\n", binaryToDecimal(binaryStr));
                break;

            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
        printf("\n"); // New line for better readability
    } while (choice != 0); // Repeat until user chooses to exit

    return 0; // Indicate successful completion
}