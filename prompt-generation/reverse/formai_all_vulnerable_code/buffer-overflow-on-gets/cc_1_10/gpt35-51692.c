//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 100
 
/*
 * Function to convert hexadecimal to decimal
 */
int hexToDec(char hex[])
{
    int len = strlen(hex);
    int base = 1;
    int dec = 0;
    int i;
 
    for (i = len - 1; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            dec += (hex[i] - 48) * base;
            base = base * 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            dec += (hex[i] - 87) * base;
            base = base * 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            dec += (hex[i] - 55) * base;
            base = base * 16;
        }
    }
 
    return dec;
}
 
/*
 * Function to convert decimal to hexadecimal
 */
char *decToHex(int dec)
{
    int rem[MAX], i = 0, len = 0;
    char *hex = (char*) malloc (sizeof(char) * MAX);
 
    while (dec != 0)
    {
        rem[i] = dec % 16;
        dec = dec / 16;
        i++;
        len++;
    }
 
    for (i = len - 1; i >= 0; i--)
    {
        if (rem[i] >= 0 && rem[i] <= 9)
        {
            hex[len - i - 1] = rem[i] + 48;
        }
        else
        {
            hex[len - i - 1] = rem[i] + 55;
        }
    }
 
    hex[len] = '\0';
 
    return hex;
}
 
/*
 * Main Function
 */
int main()
{
    char hex[MAX];
    int dec;
    printf("Enter the hexadecimal number: ");
    gets(hex);
 
    dec = hexToDec(hex);
 
    printf("Decimal equivalent = %d\n", dec);
    printf("Hexadecimal equivalent = %s\n", decToHex(dec));
 
    return 0;
}