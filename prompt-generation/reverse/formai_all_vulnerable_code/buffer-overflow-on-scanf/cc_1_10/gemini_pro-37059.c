//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: thoughtful
// Binary Converter Example

#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    // Array to store the binary representation
    int binaryNum[32];

    // Counter for the binary array
    int i = 0;

    // Convert the decimal number to binary by dividing by 2
    while (n > 0) {
        // Store the remainder in the binary array
        binaryNum[i] = n % 2;

        // Divide the number by 2
        n /= 2;

        // Increment the counter
        i++;
    }

    // Print the binary representation
    printf("Binary representation: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
    printf("\n");
}

// Function to convert binary to decimal
int binaryToDecimal(int n) {
    // Initialize the decimal number
    int decimalNum = 0;

    // Counter for the binary number
    int i = 0;

    // Convert the binary number to decimal by multiplying by powers of 2
    while (n > 0) {
        // Get the last digit of the binary number
        int lastDigit = n % 10;

        // Multiply the last digit by 2^i
        decimalNum += lastDigit * (1 << i);

        // Divide the binary number by 10
        n /= 10;

        // Increment the counter
        i++;
    }

    // Return the decimal number
    return decimalNum;
}

// Main function
int main() {
    // Get the decimal number from the user
    int decimalNum;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);

    // Convert the decimal number to binary
    decimalToBinary(decimalNum);

    // Get the binary number from the user
    int binaryNum;
    printf("Enter a binary number: ");
    scanf("%d", &binaryNum);

    // Convert the binary number to decimal
    printf("Decimal representation: %d\n", binaryToDecimal(binaryNum));

    return 0;
}