//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: puzzling
#include<stdio.h>
#include<string.h>

// Function to convert decimal to hexadecimal
char *decimalToHex(int num)
{
    char *hex = (char *)malloc(2 * sizeof(char));
    if(hex == NULL)
        return NULL;
    int i, n;
    char *p;
    for(i = 15; i >= 0; i--)
    {
        n = num % 16;
        if(n < 10)
            hex[1] = n + '0';
        else
            hex[1] = n + 'a' - 10;
        num = num / 16;
    }
    p = hex;
    while(*p!= '\0')
    {
        *p++ = *--hex;
    }
    return hex;
}

// Function to convert hexadecimal to decimal
int hexToDecimal(char *num)
{
    int i;
    int decimal = 0;
    for(i = 0; num[i]!= '\0'; i++)
    {
        decimal = decimal * 16 + num[i] - '0';
    }
    return decimal;
}

int main()
{
    char input[100], output[100];
    int decimal, hexadecimal;
    printf("Enter the decimal number: ");
    scanf("%s", input);
    decimal = atoi(input);
    hexadecimal = decimalToHex(decimal);
    if(hexadecimal!= NULL)
    {
        printf("Hexadecimal representation of %d is: %s\n", decimal, hexadecimal);
        free(hexadecimal);
    }
    else
        printf("Invalid decimal number\n");
    printf("Enter the hexadecimal number: ");
    scanf("%s", output);
    hexadecimal = hexToDecimal(output);
    printf("Decimal representation of %s is: %d\n", output, hexadecimal);
    return 0;
}