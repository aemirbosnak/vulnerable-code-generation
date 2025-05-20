//FormAI DATASET v1.0 Category: Temperature Converter ; Style: standalone
#include <stdio.h>

void instructions() {
    printf("\nThis program converts temperature values from Celsius to Fahrenheit and vice versa.\n\n");
    printf("Enter 1 to convert from Celsius to Fahrenheit.\n");
    printf("Enter 2 to convert from Fahrenheit to Celsius.\n");
    printf("Enter 0 to exit the program.\n\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

int main() {
    float temp;
    int choice;

    printf("Welcome to the temperature converter!\n\n");

    do {
        instructions();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("\nThank you for using the temperature converter! Goodbye.\n");
                break;
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &temp);
                printf("\n%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n\n", temp, celsiusToFahrenheit(temp));
                break;
            case 2:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &temp);
                printf("\n%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n\n", temp, fahrenheitToCelsius(temp));
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}