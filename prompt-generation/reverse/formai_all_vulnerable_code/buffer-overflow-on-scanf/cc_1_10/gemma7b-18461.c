//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char input_buffer[MAX_BUFFER_SIZE];
    char output_buffer[MAX_BUFFER_SIZE];
    int input_length = 0;
    int output_length = 0;
    int i = 0;
    int hex_value = 0;

    // Get input from the user
    printf("Enter a hexadecimal number: ");
    scanf("%s", input_buffer);

    // Calculate the length of the input
    input_length = strlen(input_buffer);

    // Convert the input to uppercase
    for (i = 0; i < input_length; i++)
    {
        input_buffer[i] = toupper(input_buffer[i]);
    }

    // Validate the input
    if (input_length % 2 != 0)
    {
        printf("Error: Invalid input format.\n");
        return 1;
    }

    // Convert the input to hexadecimal digits
    for (i = 0; i < input_length; i++)
    {
        hex_value = input_buffer[i] - 'A' + 10;
        output_buffer[output_length++] = '0' + hex_value / 16;
        output_buffer[output_length++] = '0' + hex_value % 16;
    }

    // Print the output
    printf("Hexadecimal equivalent: ");
    for (i = 0; i < output_length; i++)
    {
        printf("%c ", output_buffer[i]);
    }

    printf("\n");

    return 0;
}