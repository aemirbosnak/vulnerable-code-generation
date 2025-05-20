//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, temp, type;
    float conversion;

    system("clear");
    printf("----------------------------------------------------\n");
    printf("WELCOME TO THE FUTURE OF TEMPERATURE CONVERSION!\n");
    printf("----------------------------------------------------\n");
    printf("Please select an option:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the temperature in Fahrenheit:");
            scanf("%d", &temp);
            conversion = (temp - 32) * 5 / 9;
            printf("The temperature in Celsius is: %.2f", conversion);
            break;
        case 2:
            printf("Enter the temperature in Celsius:");
            scanf("%d", &temp);
            conversion = (temp * 9 / 5) + 32;
            printf("The temperature in Fahrenheit is: %.2f", conversion);
            break;
        case 3:
            printf("Enter the temperature in Kelvin:");
            scanf("%d", &temp);
            conversion = temp - 273.15;
            printf("The temperature in Celsius is: %.2f", conversion);
            break;
        case 4:
            printf("Enter the temperature in Celsius:");
            scanf("%d", &temp);
            conversion = temp + 273.15;
            printf("The temperature in Kelvin is: %.2f", conversion);
            break;
        default:
            printf("Invalid choice!");
            break;
    }

    system("pause");
}