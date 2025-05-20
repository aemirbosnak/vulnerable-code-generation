//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char buff[1024];
    int i = 0;
    long num = 0;
    char unit = ' ';
    char flag = 'N';

    while (flag != 'Y')
    {
        printf("Enter the temperature: ");
        fgets(buff, 1024, stdin);

        for (i = 0; buff[i] != '\0'; i++)
        {
            if (isdigit(buff[i]))
            {
                num = num * 10 + buff[i] - '0';
            }
            else if (buff[i] == 'F' || buff[i] == 'C')
            {
                unit = buff[i];
            }
        }

        switch (unit)
        {
            case 'F':
                num = (num - 32) * 5 / 9;
                printf("The temperature in Celsius is: %.2lf\n", num);
                break;
            case 'C':
                num = (num * 9 / 5) + 32;
                printf("The temperature in Fahrenheit is: %.2lf\n", num);
                break;
            default:
                printf("Invalid unit.\n");
                break;
        }

        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &flag);
    }

    return;
}