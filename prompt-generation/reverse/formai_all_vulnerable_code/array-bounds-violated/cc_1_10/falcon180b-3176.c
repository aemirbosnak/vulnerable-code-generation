//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_NUMBER_LENGTH 32
#define BASE_NUMBER 10
#define BASE_NUMBER_STRING "0123456789"
#define BASE_NUMBER_LENGTH 10

// Function to convert decimal to binary
void decimalToBinary(int decimalNumber, char* binaryNumber)
{
    int remainder, i = 0;
    char binaryDigit;

    // Iterate until the quotient is zero
    while (decimalNumber!= 0)
    {
        // Calculate the remainder
        remainder = decimalNumber % BASE_NUMBER;

        // Convert the remainder to binary digit
        binaryDigit = BASE_NUMBER_STRING[remainder];

        // Append the binary digit to the binary number
        binaryNumber[i] = binaryDigit;

        // Increment the index
        i++;

        // Divide the decimal number by the base number
        decimalNumber /= BASE_NUMBER;
    }

    // Reverse the binary number
    for (int j = 0; j < i / 2; j++)
    {
        char temp = binaryNumber[j];
        binaryNumber[j] = binaryNumber[i - j - 1];
        binaryNumber[i - j - 1] = temp;
    }
}

// Function to convert binary to decimal
int binaryToDecimal(char* binaryNumber)
{
    int decimalNumber = 0, base = 1;
    int length = strlen(binaryNumber);

    // Iterate over the binary number from right to left
    for (int i = length - 1; i >= 0; i--)
    {
        // Convert the binary digit to decimal
        if (binaryNumber[i] == '1')
        {
            decimalNumber += base;
        }

        // Increment the base
        base *= BASE_NUMBER;
    }

    // Return the decimal number
    return decimalNumber;
}

int main()
{
    char binaryNumber[MAX_NUMBER_LENGTH];
    int decimalNumber;

    // Prompt the user to enter a decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Convert the decimal number to binary
    decimalToBinary(decimalNumber, binaryNumber);

    // Print the binary number
    printf("Binary number: %s\n", binaryNumber);

    // Convert the binary number to decimal
    int result = binaryToDecimal(binaryNumber);

    // Print the decimal number
    printf("Decimal number: %d\n", result);

    // Exit the program
    return 0;
}