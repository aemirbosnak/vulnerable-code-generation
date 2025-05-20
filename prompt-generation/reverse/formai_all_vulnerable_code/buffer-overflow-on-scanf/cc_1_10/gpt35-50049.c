//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: detailed
#include <stdio.h>
#include <string.h>

void reverse(char *str);

int main()
{
    int num;
    char hex[16];
    char hex_reverse[16];
    
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    
    // convert decimal to hexadecimal
    int i = 0;
    do
    {
        int rem = num % 16;
        if (rem < 10)
        {
            hex[i++] = rem + '0';
        }
        else
        {
            hex[i++] = rem - 10 + 'A';
        }
        num /= 16;
    } while (num != 0);
    hex[i] = '\0';
    
    // reverse the hexadecimal number
    strcpy(hex_reverse, hex);
    reverse(hex_reverse);
    
    // print the results
    printf("The hexadecimal equivalent is: %s\n", hex_reverse);
    
    return 0;
}

void reverse(char *str)
{
    int length = strlen(str);
    int i;
    for (i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}