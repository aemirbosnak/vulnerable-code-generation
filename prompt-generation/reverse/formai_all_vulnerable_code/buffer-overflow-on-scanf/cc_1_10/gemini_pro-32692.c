//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef float Temperature;

Temperature CelciusToFahrenheit(Temperature celcius) {
    return celcius * 1.8 + 32;
}

Temperature FahrenheitToCelcius(Temperature fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

Temperature GetTemperature(char *prompt, Temperature (*converter)(Temperature)) {
    float temperature;
    printf("%s", prompt);
    while (scanf("%f", &temperature) != 1) {
        printf("Invalid input. Please enter a valid temperature.\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    return converter(temperature);
}

void PrintTemperature(Temperature temperature, char *unit) {
    printf("%.1f degrees %s\n", temperature, unit);
}

int main() {
    bool running = true;
    char input[100];
    Temperature celcius, fahrenheit;

    while (running) {
        printf("Welcome to the temperature converter!\n");
        printf("1. Convert Celcius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celcius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        fgets(input, sizeof(input), stdin);
        switch (input[0]) {
            case '1':
                celcius = GetTemperature("Enter temperature in Celcius: ", FahrenheitToCelcius);
                PrintTemperature(celcius, "Celcius");
                break;
            case '2':
                fahrenheit = GetTemperature("Enter temperature in Fahrenheit: ", CelciusToFahrenheit);
                PrintTemperature(fahrenheit, "Fahrenheit");
                break;
            case '3':
                running = false;
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }

    printf("Goodbye!\n");
    return 0;
}