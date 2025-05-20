//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: automated
#include <stdio.h>

void displayMenu() {
    printf("\n--- Temperature Converter ---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
    printf("-----------------------------\n");
    printf("Select an option (1-7): ");
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}

int main() {
    int choice;
    double temperature, convertedTemperature;

    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 7.\n");
            while (getchar() != '\n'); // clear invalid input
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                if (scanf("%lf", &temperature) != 1) {
                    printf("Invalid input! Please enter a valid number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;

            case 2:
                printf("Enter temperature in Celsius: ");
                if (scanf("%lf", &temperature) != 1) {
                    printf("Invalid input! Please enter a valid number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                convertedTemperature = celsiusToKelvin(temperature);
                printf("%.2f Celsius is %.2f Kelvin\n", temperature, convertedTemperature);
                break;

            case 3:
                printf("Enter temperature in Fahrenheit: ");
                if (scanf("%lf", &temperature) != 1) {
                    printf("Invalid input! Please enter a valid number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, convertedTemperature);
                break;

            case 4:
                printf("Enter temperature in Fahrenheit: ");
                if (scanf("%lf", &temperature) != 1) {
                    printf("Invalid input! Please enter a valid number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                convertedTemperature = fahrenheitToKelvin(temperature);
                printf("%.2f Fahrenheit is %.2f Kelvin\n", temperature, convertedTemperature);
                break;

            case 5:
                printf("Enter temperature in Kelvin: ");
                if (scanf("%lf", &temperature) != 1) {
                    printf("Invalid input! Please enter a valid number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                convertedTemperature = kelvinToCelsius(temperature);
                printf("%.2f Kelvin is %.2f Celsius\n", temperature, convertedTemperature);
                break;

            case 6:
                printf("Enter temperature in Kelvin: ");
                if (scanf("%lf", &temperature) != 1) {
                    printf("Invalid input! Please enter a valid number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                convertedTemperature = kelvinToFahrenheit(temperature);
                printf("%.2f Kelvin is %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;

            case 7:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please select an option between 1 and 7.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}