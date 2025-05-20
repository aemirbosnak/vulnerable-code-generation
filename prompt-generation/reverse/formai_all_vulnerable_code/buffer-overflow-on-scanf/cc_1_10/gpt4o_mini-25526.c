//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: high level of detail
#include <stdio.h>

void displayMenu() {
    printf("\nTemperature Converter Menu:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
    printf("Please select an option (1-7): ");
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double fahrenheitToKelvin(double fahrenheit) {
    return celsiusToKelvin(fahrenheitToCelsius(fahrenheit));
}

double kelvinToFahrenheit(double kelvin) {
    return celsiusToFahrenheit(kelvinToCelsius(kelvin));
}

int main() {
    int choice;
    double temperature, convertedTemperature;

    printf("Welcome to the Temperature Converter!\n");
    
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, convertedTemperature);
                break;
            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                convertedTemperature = celsiusToKelvin(temperature);
                printf("%.2f Celsius is %.2f Kelvin\n", temperature, convertedTemperature);
                break;
            case 4:
                printf("Enter temperature in Kelvin: ");
                scanf("%lf", &temperature);
                convertedTemperature = kelvinToCelsius(temperature);
                printf("%.2f Kelvin is %.2f Celsius\n", temperature, convertedTemperature);
                break;
            case 5:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                convertedTemperature = fahrenheitToKelvin(temperature);
                printf("%.2f Fahrenheit is %.2f Kelvin\n", temperature, convertedTemperature);
                break;
            case 6:
                printf("Enter temperature in Kelvin: ");
                scanf("%lf", &temperature);
                convertedTemperature = kelvinToFahrenheit(temperature);
                printf("%.2f Kelvin is %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;
            case 7:
                printf("Exiting the Temperature Converter. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}