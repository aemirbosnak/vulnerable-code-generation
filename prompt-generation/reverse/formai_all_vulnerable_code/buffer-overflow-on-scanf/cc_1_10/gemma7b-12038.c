//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    char output[200];
    int i, j, k, l, num, flag = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    // Check if input is valid
    for (i = 0; input[i] != '\0'; i++)
    {
        if ((input[i] < 'a' || input[i] > 'f') && (input[i] < 'A' || input[i] > 'F'))
        {
            flag = 1;
            break;
        }
    }

    // Convert input to uppercase
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a')
        {
            input[i] -= 32;
        }
    }

    // Calculate number of digits in input
    num = 0;
    for (i = 0; input[i] != '\0'; i++)
    {
        num++;
    }

    // Allocate memory for output
    output[0] = '\0';
    k = 0;

    // Iterate over input digits and convert to hex
    for (i = num - 1; i >= 0; i--)
    {
        l = input[i] - 'a' + 10;
        output[k++] = '0' + l / 16;
        output[k++] = '0' + l % 16;
        output[k++] = ':';
    }

    // Remove trailing colon
    output[k - 1] = '\0';

    // Print output
    printf("Hexadecimal equivalent: %s\n", output);

    return 0;
}