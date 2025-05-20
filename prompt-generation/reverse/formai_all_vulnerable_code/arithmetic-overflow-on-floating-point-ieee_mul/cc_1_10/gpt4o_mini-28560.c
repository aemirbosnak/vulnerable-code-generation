//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: optimized
#include <stdio.h>

#define MAX_CONVERSIONS 100

typedef enum {
    CELSIUS,
    FAHRENHEIT,
    KELVIN
} TemperatureScale;

typedef struct {
    double value;
    TemperatureScale scale;
} Temperature;

void printMenu() {
    printf("Temperature Converter Menu:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
    printf("Please select an option (1-7): ");
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
    return fahrenheitToCelsius(fahrenheit) + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return celsiusToFahrenheit(kelvinToCelsius(kelvin));
}

void convertTemperature(Temperature temp, TemperatureScale targetScale) {
    double result;

    switch (temp.scale) {
        case CELSIUS:
            if (targetScale == FAHRENHEIT) {
                result = celsiusToFahrenheit(temp.value);
                printf("%.2f Celsius = %.2f Fahrenheit\n", temp.value, result);
            } else if (targetScale == KELVIN) {
                result = celsiusToKelvin(temp.value);
                printf("%.2f Celsius = %.2f Kelvin\n", temp.value, result);
            }
            break;
        case FAHRENHEIT:
            if (targetScale == CELSIUS) {
                result = fahrenheitToCelsius(temp.value);
                printf("%.2f Fahrenheit = %.2f Celsius\n", temp.value, result);
            } else if (targetScale == KELVIN) {
                result = fahrenheitToKelvin(temp.value);
                printf("%.2f Fahrenheit = %.2f Kelvin\n", temp.value, result);
            }
            break;
        case KELVIN:
            if (targetScale == CELSIUS) {
                result = kelvinToCelsius(temp.value);
                printf("%.2f Kelvin = %.2f Celsius\n", temp.value, result);
            } else if (targetScale == FAHRENHEIT) {
                result = kelvinToFahrenheit(temp.value);
                printf("%.2f Kelvin = %.2f Fahrenheit\n", temp.value, result);
            }
            break;
        default:
            printf("Invalid temperature scale!\n");
    }
}

int main() {
    int choice;
    Temperature temp;
    double inputValue;

    printf("Welcome to the Temperature Converter!\n");

    while (1) {
        printMenu();
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        printf("Enter the temperature value: ");
        scanf("%lf", &inputValue);

        switch (choice) {
            case 1:
                temp.value = inputValue;
                temp.scale = CELSIUS;
                convertTemperature(temp, FAHRENHEIT);
                break;
            case 2:
                temp.value = inputValue;
                temp.scale = CELSIUS;
                convertTemperature(temp, KELVIN);
                break;
            case 3:
                temp.value = inputValue;
                temp.scale = FAHRENHEIT;
                convertTemperature(temp, CELSIUS);
                break;
            case 4:
                temp.value = inputValue;
                temp.scale = FAHRENHEIT;
                convertTemperature(temp, KELVIN);
                break;
            case 5:
                temp.value = inputValue;
                temp.scale = KELVIN;
                convertTemperature(temp, CELSIUS);
                break;
            case 6:
                temp.value = inputValue;
                temp.scale = KELVIN;
                convertTemperature(temp, FAHRENHEIT);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}