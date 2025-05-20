//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 1000

void decimal_to_hexadecimal(long int decimal_input);
long int hexadecimal_to_decimal(char *hexadecimal_input);

int main()
{
    char input[MAX_DIGITS];
    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    // Check if the input is valid
    for (int i = 0; i < strlen(input); i++)
    {
        if (!((input[i] >= '0' && input[i] <= '9') || (input[i] >= 'a' && input[i] <= 'f') || (input[i] >= 'A' && input[i] <= 'F')))
        {
            printf("Invalid input! Please enter a hexadecimal number.\n");
            return 0;
        }
    }
    
    // Convert hexadecimal to decimal
    long int decimal_output = hexadecimal_to_decimal(input);
    printf("Decimal equivalent: %ld\n", decimal_output);

    // Convert decimal to hexadecimal
    printf("Hexadecimal equivalent: ");
    decimal_to_hexadecimal(decimal_output);

    return 0;
}

void decimal_to_hexadecimal(long int decimal_input)
{
    char hexadecimal_output[MAX_DIGITS];
    int index = 0;

    while (decimal_input != 0)
    {
        int rem = decimal_input % 16;
        if (rem < 10)
            hexadecimal_output[index++] = rem + 48; // Add 48 for ASCII value of digits 0-9
        else
            hexadecimal_output[index++] = rem + 55; // Add 55 for ASCII value of alphabets A-F
        decimal_input /= 16;
    }

    // Print the hexadecimal output in reverse order
    for (int i = index - 1; i >= 0; i--)
        printf("%c", hexadecimal_output[i]);
    printf("\n");
}

long int hexadecimal_to_decimal(char *hexadecimal_input)
{
    int length = strlen(hexadecimal_input);
    long int decimal_output = 0;
    int base = 1;

    for (int i = length - 1; i >= 0; i--)
    {
        if (hexadecimal_input[i] >= '0' && hexadecimal_input[i] <= '9')
        {
            decimal_output += (hexadecimal_input[i] - 48) * base; // Subtract 48 for ASCII value of digits 0-9
            base *= 16;
        }
        else if (hexadecimal_input[i] >= 'A' && hexadecimal_input[i] <= 'F')
        {
            decimal_output += (hexadecimal_input[i] - 55) * base; // Subtract 55 for ASCII value of alphabets A-F
            base *= 16;
        }
        else if (hexadecimal_input[i] >= 'a' && hexadecimal_input[i] <= 'f')
        {
            decimal_output += (hexadecimal_input[i] - 87) * base; // Subtract 87 for ASCII value of alphabets a-f
            base *= 16;
        }
    }
    return decimal_output;
}