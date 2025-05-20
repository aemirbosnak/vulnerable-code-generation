//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    double temperature;
    int choice;
    char *unit;

    printf("Welcome to the Temperature Monitor!\n");
    printf("Please select a unit of measurement:\n");
    printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            unit = "Celsius";
            break;
        case 2:
            unit = "Fahrenheit";
            break;
        case 3:
            unit = "Kelvin";
            break;
        default:
            printf("Invalid choice. Exiting program.\n");
            return 1;
    }

    while(1)
    {
        printf("Enter current temperature: ");
        scanf("%lf", &temperature);

        if(choice == 1)
        {
            temperature = (temperature - 32) * 5/9;
            printf("Current temperature is %.2lf %s.\n", temperature, unit);
        }
        else if(choice == 2)
        {
            temperature = (temperature * 9/5) + 32;
            printf("Current temperature is %.2lf %s.\n", temperature, unit);
        }
        else if(choice == 3)
        {
            temperature += 273.15;
            printf("Current temperature is %.2lf %s.\n", temperature, unit);
        }
        else
        {
            printf("Invalid choice. Exiting program.\n");
            return 1;
        }

        printf("Do you want to continue monitoring? (y/n): ");
        char continue_monitoring;
        scanf(" %c", &continue_monitoring);

        if(continue_monitoring == 'n' || continue_monitoring == 'N')
        {
            break;
        }
    }

    printf("Exiting program.\n");
    return 0;
}