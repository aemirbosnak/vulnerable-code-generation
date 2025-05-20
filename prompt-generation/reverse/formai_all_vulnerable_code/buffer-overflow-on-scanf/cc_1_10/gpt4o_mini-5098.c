//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: satisfied
#include <stdio.h>

void displayMenu(); 
void celsiusToFahrenheit();
void fahrenheitToCelsius();
void kelvinToCelsius();
void celsiusToKelvin();
void fahrenheitToKelvin();
void kelvinToFahrenheit();
double convertCelsiusToFahrenheit(double celsius);
double convertFahrenheitToCelsius(double fahrenheit);
double convertCelsiusToKelvin(double celsius);
double convertKelvinToCelsius(double kelvin);
double convertKelvinToFahrenheit(double kelvin);
double convertFahrenheitToKelvin(double fahrenheit);

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                celsiusToFahrenheit();
                break;
            case 2:
                fahrenheitToCelsius();
                break;
            case 3:
                kelvinToCelsius();
                break;
            case 4:
                celsiusToKelvin();
                break;
            case 5:
                fahrenheitToKelvin();
                break;
            case 6:
                kelvinToFahrenheit();
                break;
            case 0:
                printf("Exiting the program. Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("Temperature Converter\n");
    printf("======================\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
}

void celsiusToFahrenheit() {
    double celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    double fahrenheit = convertCelsiusToFahrenheit(celsius);
    printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", celsius, fahrenheit);
}

void fahrenheitToCelsius() {
    double fahrenheit;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);
    double celsius = convertFahrenheitToCelsius(fahrenheit);
    printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", fahrenheit, celsius);
}

void kelvinToCelsius() {
    double kelvin;
    printf("Enter temperature in Kelvin: ");
    scanf("%lf", &kelvin);
    double celsius = convertKelvinToCelsius(kelvin);
    printf("%.2lf Kelvin is equal to %.2lf Celsius.\n", kelvin, celsius);
}

void celsiusToKelvin() {
    double celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    double kelvin = convertCelsiusToKelvin(celsius);
    printf("%.2lf Celsius is equal to %.2lf Kelvin.\n", celsius, kelvin);
}

void fahrenheitToKelvin() {
    double fahrenheit;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);
    double kelvin = convertFahrenheitToKelvin(fahrenheit);
    printf("%.2lf Fahrenheit is equal to %.2lf Kelvin.\n", fahrenheit, kelvin);
}

void kelvinToFahrenheit() {
    double kelvin;
    printf("Enter temperature in Kelvin: ");
    scanf("%lf", &kelvin);
    double fahrenheit = convertKelvinToFahrenheit(kelvin);
    printf("%.2lf Kelvin is equal to %.2lf Fahrenheit.\n", kelvin, fahrenheit);
}

double convertCelsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double convertFahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double convertCelsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double convertKelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double convertKelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}

double convertFahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0 + 273.15;
}