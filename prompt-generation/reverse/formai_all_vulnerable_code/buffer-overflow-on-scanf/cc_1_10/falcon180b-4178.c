//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void convert(char hex[], char dec[]);

int main()
{
    char hex[100], dec[100];
    int i, j;

    printf("Enter hexadecimal number: ");
    scanf("%s", hex);

    printf("Hexadecimal number: %s\n", hex);
    printf("Decimal number: ");

    for(i=0,j=0; hex[i]!= '\0'; i++)
    {
        if(isdigit(hex[i]))
        {
            dec[j++] = hex[i];
        }
        else if(isalpha(hex[i]))
        {
            if(isupper(hex[i]))
            {
                dec[j++] = hex[i] + 55;
            }
            else
            {
                dec[j++] = hex[i] + 48;
            }
        }
        else
        {
            printf("Invalid hexadecimal number!\n");
            return 0;
        }
    }

    dec[j] = '\0';
    printf("%s\n", dec);

    return 0;
}

void convert(char hex[], char dec[])
{
    int i, j=0;

    for(i=0; hex[i]!= '\0'; i++)
    {
        if(isdigit(hex[i]))
        {
            dec[j++] = hex[i];
        }
        else if(isalpha(hex[i]))
        {
            if(isupper(hex[i]))
            {
                dec[j++] = hex[i] + 55;
            }
            else
            {
                dec[j++] = hex[i] + 48;
            }
        }
        else
        {
            printf("Invalid hexadecimal number!\n");
            return;
        }
    }

    dec[j] = '\0';
}