//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char input_buffer[MAX_BUFFER_SIZE];
    char output_buffer[MAX_BUFFER_SIZE];
    int input_length = 0;
    int output_length = 0;
    int i = 0;
    int j = 0;
    int hex_value = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input_buffer);

    input_length = strlen(input_buffer);

    for (i = 0; i < input_length; i++)
    {
        if (input_buffer[i] >= 'a' && input_buffer[i] <= 'f')
        {
            hex_value = input_buffer[i] - 'a' + 10;
        }
        else if (input_buffer[i] >= 'A' && input_buffer[i] <= 'F')
        {
            hex_value = input_buffer[i] - 'A' + 10;
        }
        else if (input_buffer[i] >= '0' && input_buffer[i] <= '9')
        {
            hex_value = input_buffer[i] - '0';
        }
        else
        {
            printf("Error: Invalid input.\n");
            return 1;
        }

        output_buffer[output_length++] = hex_value << 4 | hex_value & 0xf;
    }

    output_buffer[output_length] = '\0';

    printf("Hexadecimal conversion: %s\n", output_buffer);

    return 0;
}