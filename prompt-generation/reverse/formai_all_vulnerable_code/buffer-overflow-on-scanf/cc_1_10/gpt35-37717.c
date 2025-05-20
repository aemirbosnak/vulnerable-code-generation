//FormAI DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal number to binary
void decimalToBinary(int decimalNumber)
{
    // Array to store binary number
    int binaryNumber[32];

    // Counter for binary array
    int i = 0;

    // Convert decimal to binary
    while (decimalNumber > 0)
    {
        // Storing remainder in binary array
        binaryNumber[i] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        i++;
    }

    // Printing binary in reverse order
    printf("\nBinary number: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNumber[j]);
}

// Function to convert binary number to decimal
void binaryToDecimal(int binaryNumber)
{
    // Initializing variables
    int decimalNumber = 0, base = 1;

    // Converting binary to decimal
    while (binaryNumber > 0)
    {
        // Getting last digit
        int lastDigit = binaryNumber % 10;
        binaryNumber = binaryNumber / 10;

        // Multiplying with base and adding to decimal number
        decimalNumber += lastDigit * base;
        base *= 2;
    }

    // Printing decimal number
    printf("\nDecimal number: %d\n", decimalNumber);
}

int main()
{
    int choice, decimalNumber, binaryNumber;

    // Menu-driven program
    while (1)
    {
        printf("\nBinary Converter\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Convert binary to decimal\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter decimal number: ");
            scanf("%d", &decimalNumber);
            decimalToBinary(decimalNumber);
            break;
        
        case 2:
            printf("Enter binary number: ");
            scanf("%d", &binaryNumber);
            binaryToDecimal(binaryNumber);
            break;

        case 3:
            printf("\nThank you for using Binary Converter.\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}