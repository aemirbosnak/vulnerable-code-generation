//FormAI DATASET v1.0 Category: Temperature Converter ; Style: scalable
#include <stdio.h>

void fahrenheitToCelsius(float f);
void celsiusToFahrenheit(float c);

int main() {
    float temperature;
    int choice;

    printf("Welcome to the Temperature Converter!\n");

    do {
        printf("\nPlease choose an option: \n");
        printf("1. Fahrenheit to Celsius\n");
        printf("2. Celsius to Fahrenheit\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                fahrenheitToCelsius(temperature);
                break;
            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                celsiusToFahrenheit(temperature);
                break;
            case 3:
                printf("\nThank you for using the Temperature Converter.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

void fahrenheitToCelsius(float f) {
    float c = ((f - 32) * 5) / 9;
    printf("%.2f Fahrenheit is %.2f Celsius\n", f, c);
}

void celsiusToFahrenheit(float c) {
    float f = ((c * 9) / 5) + 32;
    printf("%.2f Celsius is %.2f Fahrenheit\n", c, f);
}