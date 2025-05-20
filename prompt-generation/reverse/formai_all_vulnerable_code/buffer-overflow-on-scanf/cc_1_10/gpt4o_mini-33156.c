//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: intelligent
#include <stdio.h>

// Function prototypes
void displayMenu();
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);
double celsiusToKelvin(double celsius);
double kelvinToCelsius(double kelvin);
double fahrenheitToKelvin(double fahrenheit);
double kelvinToFahrenheit(double kelvin);
void performConversion(int choice);

int main() {
    int choice;
    
    printf("Welcome to the Temperature Converter!\n");
    
    do {
        displayMenu();
        
        printf("Enter your choice (1-6) or 0 to exit: ");
        scanf("%d", &choice);
        
        if (choice < 0 || choice > 6) {
            printf("Invalid choice! Please try again.\n");
        } else if (choice != 0) {
            performConversion(choice);
        }
        
    } while (choice != 0);
    
    printf("Thank you for using the Temperature Converter. Goodbye!\n");
    
    return 0;
}

void displayMenu() {
    printf("\nTemperature Conversion Options:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}

void performConversion(int choice) {
    double inputTemperature, outputTemperature;

    switch (choice) {
        case 1: // Celsius to Fahrenheit
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &inputTemperature);
            outputTemperature = celsiusToFahrenheit(inputTemperature);
            printf("%.2f Celsius = %.2f Fahrenheit\n", inputTemperature, outputTemperature);
            break;
            
        case 2: // Fahrenheit to Celsius
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &inputTemperature);
            outputTemperature = fahrenheitToCelsius(inputTemperature);
            printf("%.2f Fahrenheit = %.2f Celsius\n", inputTemperature, outputTemperature);
            break;
            
        case 3: // Celsius to Kelvin
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &inputTemperature);
            outputTemperature = celsiusToKelvin(inputTemperature);
            printf("%.2f Celsius = %.2f Kelvin\n", inputTemperature, outputTemperature);
            break;
            
        case 4: // Kelvin to Celsius
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &inputTemperature);
            outputTemperature = kelvinToCelsius(inputTemperature);
            printf("%.2f Kelvin = %.2f Celsius\n", inputTemperature, outputTemperature);
            break;
            
        case 5: // Fahrenheit to Kelvin
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &inputTemperature);
            outputTemperature = fahrenheitToKelvin(inputTemperature);
            printf("%.2f Fahrenheit = %.2f Kelvin\n", inputTemperature, outputTemperature);
            break;
            
        case 6: // Kelvin to Fahrenheit
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &inputTemperature);
            outputTemperature = kelvinToFahrenheit(inputTemperature);
            printf("%.2f Kelvin = %.2f Fahrenheit\n", inputTemperature, outputTemperature);
            break;
        default:
            printf("Invalid option!\n");
            break;
    }
}