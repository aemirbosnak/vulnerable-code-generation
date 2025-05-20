//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: rigorous
#include <stdio.h>

void print_menu() {
    printf("Temperature Converter\n");
    printf("=====================\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
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

float fahrenheit_to_kelvin(float fahrenheit) {
    float celsius = fahrenheit_to_celsius(fahrenheit);
    return celsius_to_kelvin(celsius);
}

float kelvin_to_fahrenheit(float kelvin) {
    float celsius = kelvin_to_celsius(kelvin);
    return celsius_to_fahrenheit(celsius);
}

int main() {
    int choice;
    float temperature, converted_temperature;

    while (1) {
        print_menu();
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting the Temperature Converter. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 6) {
            printf("Invalid choice! Please select an option from the menu.\n");
            continue;
        }

        printf("Enter the temperature: ");
        scanf("%f", &temperature);

        switch (choice) {
            case 1:
                converted_temperature = celsius_to_fahrenheit(temperature);
                printf("%.2f Celsius is %.2f Fahrenheit.\n", temperature, converted_temperature);
                break;
            case 2:
                converted_temperature = fahrenheit_to_celsius(temperature);
                printf("%.2f Fahrenheit is %.2f Celsius.\n", temperature, converted_temperature);
                break;
            case 3:
                converted_temperature = celsius_to_kelvin(temperature);
                printf("%.2f Celsius is %.2f Kelvin.\n", temperature, converted_temperature);
                break;
            case 4:
                converted_temperature = kelvin_to_celsius(temperature);
                printf("%.2f Kelvin is %.2f Celsius.\n", temperature, converted_temperature);
                break;
            case 5:
                converted_temperature = fahrenheit_to_kelvin(temperature);
                printf("%.2f Fahrenheit is %.2f Kelvin.\n", temperature, converted_temperature);
                break;
            case 6:
                converted_temperature = kelvin_to_fahrenheit(temperature);
                printf("%.2f Kelvin is %.2f Fahrenheit.\n", temperature, converted_temperature);
                break;
            default:
                printf("An unexpected error occurred. Please try again.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}