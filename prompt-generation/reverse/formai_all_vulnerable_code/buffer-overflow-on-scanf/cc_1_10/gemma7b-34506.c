//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[10], output[10], tmp[10];
    int i, num, hex_val, offset = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    // Convert the input string to uppercase
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a')
            input[i] -= 32;
    }

    // Validate the input
    if (input[0] != '0' && input[0] != '0x')
    {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    // Convert the input to an integer
    num = strtol(input, NULL, 16);

    // Convert the integer to a hexadecimal string
    hex_val = num / 16;
    sprintf(output, "%x", hex_val);
    offset = strlen(output);

    // Convert the remaining digits to hexadecimal
    hex_val = num % 16;
    sprintf(tmp, "%x", hex_val);
    strcat(output, tmp);

    // Pad the output with zeros if necessary
    if (offset < 2)
    {
        for (i = 0; i < 2 - offset; i++)
            strcat(output, "0");
    }

    // Print the hexadecimal number
    printf("Hexadecimal equivalent: %s\n", output);

    return 0;
}