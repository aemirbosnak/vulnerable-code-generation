//FormAI DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to convert Fahrenheit to Kelvin
float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}

// Function to convert Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

// Function to convert Kelvin to Fahrenheit
float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}

int main() {
    float temperature;
    int choice;

    printf("Enter a temperature: ");
    scanf("%f", &temperature);

    printf("\nChoose an option: \n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Celsius to Kelvin\n");
    printf("3. Convert Fahrenheit to Celsius\n");
    printf("4. Convert Fahrenheit to Kelvin\n");
    printf("5. Convert Kelvin to Celsius\n");
    printf("6. Convert Kelvin to Fahrenheit\n");
    printf("7. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\n%.2f Celsius = %.2f Fahrenheit\n", temperature, celsiusToFahrenheit(temperature));
            break;
        case 2:
            printf("\n%.2f Celsius = %.2f Kelvin\n", temperature, celsiusToKelvin(temperature));
            break;
        case 3:
            printf("\n%.2f Fahrenheit = %.2f Celsius\n", temperature, fahrenheitToCelsius(temperature));
            break;
        case 4:
            printf("\n%.2f Fahrenheit = %.2f Kelvin\n", temperature, fahrenheitToKelvin(temperature));
            break;
        case 5:
            printf("\n%.2f Kelvin = %.2f Celsius\n", temperature, kelvinToCelsius(temperature));
            break;
        case 6:
            printf("\n%.2f Kelvin = %.2f Fahrenheit\n", temperature, kelvinToFahrenheit(temperature));
            break;
        case 7:
            printf("\nProgram terminated.\n");
            return 0;
        default:
            printf("\nInvalid option. Program terminated.\n");
            return 0;
    }
    
    return 0;
}