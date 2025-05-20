//FormAI DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to convert Kilometers to Miles
float kilometersToMiles(float kilometers) {
    return kilometers * 0.621371;
}

// Function to convert Miles to Kilometers
float milesToKilometers(float miles) {
    return miles * 1.60934;
}

int main() {
    int option;
    float value, result;
    
    printf("Welcome to the Unit Converter\n\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    printf("5. Quit\n\n");
    
    do {
        printf("Enter your option: ");
        scanf("%d", &option);
        
        if (option == 1) {
            printf("Enter temperature in Celsius: ");
            scanf("%f", &value);
            result = celsiusToFahrenheit(value);
            printf("%.2f celcius is equal to %.2f fahrenheit.\n\n", value, result);
        } else if (option == 2) {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &value);
            result = fahrenheitToCelsius(value);
            printf("%.2f fahrenheit is equal to %.2f celcius.\n\n", value, result);
        } else if (option == 3) {
            printf("Enter distance in kilometers: ");
            scanf("%f", &value);
            result = kilometersToMiles(value);
            printf("%.2f kilometers is equal to %.2f miles.\n\n", value, result);
        } else if (option == 4) {
            printf("Enter distance in miles: ");
            scanf("%f", &value);
            result = milesToKilometers(value);
            printf("%.2f miles is equal to %.2f kilometers.\n\n", value, result);
        } else if (option == 5) {
            printf("Thank you for using the Unit Converter.\n");
        } else {
            printf("Invalid option. Please try again.\n\n");
        }
    } while (option != 5);
    
    return 0;
}