//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: decentralized
#include <stdio.h>

// Function prototypes
void displayMenu();
void convertCelsiusToFahrenheit();
void convertFahrenheitToCelsius();
void convertCelsiusToKelvin();
void convertKelvinToCelsius();
void convertFahrenheitToKelvin();
void convertKelvinToFahrenheit();

// Main function
int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("\nChoose an option (1-6) or 0 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertCelsiusToFahrenheit();
                break;
            case 2:
                convertFahrenheitToCelsius();
                break;
            case 3:
                convertCelsiusToKelvin();
                break;
            case 4:
                convertKelvinToCelsius();
                break;
            case 5:
                convertFahrenheitToKelvin();
                break;
            case 6:
                convertKelvinToFahrenheit();
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n=== Temperature Converter ===");
    printf("\n1. Celsius to Fahrenheit");
    printf("\n2. Fahrenheit to Celsius");
    printf("\n3. Celsius to Kelvin");
    printf("\n4. Kelvin to Celsius");
    printf("\n5. Fahrenheit to Kelvin");
    printf("\n6. Kelvin to Fahrenheit");
}

// Function to convert Celsius to Fahrenheit
void convertCelsiusToFahrenheit() {
    float celsius, fahrenheit;
    printf("\nEnter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f Celsius is %.2f Fahrenheit\n", celsius, fahrenheit);
}

// Function to convert Fahrenheit to Celsius
void convertFahrenheitToCelsius() {
    float fahrenheit, celsius;
    printf("\nEnter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) * 5/9;
    printf("%.2f Fahrenheit is %.2f Celsius\n", fahrenheit, celsius);
}

// Function to convert Celsius to Kelvin
void convertCelsiusToKelvin() {
    float celsius, kelvin;
    printf("\nEnter temperature in Celsius: ");
    scanf("%f", &celsius);
    kelvin = celsius + 273.15;
    printf("%.2f Celsius is %.2f Kelvin\n", celsius, kelvin);
}

// Function to convert Kelvin to Celsius
void convertKelvinToCelsius() {
    float kelvin, celsius;
    printf("\nEnter temperature in Kelvin: ");
    scanf("%f", &kelvin);
    celsius = kelvin - 273.15;
    printf("%.2f Kelvin is %.2f Celsius\n", kelvin, celsius);
}

// Function to convert Fahrenheit to Kelvin
void convertFahrenheitToKelvin() {
    float fahrenheit, kelvin;
    printf("\nEnter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    kelvin = (fahrenheit - 32) * 5/9 + 273.15;
    printf("%.2f Fahrenheit is %.2f Kelvin\n", fahrenheit, kelvin);
}

// Function to convert Kelvin to Fahrenheit
void convertKelvinToFahrenheit() {
    float kelvin, fahrenheit;
    printf("\nEnter temperature in Kelvin: ");
    scanf("%f", &kelvin);
    fahrenheit = (kelvin - 273.15) * 9/5 + 32;
    printf("%.2f Kelvin is %.2f Fahrenheit\n", kelvin, fahrenheit);
}