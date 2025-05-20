//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Dennis Ritchie
#include <stdio.h>

void displayMenu();
void convertToCelsius(float fahrenheit);
void convertToFahrenheit(float celsius);

int main() {
    int choice;
    float temperature;

    while (1) {
        displayMenu();
        
        printf("Enter your choice (1-3, 3 to exit): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (choice == 3) {
            printf("Exiting the Temperature Converter. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                if (scanf("%f", &temperature) != 1) {
                    printf("Invalid input. Please enter a valid number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                convertToCelsius(temperature);
                break;
            case 2:
                printf("Enter temperature in Celsius: ");
                if (scanf("%f", &temperature) != 1) {
                    printf("Invalid input. Please enter a valid number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                convertToFahrenheit(temperature);
                break;
            default:
                printf("Invalid choice. Please select between 1 and 3.\n");
                break;
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\nTemperature Converter Menu\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Exit\n");
}

void convertToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5 / 9;
    printf("Temperature in Celsius: %.2f°C\n", celsius);
}

void convertToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9 / 5) + 32;
    printf("Temperature in Fahrenheit: %.2f°F\n", fahrenheit);
}