//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void main()
{
    int choice, num, flag = 0;
    char unit, unit_conv;

    system("clear");
    printf("Welcome to the Ultimate Temperature Converter!\n");
    printf("----------------------------------------\n");

    printf("Please select an option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Convert Kelvin to Celsius\n");
    printf("4. Convert Celsius to Kelvin\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the temperature in Celsius:");
            scanf("%d", &num);
            unit = 'C';
            unit_conv = 'F';
            flag = 1;
            break;
        case 2:
            printf("Enter the temperature in Fahrenheit:");
            scanf("%d", &num);
            unit = 'F';
            unit_conv = 'C';
            flag = 1;
            break;
        case 3:
            printf("Enter the temperature in Kelvin:");
            scanf("%d", &num);
            unit = 'K';
            unit_conv = 'C';
            flag = 1;
            break;
        case 4:
            printf("Enter the temperature in Celsius:");
            scanf("%d", &num);
            unit = 'C';
            unit_conv = 'K';
            flag = 1;
            break;
        default:
            printf("Invalid choice!\n");
            flag = 0;
            break;
    }

    if (flag)
    {
        int converted_num = 0;

        switch (unit_conv)
        {
            case 'F':
                converted_num = (num * 1.8) + 32;
                break;
            case 'K':
                converted_num = num - 273.15;
                break;
        }

        printf("The converted temperature is: %.2f %s\n", converted_num, unit);
    }

    system("pause");
}