//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Alan Turing
#include <stdio.h>
#include <string.h>

#define MAX_BITS 32  // Maximum bits for a binary number representation

// Function to convert decimal to binary
void decimalToBinary(int decimal, char *binary) {
    int index = 0;
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        // Check if the ith bit is set
        if (decimal & (1 << i)) {
            binary[index++] = '1';
        } else {
            binary[index++] = '0';
        }
    }
    binary[index] = '\0'; // Null terminate the binary string
}

// Function to convert binary string to decimal
int binaryToDecimal(const char *binary) {
    int decimal = 0;
    int length = strlen(binary);
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal |= (1 << (length - 1 - i));  // Set the corresponding bit
        }
    }
    return decimal;
}

// Function to print the binary representation of a number
void printBinary(int decimal) {
    char binary[MAX_BITS + 1];
    decimalToBinary(decimal, binary);
    printf("Decimal: %d, Binary: %s\n", decimal, binary);
}

// Function to read and validate user input
int readDecimal() {
    int number;
    char buffer[10];
    
    while (1) {
        printf("Enter a decimal number (0 to exit): ");
        fgets(buffer, sizeof(buffer), stdin); // Use fgets to prevent buffer overflow

        // Try to convert the input to an integer
        if (sscanf(buffer, "%d", &number) != 1 || number < 0) {
            printf("Invalid input. Please enter a non-negative integer.\n");
        } else {
            return number;
        }
    }
}

int main() {
    int number;
    printf("Welcome to the Decimal to Binary Converter!\n");
    
    // Main loop of the program
    while (1) {
        number = readDecimal(); // Get user input

        if (number == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;  // Exit if the user enters 0
        }

        printBinary(number); // Print the binary representation
    }

    // Additional functionality: Binary to Decimal conversion
    char binary[MAX_BITS + 1];
    
    printf("\nNow, let's convert a binary string to decimal.\n");
    printf("Enter a binary string (e.g., 101010): ");
    fgets(binary, sizeof(binary), stdin);
    
    // Remove newline character, if present
    size_t len = strlen(binary);
    if (len > 0 && binary[len - 1] == '\n') {
        binary[len - 1] = '\0';
    }

    // Validate binary input and attempt conversion
    for (size_t i = 0; i < strlen(binary); i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            printf("Invalid binary string. Please enter a valid binary format.\n");
            return 1; // Exit program if invalid input is provided
        }
    }

    int decimal = binaryToDecimal(binary);
    printf("Binary: %s, Decimal: %d\n", binary, decimal);

    return 0; // Indicate successful completion
}