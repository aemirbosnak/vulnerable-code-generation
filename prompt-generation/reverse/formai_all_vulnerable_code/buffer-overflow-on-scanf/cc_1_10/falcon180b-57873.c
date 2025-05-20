//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int choice;
    float temp, converted_temp;
    char unit[10];

    printf("Welcome to the Temperature Converter!\n");
    printf("Enter the temperature value: ");
    scanf("%f", &temp);
    printf("Enter the unit of temperature (Celsius/Fahrenheit/Kelvin): ");
    scanf("%s", unit);

    if (strcmp(unit, "Celsius") == 0)
    {
        printf("Enter the unit you want to convert to (Fahrenheit/Kelvin): ");
        scanf("%s", unit);

        if (strcmp(unit, "Fahrenheit") == 0)
        {
            converted_temp = (temp * 9/5) + 32;
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temp, converted_temp);
        }
        else if (strcmp(unit, "Kelvin") == 0)
        {
            converted_temp = temp + 273.15;
            printf("%.2f degrees Celsius is equal to %.2f Kelvin.\n", temp, converted_temp);
        }
        else
        {
            printf("Invalid unit!\n");
        }
    }
    else if (strcmp(unit, "Fahrenheit") == 0)
    {
        printf("Enter the unit you want to convert to (Celsius/Kelvin): ");
        scanf("%s", unit);

        if (strcmp(unit, "Celsius") == 0)
        {
            converted_temp = (temp - 32) * 5/9;
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temp, converted_temp);
        }
        else if (strcmp(unit, "Kelvin") == 0)
        {
            converted_temp = (temp + 459.67) * 5/9;
            printf("%.2f degrees Fahrenheit is equal to %.2f Kelvin.\n", temp, converted_temp);
        }
        else
        {
            printf("Invalid unit!\n");
        }
    }
    else if (strcmp(unit, "Kelvin") == 0)
    {
        printf("Enter the unit you want to convert to (Celsius/Fahrenheit): ");
        scanf("%s", unit);

        if (strcmp(unit, "Celsius") == 0)
        {
            converted_temp = temp - 273.15;
            printf("%.2f Kelvin is equal to %.2f degrees Celsius.\n", temp, converted_temp);
        }
        else if (strcmp(unit, "Fahrenheit") == 0)
        {
            converted_temp = (temp * 9/5) - 459.67;
            printf("%.2f Kelvin is equal to %.2f degrees Fahrenheit.\n", temp, converted_temp);
        }
        else
        {
            printf("Invalid unit!\n");
        }
    }
    else
    {
        printf("Invalid unit!\n");
    }

    return 0;
}