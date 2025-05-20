//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT 256

int main()
{
    char input[MAX_CONVERT] = "";
    int i = 0;
    unsigned int number = 0;
    unsigned char hex[MAX_CONVERT] = "";

    printf("Enter a hexadecimal number (up to %d digits): ", MAX_CONVERT - 1);
    scanf("%s", input);

    // Validate input
    if (input[0] != '0' && input[0] != '0' && input[0] != 'x' && input[0] != 'X')
    {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    // Convert input to uppercase
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a')
        {
            input[i] -= 32;
        }
    }

    // Calculate number of digits
    int numDigits = 0;
    while (input[numDigits] != '\0')
    {
        numDigits++;
    }

    // Convert input to hexadecimal number
    for (i = 0; i < numDigits; i++)
    {
        int digit = input[i] - '0';
        hex[i] = digit > 9 ? 'a' + digit - 10 : '0' + digit;
    }

    // Print hexadecimal number
    printf("Hexadecimal equivalent: ");
    for (i = 0; hex[i] != '\0'; i++)
    {
        printf("%c ", hex[i]);
    }

    printf("\n");

    return 0;
}