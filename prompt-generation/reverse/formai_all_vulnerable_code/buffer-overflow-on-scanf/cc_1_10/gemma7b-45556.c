//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input_hex[10];
    int i, j, k, converted_number, valid_input = 1;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input_hex);

    // Check for valid input
    for (i = 0; input_hex[i] != '\0'; i++)
    {
        if ((input_hex[i] < 'a' || input_hex[i] > 'f') && (input_hex[i] < 'A' || input_hex[i] > 'F'))
        {
            valid_input = 0;
        }
    }

    // Convert the input to uppercase
    for (i = 0; input_hex[i] != '\0'; i++)
    {
        if (input_hex[i] >= 'a')
        {
            input_hex[i] -= 32;
        }
    }

    // Calculate the converted number
    converted_number = 0;
    k = 0;
    for (i = 0; input_hex[i] != '\0'; i++)
    {
        j = input_hex[i] - 'a' + 10;
        converted_number += j * pow(16, k);
        k++;
    }

    // Print the converted number
    if (valid_input)
    {
        printf("Converted hexadecimal number: %d\n", converted_number);
    }
    else
    {
        printf("Invalid input.\n");
    }

    return 0;
}