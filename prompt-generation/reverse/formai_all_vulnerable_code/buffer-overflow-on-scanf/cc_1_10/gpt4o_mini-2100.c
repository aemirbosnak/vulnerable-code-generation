//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: enthusiastic
#include <stdio.h>

void displayWelcomeMessage() {
    printf("************************************\n");
    printf("* Welcome to the Temperature Converter! *\n");
    printf("************************************\n");
    printf("Convert temperatures between Celsius and Fahrenheit with ease!\n\n");
}

void displayMenu() {
    printf("Select the conversion you want to perform:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

void performConversion(int choice) {
    float temperature, result;
    
    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        result = celsiusToFahrenheit(temperature);
        printf("%.2f Celsius is equal to %.2f Fahrenheit.\n\n", temperature, result);
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        result = fahrenheitToCelsius(temperature);
        printf("%.2f Fahrenheit is equal to %.2f Celsius.\n\n", temperature, result);
    } else {
        printf("Exiting the program. Thank you for using the Temperature Converter!\n");
    }
}

int main() {
    int choice;
    displayWelcomeMessage();
    
    do {
        displayMenu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        
        if (choice == 1 || choice == 2) {
            performConversion(choice);
        } else if (choice != 3) {
            printf("Invalid choice! Please choose between 1 and 3.\n\n");
        }

    } while (choice != 3);
    
    return 0;
}