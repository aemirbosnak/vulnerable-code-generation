//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to binary
void decimalToBinary(int n, char *binary) {
    int index = 0;

    // Handle special case for 0
    if (n == 0) {
        strcpy(binary, "0");
        return;
    }

    while (n > 0) {
        binary[index++] = (n % 2) + '0';  // Store the current bit
        n = n / 2;                        // Reduce n
    }

    binary[index] = '\0';  // Null-terminate the string

    // Reverse the string to get correct order
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }
}

// Function to convert a binary string to decimal
int binaryToDecimal(const char *binary) {
    int decimal = 0;
    int base = 1;  // Initialize base to 1 (2^0)

    // Start from the end of the binary string
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;  // Add base value if the bit is 1
        }
        base *= 2;  // Increment the base for next bit position
    }

    return decimal;
}

// Function to display a menu and get user choice
int displayMenu() {
    int choice;
    printf("Binary Converter Program\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function for handling conversion from Decimal to Binary
void handleDecimalToBinary() {
    int decimal;
    char binary[65];  // accommodates up to 64 bits + null terminator

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal, binary);
    printf("Binary representation of %d is: %s\n", decimal, binary);
}

// Function for handling conversion from Binary to Decimal
void handleBinaryToDecimal() {
    char binary[65];

    printf("Enter a binary number: ");
    scanf("%s", binary);

    int decimal = binaryToDecimal(binary);
    printf("Decimal representation of %s is: %d\n", binary, decimal);
}

int main() {
    int choice;

    while (1) {
        choice = displayMenu();

        switch (choice) {
            case 1:
                handleDecimalToBinary();
                break;
            case 2:
                handleBinaryToDecimal();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}