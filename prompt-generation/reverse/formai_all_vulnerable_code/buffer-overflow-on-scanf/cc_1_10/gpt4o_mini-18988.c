//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: retro
#include <stdio.h>

void display_menu() {
    printf("\n");
    printf("*************************************\n");
    printf("*         TEMPERATURE CONVERTER     *\n");
    printf("*************************************\n");
    printf("*                                   *\n");
    printf("*  1. Celsius to Fahrenheit         *\n");
    printf("*  2. Fahrenheit to Celsius         *\n");
    printf("*  3. Celsius to Kelvin             *\n");
    printf("*  4. Kelvin to Celsius             *\n");
    printf("*  5. Exit                          *\n");
    printf("*                                   *\n");
    printf("*************************************\n");
    printf("Please enter your choice (1-5): ");
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

int main() {
    int choice = 0;
    float temperature, converted_temperature;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                converted_temperature = celsius_to_fahrenheit(temperature);
                printf("Temperature in Fahrenheit: %.2f\n", converted_temperature);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                converted_temperature = fahrenheit_to_celsius(temperature);
                printf("Temperature in Celsius: %.2f\n", converted_temperature);
                break;

            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                converted_temperature = celsius_to_kelvin(temperature);
                printf("Temperature in Kelvin: %.2f\n", converted_temperature);
                break;

            case 4:
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &temperature);
                converted_temperature = kelvin_to_celsius(temperature);
                printf("Temperature in Celsius: %.2f\n", converted_temperature);
                break;

            case 5:
                printf("Exiting the program. Stay warm!\n");
                return 0;

            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    }

    return 0;
}