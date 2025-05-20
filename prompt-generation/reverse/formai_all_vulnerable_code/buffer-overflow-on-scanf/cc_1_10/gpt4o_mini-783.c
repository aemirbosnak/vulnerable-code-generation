//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: Alan Turing
#include <stdio.h>

// Function prototypes
void convertToHexadecimal(int num, char hex[]);
void printHexadecimal(char hex[]);

int main() {
    int decimalNumber;
    char hexadecimal[20]; // Enough to store hexadecimal representation

    // Introduction
    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    printf("Please enter a positive decimal integer: ");
    
    // Use a loop to ensure valid input
    while (1) {
        // Read user input
        scanf("%d", &decimalNumber);

        // Check if the input is valid (i.e., positive integer)
        if (decimalNumber >= 0) {
            break; // Exit loop if valid input
        } else {
            printf("Invalid input. Please enter a positive decimal integer: ");
        }
    }

    // Convert decimal to hexadecimal
    convertToHexadecimal(decimalNumber, hexadecimal);
    
    // Print the results
    printHexadecimal(hexadecimal);

    return 0;
}

// Function to convert decimal to hexadecimal
void convertToHexadecimal(int num, char hex[]) {
    int index = 0; // Index for hexadecimal string
    const char hexDigits[] = "0123456789ABCDEF"; // Array of hexadecimal digits

    // Edge case when number is zero
    if (num == 0) {
        hex[index++] = '0';
    } else {
        while (num > 0) {
            int remainder = num % 16; // Get remainder
            hex[index++] = hexDigits[remainder]; // Map to hexadecimal digit
            num /= 16; // Divide by 16 for next iteration
        }
    }
    
    // Since we've built the hex string in reverse, we need to reverse it
    for (int i = 0; i < index / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[index - i - 1];
        hex[index - i - 1] = temp;
    }

    // Null-terminate the hexadecimal string
    hex[index] = '\0';
}

// Function to print hexadecimal representation
void printHexadecimal(char hex[]) {
    printf("The hexadecimal representation is: %s\n", hex);
}