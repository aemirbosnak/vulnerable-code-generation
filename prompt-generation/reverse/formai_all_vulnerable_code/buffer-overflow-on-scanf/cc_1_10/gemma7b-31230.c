//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the C Hexadecimal Converter function
int hex_converter(char *num)
{
    int i, j, hex_value = 0, n = strlen(num);
    char hex_digits[] = "0123456789ABCDEF";

    for (i = 0; i < n; i++)
    {
        // Check if the character is a letter
        if (num[i] >= 'a' && num[i] <= 'f')
        {
            j = num[i] - 'a' + 10;
        }
        // Check if the character is a number
        else if (num[i] >= '0' && num[i] <= '9')
        {
            j = num[i] - '0';
        }
        else
        {
            return -1;
        }

        hex_value += j * pow(16, n - i - 1);
    }

    return hex_value;
}

int main()
{
    char num[20];

    // Get the hexadecimal number from the user
    printf("Enter a hexadecimal number: ");
    scanf("%s", num);

    // Convert the hexadecimal number to an integer
    int hex_value = hex_converter(num);

    // Print the converted value
    if (hex_value != -1)
    {
        printf("The converted value is: %d\n", hex_value);
    }
    else
    {
        printf("Error converting the number.\n");
    }

    return 0;
}