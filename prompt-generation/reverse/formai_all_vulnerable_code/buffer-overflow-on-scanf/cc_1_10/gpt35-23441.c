//FormAI DATASET v1.0 Category: Temperature Converter ; Style: expert-level
#include <stdio.h>

float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);

int main() {
    float temperature, converted_temperature;
    int choice;

    printf("Welcome to the temperature converter!\n");
    
    do {
        printf("\nSelect an option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                converted_temperature = celsius_to_fahrenheit(temperature);
                printf("%.2f°C = %.2f°F\n", temperature, converted_temperature);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                converted_temperature = fahrenheit_to_celsius(temperature);
                printf("%.2f°F = %.2f°C\n", temperature, converted_temperature);
                break;
            case 3:
                printf("Thanks for using the temperature converter!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 3.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}

float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = ((celsius * 9) / 5) + 32;
    return fahrenheit;
}

float fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}