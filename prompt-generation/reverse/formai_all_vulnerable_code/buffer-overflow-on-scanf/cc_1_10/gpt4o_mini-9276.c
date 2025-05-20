//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void decimalToBinary(int decimal, char* binary);
void reverseString(char* str);
void displayBinaryConversion(int decimal, const char* binary);

int main() {
    int decimalNumber;
    char binaryRepresentation[33]; // Enough space for 32 bits and null terminator

    printf("Welcome to the Magical Decimal to Binary Converter!\n");
    printf("Please enter a positive decimal number (0 to exit): ");

    while (1) {
        printf("> ");
        scanf("%d", &decimalNumber);

        if (decimalNumber < 0) {
            printf("Negative number detected! Exiting...\n");
            break;
        }

        // Convert decimal to binary
        decimalToBinary(decimalNumber, binaryRepresentation);

        // Display the conversion
        displayBinaryConversion(decimalNumber, binaryRepresentation);
        
        printf("\nEnter another number (0 to exit): ");
    }

    return 0;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal, char* binary) {
    int index = 0;

    // Handle zero explicitly
    if (decimal == 0) {
        binary[index++] = '0';
        binary[index] = '\0';
        return;
    }

    // Convert decimal to binary
    while (decimal > 0) {
        binary[index++] = (decimal % 2) + '0'; // Convert digit to character
        decimal /= 2;
    }
    binary[index] = '\0'; // Null-terminate the string

    // Reverse the string to get the correct order
    reverseString(binary);
}

// Function to reverse a string (used to reorder binary digits)
void reverseString(char* str) {
    int start = 0;
    int end = 0;

    // Get the length of string
    while (str[end] != '\0') {
        end++;
    }
    end--; // Set end to last character index

    // Swap characters from start to end
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to display the binary conversion
void displayBinaryConversion(int decimal, const char* binary) {
    printf("Decimal: %d\n", decimal);
    printf("Binary:  %s\n", binary);
}