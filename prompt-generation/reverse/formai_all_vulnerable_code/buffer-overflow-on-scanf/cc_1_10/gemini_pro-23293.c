//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEX_BASE 16

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex)
{
    int len = strlen(hex);
    int i, value = 0;

    // Iterate over the hexadecimal string in reverse order
    for (i = len - 1; i >= 0; i--)
    {
        // Get the digit value of the current character
        int digit;
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            digit = hex[i] - '0';
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            digit = hex[i] - 'a' + 10;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            digit = hex[i] - 'A' + 10;
        }
        else
        {
            // Invalid hexadecimal character
            return -1;
        }

        // Multiply the digit value by the appropriate power of HEX_BASE and add it to the result
        value += digit * pow(HEX_BASE, len - i - 1);
    }

    return value;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int num)
{
    // Allocate memory for the hexadecimal string
    char *hex = malloc(sizeof(char) * 11);
    if (hex == NULL)
    {
        return NULL;
    }

    // Convert the integer to a hexadecimal string
    int i = 0;
    while (num > 0)
    {
        int digit = num % HEX_BASE;
        if (digit < 10)
        {
            hex[i++] = digit + '0';
        }
        else
        {
            hex[i++] = digit - 10 + 'a';
        }
        num /= HEX_BASE;
    }
    hex[i] = '\0';

    // Reverse the hexadecimal string
    int len = strlen(hex);
    for (i = 0; i < len / 2; i++)
    {
        char temp = hex[i];
        hex[i] = hex[len - i - 1];
        hex[len - i - 1] = temp;
    }

    return hex;
}

int main()
{
    // Get the hexadecimal string from the user
    char hex[100];
    printf("Enter a hexadecimal string: ");
    scanf("%s", hex);

    // Convert the hexadecimal string to an integer
    int num = hex_to_int(hex);
    if (num == -1)
    {
        printf("Invalid hexadecimal string.\n");
        return 1;
    }

    // Print the integer value
    printf("The integer value of the hexadecimal string is: %d\n", num);

    // Convert the integer back to a hexadecimal string
    char *hex_result = int_to_hex(num);
    if (hex_result == NULL)
    {
        printf("Error allocating memory for hexadecimal string.\n");
        return 1;
    }

    // Print the hexadecimal string
    printf("The hexadecimal string of the integer is: %s\n", hex_result);

    // Free the allocated memory
    free(hex_result);

    return 0;
}