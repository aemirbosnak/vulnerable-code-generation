//FormAI DATASET v1.0 Category: Unit converter ; Style: introspective
#include <stdio.h>

float convertCelsiusToFahrenheit(float celsius);
float convertFahrenheitToCelsius(float fahrenheit);
float convertMilesToKilometers(float miles);
float convertKilometersToMiles(float kilometers);

int main() {
    int option;
    float value, result;
    
    printf("Welcome to the Introspective C Unit Converter!\n\n");
    
    do {
        printf("Please select an option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Miles to Kilometers\n");
        printf("4. Kilometers to Miles\n");
        printf("5. Exit\n");
        printf("Option: ");
        
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("\nCelsius to Fahrenheit\n");
                printf("Enter a temperature in Celsius: ");
                scanf("%f", &value);
                result = convertCelsiusToFahrenheit(value);
                printf("%.2f Celsius = %.2f Fahrenheit\n\n", value, result);
                break;
            case 2:
                printf("\nFahrenheit to Celsius\n");
                printf("Enter a temperature in Fahrenheit: ");
                scanf("%f", &value);
                result = convertFahrenheitToCelsius(value);
                printf("%.2f Fahrenheit = %.2f Celsius\n\n", value, result);
                break;
            case 3:
                printf("\nMiles to Kilometers\n");
                printf("Enter a distance in miles: ");
                scanf("%f", &value);
                result = convertMilesToKilometers(value);
                printf("%.2f miles = %.2f kilometers\n\n", value, result);
                break;
            case 4:
                printf("\nKilometers to Miles\n");
                printf("Enter a distance in kilometers: ");
                scanf("%f", &value);
                result = convertKilometersToMiles(value);
                printf("%.2f kilometers = %.2f miles\n\n", value, result);
                break;
            case 5:
                printf("Thank you for using the Introspective C Unit Converter!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n\n");
                break;
        }
    } while(option != 5);
    
    return 0;
}

float convertCelsiusToFahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

float convertFahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

float convertMilesToKilometers(float miles) {
    return miles * 1.609;
}

float convertKilometersToMiles(float kilometers) {
    return kilometers / 1.609;
}