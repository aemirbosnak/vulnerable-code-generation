//FormAI DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

int main() {
    int option;
    double celsius, fahrenheit, kelvin;
    
    printf("Welcome to the Temperature Converter\n");
    printf("Please select an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Exit\n");
    scanf("%d", &option);
    
    while(option != 3) {
        switch(option) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &celsius);
                fahrenheit = celsiusToFahrenheit(celsius);
                printf("%.2lf Celsius is equal to %.2lf Fahrenheit\n", celsius, fahrenheit);
                break;
            
            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &celsius);
                kelvin = celsiusToKelvin(celsius);
                printf("%.2lf Celsius is equal to %.2lf Kelvin\n", celsius, kelvin);
                break;
            
            default:
                printf("Invalid option selected\n");
        }
        
        printf("\nPlease select another option or enter 3 to exit:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Celsius to Kelvin\n");
        printf("3. Exit\n");
        scanf("%d", &option);
    }
    
    printf("Thank you for using the Temperature Converter");
    
    return 0;
}