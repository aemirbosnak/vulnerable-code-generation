//FormAI DATASET v1.0 Category: Binary Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num, i, j, temp;
    char bin[32], ans[32];

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    // Convert decimal to binary
    for(i = 0; num > 0; i++)
    {
        bin[i] = num % 2 + '0';
        num /= 2;
    }

    // Reverse binary number and add leading zeros if needed
    j = i - 1;
    for(i = 0; i < j; i++, j--)
    {
        temp = bin[i];
        bin[i] = bin[j];
        bin[j] = temp;
    }
    for(i = strlen(bin); i < 32; i++)
    {
        bin[i] = '0';
    }
    bin[32] = '\0';

    // Convert binary to decimal
    int dec = 0, base = 1;
    for(i = strlen(bin) - 1; i >= 0; i--)
    {
        if(bin[i] == '1')
        {
            dec += base;
        }
        base *= 2;
    }

    // Convert decimal to binary using bitwise operators
    int bits[32];
    for(i = 0; i < 32; i++)
    {
        bits[i] = num & 1;
        num >>= 1;
    }

    // Reverse bits array and add leading zeros if needed
    j = i - 1;
    for(i = 0; i < j; i++, j--)
    {
        temp = bits[i];
        bits[i] = bits[j];
        bits[j] = temp;
    }
    for(i = strlen(bits); i < 32; i++)
    {
        bits[i] = 0;
    }
    bits[32] = '\0';

    // Convert bits array to binary string
    char bitwise[32];
    for(i = 0; i < 32; i++)
    {
        bitwise[i] = bits[i] + '0';
    }
    bitwise[32] = '\0';

    // Display results
    printf("Decimal to Binary conversion:\n");
    printf("Decimal: %d\nBinary: %s\n\n", num, bin);
    printf("Binary to Decimal conversion:\n");
    printf("Binary: %s\nDecimal: %d\n\n", bin, dec);
    printf("Bitwise Binary Conversion:\n");
    printf("Decimal: %d\nBinary: %s\n", num, bitwise);

    return 0;
}