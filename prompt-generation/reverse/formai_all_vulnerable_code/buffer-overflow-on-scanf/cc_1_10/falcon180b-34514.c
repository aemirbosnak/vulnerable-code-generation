//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit;
    fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius;
    celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

// Function to display menu options
void displayMenu() {
    printf("Temperature Monitor Menu\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

// Main function
int main() {
    int choice;
    float temperature;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, celsiusToFahrenheit(temperature));
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, fahrenheitToCelsius(temperature));
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice!= 3);

    return 0;
}