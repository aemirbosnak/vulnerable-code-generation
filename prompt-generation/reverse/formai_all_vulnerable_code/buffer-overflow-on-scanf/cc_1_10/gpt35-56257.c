//FormAI DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert Fahrenheit to Kelvin
double fahrenheitToKelvin(double fahrenheit) {
    double celsius = fahrenheitToCelsius(fahrenheit);
    return celsiusToKelvin(celsius);
}

// Function to convert Kelvin to Fahrenheit
double kelvinToFahrenheit(double kelvin) {
    double celsius = kelvinToCelsius(kelvin);
    return celsiusToFahrenheit(celsius);
}

// Main function
int main() {
    int choice;
    double value;
    
    printf("\n\n===============================");
    printf("\nWelcome to the Unit Converter!");
    printf("\n===============================\n\n");
    
    while (1) {
        printf("\nWhat would you like to convert?");
        printf("\n1. Celsius to Fahrenheit");
        printf("\n2. Fahrenheit to Celsius");
        printf("\n3. Celsius to Kelvin");
        printf("\n4. Kelvin to Celsius");
        printf("\n5. Fahrenheit to Kelvin");
        printf("\n6. Kelvin to Fahrenheit");
        printf("\n7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 7) {
            printf("\nGoodbye!\n");
            break;
        }
        
        printf("\nEnter the value to convert: ");
        scanf("%lf", &value);
        
        switch (choice) {
            case 1:
                printf("\n%.2lf Celsius = %.2lf Fahrenheit\n", value, celsiusToFahrenheit(value));
                break;
            case 2:
                printf("\n%.2lf Fahrenheit = %.2lf Celsius\n", value, fahrenheitToCelsius(value));
                break;
            case 3:
                printf("\n%.2lf Celsius = %.2lf Kelvin\n", value, celsiusToKelvin(value));
                break;
            case 4:
                printf("\n%.2lf Kelvin = %.2lf Celsius\n", value, kelvinToCelsius(value));
                break;
            case 5:
                printf("\n%.2lf Fahrenheit = %.2lf Kelvin\n", value, fahrenheitToKelvin(value));
                break;
            case 6:
                printf("\n%.2lf Kelvin = %.2lf Fahrenheit\n", value, kelvinToFahrenheit(value));
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    }
    
    return 0;
}