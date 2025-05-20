//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: satisfied
#include <stdio.h>

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void display_menu() {
    printf("\n");
    printf("=====================================\n");
    printf("   Temperature Converter Program     \n");
    printf("=====================================\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("=====================================\n");
    printf("Please choose an option (1-3): ");
}

int main() {
    int choice;
    float temperature, converted_temp;

    while (1) {
        display_menu();

        // Take user choice
        scanf("%d", &choice);

        // Process user choice
        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                converted_temp = celsius_to_fahrenheit(temperature);
                printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, converted_temp);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                converted_temp = fahrenheit_to_celsius(temperature);
                printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, converted_temp);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}