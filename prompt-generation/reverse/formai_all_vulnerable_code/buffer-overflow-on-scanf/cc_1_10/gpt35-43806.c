//FormAI DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive function to convert a decimal number to its hexadecimal equivalent
void dec2hex(int n)
{
    int rem;
    char hex[100];

    if (n == 0)
    {
        printf("0x");
        return;
    }
    else
    {
        rem = n % 16;
        n /= 16;
        dec2hex(n);
    }

    // Convert remainder to hexadecimal and store it in the array
    if (rem < 10)
    {
        hex[strlen(hex)] = rem + 48;
    }
    else
    {
        hex[strlen(hex)] = rem + 55;
    }

    // If it is the first digit, print "0x" before the result
    if (strlen(hex) == 1)
    {
        printf("0x");
    }

    // Print the result
    printf("%c", hex[strlen(hex) - 1]);
}

// Recursive function to convert a decimal number to its rgb equivalent
void dec2rgb(int n, char *rgb)
{
    int rem;

    if (n == 0)
    {
        return;
    }
    else
    {
        rem = n % 256;
        n /= 256;
        dec2rgb(n, rgb);
    }

    // Convert remainder to decimal and store it in the array
    char rem_str[10];
    sprintf(rem_str, "%d", rem);
    strcat(rgb, rem_str);

    if (strlen(rgb) < 9)
    {
        strcat(rgb, ",");
    }
}

// Main function to call the conversion functions
int main()
{
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);

    // Convert decimal to hexadecimal
    printf("The hexadecimal equivalent of %d is ", n);
    dec2hex(n);
    printf("\n");

    // Convert decimal to rgb
    char rgb[30] = "";
    dec2rgb(n, rgb);
    printf("The rgb equivalent of %d is (%s)\n", n, rgb);

    return 0;
}