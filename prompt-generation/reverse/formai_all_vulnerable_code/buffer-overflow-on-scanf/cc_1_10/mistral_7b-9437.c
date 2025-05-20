//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

float fahrenheit_to_celsius(float temperature_f) {
    return (5.0f / 9.0f) * (temperature_f - 32.0f);
}

float celsius_to_fahrenheit(float temperature_c) {
    return (temperature_c * 9.0f / 5.0f) + 32.0f;
}

void print_menu() {
    printf("\n*********************************\n");
    printf("* Welcome to Temperature Converter *\n");
    printf("*********************************\n");
    printf("* 1. Convert Fahrenheit to Celsius *\n");
    printf("* 2. Convert Celsius to Fahrenheit *\n");
    printf("* 3. Exit                         *\n");
    printf("*********************************\n");
}

int main() {
    char choice;
    float temperature, result;

    while (1) {
        print_menu();
        scanf("%c", &choice);

        if (choice == '1') {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);

            while (getchar() != '\n') {
                putchar(getchar());
            }

            result = fahrenheit_to_celsius(temperature);
            printf("The temperature in Celsius is: %.2f\n", result);
        } else if (choice == '2') {
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);

            while (getchar() != '\n') {
                putchar(getchar());
            }

            result = celsius_to_fahrenheit(temperature);
            printf("The temperature in Fahrenheit is: %.2f\n", result);
        } else if (choice == '3') {
            printf("Exiting program...\n");
            exit(0);
        } else {
            printf("Invalid choice! Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}