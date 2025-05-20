//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: systematic
#include <stdio.h>

// Function prototypes
void displayMenu();
void celsiusToFahrenheit();
void celsiusToKelvin();
void fahrenheitToCelsius();
void fahrenheitToKelvin();
void kelvinToCelsius();
void kelvinToFahrenheit();
float getTemperatureInput();

int main() {
    int choice;

    // Main loop
    do {
        displayMenu();
        printf("Enter your choice (1-6), or 0 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: celsiusToFahrenheit(); break;
            case 2: celsiusToKelvin(); break;
            case 3: fahrenheitToCelsius(); break;
            case 4: fahrenheitToKelvin(); break;
            case 5: kelvinToCelsius(); break;
            case 6: kelvinToFahrenheit(); break;
            case 0: printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice! Please select between 0-6.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n======================\n");
    printf("Temperature Converter\n");
    printf("======================\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
}

// Function to convert Celsius to Fahrenheit
void celsiusToFahrenheit() {
    float celsius = getTemperatureInput();
    float fahrenheit = (celsius * 9 / 5) + 32;
    printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);
}

// Function to convert Celsius to Kelvin
void celsiusToKelvin() {
    float celsius = getTemperatureInput();
    float kelvin = celsius + 273.15;
    printf("%.2f Celsius is equal to %.2f Kelvin\n", celsius, kelvin);
}

// Function to convert Fahrenheit to Celsius
void fahrenheitToCelsius() {
    float fahrenheit = getTemperatureInput();
    float celsius = (fahrenheit - 32) * 5 / 9;
    printf("%.2f Fahrenheit is equal to %.2f Celsius\n", fahrenheit, celsius);
}

// Function to convert Fahrenheit to Kelvin
void fahrenheitToKelvin() {
    float fahrenheit = getTemperatureInput();
    float kelvin = (fahrenheit - 32) * 5 / 9 + 273.15;
    printf("%.2f Fahrenheit is equal to %.2f Kelvin\n", fahrenheit, kelvin);
}

// Function to convert Kelvin to Celsius
void kelvinToCelsius() {
    float kelvin = getTemperatureInput();
    float celsius = kelvin - 273.15;
    printf("%.2f Kelvin is equal to %.2f Celsius\n", kelvin, celsius);
}

// Function to convert Kelvin to Fahrenheit
void kelvinToFahrenheit() {
    float kelvin = getTemperatureInput();
    float fahrenheit = (kelvin - 273.15) * 9 / 5 + 32;
    printf("%.2f Kelvin is equal to %.2f Fahrenheit\n", kelvin, fahrenheit);
}

// Function to get a valid temperature input from the user
float getTemperatureInput() {
    float temp;
    printf("Enter the temperature: ");
    scanf("%f", &temp);
    return temp;
}