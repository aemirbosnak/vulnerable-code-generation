//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: invasive
#include <stdio.h>

void displayMenu() {
    printf("\nTemperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

void performConversion(int option) {
    float temp, result;

    if (option == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temp);
        result = celsiusToFahrenheit(temp);
        printf("%.2f Celsius is equal to %.2f Fahrenheit\n", temp, result);
    } else if (option == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temp);
        result = fahrenheitToCelsius(temp);
        printf("%.2f Fahrenheit is equal to %.2f Celsius\n", temp, result);
    } else {
        printf("Exiting the program.\n");
    }
}

int main() {
    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        if (choice < 1 || choice > 3) {
            printf("Invalid option! Please choose a valid option between 1-3.\n");
        } else {
            if (choice != 3) {
                performConversion(choice);
            }
        }
        
    } while (choice != 3);
    
    return 0;
}