//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 32  // Define a max bit length for binary representation

// Function prototype declarations
void decimalToBinary(int decimal, char binary[]);
void reverseString(char str[]);
void displayBinary(const char binary[]);

int main() {
    int decimalNumber;
    char binaryRepresentation[MAX_BITS + 1]; // +1 for null terminator

    // Introduction (inspired by the spirit of Knuth)
    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("Enter a decimal number (non-negative integer): ");
    
    // Read user input
    if (scanf("%d", &decimalNumber) != 1 || decimalNumber < 0) {
        fprintf(stderr, "Error: Please enter a valid non-negative integer.\n");
        return EXIT_FAILURE;  // Exit with failure if input is invalid
    }

    // Convert the decimal number to binary representation
    decimalToBinary(decimalNumber, binaryRepresentation);
    
    // Display the results
    displayBinary(binaryRepresentation);

    return EXIT_SUCCESS;  // Indicate successful execution
}

// Function to convert decimal to binary using bit manipulation
void decimalToBinary(int decimal, char binary[]) {
    int index = 0;

    // Special case for zero
    if (decimal == 0) {
        binary[index++] = '0';
    } else {
        while (decimal > 0 && index < MAX_BITS) {
            // Capture the least significant bit
            binary[index++] = (decimal % 2) + '0';
            decimal /= 2; // Divide by 2 to shift right
        }
    }

    binary[index] = '\0'; // Null-terminate the string

    // Reverse the binary string to get the correct order
    reverseString(binary);
}

// Function to reverse a string in place
void reverseString(char str[]) {
    int left = 0;
    int right = 0;
    
    // Find the length of the string
    while (str[right] != '\0') {
        right++;
    }
    right--;  // Adjust to get the last valid character

    // Swap characters from the start and end
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

// Function to display the binary string
void displayBinary(const char binary[]) {
    printf("The binary representation is: %s\n", binary);
}