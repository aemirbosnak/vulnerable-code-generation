//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
char* decToBin(int n) {
    // Check if the number is negative
    if (n < 0) {
        return NULL;
    }

    // Allocate memory for the binary string
    char* binary = (char*) malloc(33 * sizeof(char));

    // Initialize the binary string to all 0s
    for (int i = 0; i < 33; i++) {
        binary[i] = '0';
    }

    // Convert the number to binary by repeatedly dividing by 2 and storing the remainder
    int i = 32;
    while (n > 0) {
        binary[i--] = (n % 2) + '0';
        n /= 2;
    }

    // Return the binary string
    return binary;
}

// Function to convert a binary number to decimal
int binToDec(char* binary) {
    // Check if the string is valid binary
    for (int i = 0; i < 33; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            return -1;
        }
    }

    // Convert the binary string to decimal by multiplying each digit by 2^i
    int decimal = 0;
    for (int i = 32, j = 0; i >= 0; i--, j++) {
        decimal += (binary[i] - '0') << j;
    }

    // Return the decimal number
    return decimal;
}

// Driver code
int main() {
    // Get the decimal number from the user
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Convert the decimal number to binary
    char* binary = decToBin(decimal);

    // Print the binary number
    printf("The binary representation of %d is: %s\n", decimal, binary);

    // Convert the binary number back to decimal
    int newDecimal = binToDec(binary);

    // Print the new decimal number
    printf("The decimal representation of the binary number is: %d\n", newDecimal);

    // Free the memory allocated for the binary string
    free(binary);

    return 0;
}