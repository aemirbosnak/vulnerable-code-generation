//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
double CelsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double FahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to convert Celsius to Kelvin
double CelsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
double KelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert Fahrenheit to Kelvin
double FahrenheitToKelvin(double fahrenheit) {
    double celsius = FahrenheitToCelsius(fahrenheit);
    return CelsiusToKelvin(celsius);
}

// Function to convert Kelvin to Fahrenheit
double KelvinToFahrenheit(double kelvin) {
    double celsius = KelvinToCelsius(kelvin);
    return CelsiusToFahrenheit(celsius);
}

// Function to print instructions and get user input
void DisplayMenu() {
    printf("\nTemperature Converter\n");
    printf("======================\n");
    printf("Choose the conversion type:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
}

// Function to get user choice
int GetUserChoice() {
    int choice = 0;
    printf("Enter your choice (1-7): ");
    scanf("%d", &choice);
    return choice;
}

// Function to get temperature from the user
double GetTemperature() {
    double temp;
    printf("Enter the temperature: ");
    scanf("%lf", &temp);
    return temp;
}

// Main program
int main() {
    int choice;
    double temperature, result;
    
    do {
        DisplayMenu();
        choice = GetUserChoice();

        switch (choice) {
            case 1:
                temperature = GetTemperature();
                result = CelsiusToFahrenheit(temperature);
                printf("%.2lf Celsius = %.2lf Fahrenheit\n", temperature, result);
                break;

            case 2:
                temperature = GetTemperature();
                result = FahrenheitToCelsius(temperature);
                printf("%.2lf Fahrenheit = %.2lf Celsius\n", temperature, result);
                break;

            case 3:
                temperature = GetTemperature();
                result = CelsiusToKelvin(temperature);
                printf("%.2lf Celsius = %.2lf Kelvin\n", temperature, result);
                break;

            case 4:
                temperature = GetTemperature();
                result = KelvinToCelsius(temperature);
                printf("%.2lf Kelvin = %.2lf Celsius\n", temperature, result);
                break;

            case 5:
                temperature = GetTemperature();
                result = FahrenheitToKelvin(temperature);
                printf("%.2lf Fahrenheit = %.2lf Kelvin\n", temperature, result);
                break;

            case 6:
                temperature = GetTemperature();
                result = KelvinToFahrenheit(temperature);
                printf("%.2lf Kelvin = %.2lf Fahrenheit\n", temperature, result);
                break;

            case 7:
                printf("Exiting the program. Thank you!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 7);
    
    return 0;
}