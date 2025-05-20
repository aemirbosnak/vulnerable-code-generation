//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Hexadecimal Converter!\n");
    printf("Enter a decimal number: ");
    int decimal;
    scanf("%d", &decimal);

    char hex[100];
    int remainder;
    int count = 0;

    while (decimal != 0)
    {
        remainder = decimal % 16;
        if (remainder < 10)
        {
            hex[count] = 48 + remainder;
        }
        else
        {
            hex[count] = 55 + remainder;
        }
        count++;
        decimal /= 16;
    }

    printf("The hexadecimal conversion is: ");
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%c", hex[i]);
    }
    printf("\n");

    printf("Would you like to convert another number?(Y/N) ");
    char answer;
    scanf(" %c", &answer);

    if (answer == 'Y' || answer == 'y')
    {
        system("clear");
        main(); //recursive call to main function
    }
    else
    {
        printf("Thank you for using the Hexadecimal Converter!\n");
        return 0;
    }
}