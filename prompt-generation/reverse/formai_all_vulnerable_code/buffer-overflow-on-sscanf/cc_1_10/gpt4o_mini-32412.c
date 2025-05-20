//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("\n=================== Temperature Converter ===================\n");
    printf("Choose the conversion type:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
    printf("=============================================================\n");
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    float celsius = fahrenheit_to_celsius(fahrenheit);
    return celsius_to_kelvin(celsius);
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float kelvin_to_fahrenheit(float kelvin) {
    float celsius = kelvin_to_celsius(kelvin);
    return celsius_to_fahrenheit(celsius);
}

int main() {
    int choice;
    float temperature, converted_temperature;
    char buffer[100];

    while (1) {
        display_menu();
        
        printf("Enter your choice: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            sscanf(buffer, "%d", &choice);
        } else {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        if (choice == 7) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 6) {
            printf("Invalid choice. Please select a valid option.\n");
            continue;
        }

        printf("Enter the temperature to convert: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            sscanf(buffer, "%f", &temperature);
        } else {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        switch (choice) {
            case 1:
                converted_temperature = celsius_to_fahrenheit(temperature);
                printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, converted_temperature);
                break;
            case 2:
                converted_temperature = celsius_to_kelvin(temperature);
                printf("%.2f Celsius = %.2f Kelvin\n", temperature, converted_temperature);
                break;
            case 3:
                converted_temperature = fahrenheit_to_celsius(temperature);
                printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, converted_temperature);
                break;
            case 4:
                converted_temperature = fahrenheit_to_kelvin(temperature);
                printf("%.2f Fahrenheit = %.2f Kelvin\n", temperature, converted_temperature);
                break;
            case 5:
                converted_temperature = kelvin_to_celsius(temperature);
                printf("%.2f Kelvin = %.2f Celsius\n", temperature, converted_temperature);
                break;
            case 6:
                converted_temperature = kelvin_to_fahrenheit(temperature);
                printf("%.2f Kelvin = %.2f Fahrenheit\n", temperature, converted_temperature);
                break;
        }

        printf("\nWould you like to perform another conversion? (y/n): ");
        char continue_choice;
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            sscanf(buffer, " %c", &continue_choice);
        }

        if (continue_choice != 'y' && continue_choice != 'Y') {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
    }

    return 0;
}