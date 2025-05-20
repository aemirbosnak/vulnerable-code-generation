//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: modular
#include <stdio.h>

// Function prototypes
void displayMenu();
void convertFromCelsius();
void convertFromFahrenheit();
void convertFromKelvin();
float celsiusToFahrenheit(float celsius);
float celsiusToKelvin(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToCelsius(float kelvin);
float kelvinToFahrenheit(float kelvin);

int main() {
    int choice;

    do {
        displayMenu();
        printf("Select an option (1-4, or 5 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertFromCelsius();
                break;
            case 2:
                convertFromFahrenheit();
                break;
            case 3:
                convertFromKelvin();
                break;
            case 4:
                printf("Conversion options selected!\n");
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// Function Definitions
void displayMenu() {
    printf("\nTemperature Converter\n");
    printf("1. Convert Celsius\n");
    printf("2. Convert Fahrenheit\n");
    printf("3. Convert Kelvin\n");
    printf("4. Display conversion options\n");
    printf("5. Exit\n");
}

void convertFromCelsius() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, celsiusToFahrenheit(celsius));
    printf("%.2f Celsius = %.2f Kelvin\n", celsius, celsiusToKelvin(celsius));
}

void convertFromFahrenheit() {
    float fahrenheit;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    
    printf("%.2f Fahrenheit = %.2f Celsius\n", fahrenheit, fahrenheitToCelsius(fahrenheit));
    printf("%.2f Fahrenheit = %.2f Kelvin\n", fahrenheit, fahrenheitToKelvin(fahrenheit));
}

void convertFromKelvin() {
    float kelvin;
    printf("Enter temperature in Kelvin: ");
    scanf("%f", &kelvin);
    
    printf("%.2f Kelvin = %.2f Celsius\n", kelvin, kelvinToCelsius(kelvin));
    printf("%.2f Kelvin = %.2f Fahrenheit\n", kelvin, kelvinToFahrenheit(kelvin));
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0 + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}