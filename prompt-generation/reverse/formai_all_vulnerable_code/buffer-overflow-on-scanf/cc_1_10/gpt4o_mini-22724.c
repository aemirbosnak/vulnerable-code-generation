//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

void convertToBinary(int number) {
    // Array to store the binary number
    int binary[32];
    int index = 0;

    // Edge case for zero
    if (number == 0) {
        printf("Binary representation: 0\n");
        return;
    }

    // Process the number and fill the binary array
    while (number > 0) {
        binary[index] = number % 2; // Store the remainder (0 or 1)
        number = number / 2;         // Divide the number by 2
        index++;
    }

    // Print the binary representation in reverse order
    printf("Binary representation: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main() {
    int decimalNumber;

    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("Please enter a decimal number: ");

    // Read input from user
    if (scanf("%d", &decimalNumber) != 1) {
        printf("Invalid input! Please enter a valid integer.\n");
        return 1; // Exit with error code
    }

    // Check for negative input
    if (decimalNumber < 0) {
        printf("Negative numbers are not supported. Please enter a non-negative integer.\n");
        return 1; // Exit with error code
    }

    convertToBinary(decimalNumber); // Call the conversion function

    return 0; // Successful termination
}