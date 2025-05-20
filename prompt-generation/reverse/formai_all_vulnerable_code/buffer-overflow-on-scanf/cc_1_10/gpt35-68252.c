//FormAI DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>

//Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

//Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

//Function to convert Celsius to Kelvin
float celsius_to_kelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

//Function to convert Kelvin to Celsius
float kelvin_to_celsius(float kelvin) {
    float celsius = kelvin - 273.15;
    return celsius;
}

int main() {
    int choice;
    float value, result;
    
    printf("Welcome to the Unit Converter!\n");
    printf("Choose an option from the menu below:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &value);
            result = celsius_to_fahrenheit(value);
            printf("%.2f Celsius = %.2f Fahrenheit\n", value, result);
            break;
            
        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &value);
            result = fahrenheit_to_celsius(value);
            printf("%.2f Fahrenheit = %.2f Celsius\n", value, result);
            break;
            
        case 3:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &value);
            result = celsius_to_kelvin(value);
            printf("%.2f Celsius = %.2f Kelvin\n", value, result);
            break;
            
        case 4:
            printf("Enter the temperature in Kelvin: ");
            scanf("%f", &value);
            result = kelvin_to_celsius(value);
            printf("%.2f Kelvin = %.2f Celsius\n", value, result);
            break;
            
        default:
            printf("Invalid choice! Please choose a number from the menu.\n");
            break;
    }
    
    return 0;
}