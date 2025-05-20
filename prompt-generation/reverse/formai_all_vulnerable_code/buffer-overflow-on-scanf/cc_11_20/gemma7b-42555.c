//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char input_buffer[MAX_BUFFER_SIZE];
    char output_buffer[MAX_BUFFER_SIZE];
    int input_length = 0;
    int output_length = 0;
    int i = 0;
    int is_valid = 0;
    int is_hex_digit = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input_buffer);

    input_length = strlen(input_buffer);

    for (i = 0; i < input_length; i++)
    {
        if (input_buffer[i] >= 'a' && input_buffer[i] <= 'f')
        {
            is_hex_digit = 1;
        }
        else if (input_buffer[i] >= 'A' && input_buffer[i] <= 'F')
        {
            is_hex_digit = 1;
        }
        else if (input_buffer[i] >= '0' && input_buffer[i] <= '9')
        {
            is_hex_digit = 1;
        }
        else
        {
            is_valid = 0;
            break;
        }
    }

    if (is_valid)
    {
        for (i = 0; i < input_length; i++)
        {
            output_buffer[i] = input_buffer[i] - 0x20;
        }

        output_length = input_length;

        printf("Converted hexadecimal number: ");
        for (i = 0; i < output_length; i++)
        {
            printf("%c ", output_buffer[i]);
        }

        printf("\n");
    }
    else
    {
        printf("Invalid input.\n");
    }

    return 0;
}