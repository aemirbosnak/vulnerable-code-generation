//FormAI DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>

// function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

// function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0/9.0;
}

// function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

// function to convert Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

int main() {
    int option;
    float temperature, converted;
    
    printf("Welcome to the temperature converter!\n\n");
    printf("Please select an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n\n");
    
    // get user input for option and temperature
    printf("Option: ");
    scanf("%d", &option);
    
    printf("Temperature: ");
    scanf("%f", &temperature);
    
    // convert temperature based on selected option
    switch(option) {
        case 1:
            converted = celsiusToFahrenheit(temperature);
            printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, converted);
            break;
        case 2:
            converted = fahrenheitToCelsius(temperature);
            printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, converted);
            break;
        case 3:
            converted = celsiusToKelvin(temperature);
            printf("%.2f Celsius = %.2f Kelvin\n", temperature, converted);
            break;
        case 4:
            converted = kelvinToCelsius(temperature);
            printf("%.2f Kelvin = %.2f Celsius\n", temperature, converted);
            break;
        default:
            printf("Invalid option selected.\n");
            break;
    }
    
    return 0;
}