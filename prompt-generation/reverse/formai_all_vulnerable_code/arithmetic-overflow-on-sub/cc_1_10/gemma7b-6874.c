//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, num, i, flag = 0;
    float converted_num;

    system("clear");

    printf("\n\t\t\tWelcome to the Crazy Temperature Converter!\n");
    printf("\t\t\tPlease select an option:\n");
    printf("\t\t\t1. Convert Fahrenheit to Celsius\n");
    printf("\t\t\t2. Convert Celsius to Fahrenheit\n");
    printf("\t\t\t3. Convert Kelvin to Fahrenheit\n");
    printf("\t\t\t4. Convert Kelvin to Celsius\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("\t\t\tEnter the temperature in Fahrenheit:");
            scanf("%d", &num);
            converted_num = (num - 32) * 5 / 9;
            printf("\t\t\tThe temperature in Celsius is: %.2f", converted_num);
            break;

        case 2:
            printf("\t\t\tEnter the temperature in Celsius:");
            scanf("%d", &num);
            converted_num = (num * 9 / 5) + 32;
            printf("\t\t\tThe temperature in Fahrenheit is: %.2f", converted_num);
            break;

        case 3:
            printf("\t\t\tEnter the temperature in Kelvin:");
            scanf("%d", &num);
            converted_num = (num - 273) * 1.8 + 32;
            printf("\t\t\tThe temperature in Fahrenheit is: %.2f", converted_num);
            break;

        case 4:
            printf("\t\t\tEnter the temperature in Kelvin:");
            scanf("%d", &num);
            converted_num = (num - 273) * 1.8 + 0;
            printf("\t\t\tThe temperature in Celsius is: %.2f", converted_num);
            break;

        default:
            printf("\t\t\tInvalid input. Please try again.");
            flag = 1;
            break;
    }

    if (flag == 0)
    {
        system("pause");
    }
}