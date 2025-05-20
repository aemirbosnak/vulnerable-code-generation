//FormAI DATASET v1.0 Category: Temperature Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// A function to display the program header
void displayHeader() {
    printf("**** Temperature Converter ****\n\n");
}

// A function to display the conversion menu
void displayMenu() {
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n\n");
}

// A function to perform the Celsius to Fahrenheit conversion
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}

// A function to perform the Fahrenheit to Celsius conversion
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}

int main() {
    char choice;
    float temperature, result;
    
    displayHeader();
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &temperature);
                result = celsiusToFahrenheit(temperature);
                printf("Result: %.2f Fahrenheit\n\n", result);
                break;
            case '2':
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                result = fahrenheitToCelsius(temperature);
                printf("Result: %.2f Celsius\n\n", result);
                break;
            case '3':
                printf("\nExiting Temperature Converter...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Please try again.\n\n");
        }
    } while (choice != '3');

    return 0;
}