//FormAI DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>

//function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}

//function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}

//function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    double kelvin = celsius + 273.15;
    return kelvin;
}

//function to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    double celsius = kelvin - 273.15;
    return celsius;
}

int main() {
    int choice;
    double value, result;
    printf("Welcome to the Unit Converter!\n");

    while (1) {
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Celsius to Kelvin\n");
        printf("4. Kelvin to Celsius\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value in Celsius: ");
            scanf("%lf", &value);
            result = celsiusToFahrenheit(value);
            printf("%.2lf Celsius = %.2lf Fahrenheit\n", value, result);
        }
        else if (choice == 2) {
            printf("Enter value in Fahrenheit: ");
            scanf("%lf", &value);
            result = fahrenheitToCelsius(value);
            printf("%.2lf Fahrenheit = %.2lf Celsius\n", value, result);
        }
        else if (choice == 3) {
            printf("Enter value in Celsius: ");
            scanf("%lf", &value);
            result = celsiusToKelvin(value);
            printf("%.2lf Celsius = %.2lf Kelvin\n", value, result);
        }
        else if (choice == 4) {
            printf("Enter value in Kelvin: ");
            scanf("%lf", &value);
            result = kelvinToCelsius(value);
            printf("%.2lf Kelvin = %.2lf Celsius\n", value, result);
        } 
        else if (choice == 5) {
            printf("Thank you for using the Unit Converter.\n");
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}