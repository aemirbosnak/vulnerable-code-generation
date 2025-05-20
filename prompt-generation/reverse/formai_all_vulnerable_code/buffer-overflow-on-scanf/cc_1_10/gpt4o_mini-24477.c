//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Donald Knuth
#include <stdio.h>

/* A useful function to convert Celsius to Fahrenheit */
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

/* A delightful function to convert Fahrenheit to Celsius */
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

/* A function to display the menu that offers several conversion options */
void display_menu() {
    printf("\nTemperature Converter - A delightful experience in conversions!\n");
    printf("----------------------------------------------------------\n");
    printf("Please select the conversion type:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("----------------------------------------------------------\n");
}

/* The main function that orchestrates the converter */
int main() {
    int choice;
    float temperature;
    float converted_temperature;

    printf("\nWelcome to the Temperature Converter!\n");

    do {
        display_menu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                converted_temperature = celsius_to_fahrenheit(temperature);
                printf("The temperature in Fahrenheit is: %.2f°F\n", converted_temperature);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                converted_temperature = fahrenheit_to_celsius(temperature);
                printf("The temperature in Celsius is: %.2f°C\n", converted_temperature);
                break;

            case 3:
                printf("Exiting the program. Thank you for using the Temperature Converter!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 3);

    return 0;
}