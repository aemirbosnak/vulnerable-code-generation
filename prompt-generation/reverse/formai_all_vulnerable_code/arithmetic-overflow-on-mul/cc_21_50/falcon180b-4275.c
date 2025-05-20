//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 1000

int main(void)
{
    char input[MAX_LENGTH];
    char output[MAX_LENGTH * 3];
    int length;
    int i;
    int j;
    int value;
    int hexadecimal;
    int decimal;
    int negative;
    int digit;

    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_LENGTH, stdin);
    length = strlen(input);

    if (length == 0)
    {
        printf("Error: Empty input.\n");
        exit(1);
    }

    if (input[0] == '-')
    {
        negative = 1;
        i = 1;
    }
    else
    {
        negative = 0;
        i = 0;
    }

    while (i < length && input[i]!= '\0')
    {
        digit = tolower(input[i]);
        if (digit < '0' || digit > '9')
        {
            if (digit < 'a' || digit > 'f')
            {
                printf("Error: Invalid character '%c'.\n", digit);
                exit(1);
            }
        }
        i++;
    }

    if (negative)
    {
        i = 0;
        hexadecimal = 0;
        while (i < length)
        {
            digit = tolower(input[i]);
            if (digit < '0' || digit > '9')
            {
                if (digit < 'a' || digit > 'f')
                {
                    printf("Error: Invalid character '%c'.\n", digit);
                    exit(1);
                }
            }
            hexadecimal = hexadecimal * 16 + (digit - '0');
            if (digit < 'a')
            {
                hexadecimal += 10;
            }
            i++;
        }
        decimal = -hexadecimal;
        sprintf(output, "-%X", decimal);
    }
    else
    {
        hexadecimal = 0;
        i = 0;
        while (i < length)
        {
            digit = tolower(input[i]);
            if (digit < '0' || digit > '9')
            {
                if (digit < 'a' || digit > 'f')
                {
                    printf("Error: Invalid character '%c'.\n", digit);
                    exit(1);
                }
            }
            hexadecimal = hexadecimal * 16 + (digit - '0');
            if (digit < 'a')
            {
                hexadecimal += 10;
            }
            i++;
        }
        sprintf(output, "%X", hexadecimal);
    }

    printf("Hexadecimal number: %s\n", output);

    return 0;
}