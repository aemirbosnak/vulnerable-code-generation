//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: interoperable
#include <stdio.h>

// Function prototypes
void displayMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void getTemperature(float *temperature);
void convertTemperature(int choice);

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Choose an option (1-3): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 3.\n");
            // Clear the invalid input
            while (getchar() != '\n');
            choice = 0; // Reset choice
        }
        
        switch (choice) {
            case 1:
                convertTemperature(choice);
                break;
            case 2:
                convertTemperature(choice);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\nTemperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to handle temperature input
void getTemperature(float *temperature) {
    printf("Enter the temperature: ");
    while (scanf("%f", temperature) != 1) {
        printf("Invalid input. Please enter a valid temperature: ");
        // Clear invalid input
        while (getchar() != '\n');
    }
}

// Function to perform temperature conversion based on user choice
void convertTemperature(int choice) {
    float temperature, convertedTemperature;

    if (choice == 1) {
        // Celsius to Fahrenheit
        getTemperature(&temperature);
        convertedTemperature = celsiusToFahrenheit(temperature);
        printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, convertedTemperature);
    } else if (choice == 2) {
        // Fahrenheit to Celsius
        getTemperature(&temperature);
        convertedTemperature = fahrenheitToCelsius(temperature);
        printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, convertedTemperature);
    }
}