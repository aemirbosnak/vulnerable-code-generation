//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char *argv[])
{
    char input[100];
    char hex[100];
    char dec[100];
    char oct[100];
    int i, j;
    int flag = 0;

    printf("Enter a valid hexadecimal, decimal or octal number: ");
    scanf("%s", input);

    if(isdigit(input[0]))
    {
        if(input[0] == '0' && input[1] == 'x')
        {
            strcpy(hex, input);
            strcat(hex, "0");
            printf("Hexadecimal: %s\n", hex);
            flag = 1;
        }
        else
        {
            strcpy(dec, input);
            printf("Decimal: %s\n", dec);
            flag = 1;
        }
    }
    else if(input[0] == '0')
    {
        strcpy(oct, input);
        printf("Octal: %s\n", oct);
        flag = 1;
    }
    else
    {
        printf("Invalid input!\n");
    }

    if(flag == 0)
    {
        for(i = 0, j = strlen(input) - 1; i < j; i++, j--)
        {
            hex[i] = input[j];
            dec[i] = input[j] - '0';
            oct[i] = input[j] - '0';
        }
        hex[i] = '\0';
        dec[i] = '\0';
        oct[i] = '\0';

        printf("Hexadecimal: %s\n", hex);
        printf("Decimal: %s\n", dec);
        printf("Octal: %s\n", oct);
    }

    return 0;
}