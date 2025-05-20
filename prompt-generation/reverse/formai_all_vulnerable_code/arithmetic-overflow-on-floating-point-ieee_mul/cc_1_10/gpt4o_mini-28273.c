//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

void displayMenu();
void convertFromCelsius();
void convertFromFahrenheit();
void convertFromKelvin();
double celsiusToFahrenheit(double celsius);
double celsiusToKelvin(double celsius);
double fahrenheitToCelsius(double fahrenheit);
double fahrenheitToKelvin(double fahrenheit);
double kelvinToCelsius(double kelvin);
double kelvinToFahrenheit(double kelvin);

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice (1-4 to convert, 5 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertFromCelsius();
                break;
            case 2:
                convertFromFahrenheit();
                break;
            case 3:
                convertFromKelvin();
                break;
            case 4:
                printf("Leaving the converter. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void displayMenu() {
    printf("\n--- Temperature Converter ---\n");
    printf("1. Convert from Celsius\n");
    printf("2. Convert from Fahrenheit\n");
    printf("3. Convert from Kelvin\n");
    printf("4. Exit\n");
}

void convertFromCelsius() {
    double celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    
    printf("%.2f Celsius is equivalent to %.2f Fahrenheit\n", celsius, celsiusToFahrenheit(celsius));
    printf("%.2f Celsius is equivalent to %.2f Kelvin\n", celsius, celsiusToKelvin(celsius));
}

void convertFromFahrenheit() {
    double fahrenheit;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);
    
    printf("%.2f Fahrenheit is equivalent to %.2f Celsius\n", fahrenheit, fahrenheitToCelsius(fahrenheit));
    printf("%.2f Fahrenheit is equivalent to %.2f Kelvin\n", fahrenheit, fahrenheitToKelvin(fahrenheit));
}

void convertFromKelvin() {
    double kelvin;
    printf("Enter temperature in Kelvin: ");
    scanf("%lf", &kelvin);
    
    printf("%.2f Kelvin is equivalent to %.2f Celsius\n", kelvin, kelvinToCelsius(kelvin));
    printf("%.2f Kelvin is equivalent to %.2f Fahrenheit\n", kelvin, kelvinToFahrenheit(kelvin));
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}