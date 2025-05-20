//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

int main(int argc, char *argv[])
{
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    int len;
    int i, j;
    int hex_value;

    // Get input from user
    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_SIZE, stdin);

    // Remove newline character from input
    len = strlen(input);
    input[len - 1] = '\0';

    // Validate input
    for (i = 0; i < len; i++)
    {
        if (!isxdigit(input[i]))
        {
            printf("Invalid input. Please enter a valid hexadecimal number.\n");
            return 0;
        }
    }

    // Convert hexadecimal to decimal
    j = 0;
    for (i = len - 1; i >= 0; i--)
    {
        hex_value = tolower(input[i]) - '0';
        if (hex_value < 0 || hex_value > 9)
        {
            hex_value = tolower(input[i]) - 'a' + 10;
        }
        output[j++] = hex_value + '0';
    }

    // Reverse output string
    for (i = 0, j = strlen(output) - 1; i < j; i++, j--)
    {
        char temp = output[i];
        output[i] = output[j];
        output[j] = temp;
    }

    // Add leading zeros if necessary
    while (strlen(output) < 8)
    {
        output[strlen(output)] = '0';
    }

    // Print output
    printf("The decimal equivalent of %s is %s.\n", input, output);

    return 0;
}