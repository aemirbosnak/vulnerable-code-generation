//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimalNumber, char* hexadecimalNumber)
{
    // Array of hexadecimal digits
    char hexadecimalDigits[] = "0123456789ABCDEF";
    
    int quotient, remainder;
    int i = 0;

    // Convert decimal to hexadecimal
    while (decimalNumber != 0)
    {
        quotient = decimalNumber / 16;
        remainder = decimalNumber % 16;
        hexadecimalNumber[i++] = hexadecimalDigits[remainder];
        decimalNumber = quotient;
    }

    // Add 0x prefix
    hexadecimalNumber[i++] = 'x';
    hexadecimalNumber[i++] = '0';

    // Reverse the string
    int j, k;
    char temp;

    for (j = 0, k = i - 1; j < k; j++, k--)
    {
        temp = hexadecimalNumber[j];
        hexadecimalNumber[j] = hexadecimalNumber[k];
        hexadecimalNumber[k] = temp;
    }
}

int main()
{
    int decimalNumber;
    char hexadecimalNumber[20];

    // Take input from user
    printf("Enter decimal number: ");
    scanf("%d", &decimalNumber);

    // Convert decimal to hexadecimal
    decimalToHexadecimal(decimalNumber, hexadecimalNumber);

    // Print hexadecimal number
    printf("Hexadecimal: %s\n", hexadecimalNumber);

    return 0;
}