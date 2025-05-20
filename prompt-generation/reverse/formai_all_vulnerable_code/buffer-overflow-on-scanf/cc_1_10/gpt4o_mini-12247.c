//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: decentralized
#include <stdio.h>

void print_menu() {
    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Select an option (1-3): ");
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0/9.0;
}

void convert_and_display(int choice) {
    float temperature;

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        float result = celsius_to_fahrenheit(temperature);
        printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, result);
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        float result = fahrenheit_to_celsius(temperature);
        printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, result);
    }
}

int main() {
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            convert_and_display(choice);
        } else if (choice != 3) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    printf("Exiting the Temperature Converter. Goodbye!\n");
    return 0;
}