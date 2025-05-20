//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Function to convert binary to decimal
int binaryToDecimal(int n)
{
    int num = n;
    int decimalNumber = 0, i = 0, remainder;
    while (num != 0)
    {
        remainder = num % 10;
        num /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }
    return decimalNumber;
}

// Function to convert decimal to binary
int decimalToBinary(int n)
{
    int quotient;
    int binaryNumber = 0, i = 1, remainder;
    while (n != 0)
    {
        remainder = n % 2;
        n /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }
    return binaryNumber;
}

// Driver code
int main()
{
    int choice, number;
    printf("Enter your choice:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter a binary number: ");
        scanf("%d", &number);
        printf("Decimal equivalent of %d is: %d\n", number, binaryToDecimal(number));
        break;
    case 2:
        printf("Enter a decimal number: ");
        scanf("%d", &number);
        printf("Binary equivalent of %d is: %d\n", number, decimalToBinary(number));
        break;
    default:
        printf("Invalid choice!\n");
    }
    return 0;
}