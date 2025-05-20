//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[100];
    int i, j, len;
    char hex[200];

    // Prompt user for input
    printf("Enter a hexadecimal number: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    len = strlen(input);
    if (input[len - 1] == '\n')
    {
        input[len - 1] = '\0';
        len--;
    }

    // Convert input to uppercase
    for (i = 0; i < len; i++)
    {
        input[i] = toupper(input[i]);
    }

    // Convert hexadecimal to decimal
    j = 0;
    for (i = 0; i < len; i++)
    {
        if (isdigit(input[i]))
        {
            hex[j] = input[i];
            j++;
        }
        else if (isalpha(input[i]))
        {
            if (isupper(input[i]))
            {
                hex[j] = input[i] - 55;
            }
            else
            {
                hex[j] = input[i] - 48;
            }
            j++;
        }
        else
        {
            printf("Invalid character found.\n");
            return 0;
        }
    }

    // Convert decimal to binary
    for (i = 0; i < j; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            if (hex[i] & (1 << k))
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
    }

    return 0;
}