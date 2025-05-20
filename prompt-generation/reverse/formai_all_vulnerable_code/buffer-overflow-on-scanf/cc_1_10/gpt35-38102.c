//FormAI DATASET v1.0 Category: Binary Converter ; Style: intelligent
// Intelligent C Binary Converter Example
// Written by [Your Name], [Date]

#include <stdio.h>
#include <math.h>

// Function to convert decimal to Binary
void decToBin(int decimal) {
    int binaryNumber[32], i = 0;

    // Calculating binary of decimal
    while(decimal > 0) {
        binaryNumber[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    // Displaying binary number
    printf("\nBinary Representation: ");
    for(int j = i - 1; j >= 0; j--)
        printf("%d", binaryNumber[j]);
}

// Function to convert Binary to decimal
void binToDec(long long binary) {
    int decimal = 0, i = 0, remainder;

    // Calculating decimal of binary
    while(binary != 0) {
        remainder = binary % 10;
        binary /= 10;
        decimal += remainder * pow(2, i);
        i++;
    }

    // Displaying decimal number
    printf("\nDecimal Representation: %d", decimal);
}

int main() {
    int option;
    long long binary;
    int decimal;

    do {
        // Displaying menu options
        printf("\n\nChoose an option:\n1. Binary to Decimal Conversion\n2. Decimal to Binary Conversion\n3. Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1: // Binary to decimal conversion
                printf("\nEnter a Binary Number: ");
                scanf("%lld", &binary);
                binToDec(binary); // Converting binary to decimal
                break;
            case 2: // Decimal to binary conversion
                printf("\nEnter a Decimal Number: ");
                scanf("%d", &decimal);
                decToBin(decimal); // Converting decimal to binary
                break;
            case 3: // Exit the program
                printf("Goodbye!");
                break;
            default: // Handling invalid option
                printf("Invalid option, please try again!\n");
        }
    } while(option != 3); // Loop until user chooses to exit

    return 0;
}