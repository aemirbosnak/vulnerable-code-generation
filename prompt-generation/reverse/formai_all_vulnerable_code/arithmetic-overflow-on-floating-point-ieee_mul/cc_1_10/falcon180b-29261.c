//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the conversion factors
#define C_TO_F(c) ((c) * 9.0 / 5.0 + 32.0)
#define F_TO_C(f) ((f - 32.0) * 5.0 / 9.0)

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return C_TO_F(celsius);
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return F_TO_C(fahrenheit);
}

int main() {
    char choice;
    double temperature, converted_temperature;

    // Prompt the user to enter a temperature and a conversion option
    printf("Enter a temperature to convert (in Celsius or Fahrenheit): ");
    scanf("%lf", &temperature);

    printf("Enter a conversion option:\n");
    printf("C) Celsius to Fahrenheit\n");
    printf("F) Fahrenheit to Celsius\n");
    scanf(" %c", &choice);

    // Convert the temperature based on the user's choice
    switch (choice) {
        case 'C':
        case 'c':
            converted_temperature = celsius_to_fahrenheit(temperature);
            printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit.\n", temperature, converted_temperature);
            break;
        case 'F':
        case 'f':
            converted_temperature = fahrenheit_to_celsius(temperature);
            printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius.\n", temperature, converted_temperature);
            break;
        default:
            printf("Invalid conversion option.\n");
            break;
    }

    return 0;
}