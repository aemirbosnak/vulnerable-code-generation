//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char input_buffer[MAX_BUFFER_SIZE];
    char output_buffer[MAX_BUFFER_SIZE];
    int input_length = 0;
    int output_length = 0;
    int i = 0;
    int j = 0;
    int num = 0;
    int is_hex = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input_buffer);

    input_length = strlen(input_buffer);

    for (i = 0; i < input_length; i++)
    {
        if (input_buffer[i] >= 'a' && input_buffer[i] <= 'f')
        {
            is_hex = 1;
        }
    }

    if (is_hex)
    {
        for (i = 0; i < input_length; i++)
        {
            num = input_buffer[i] - 'a' + 10;
            output_buffer[j] = num >> 4 & 0xf;
            output_buffer[j + 1] = num & 0xf;
            j += 2;
        }
    }
    else
    {
        printf("Error: Invalid input.\n");
    }

    printf("Converted hexadecimal number: ");
    for (i = 0; i < output_length; i++)
    {
        printf("%x ", output_buffer[i]);
    }

    printf("\n");

    return 0;
}