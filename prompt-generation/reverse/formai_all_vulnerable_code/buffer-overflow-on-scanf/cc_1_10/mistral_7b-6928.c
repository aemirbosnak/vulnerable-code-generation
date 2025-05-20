//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Enthusiastically named temperature conversion functions 😎
void fahrenheit_to_celcius(float fahrenheit, float *celcius) {
    *celcius = (fahrenheit - 32.0) * 5.0 / 9.0;
}

void celcius_to_fahrenheit(float celcius, float *fahrenheit) {
    *fahrenheit = celcius * 9.0 / 5.0 + 32.0;
}

// 🌡️ Temperature Conversion Menu 🌡️
void temperature_conversion_menu() {
    printf("\n--- Temperature Converter Menu ---\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    float fahrenheit, celcius;
    int choice;

    do {
        temperature_conversion_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                fahrenheit_to_celcius(fahrenheit, &celcius);
                printf("Temperature in Celsius: %.2f°C\n", celcius);
                break;

            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &celcius);
                celcius_to_fahrenheit(celcius, &fahrenheit);
                printf("Temperature in Fahrenheit: %.2f°F\n", fahrenheit);
                break;

            case 3:
                printf("Goodbye! Have a great day! 🌞\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (1); // Infinite loop for the menu

    return 0;
}