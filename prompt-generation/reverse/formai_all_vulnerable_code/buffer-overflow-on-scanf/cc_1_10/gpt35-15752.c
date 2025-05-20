//FormAI DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

int main() {
    printf("*********** Unit Converter ***********\n");
    
    int choice;
    
    do {
        printf("\n\nWhat would you like to convert?\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Celsius to Kelvin\n");
        printf("4. Kelvin to Celsius\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                float celsius, fahrenheit;
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &celsius);
                fahrenheit = celsiusToFahrenheit(celsius);
                printf("\n%f degrees Celsius is equal to %f degrees Fahrenheit.\n", celsius, fahrenheit);
                break;
            }
            case 2: {
                float fahrenheit, celsius;
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                celsius = fahrenheitToCelsius(fahrenheit);
                printf("\n%f degrees Fahrenheit is equal to %f degrees Celsius.\n", fahrenheit, celsius);
                break;
            }
            case 3: {
                float celsius, kelvin;
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &celsius);
                kelvin = celsiusToKelvin(celsius);
                printf("\n%f degrees Celsius is equal to %f Kelvin.\n", celsius, kelvin);
                break;
            }
            case 4: {
                float kelvin, celsius;
                printf("\nEnter temperature in Kelvin: ");
                scanf("%f", &kelvin);
                celsius = kelvinToCelsius(kelvin);
                printf("\n%f Kelvin is equal to %f degrees Celsius.\n", kelvin, celsius);
                break;
            }
            case 5:
                printf("\nThank you for using the unit converter!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}