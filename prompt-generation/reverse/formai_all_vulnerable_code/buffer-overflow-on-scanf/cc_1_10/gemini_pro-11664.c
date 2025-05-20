//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary representation
char *decimalToBinary(int n)
{
    // Base case: If n is 0, return "0"
    if (n == 0)
        return "0";

    // Recursively divide n by 2 and store the remainder in a character array
    char *s = decimalToBinary(n / 2);

    // Append the remainder to the result
    char *result = malloc(strlen(s) + 2);
    sprintf(result, "%s%d", s, n % 2);

    // Free the memory allocated for the recursive call
    free(s);

    // Return the result
    return result;
}

// Function to convert a binary number to decimal representation
int binaryToDecimal(char *s)
{
    // Base case: If the string is empty, return 0
    if (strlen(s) == 0)
        return 0;

    // Recursively multiply the last digit by 2 and add it to the result
    return (s[strlen(s) - 1] - '0') * (1 << (strlen(s) - 1)) + binaryToDecimal(s + 1);
}

// Main function
int main()
{
    // Get the decimal number from the user
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);

    // Convert the decimal number to binary representation and print it
    char *binaryRepresentation = decimalToBinary(n);
    printf("Binary representation: %s\n", binaryRepresentation);

    // Convert the binary representation back to decimal and print it
    int decimalRepresentation = binaryToDecimal(binaryRepresentation);
    printf("Decimal representation: %d\n", decimalRepresentation);

    // Free the memory allocated for the binary representation
    free(binaryRepresentation);

    return 0;
}