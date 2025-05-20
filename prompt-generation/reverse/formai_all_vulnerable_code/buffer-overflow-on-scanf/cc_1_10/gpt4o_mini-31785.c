//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: energetic
#include <stdio.h>

void decimalToBinary(int n) {
    // Array to store binary number
    int binaryNum[32];
    
    // Index for storing binary
    int index = 0;

    // Base case for 0
    if (n == 0) {
        printf("Binary representation is: 0\n");
        return;
    }
    
    // Making the decimal number go binary!
    while (n > 0) {
        // Storing the remainder in binary array
        binaryNum[index] = n % 2;
        n = n / 2;
        index++;
    }

    // Printing in reverse order to show correct representation
    printf("Binary representation is: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binaryNum[i]);
    }
    printf("\n");
}

int main() {
    int decimalNum;

    // Welcome message
    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("===========================================\n");
    printf("Enter a positive integer to convert to binary: ");
    
    // Reading user input
    if (scanf("%d", &decimalNum) != 1 || decimalNum < 0) {
        printf("Oh snap! Please enter a valid positive integer next time.\n");
        return 1;
    }

    // Call the function to convert and display the binary
    decimalToBinary(decimalNum);

    // Goodbye message
    printf("Thanks for using the converter! Until next time!\n");
    return 0;
}