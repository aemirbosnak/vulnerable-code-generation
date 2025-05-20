//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char choice;
    double temperature;

    // Initialize temperature variable
    temperature = 0;

    // Loop until user decides to quit
    do {
        // Display menu
        printf("Temperature Converter\n");
        printf("------------------------\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Kelvin to Celsius\n");
        printf("4. Celsius to Kelvin\n");
        printf("5. Quit\n");

        // Read user choice
        scanf(" %c", &choice);

        // Convert temperature based on user choice
        switch(choice) {
            case '1':
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                printf("%.2lf Celsius = %.2lf Fahrenheit\n", temperature, (temperature * 9/5) + 32);
                break;
            case '2':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                printf("%.2lf Fahrenheit = %.2lf Celsius\n", temperature, (temperature - 32) * 5/9);
                break;
            case '3':
                printf("Enter temperature in Kelvin: ");
                scanf("%lf", &temperature);
                printf("%.2lf Kelvin = %.2lf Celsius\n", temperature, temperature - 273.15);
                break;
            case '4':
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                printf("%.2lf Celsius = %.2lf Kelvin\n", temperature, temperature + 273.15);
                break;
            case '5':
                printf("Thank you for using Temperature Converter.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= '5');

    return 0;
}