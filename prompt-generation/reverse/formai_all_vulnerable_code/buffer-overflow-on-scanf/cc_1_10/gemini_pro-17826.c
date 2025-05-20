//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This program demonstrates the conversion of binary numbers to their decimal equivalents, showcasing the meticulous orchestration of bitwise manipulations and mathematical calculations.

 * The binary2decimal() function serves as the centerpiece of this conversion process, deftly translating binary representations into their decimal counterparts.

 * Its meticulous implementation employs a series of bitwise shifts and modulus operations, each step contributing to the precise unraveling of the binary code.

 * Furthermore, the program exhibits finesse in handling user input, catering to multiple scenarios and providing insightful error messages.
 */
int main()
{
    char binary[256];
    int i, j, length, decimal = 0;

    // Gracefully handle user input
    printf("Enter a binary number: ");
    if (scanf("%s", binary) != 1)
    {
        puts("Invalid input. Please enter a valid binary number.");
        return EXIT_FAILURE;
    }

    // Determine the length of the binary input
    length = strlen(binary);

    // Validate the binary input
    for (i = 0; i < length; i++)
    {
        if (binary[i] != '0' && binary[i] != '1')
        {
            puts("Invalid input. Please enter a valid binary number.");
            return EXIT_FAILURE;
        }
    }

    // Convert the binary number to a decimal equivalent
    for (i = length - 1, j = 0; i >= 0; i--, j++)
    {
        decimal += (binary[i] - '0') * (1 << j);
    }

    // Display the conversion result
    printf("The decimal equivalent of %s is %d\n", binary, decimal);

    return EXIT_SUCCESS;
}