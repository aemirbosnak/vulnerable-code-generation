//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check if input is a valid number
int is_number(char *str)
{
    int i = 0;
    while (str[i]) {
        if (!isdigit(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius)
{
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit)
{
    return (fahrenheit - 32) / 1.8;
}

// Function to prompt user for temperature input and convert to Celsius
double get_temperature_celsius()
{
    char input[50];
    double temperature = 0;

    // Prompt user for temperature input
    printf("Enter temperature: ");
    fgets(input, 50, stdin);

    // Check if input is a valid number
    if (is_number(input)) {
        // Convert input to Celsius
        temperature = atof(input);
    } else {
        // Invalid input, exit program
        printf("Invalid input.\n");
        exit(1);
    }

    return temperature;
}

// Function to prompt user for temperature conversion and display result
void convert_temperature()
{
    double temperature = get_temperature_celsius();
    int choice;

    // Prompt user for temperature conversion
    printf("Convert temperature from Celsius to Fahrenheit? (y/n) ");
    scanf("%d", &choice);

    // Convert temperature and display result
    if (choice == 1) {
        double fahrenheit = celsius_to_fahrenheit(temperature);
        printf("%.2f Celsius is %.2f Fahrenheit.\n", temperature, fahrenheit);
    } else if (choice == 0) {
        double fahrenheit = fahrenheit_to_celsius(temperature);
        printf("%.2f Celsius is %.2f Fahrenheit.\n", temperature, fahrenheit);
    } else {
        printf("Invalid choice.\n");
    }
}

int main()
{
    convert_temperature();

    return 0;
}