//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: visionary
#include <stdio.h>

// Function prototypes
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float celsiusToKelvin(float celsius);
float kelvinToCelsius(float kelvin);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToFahrenheit(float kelvin);

void displayMenu();
void processChoice(int choice);
void clearScreen();

int main() {
    int choice;
    
    do {
        clearScreen();
        displayMenu();
        
        printf("Enter your choice (1-6) or 0 to exit: ");
        scanf("%d", &choice);
        
        processChoice(choice);
    } while (choice != 0);
    
    printf("Thank you for using the Temperature Converter. Goodbye!\n");
    return 0;
}

void displayMenu() {
    printf("========================================\n");
    printf("          Temperature Converter         \n");
    printf("========================================\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
    printf("========================================\n");
}

void processChoice(int choice) {
    float inputTemperature, outputTemperature;
    
    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &inputTemperature);
            outputTemperature = celsiusToFahrenheit(inputTemperature);
            printf("%.2f Celsius = %.2f Fahrenheit\n", inputTemperature, outputTemperature);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &inputTemperature);
            outputTemperature = fahrenheitToCelsius(inputTemperature);
            printf("%.2f Fahrenheit = %.2f Celsius\n", inputTemperature, outputTemperature);
            break;
        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &inputTemperature);
            outputTemperature = celsiusToKelvin(inputTemperature);
            printf("%.2f Celsius = %.2f Kelvin\n", inputTemperature, outputTemperature);
            break;
        case 4:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &inputTemperature);
            outputTemperature = kelvinToCelsius(inputTemperature);
            printf("%.2f Kelvin = %.2f Celsius\n", inputTemperature, outputTemperature);
            break;
        case 5:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &inputTemperature);
            outputTemperature = fahrenheitToKelvin(inputTemperature);
            printf("%.2f Fahrenheit = %.2f Kelvin\n", inputTemperature, outputTemperature);
            break;
        case 6:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &inputTemperature);
            outputTemperature = kelvinToFahrenheit(inputTemperature);
            printf("%.2f Kelvin = %.2f Fahrenheit\n", inputTemperature, outputTemperature);
            break;
        case 0:
            // Exit option already handled in main loop
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
    
    getchar(); // To clear the newline character from the input buffer
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user to continue
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheitToKelvin(float fahrenheit) {
    return celsiusToKelvin(fahrenheitToCelsius(fahrenheit));
}

float kelvinToFahrenheit(float kelvin) {
    return celsiusToFahrenheit(kelvinToCelsius(kelvin));
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the screen
}