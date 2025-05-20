//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: high level of detail
#include <stdio.h>

// Function prototypes
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void displayMenu();
void performConversion(int choice);

int main() {
    int userChoice;

    printf("Welcome to the Temperature Converter Program!\n");
    printf("You can convert temperatures between Celsius and Fahrenheit.\n");

    do {
        displayMenu();
        printf("Please enter your choice (1-3): ");
        scanf("%d", &userChoice);

        if (userChoice != 3) {
            performConversion(userChoice);
        }
    } while (userChoice != 3); // Continue until user chooses to exit

    printf("Thank you for using the Temperature Converter. Goodbye!\n");
    return 0;
}

void displayMenu() {
    printf("\nMenu Options:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

void performConversion(int choice) {
    float temperatureInput;
    float convertedTemperature;

    if (choice == 1) {
        printf("You selected Celsius to Fahrenheit conversion.\n");
        printf("Please enter the temperature in Celsius: ");
        scanf("%f", &temperatureInput);
        convertedTemperature = celsiusToFahrenheit(temperatureInput);
        printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperatureInput, convertedTemperature);
    } 
    else if (choice == 2) {
        printf("You selected Fahrenheit to Celsius conversion.\n");
        printf("Please enter the temperature in Fahrenheit: ");
        scanf("%f", &temperatureInput);
        convertedTemperature = fahrenheitToCelsius(temperatureInput);
        printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperatureInput, convertedTemperature);
    } 
    else {
        printf("Invalid choice! Please select a valid option from the menu.\n");
    }
}

float celsiusToFahrenheit(float celsius) {
    // Formula to convert Celsius to Fahrenheit
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit) {
    // Formula to convert Fahrenheit to Celsius
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}