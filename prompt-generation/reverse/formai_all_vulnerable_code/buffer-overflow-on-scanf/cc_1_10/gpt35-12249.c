//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: real-life
#include <stdio.h>
#include <string.h>

/* Function to convert hexadecimal to decimal */
int hexToDec(char hex[])
{
    int len = strlen(hex);
    int base = 1;
    int dec = 0;
    int i;

    for (i = len-1; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            dec += (hex[i] - 48) * base;
            base *= 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            dec += (hex[i] - 87) * base;
            base *= 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            dec += (hex[i] - 55) * base;
            base *= 16;
        }
        else
        {
            printf("Invalid hexadecimal input.");
            return 0;
        }
    }

    return dec;
}

int main()
{
    char hex[100];
    int dec;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    dec = hexToDec(hex);

    printf("The decimal equivalent of %s is: %d", hex, dec);

    return 0;
}