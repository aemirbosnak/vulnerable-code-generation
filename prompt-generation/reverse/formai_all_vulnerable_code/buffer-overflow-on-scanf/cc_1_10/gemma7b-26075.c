//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: grateful
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
            printf("Invalid input.\n");
            return 1;
        }

        num = num * 16 + hex_value;

        output_buffer[output_length++] = num;
    }

    printf("Converted hexadecimal number: ");

    for (j = 0; j < output_length; j++)
    {
        printf("%x ", output_buffer[j]);
    }

    printf("\n");

    return 0;
}