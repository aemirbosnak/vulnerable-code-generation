//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: irregular
#include <stdio.h>

void welcome_message() {
    printf("Welcome to the Irregular Temperature Converter!\n");
    printf("You can convert between Celsius, Fahrenheit, and Kelvin.\n");
    printf("Please follow the prompts to make your conversions!\n\n");
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

double fahrenheit_to_kelvin(double fahrenheit) {
    double celsius = fahrenheit_to_celsius(fahrenheit);
    return celsius_to_kelvin(celsius);
}

double kelvin_to_fahrenheit(double kelvin) {
    double celsius = kelvin_to_celsius(kelvin);
    return celsius_to_fahrenheit(celsius);
}

void display_menu() {
    printf("Conversion Options:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
}

int main() {
    int choice;
    double temperature, result;

    welcome_message();

    do {
        display_menu();
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 7) {
            if (choice != 7)
                printf("Invalid choice, please try again!\n\n");
            continue;
        }

        if (choice == 7) {
            printf("Exiting the Temperature Converter. Goodbye!\n");
            break;
        }

        printf("Enter the temperature you would like to convert: ");
        scanf("%lf", &temperature);

        switch (choice) {
            case 1:
                result = celsius_to_fahrenheit(temperature);
                printf("%.2f Celsius is %.2f Fahrenheit.\n\n", temperature, result);
                break;
            case 2:
                result = fahrenheit_to_celsius(temperature);
                printf("%.2f Fahrenheit is %.2f Celsius.\n\n", temperature, result);
                break;
            case 3:
                result = celsius_to_kelvin(temperature);
                printf("%.2f Celsius is %.2f Kelvin.\n\n", temperature, result);
                break;
            case 4:
                result = kelvin_to_celsius(temperature);
                printf("%.2f Kelvin is %.2f Celsius.\n\n", temperature, result);
                break;
            case 5:
                result = fahrenheit_to_kelvin(temperature);
                printf("%.2f Fahrenheit is %.2f Kelvin.\n\n", temperature, result);
                break;
            case 6:
                result = kelvin_to_fahrenheit(temperature);
                printf("%.2f Kelvin is %.2f Fahrenheit.\n\n", temperature, result);
                break;
            default:
                printf("This should never happen!\n");
                break;
        }
    } while (1);

    return 0;
}