//FormAI DATASET v1.0 Category: Binary Converter ; Style: shape shifting
#include <stdio.h>

// Shape Shifting Binary Converter

// Binary to decimal conversion function
int binaryToDecimal(int bin) {
    int dec = 0, i = 0, rem;
    while (bin != 0) {
        rem = bin % 10;
        bin /= 10;
        dec += rem * (1 << i);
        ++i;
    }
    return dec;
}

// Decimal to binary conversion function
int decimalToBinary(int dec) {
    int binary = 0, i = 1, rem;
    while (dec != 0) {
        rem = dec % 2;
        dec /= 2;
        binary += rem * i;
        i *= 10;
    }
    return binary;
}

// Main function
int main() {
    // Shape Shifter Initializing...
    printf("========================================= \n");
    printf("| Hello! I am the Binary Shape Shifter! | \n");
    printf("========================================= \n\n");

    // User Menu
    int choice, input;
    do {
        printf("What would you like to do? \n");
        printf("1. Convert from Binary to Decimal \n");
        printf("2. Convert from Decimal to Binary \n");
        printf("3. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        // Shape Shifter Transforming...
        switch (choice) {
            case 1:
                printf("Converting from Binary to Decimal...\n");
                printf("Enter a binary number: ");
                scanf("%d", &input);
                printf("%d in binary = %d in decimal\n\n", input, binaryToDecimal(input));
                break;
            case 2:
                printf("Converting from Decimal to Binary...\n");
                printf("Enter a decimal number: ");
                scanf("%d", &input);
                printf("%d in decimal = %d in binary\n\n", input, decimalToBinary(input));
                break;
            case 3:
                printf("Goodbye!\n\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    } while (choice != 3);

    return 0;
}