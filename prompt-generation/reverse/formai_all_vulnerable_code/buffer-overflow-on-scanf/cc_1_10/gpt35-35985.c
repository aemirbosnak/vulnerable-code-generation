//FormAI DATASET v1.0 Category: Temperature Converter ; Style: recursive
#include <stdio.h>

double celsius_to_fahrenheit(double);
double fahrenheit_to_celsius(double);

int main()
{
    int option;
    double temp;
    printf("Temperature Converter\n");
    do
    {
        printf("Enter 1 to convert Celsius to Fahrenheit\n");
        printf("Enter 2 to convert Fahrenheit to Celsius\n");
        printf("Enter any other number to exit\n");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temp);
                printf("%.2lf Celsius = %.2lf Fahrenheit\n", temp, celsius_to_fahrenheit(temp));
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temp);
                printf("%.2lf Fahrenheit = %.2lf Celsius\n", temp, fahrenheit_to_celsius(temp));
                break;
            default:
                printf("Exiting...");
                break;
        }
    } while (option == 1 || option == 2);
    return 0;
}

double celsius_to_fahrenheit(double celsius)
{
    if (celsius == -273.15)    // Absolute zero
    {
        printf("Error: Temperature can't be lower than absolute zero (-273.15 Celsius)\n");
    }
    else if (celsius < -273.15)    // Lower than absolute zero
    {
        return celsius_to_fahrenheit(celsius + 1);
    }
    else    // Normal temperature
    {
        return (celsius * 9 / 5) + 32;
    }
}

double fahrenheit_to_celsius(double fahrenheit)
{
    if (fahrenheit == -459.67)    // Absolute zero
    {
        printf("Error: Temperature can't be lower than absolute zero (-459.67 Fahrenheit)\n");
    }
    else if (fahrenheit < -459.67)    // Lower than absolute zero
    {
        return fahrenheit_to_celsius(fahrenheit + 1);
    }
    else    // Normal temperature
    {
        return (fahrenheit - 32) * 5 / 9;
    }
}