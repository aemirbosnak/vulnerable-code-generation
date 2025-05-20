//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: thoughtful
#include <stdio.h>

// Function prototypes
void displayMenu();
void convertCelsiusToFahrenheit();
void convertFahrenheitToCelsius();
void convertCelsiusToKelvin();
void convertKelvinToCelsius();
void convertFahrenheitToKelvin();
void convertKelvinToFahrenheit();
void pause();

// Main function
int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-7) or 0 to exit: ");
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
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
        pause();
    } while (choice != 0);

    return 0;
}

// Function to display the menu options
void displayMenu() {
    printf("\n*** Temperature Converter ***\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Convert Celsius to Kelvin\n");
    printf("4. Convert Kelvin to Celsius\n");
    printf("5. Convert Fahrenheit to Kelvin\n");
    printf("6. Convert Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
}

// Function to convert Celsius to Fahrenheit
void convertCelsiusToFahrenheit() {
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("%.2f Celsius is %.2f Fahrenheit\n", celsius, fahrenheit);
}

// Function to convert Fahrenheit to Celsius
void convertFahrenheitToCelsius() {
    float fahrenheit, celsius;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) * 5 / 9;
    printf("%.2f Fahrenheit is %.2f Celsius\n", fahrenheit, celsius);
}

// Function to convert Celsius to Kelvin
void convertCelsiusToKelvin() {
    float celsius, kelvin;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    kelvin = celsius + 273.15;
    printf("%.2f Celsius is %.2f Kelvin\n", celsius, kelvin);
}

// Function to convert Kelvin to Celsius
void convertKelvinToCelsius() {
    float kelvin, celsius;
    printf("Enter temperature in Kelvin: ");
    scanf("%f", &kelvin);
    celsius = kelvin - 273.15;
    printf("%.2f Kelvin is %.2f Celsius\n", kelvin, celsius);
}

// Function to convert Fahrenheit to Kelvin
void convertFahrenheitToKelvin() {
    float fahrenheit, kelvin;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    kelvin = (fahrenheit - 32) * 5 / 9 + 273.15;
    printf("%.2f Fahrenheit is %.2f Kelvin\n", fahrenheit, kelvin);
}

// Function to convert Kelvin to Fahrenheit
void convertKelvinToFahrenheit() {
    float kelvin, fahrenheit;
    printf("Enter temperature in Kelvin: ");
    scanf("%f", &kelvin);
    fahrenheit = (kelvin - 273.15) * 9 / 5 + 32;
    printf("%.2f Kelvin is %.2f Fahrenheit\n", kelvin, fahrenheit);
}

// Function to pause the program and wait for user
void pause() {
    printf("Press Enter to continue...");
    while (getchar() != '\n');  // Clear the newline left by the previous input
    getchar();                  // Wait for user to press Enter
}