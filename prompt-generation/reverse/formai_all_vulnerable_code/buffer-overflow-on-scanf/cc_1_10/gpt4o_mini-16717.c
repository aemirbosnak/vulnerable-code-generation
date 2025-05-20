//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: recursive
#include <stdio.h>

void printBinary(int n) {
    // Base case for zero
    if (n == 0) {
        return; // If it's zero, don't print anything further
    }
    
    // Recursive call to print the binary representation of n / 2
    printBinary(n / 2);
    
    // Print the remainder when n is divided by 2
    printf("%d", n % 2);
}

void decimalToBinary(int n) {
    // Handle the case for negative numbers by using two's complement
    if (n < 0) {
        // Calculate two's complement for negative numbers
        unsigned int mask = (1 << (sizeof(int) * 8 - 1));
        n = (~n) + 1; // Calculate two's complement
        printBinary(mask | n); // Print the binary representation including the sign bit
        return;
    }

    // Special case for zero
    if (n == 0) {
        printf("0");
        return;
    }

    // Print the binary representation for positive numbers
    printBinary(n);
}

int main() {
    int decimalNumber;

    printf("Enter an integer (positive or negative): ");
    // Validate user input
    while (1) {
        if (scanf("%d", &decimalNumber) != 1) {
            printf("Invalid input. Please enter a valid integer: ");
            while (getchar() != '\n'); // clear invalid input
        } else {
            break;
        }
    }

    printf("The binary representation of %d is: ", decimalNumber);
    decimalToBinary(decimalNumber);
    printf("\n");

    return 0;
}