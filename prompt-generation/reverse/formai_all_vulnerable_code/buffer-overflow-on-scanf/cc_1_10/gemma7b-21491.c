//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERT_LENGTH 255

int main()
{
    char input_hex[MAX_CONVERT_LENGTH];
    char output_decimal[MAX_CONVERT_LENGTH];
    int input_length = 0;
    int i = 0;
    int converted_value = 0;
    char delimiter = ' ';

    // Get the input hex string from the user
    printf("Enter an hexadecimal string: ");
    scanf("%s", input_hex);

    // Calculate the length of the input string
    input_length = strlen(input_hex);

    // Convert the input string to uppercase
    for (i = 0; i < input_length; i++)
    {
        input_hex[i] = toupper(input_hex[i]);
    }

    // Convert the input string to decimal
    for (i = 0; i < input_length; i++)
    {
        // Check if the character is a letter
        if (input_hex[i] >= 'A' && input_hex[i] <= 'F')
        {
            converted_value += (input_hex[i] - 'A') * 16 + i;
        }
        // Check if the character is a number
        else if (input_hex[i] >= '0' && input_hex[i] <= '9')
        {
            converted_value += (input_hex[i] - '0') * 16 + i;
        }
    }

    // Convert the decimal value to a string
    sprintf(output_decimal, "%d", converted_value);

    // Print the output decimal string
    printf("The decimal equivalent of the input hexadecimal string is: %s\n", output_decimal);

    return 0;
}