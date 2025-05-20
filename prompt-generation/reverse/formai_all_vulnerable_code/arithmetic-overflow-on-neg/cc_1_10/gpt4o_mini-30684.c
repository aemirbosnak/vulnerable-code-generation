//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal number to binary
void decimalToBinary(int n, char *binary) {
    int index = 0;
    while (n > 0) {
        binary[index++] = (n % 2) + '0'; // Store the respective binary digit
        n /= 2;
    }
    // Reverse the binary string to get the correct order
    binary[index] = '\0'; // Null-terminate the string
    int length = strlen(binary);
    for (int i = 0; i < length / 2; ++i) {
        char temp = binary[i];
        binary[i] = binary[length - i - 1];
        binary[length - i - 1] = temp;
    }
}

// Function to display the binary representation of the number
void displayBinary(int n) {
    char binary[32]; // To hold binary representation (up to 32 bits)
    decimalToBinary(n, binary);
    printf("Decimal: %d -> Binary: %s\n", n, binary);
}

// Function to check if a number is negative and convert it accordingly
void convertNegative(int n) {
    if (n < 0) {
        printf("You entered a negative number: %d\n", n);
        printf("Converting to binary using two's complement representation:\n");
        
        // Convert using two's complement
        n = -n; // Make it positive for conversion
        char binary[32];
        decimalToBinary(n, binary);

        // Find two's complement
        for (int i = 0; i < strlen(binary); ++i) {
            binary[i] = (binary[i] == '0') ? '1' : '0'; // Invert bits
        }
        
        // Add 1 to binary for two's complement
        int carry = 1;
        for (int i = strlen(binary) - 1; i >= 0 && carry; --i) {
            if (binary[i] == '1') {
                binary[i] = '0'; // Reset to zero and continue carry
            } else {
                binary[i] = '1'; // Set to one and stop carry
                carry = 0;
            }
        }
        
        printf("Negative Decimal: %d -> Binary (Two's Complement): %s\n", n, binary);
    } else {
        displayBinary(n);
    }
}

// Function to accept user input and handle the conversion
void userInputConversion() {
    int number;
    printf("Enter an integer (positive or negative): ");
    scanf("%d", &number);

    convertNegative(number);
}

int main() {
    printf("Welcome to the Decimal to Binary Converter!\n");
    char choice;
    do {
        userInputConversion();
        printf("Would you like to convert another number? (y/n): ");
        scanf(" %c", &choice); // Notice the space before %c to consume any newline
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Decimal to Binary Converter. Goodbye!\n");
    return 0;
}