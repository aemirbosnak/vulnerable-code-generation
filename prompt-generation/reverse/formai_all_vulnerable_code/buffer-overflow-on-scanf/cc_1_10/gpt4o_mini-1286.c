//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: detailed
#include <stdio.h>

// Function prototypes
void displayMenu();
void convertCelsiusToFahrenheit();
void convertFahrenheitToCelsius();

int main() {
    int choice;
    
    // Introductory message
    printf("===================================\n");
    printf("   Welcome to the Temperature Converter   \n");
    printf("===================================\n");
    
    do {
        displayMenu();
        printf("Please enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertCelsiusToFahrenheit();
                break;
            case 2:
                convertFahrenheitToCelsius();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
    } while (choice != 3);
    
    return 0;
}

// Function to display the menu options
void displayMenu() {
    printf("\nTemperature Conversion Menu:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

// Function to convert Celsius to Fahrenheit
void convertCelsiusToFahrenheit() {
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    
    // Conversion formula
    fahrenheit = (celsius * 9 / 5) + 32;
    
    // Display the result
    printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);
}

// Function to convert Fahrenheit to Celsius
void convertFahrenheitToCelsius() {
    float fahrenheit, celsius;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    
    // Conversion formula
    celsius = (fahrenheit - 32) * 5 / 9;
    
    // Display the result
    printf("%.2f Fahrenheit is equal to %.2f Celsius\n", fahrenheit, celsius);
}