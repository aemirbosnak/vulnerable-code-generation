//FormAI DATASET v1.0 Category: Binary Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int decimalNumber)
{
    int binaryNumber[100], index = 0;
    while (decimalNumber > 0) {
        binaryNumber[index] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        index++;
    }
    for (int i = index - 1; i >= 0; i--)
        printf("%d", binaryNumber[i]);
}

// Function to convert binary to decimal
void binaryToDecimal(long long binaryNumber)
{
    int decimalNumber = 0, base = 1;
    while (binaryNumber > 0) {
        int lastDigit = binaryNumber % 10;
        binaryNumber = binaryNumber / 10;
        decimalNumber += lastDigit * base;
        base = base * 2;
    }
    printf("%d", decimalNumber);
}

int main()
{
    int choice, decimalNumber;
    long long binaryNumber;

    printf("1. Decimal to Binary Conversion\n");
    printf("2. Binary to Decimal Conversion\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("Enter the decimal number: ");
        scanf("%d", &decimalNumber);
        printf("Binary Number: ");
        decimalToBinary(decimalNumber);
        break;
    case 2:
        printf("Enter the binary number: ");
        scanf("%lld", &binaryNumber);
        printf("Decimal Number: ");
        binaryToDecimal(binaryNumber);
        break;
    default:
        printf("Invalid choice!");
        break;
    }

    return 0;
}