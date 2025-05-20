//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char hex[100];
    int decimal;
    int i = 0;
    int length;

    // Prompt the user to enter a hexadecimal number
    printf("Enter a hexadecimal number: ");

    // Read the input string
    scanf("%s", hex);

    // Check if the input string is a valid hexadecimal number
    for (i = 0; hex[i]!= '\0'; i++)
    {
        if (hex[i] < '0' || hex[i] > '9' && hex[i] < 'A' || hex[i] > 'F' && hex[i] < 'a' || hex[i] > 'f')
        {
            printf("Invalid hexadecimal number!\n");
            exit(0);
        }
    }

    // Convert the hexadecimal number to decimal
    decimal = 0;
    length = strlen(hex) - 1;
    for (i = length; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            decimal += hex[i] - '0';
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            decimal += hex[i] - 'A' + 10;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            decimal += hex[i] - 'a' + 10;
        }
    }

    // Print the decimal equivalent of the hexadecimal number
    printf("The decimal equivalent of %s is %d.\n", hex, decimal);

    return 0;
}