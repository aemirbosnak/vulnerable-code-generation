//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char input_buffer[MAX_BUFFER_SIZE];
    int input_length, i, j, offset = 0, is_hex = 0, is_valid = 1;
    unsigned int hex_value = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input_buffer);

    input_length = strlen(input_buffer);

    for (i = 0; i < input_length; i++)
    {
        if (input_buffer[i] >= 'a' && input_buffer[i] <= 'f')
        {
            is_hex = 1;
        }
        else if (input_buffer[i] >= 'A' && input_buffer[i] <= 'F')
        {
            is_hex = 1;
        }
        else if (input_buffer[i] >= '0' && input_buffer[i] <= '9')
        {
            is_hex = 1;
        }
        else
        {
            is_valid = 0;
        }
    }

    if (is_valid && is_hex)
    {
        for (i = 0; i < input_length; i++)
        {
            if (input_buffer[i] >= 'a' && input_buffer[i] <= 'f')
            {
                offset = 32;
            }
            else if (input_buffer[i] >= 'A' && input_buffer[i] <= 'F')
            {
                offset = 32;
            }
            else if (input_buffer[i] >= '0' && input_buffer[i] <= '9')
            {
                offset = 0;
            }

            hex_value = hex_value * 16 + input_buffer[i] - offset;
        }

        printf("Hexadecimal value: %x", hex_value);
    }
    else
    {
        printf("Invalid input.");
    }

    return 0;
}