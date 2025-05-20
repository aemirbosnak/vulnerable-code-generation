//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (9.0 / 5.0) * celsius + 32.0;
}

// Function to print temperature conversion menu
void print_menu() {
    printf("\n\n*** Welcome to Temperature Converter ***\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    double temperature, conversion_factor = 1.0;
    char choice;

    while (1) {
        print_menu();
        scanf("%c", &choice);

        if (choice == '1') {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            temperature = fahrenheit_to_celsius(temperature);
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temperature, temperature);
        } else if (choice == '2') {
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            temperature = celsius_to_fahrenheit(temperature);
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature, temperature);
        } else if (choice == '3') {
            printf("Exiting program...\n");
            exit(0);
        } else {
            printf("Invalid choice! Please try again.\n");
        }

        printf("\nDo you want to perform another conversion? (Y/N): ");
        scanf("%c", &choice);
        if (choice != 'Y') {
            break;
        }
    }

    return 0;
}