//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: satisfied
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

    // Get the input from the user
    printf("Enter a hexadecimal number: ");
    scanf("%s", input_buffer);

    // Calculate the length of the input
    input_length = strlen(input_buffer);

    // Convert the input to uppercase
    for (i = 0; i < input_length; i++)
    {
        input_buffer[i] = toupper(input_buffer[i]);
    }

    // Convert the input to hexadecimal
    output_length = convert_hex_to_decimal(input_buffer, output_buffer);

    // Print the output
    printf("The decimal equivalent of the input hexadecimal number is: ");
    for (i = 0; i < output_length; i++)
    {
        printf("%d ", output_buffer[i]);
    }

    printf("\n");

    return 0;
}

int convert_hex_to_decimal(char *hex_number, char *decimal_number)
{
    int i = 0;
    int decimal_value = 0;
    int digit_value = 0;

    // Calculate the length of the input
    int length = strlen(hex_number);

    // Iterate over the input and convert each digit to decimal
    for (i = length - 1; i >= 0; i--)
    {
        // Get the digit value
        digit_value = hex_number[i] - '0';

        // Multiply the digit value by the appropriate power of 16 and add it to the decimal value
        decimal_value += digit_value * pow(16, length - i - 1);
    }

    // Copy the decimal value to the output buffer
    decimal_number[0] = decimal_value;

    // Return the length of the output buffer
    return 1;
}