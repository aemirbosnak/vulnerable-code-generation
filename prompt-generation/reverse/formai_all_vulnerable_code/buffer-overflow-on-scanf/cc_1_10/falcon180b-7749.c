//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main()
{
    char hex[100], input[100], *ptr;
    int i, j, k, n, len, decimal = 0, valid = 1;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    // Check if input is valid hexadecimal number
    for (i = 0; input[i]!= '\0'; i++)
    {
        if (!isxdigit(input[i]))
        {
            printf("Invalid input! Please enter a valid hexadecimal number.\n");
            return 0;
        }
    }

    // Convert hexadecimal to decimal
    for (i = strlen(input) - 1, j = 0; i >= 0; i--, j++)
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            decimal += input[i] - '0';
        }
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            decimal += input[i] - 'A' + 10;
        }
        else if (input[i] >= 'a' && input[i] <= 'f')
        {
            decimal += input[i] - 'a' + 10;
        }
        else
        {
            printf("Invalid input! Please enter a valid hexadecimal number.\n");
            return 0;
        }
    }

    // Convert decimal to hexadecimal
    sprintf(hex, "%X", decimal);

    // Print result
    printf("The decimal equivalent of %s is %s.\n", input, hex);

    return 0;
}