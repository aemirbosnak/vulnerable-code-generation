//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MIN_TEMP -50.0
#define MAX_TEMP 150.0

void celsius_to_fahrenheit(double celsius) {
    double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
}

void fahrenheit_to_celsius(double fahrenheit) {
    double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
}

int main() {
    char choice;
    double temperature;

    do {
        printf("\nWelcome to the Temperature Converter!\n");
        printf("1. Convert from Celsius to Fahrenheit\n");
        printf("2. Convert from Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                while(temperature < MIN_TEMP || temperature > MAX_TEMP) {
                    printf("Invalid temperature. Temperature must be between -50 and 150 degrees.\n");
                    printf("Enter temperature in Celsius: ");
                    scanf("%lf", &temperature);
                }
                celsius_to_fahrenheit(temperature);
                break;
            case '2':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                while(temperature < -459.67 || temperature > 1093.6) {
                    printf("Invalid temperature. Temperature must be valid.\n");
                    printf("Enter temperature in Fahrenheit: ");
                    scanf("%lf", &temperature);
                }
                fahrenheit_to_celsius(temperature);
                break;
            case '3':
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while(1);

    return 0;
}