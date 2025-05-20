//FormAI DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>

double convertToFahrenheit(double tempCelsius);
double convertToCelsius(double tempFahrenheit);
double convertToKelvin(double tempCelsius);
double convertToRankine(double tempFahrenheit);

int main()
{
    double temp;
    char choice;

    printf("Welcome to the temperature converter!\n");
    printf("Please choose the type of temperature you want to convert (C/F/K/R):\n");
    scanf("%c", &choice);

    switch(choice)
    {
        case 'C':
            printf("Please enter the temperature in Celsius:\n");
            scanf("%lf", &temp);

            printf("%.2lf Celsius = %.2lf Fahrenheit\n", temp, convertToFahrenheit(temp));
            printf("%.2lf Celsius = %.2lf Kelvin\n", temp, convertToKelvin(temp));
            printf("%.2lf Celsius = %.2lf Rankine\n", temp, convertToRankine(convertToFahrenheit(temp)));
            break;
        case 'F':
            printf("Please enter the temperature in Fahrenheit:\n");
            scanf("%lf", &temp);

            printf("%.2lf Fahrenheit = %.2lf Celsius\n", temp, convertToCelsius(temp));
            printf("%.2lf Fahrenheit = %.2lf Kelvin\n", temp, convertToKelvin(convertToCelsius(temp)));
            printf("%.2lf Fahrenheit = %.2lf Rankine\n", temp, convertToRankine(temp));
            break;
        case 'K':
            printf("Please enter the temperature in Kelvin:\n");
            scanf("%lf", &temp);

            printf("%.2lf Kelvin = %.2lf Celsius\n", temp, convertToCelsius(temp));
            printf("%.2lf Kelvin = %.2lf Fahrenheit\n", temp, convertToFahrenheit(convertToCelsius(temp)));
            printf("%.2lf Kelvin = %.2lf Rankine\n", temp, convertToRankine(convertToFahrenheit(convertToCelsius(temp))));
            break;
        case 'R':
            printf("Please enter the temperature in Rankine:\n");
            scanf("%lf", &temp);

            printf("%.2lf Rankine = %.2lf Celsius\n", temp, convertToCelsius(convertToFahrenheit(temp)));
            printf("%.2lf Rankine = %.2lf Fahrenheit\n", temp, convertToFahrenheit(temp));
            printf("%.2lf Rankine = %.2lf Kelvin\n", temp, convertToKelvin(convertToCelsius(convertToFahrenheit(temp))));
            break;
        default:
            printf("Invalid choice! Please choose between C/F/K/R.\n");
            break;
    }

    return 0;
}

double convertToFahrenheit(double tempCelsius)
{
    double tempFahrenheit = (tempCelsius * 9 / 5) + 32;
    return tempFahrenheit;
}

double convertToCelsius(double tempFahrenheit)
{
    double tempCelsius = (tempFahrenheit - 32) * 5 / 9;
    return tempCelsius;
}

double convertToKelvin(double tempCelsius)
{
    double tempKelvin = tempCelsius + 273.15;
    return tempKelvin;
}

double convertToRankine(double tempFahrenheit)
{
    double tempRankine = tempFahrenheit + 459.67;
    return tempRankine;
}