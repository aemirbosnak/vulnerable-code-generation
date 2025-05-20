//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToHex(int decimalValue)
{
    char hexadecimal[30];
    int remainder;
    int i = 0;

    while (decimalValue != 0)
    {
        remainder = decimalValue % 16;

        if (remainder < 10)
        {
            hexadecimal[i] = remainder + 48;
            i++;
        }
        else
        {
            hexadecimal[i] = remainder + 55;
            i++;
        }

        decimalValue = decimalValue / 16;
    }

    if (i == 0)
    {
        printf("The hexadecimal value is: 0\n");
    }
    else
    {
        printf("The hexadecimal value is: ");

        for (int j = i - 1; j >= 0; j--)
        {
            printf("%c", hexadecimal[j]);
        }
        printf("\n");
    }
}

int main()
{
    int decimalValue;
    printf("Enter a decimal value to convert to hexadecimal: ");
    scanf("%d", &decimalValue);

    if (decimalValue < 0)
    {
        printf("Invalid input. Please enter a positive decimal value.\n");
        return 0;
    }

    convertToHex(decimalValue);

    return 0;
}