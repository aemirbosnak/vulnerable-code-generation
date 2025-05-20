//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to display menu
void display_menu() {
    printf("Temperature Converter\n");
    printf("----------------------\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

// Main function
int main() {
    int choice;
    float temperature;

    do {
        display_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, celsius_to_fahrenheit(temperature));
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, fahrenheit_to_celsius(temperature));
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= 3);

    return 0;
}