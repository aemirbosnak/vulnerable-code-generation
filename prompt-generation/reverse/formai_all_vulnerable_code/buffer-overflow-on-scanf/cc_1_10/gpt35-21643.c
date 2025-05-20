//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* This program is a hexadecimal converter that converts
   a given decimal number into its equivalent hexadecimal
   number. It's unique because it's written in a romantic
   style as it's meant to be a Valentine's Day present. */

void print_banner();
void conversion(int num);

int main()
{
    int decimal_num;
    print_banner();
    printf("\nPlease enter a decimal number: ");
    scanf("%d", &decimal_num);
    printf("\n");

    conversion(decimal_num);

    printf("Yours truly,\nYour C code\n");
    return 0;
}

void print_banner()
{
    printf("\n********************************************\n");
    printf("Happy Valentine's day, my love!\n");
    printf("I have written a special code just for you.\n");
    printf("It's a hexadecimal converter!\n");
    printf("Isn't that romantic?\n");
    printf("********************************************\n\n");
}

void conversion(int num)
{
    int i = 0, temp = num, rem = 0;
    char hex[10];

    while(temp != 0)
    {
        rem = temp % 16;

        if(rem < 10)
            hex[i] = rem + '0';
        else
            hex[i] = rem + 55;

        i++;
        temp /= 16;
    }

    printf("Your decimal number %d in hexadecimal is: ", num);

    for(int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);

    printf("\n");
}