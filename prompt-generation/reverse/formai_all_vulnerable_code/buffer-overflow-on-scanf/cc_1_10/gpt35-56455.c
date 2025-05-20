//FormAI DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BINARY_LENGTH 32 // Maximum length of binary number e.g 32 bits in integer

// Function to convert decimal to binary string
char* decimal_to_binary(int decimal) {
    char* binary = (char*) malloc(MAX_BINARY_LENGTH * sizeof(char)); // Allocate memory for binary number string
    int index = 0;
    while (decimal > 0) {
        binary[index++] = decimal % 2 + '0'; // Convert binary digit to character and add to binary number string
        decimal /= 2; // Move to next digit
    }
    binary[index] = '\0'; // Append null character at the end of binary number string
    int length = strlen(binary);
    for (int i = 0; i < length / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[length - i - 1];
        binary[length - i - 1] = temp; // Reverse the binary number string
    }
    return binary;
}

// Function to convert binary string to decimal
int binary_to_decimal(char* binary) {
    int decimal = 0;
    int length = strlen(binary);
    for (int i = 0; i < length; i++) {
        decimal += (binary[i] - '0') * pow(2, length - i - 1); // Calculate decimal value by multiplying binary digit with 2^(position) and summing up
    }
    return decimal;
}

int main() {
    int choice;
    printf("Select the conversion type:\n1. Decimal to binary\n2. Binary to decimal\n");
    scanf("%d", &choice); // Take user input for conversion type

    if (choice == 1) { // Decimal to binary conversion
        int decimal;
        printf("Enter the decimal number: ");
        scanf("%d", &decimal); // Take user input for decimal number

        char* binary = decimal_to_binary(decimal); // Call the decimal to binary conversion function

        printf("The binary equivalent of %d is %s\n", decimal, binary); // Print the binary number

        free(binary); // Free the memory allocated to binary number string
    }
    else if (choice == 2) { // Binary to decimal conversion
        char binary[MAX_BINARY_LENGTH];
        printf("Enter the binary number: ");
        scanf("%s", binary); // Take user input for binary number

        int decimal = binary_to_decimal(binary); // Call the binary to decimal conversion function

        printf("The decimal equivalent of %s is %d\n", binary, decimal); // Print the decimal number
    }
    else {
        printf("Invalid choice!\n"); // Print error message for invalid user choice
    }

    return 0;
}