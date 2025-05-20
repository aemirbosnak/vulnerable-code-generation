//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char input[MAX_BUFFER_SIZE] = "";
    char output[MAX_BUFFER_SIZE] = "";
    int input_length = 0;
    int i = 0;
    int j = 0;
    int is_hex = 0;
    int number = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    input_length = strlen(input);

    // Check if the input is hexadecimal
    for (i = 0; i < input_length; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'f')
        {
            is_hex = 1;
        }
    }

    // If the input is hexadecimal, convert it to uppercase
    if (is_hex)
    {
        for (i = 0; i < input_length; i++)
        {
            if (input[i] >= 'a')
            {
                input[i] -= 32;
            }
        }
    }

    // Convert the hexadecimal number to decimal
    for (i = 0; i < input_length; i++)
    {
        number = number * 16 + input[i] - '0';
    }

    // Print the decimal number
    printf("Decimal equivalent: %d\n", number);

    return 0;
}