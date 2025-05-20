//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: inquisitive
#include <stdio.h>

void displayMenu() {
    printf("************************************\n");
    printf("         Welcome to TempBot!       \n");
    printf("************************************\n");
    printf("Hello, inquisitive mind!\n");
    printf("Would you like to convert temperatures?\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Please select an option (1-3): ");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0/9.0;
}

void performConversion(int choice) {
    float temperature;
    
    if (choice == 1) {
        printf("Great choice! Enter the temperature in Celsius: ");
        scanf("%f", &temperature);
        float fahrenheit = celsiusToFahrenheit(temperature);
        printf("That’s %.2f°C is equivalent to %.2f°F!\n", temperature, fahrenheit);
    } else if (choice == 2) {
        printf("Awesome! Enter the temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        float celsius = fahrenheitToCelsius(temperature);
        printf("Wow! %.2f°F converts to %.2f°C!\n", temperature, celsius);
    } else {
        printf("Thank you for interacting with TempBot! Goodbye!\n");
    }
}

int main() {
    int choice = 0;

    while (choice != 3) {
        displayMenu();
        scanf("%d", &choice);
        
        if (choice < 1 || choice > 3) {
            printf("Hmm... that doesn't seem to be a valid option. Please try again!\n");
        } else {
            if (choice != 3) {
                performConversion(choice);
            }
        }
    }
    return 0;
}