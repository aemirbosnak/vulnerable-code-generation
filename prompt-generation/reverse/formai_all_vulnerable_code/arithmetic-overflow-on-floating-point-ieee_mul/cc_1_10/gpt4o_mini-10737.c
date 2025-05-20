//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: multivariable
#include <stdio.h>

// Function prototypes
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);
double celsiusToKelvin(double celsius);
double kelvinToCelsius(double kelvin);
void displayMenu();
void userInput();

int main() {
    userInput(); // Call the user interaction function
    return 0;
}

// Function to display the user menu
void displayMenu() {
    printf("Temperature Converter\n");
    printf("======================\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Convert Celsius to Kelvin\n");
    printf("4. Convert Kelvin to Celsius\n");
    printf("5. Exit\n");
    printf("======================\n");
}

// Function to handle user input and execute conversions
void userInput() {
    int choice;
    double inputTemp, resultTemp;

    do {
        displayMenu(); // Show the menu
        printf("Select an option (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &inputTemp);
                resultTemp = celsiusToFahrenheit(inputTemp);
                printf("%.2lf Celsius = %.2lf Fahrenheit\n", inputTemp, resultTemp);
                break;
                
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &inputTemp);
                resultTemp = fahrenheitToCelsius(inputTemp);
                printf("%.2lf Fahrenheit = %.2lf Celsius\n", inputTemp, resultTemp);
                break;

            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &inputTemp);
                resultTemp = celsiusToKelvin(inputTemp);
                printf("%.2lf Celsius = %.2lf Kelvin\n", inputTemp, resultTemp);
                break;

            case 4:
                printf("Enter temperature in Kelvin: ");
                scanf("%lf", &inputTemp);
                resultTemp = kelvinToCelsius(inputTemp);
                printf("%.2lf Kelvin = %.2lf Celsius\n", inputTemp, resultTemp);
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
        
        printf("\n"); // Add space for readability
    } while (choice != 5); // Continue until user chooses to exit
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}