//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: expert-level
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
    int num = 0;
    int decimal = 0;
    int binary = 0;
    int flag = 0;

    printf("Enter a binary number: ");
    scanf("%s", input_buffer);

    input_length = strlen(input_buffer);

    for (i = 0; i < input_length; i++)
    {
        if (input_buffer[i] >= 'a' && input_buffer[i] <= 'f')
        {
            flag = 1;
        }
    }

    if (flag)
    {
        printf("Error: Invalid input.\n");
        exit(1);
    }

    for (i = 0; i < input_length; i++)
    {
        num = input_buffer[i] - '0';
        decimal = decimal * 2 + num;
    }

    binary = decimal;

    while (binary)
    {
        output_buffer[output_length++] = (binary % 2) + '0';
        binary /= 2;
    }

    output_buffer[output_length] = '\0';

    printf("The binary number is: ");

    for (i = output_length - 1; i >= 0; i--)
    {
        printf("%c ", output_buffer[i]);
    }

    printf("\n");

    return 0;
}