//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char input_buffer[MAX_BUFFER_SIZE];
    char output_buffer[MAX_BUFFER_SIZE];
    int input_length, output_length, i;
    unsigned int number;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input_buffer);

    input_length = strlen(input_buffer);

    // Validate input length
    if (input_length < 1)
    {
        printf("Error: invalid input length.\n");
        return 1;
    }

    // Convert input to uppercase
    for (i = 0; i < input_length; i++)
    {
        input_buffer[i] = toupper(input_buffer[i]);
    }

    // Convert input to number
    number = strtol(input_buffer, NULL, 16);

    // Validate number conversion
    if (number == -1)
    {
        printf("Error: invalid number conversion.\n");
        return 1;
    }

    // Convert number to hexadecimal
    output_length = snprintf(output_buffer, MAX_BUFFER_SIZE, "%x", number);

    // Print output
    printf("Hexadecimal equivalent: ");
    for (i = 0; i < output_length; i++)
    {
        printf("%c ", output_buffer[i]);
    }

    printf("\n");

    return 0;
}