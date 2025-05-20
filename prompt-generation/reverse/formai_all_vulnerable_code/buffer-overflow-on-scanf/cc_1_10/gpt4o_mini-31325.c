//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: mind-bending
#include <stdio.h>

// Function declarations
void displayWelcomeMessage();
void displayMenu();
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);
double celsiusToKelvin(double celsius);
double kelvinToCelsius(double kelvin);
double fahrenheitToKelvin(double fahrenheit);
double kelvinToFahrenheit(double kelvin);
void performTemperatureConversion(int choice);

int main() {
    int choice;
    displayWelcomeMessage();

    while (1) {
        displayMenu();
        printf("Enter your choice (1-6 or 0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            break; // Exit the loop
        }
        // Perform the conversion based on user choice
        performTemperatureConversion(choice);
    }

    printf("Thank you for playing with temperatures! Until next time!\n");
    return 0;
}

void displayWelcomeMessage() {
    printf("********************************************\n");
    printf("* Welcome to the Mind-Bending Temp Convertor *\n");
    printf("********************************************\n");
}

void displayMenu() {
    printf("\nChoose your conversion adventure:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double fahrenheitToKelvin(double fahrenheit) {
    return celsiusToKelvin(fahrenheitToCelsius(fahrenheit));
}

double kelvinToFahrenheit(double kelvin) {
    return celsiusToFahrenheit(kelvinToCelsius(kelvin));
}

void performTemperatureConversion(int choice) {
    double inputTemp, resultTemp;

    // Determine the conversion and process the input
    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &inputTemp);
            resultTemp = celsiusToFahrenheit(inputTemp);
            printf("%.2lf°C is equivalent to %.2lf°F\n", inputTemp, resultTemp);
            break;
        
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &inputTemp);
            resultTemp = fahrenheitToCelsius(inputTemp);
            printf("%.2lf°F is equivalent to %.2lf°C\n", inputTemp, resultTemp);
            break;
        
        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &inputTemp);
            resultTemp = celsiusToKelvin(inputTemp);
            printf("%.2lf°C is equivalent to %.2lf K\n", inputTemp, resultTemp);
            break;
        
        case 4:
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &inputTemp);
            resultTemp = kelvinToCelsius(inputTemp);
            printf("%.2lf K is equivalent to %.2lf°C\n", inputTemp, resultTemp);
            break;
        
        case 5:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &inputTemp);
            resultTemp = fahrenheitToKelvin(inputTemp);
            printf("%.2lf°F is equivalent to %.2lf K\n", inputTemp, resultTemp);
            break;
        
        case 6:
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &inputTemp);
            resultTemp = kelvinToFahrenheit(inputTemp);
            printf("%.2lf K is equivalent to %.2lf°F\n", inputTemp, resultTemp);
            break;

        default:
            printf("Invalid choice. Please select a valid conversion.\n");
            break;
    }
}