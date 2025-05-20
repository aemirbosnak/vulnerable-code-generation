//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//Function for Celsius to Fahrenheit conversion
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

//Function for Fahrenheit to Celsius conversion
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

//Function for Kelvin to Celsius conversion
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

//Function for Celsius to Kelvin conversion
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

//Function for Fahrenheit to Kelvin conversion
float fahrenheit_to_kelvin(float fahrenheit) {
    return (fahrenheit + 459.67) * 5/9;
}

//Function for Kelvin to Fahrenheit conversion
float kelvin_to_fahrenheit(float kelvin) {
    return (kelvin * 9/5) - 459.67;
}

//Main function
int main() {
    char choice;
    float temperature, converted_temperature;

    do {
        printf("Enter the temperature to convert (in Celsius): ");
        scanf("%f", &temperature);

        printf("Enter the unit of temperature (C/F/K): ");
        scanf(" %c", &choice);

        switch(choice) {
            case 'C':
            case 'c':
                printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, celsius_to_fahrenheit(temperature));
                printf("%.2f Celsius = %.2f Kelvin\n", temperature, kelvin_to_celsius(temperature));
                break;

            case 'F':
            case 'f':
                printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, fahrenheit_to_celsius(temperature));
                printf("%.2f Fahrenheit = %.2f Kelvin\n", temperature, fahrenheit_to_kelvin(temperature));
                break;

            case 'K':
            case 'k':
                printf("%.2f Kelvin = %.2f Celsius\n", temperature, kelvin_to_celsius(temperature));
                printf("%.2f Kelvin = %.2f Fahrenheit\n", temperature, kelvin_to_fahrenheit(temperature));
                break;

            default:
                printf("Invalid choice!");
        }

        printf("\nDo you want to convert another temperature? (y/n): ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');

    return 0;
}