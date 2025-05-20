//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to binary
char *decimalToBinary(int n)
{
    // Initialize the binary string
    char *binaryString = malloc(33 * sizeof(char));
    int index = 0;

    // While the number is greater than 0
    while (n > 0)
    {
        // Get the remainder of the number divided by 2
        int remainder = n % 2;

        // Convert the remainder to a character
        char character = remainder + '0';

        // Add the character to the binary string
        binaryString[index] = character;

        // Increment the index
        index++;

        // Divide the number by 2
        n /= 2;
    }

    // Reverse the binary string
    for (int i = 0; i < index / 2; i++)
    {
        char temp = binaryString[i];
        binaryString[i] = binaryString[index - i - 1];
        binaryString[index - i - 1] = temp;
    }

    // Return the binary string
    return binaryString;
}

// Function to convert a binary number to decimal
int binaryToDecimal(char *binaryString)
{
    // Initialize the decimal number
    int decimalNumber = 0;

    // Get the length of the binary string
    int length = strlen(binaryString);

    // Iterate over the binary string
    for (int i = 0; i < length; i++)
    {
        // Get the character at the current index
        char character = binaryString[i];

        // Convert the character to an integer
        int digit = character - '0';

        // Multiply the decimal number by 2
        decimalNumber *= 2;

        // Add the digit to the decimal number
        decimalNumber += digit;
    }

    // Return the decimal number
    return decimalNumber;
}

// Main function
int main()
{
    // Get the decimal number from the user
    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Convert the decimal number to binary
    char *binaryString = decimalToBinary(decimalNumber);

    // Print the binary string
    printf("Binary string: %s\n", binaryString);

    // Convert the binary string to decimal
    int decimalNumber2 = binaryToDecimal(binaryString);

    // Print the decimal number
    printf("Decimal number: %d\n", decimalNumber2);

    // Free the memory allocated for the binary string
    free(binaryString);

    return 0;
}