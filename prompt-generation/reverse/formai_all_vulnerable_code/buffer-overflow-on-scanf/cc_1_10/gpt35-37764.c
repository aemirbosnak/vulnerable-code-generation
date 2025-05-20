//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: random
#include <stdio.h>
#include <string.h>

// A function to convert a single character from hexadecimal to decimal
int charToDec(char c)
{
    if(c>='0' && c<='9')
        return c-'0';
    else if(c>='A' && c<='F')
        return 10+c-'A';
    else if(c>='a' && c<='f')
        return 10+c-'a';
    else
        return -1;
}

// A function to convert a hexadecimal string to decimal integer
int hexToDec(char *hex)
{
    int len = strlen(hex);
    int dec = 0, base = 1;

    for(int i=len-1;i>=0;i--)
    {
        // Check if the character is valid hexadecimal character
        int num = charToDec(hex[i]);
        if(num == -1)
            return -1;
        
        dec += num*base;
        base *= 16;
    }

    return dec;
}

// A function to convert a single decimal digit to hexadecimal character
char decToChar(int d)
{
    if(d>=0 && d<=9)
        return d+'0';
    else if(d>=10 && d<=15)
        return d-10+'A';
    else
        return ' ';
}

// A function to convert a decimal integer to hexadecimal string
void decToHex(int dec, char *hex)
{
    int i=0;

    while(dec>0)
    {
        hex[i++] = decToChar(dec%16);
        dec /= 16;
    }

    hex[i] = '\0';

    // Reverse the string
    int len = strlen(hex);
    for(i=0;i<len/2;i++)
    {
        char temp = hex[i];
        hex[i] = hex[len-1-i];
        hex[len-1-i] = temp;
    }
}

// The main function
int main()
{
    char hex[100];
    int dec;

    // Testing the hexToDec function
    printf("Enter a hexadecimal string: ");
    scanf("%s",hex);
    dec = hexToDec(hex);
    if(dec == -1)
        printf("Invalid hexadecimal string\n");
    else
        printf("Decimal equivalent is %d\n",dec);

    // Testing the decToHex function
    printf("Enter a decimal integer: ");
    scanf("%d",&dec);
    decToHex(dec,hex);
    printf("Hexadecimal equivalent is %s\n",hex);

    return 0;
}