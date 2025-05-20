//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Dennis Ritchie
#include <stdio.h>

// function prototypes
double convert_fahrenheit_to_celsius(double fahrenheit);
double convert_celsius_to_fahrenheit(double celsius);

int main()
{
    int choice;
    double temperature, converted_temperature;

    printf("Welcome to the Temperature Converter!\n\n");
    printf("Please select one of the following options:\n"
           "1. Convert Fahrenheit to Celsius\n"
           "2. Convert Celsius to Fahrenheit\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("\nEnter the temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            converted_temperature = convert_fahrenheit_to_celsius(temperature);
            printf("%f degrees Fahrenheit is %f degrees Celsius\n", temperature, converted_temperature);
            break;
        case 2:
            printf("\nEnter the temperature in Celsius: ");
            scanf("%lf", &temperature);
            converted_temperature = convert_celsius_to_fahrenheit(temperature);
            printf("%f degrees Celsius is %f degrees Fahrenheit\n", temperature, converted_temperature);
            break;
        default:
            printf("\nInvalid choice! Please select 1 or 2.\n");
    }

    return 0;
}

/**
 * Converts a temperature in Fahrenheit to Celsius
 * @param fahrenheit the temperature in Fahrenheit to convert
 * @return the converted temperature in Celsius
 */
double convert_fahrenheit_to_celsius(double fahrenheit)
{
    double celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

/**
 * Converts a temperature in Celsius to Fahrenheit
 * @param celsius the temperature in Celsius to convert
 * @return the converted temperature in Fahrenheit
 */
double convert_celsius_to_fahrenheit(double celsius)
{
    double fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}