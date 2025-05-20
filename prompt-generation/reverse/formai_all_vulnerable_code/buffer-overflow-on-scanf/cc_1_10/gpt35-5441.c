//FormAI DATASET v1.0 Category: Temperature Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>

float convert_to_celsius(float fahrenheit);
float convert_to_fahrenheit(float celsius);

int main() {
    int choice;
    float temperature, converted_temp;

    do {
        printf("\n--- Temperature Converter ---\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &temperature);
                converted_temp = convert_to_fahrenheit(temperature);
                printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, converted_temp);
                break;
            case 2:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                converted_temp = convert_to_celsius(temperature);
                printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, converted_temp);
                break;
            case 3:
                printf("\nExiting...");
                exit(0);
                break;
            default:
                printf("\nPlease enter a valid choice!\n");
                break;
        }
    } while (1);

    return 0;
}

/* Function to convert Celsius to Fahrenheit */
float convert_to_fahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

/* Function to convert Fahrenheit to Celsius */
float convert_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}