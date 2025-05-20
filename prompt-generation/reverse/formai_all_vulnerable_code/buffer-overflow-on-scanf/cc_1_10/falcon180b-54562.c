//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: surrealist
#include <stdio.h>

// function prototypes
double fahrenheitToCelsius(double fahrenheit);
double celsiusToFahrenheit(double celsius);
double kelvinToCelsius(double kelvin);
double celsiusToKelvin(double celsius);

int main() {
    char choice;
    double temperature;

    do {
        printf("Temperature Converter\n");
        printf("-----------------------\n");
        printf("1. Fahrenheit to Celsius\n");
        printf("2. Celsius to Fahrenheit\n");
        printf("3. Celsius to Kelvin\n");
        printf("4. Kelvin to Celsius\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temperature, fahrenheitToCelsius(temperature));
                break;
            case '2':
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature, celsiusToFahrenheit(temperature));
                break;
            case '3':
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                printf("%.2lf degrees Celsius is equal to %.2lf Kelvin.\n", temperature, kelvinToCelsius(temperature));
                break;
            case '4':
                printf("Enter temperature in Kelvin: ");
                scanf("%lf", &temperature);
                printf("%.2lf Kelvin is equal to %.2lf degrees Celsius.\n", temperature, celsiusToKelvin(temperature));
                break;
            case '5':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice!= '5');

    return 0;
}

double fahrenheitToCelsius(double fahrenheit) {
    double celsius;
    celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

double celsiusToFahrenheit(double celsius) {
    double fahrenheit;
    fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

double kelvinToCelsius(double kelvin) {
    double celsius;
    celsius = kelvin - 273.15;
    return celsius;
}

double celsiusToKelvin(double celsius) {
    double kelvin;
    kelvin = celsius + 273.15;
    return kelvin;
}