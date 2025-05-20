//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include <stdio.h>

// Constants to convert between Celsius and Fahrenheit
#define FAHRENHEIT_TO_CELSIUS(f) ((f - 32) * 5.0 / 9.0)
#define CELSIUS_TO_FAHRENHEIT(c) ((c * 9.0 / 5.0) + 32)

void display_welcome_message() {
    printf("====================================================\n");
    printf("                Temperature Converter                \n");
    printf("                    By Your Name                    \n");
    printf("====================================================\n");
}

void prompt_user_selection() {
    printf("Choose the conversion option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Enter your choice (1-3): ");
}

double celsius_to_fahrenheit(double celsius) {
    return CELSIUS_TO_FAHRENHEIT(celsius);
}

double fahrenheit_to_celsius(double fahrenheit) {
    return FAHRENHEIT_TO_CELSIUS(fahrenheit);
}

void perform_conversion(int choice) {
    double temperature_input, temperature_output;

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%lf", &temperature_input);
        temperature_output = celsius_to_fahrenheit(temperature_input);
        printf("Temperature in Fahrenheit: %.2lf°F\n", temperature_output);
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%lf", &temperature_input);
        temperature_output = fahrenheit_to_celsius(temperature_input);
        printf("Temperature in Celsius: %.2lf°C\n", temperature_output);
    } else {
        printf("Exiting the program. Goodbye!\n");
    }
}

void temperature_converter() {
    int user_choice = 0;

    display_welcome_message();

    while (user_choice != 3) {
        prompt_user_selection();
        scanf("%d", &user_choice);

        if (user_choice < 1 || user_choice > 3) {
            printf("Invalid choice. Please select between 1 and 3.\n");
            continue;
        }

        if (user_choice != 3) {
            perform_conversion(user_choice);
        }
    }
}

int main() {
    temperature_converter();
    return 0;
}