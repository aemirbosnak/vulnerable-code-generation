//FormAI DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>

// function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
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
    float temperature;
    char unit; // 'c' for Celsius, 'f' for Fahrenheit, 'k' for Kelvin
    
    printf("Enter a temperature: ");
    scanf("%f", &temperature);
    printf("Enter the unit of the temperature (c/f/k): ");
    scanf(" %c", &unit); // add a space before %c to consume the newline character
                        
    switch(unit) {
        case 'c':
            printf("%.2f C = %.2f F\n", temperature, celsiusToFahrenheit(temperature));
            printf("%.2f C = %.2f K\n", temperature, celsiusToKelvin(temperature));
            break;
        case 'f':
            printf("%.2f F = %.2f C\n", temperature, fahrenheitToCelsius(temperature));
            printf("%.2f F = %.2f K\n", temperature, celsiusToKelvin(fahrenheitToCelsius(temperature)));
            break;
        case 'k':
            printf("%.2f K = %.2f C\n", temperature, kelvinToCelsius(temperature));
            printf("%.2f K = %.2f F\n", temperature, celsiusToFahrenheit(kelvinToCelsius(temperature)));
            break;
        default:
            printf("Invalid unit\n");
    }
    
    return 0;
}