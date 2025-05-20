//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: enthusiastic
#include <stdio.h>

/* Function declarations */
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void displayMenu();
void handleConversion(int choice);

int main() {
    printf("Welcome to the Ultimate Temperature Converter!\n");
    printf("===============================================\n");
    
    int choice;
    while (1) {
        displayMenu();
        printf("Please enter your choice (1 or 2): ");
        scanf("%d", &choice);
        
        if (choice == 3) {
            printf("Thank you for using the Temperature Converter! Goodbye!\n");
            break; // Exit the loop and end the program
        }

        handleConversion(choice);
    }
    
    return 0;
}

void displayMenu() {
    printf("\nChoose a conversion option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

void handleConversion(int choice) {
    float temperature;
    
    switch (choice) {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &temperature);
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, celsiusToFahrenheit(temperature));
            break;
        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, fahrenheitToCelsius(temperature));
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}