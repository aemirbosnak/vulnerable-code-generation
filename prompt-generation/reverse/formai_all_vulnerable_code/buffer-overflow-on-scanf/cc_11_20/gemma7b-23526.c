//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char input[MAX_BUFFER_SIZE] = "";
    char output[MAX_BUFFER_SIZE] = "";
    int i = 0;
    int offset = 0;
    int number = 0;
    int is_hex = 0;

    // Get the input from the user
    printf("Enter a number (in hexadecimal): ");
    scanf("%s", input);

    // Check if the input is in hexadecimal format
    for (i = 0; input[i] != '\0'; i++)
    {
        if (!((input[i] >= 'a' && input[i] <= 'f') || (input[i] >= 'A' && input[i] <= 'F') || (input[i] >= '0' && input[i] <= '9')))
        {
            is_hex = 1;
            break;
        }
    }

    // If the input is not in hexadecimal format, display an error message
    if (is_hex)
    {
        printf("Error: Invalid input format.\n");
        return 1;
    }

    // Convert the input to uppercase
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a')
        {
            input[i] -= 32;
        }
    }

    // Calculate the number of digits in the input
    for (i = 0; input[i] != '\0'; i++)
    {
        number++;
    }

    // Calculate the offset
    offset = number / 2;

    // Convert the input to hexadecimal
    for (i = 0; i < number; i++)
    {
        int digit = input[i] - '0';
        int hex_digit = digit / 16;
        int remainder = digit % 16;
        output[i - offset] = '0' + hex_digit;
        output[i - offset - 1] = '0' + remainder;
    }

    // Print the output
    printf("Hexadecimal equivalent: ");
    printf("%s", output);

    return 0;
}