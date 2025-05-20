//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    float toFahrenheit, toCelsius;
} TemperatureUnit;

void printMenu() {
    printf("\n-----------------------\n");
    printf("| Temperature Converter |\n");
    printf("-----------------------|\n");
    printf("| 1. Fahrenheit to Celsius |\n");
    printf("| 2. Celsius to Fahrenheit |\n");
    printf("| 3. Quit                |\n");
    printf("-----------------------|\n");
}

void convertFahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", fahrenheit, celsius);
}

void convertCelsiusToFahrenheit(float celsius) {
    float fahrenheit = celsius * 9.0 / 5.0 + 32.0;
    printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
}

void addTemperatureUnit(TemperatureUnit units[], int* size, char name[], float toFahrenheit, float toCelsius) {
    units[*size].toFahrenheit = toFahrenheit;
    units[*size].toCelsius = toCelsius;
    strcpy(units[*size].name, name);
    (*size)++;
}

int main() {
    TemperatureUnit units[5];
    int size = 0;
    addTemperatureUnit(units, &size, "Fahrenheit", 32.0, 0.0);
    addTemperatureUnit(units, &size, "Celsius", 0.0, 1.0);

    int choice;
    float temperature;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertFahrenheitToCelsius(temperature);
                break;
            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertCelsiusToFahrenheit(temperature);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}