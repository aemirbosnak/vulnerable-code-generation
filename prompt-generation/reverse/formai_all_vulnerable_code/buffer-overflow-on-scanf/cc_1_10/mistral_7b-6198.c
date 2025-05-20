//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>

typedef struct Temperature {
    char unit;
    float value;
} Temperature;

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return celsius * 9 / 5 + 32;
}

// Function to print temperature in given unit
void printTemperature(Temperature temp) {
    switch (temp.unit) {
        case 'F':
            printf("%.2f°F = %.2f°C\n", temp.value, fahrenheitToCelsius(temp.value));
            break;
        case 'C':
            printf("%.2f°C = %.2f°F\n", temp.value, celsiusToFahrenheit(temp.value));
            break;
        default:
            printf("Invalid temperature unit!\n");
            exit(EXIT_FAILURE);
    }
}

// Function to read temperature value and unit from user
Temperature readTemperature() {
    Temperature temp;
    char unit;
    float value;

    printf("Enter temperature value: ");
    scanf("%f", &value);

    printf("Enter temperature unit (F/C): ");
    scanf(" %c", &unit);

    temp.value = value;
    temp.unit = unit;

    return temp;
}

int main() {
    Temperature temp;

    while (1) {
        temp = readTemperature();
        printTemperature(temp);

        printf("Do you want to convert another temperature? (Y/N): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'N') {
            break;
        }
    }

    return EXIT_SUCCESS;
}