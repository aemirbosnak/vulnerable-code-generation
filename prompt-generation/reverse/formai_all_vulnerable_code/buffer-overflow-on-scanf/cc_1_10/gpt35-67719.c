//FormAI DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

// Function to convert Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
    float celsius = kelvin - 273.15;
    return celsius;
}

// Function to convert Fahrenheit to Kelvin
float fahrenheitToKelvin(float fahrenheit) {
    float kelvin = (fahrenheit + 459.67) * 5 / 9;
    return kelvin;
}

// Function to convert Kelvin to Fahrenheit
float kelvinToFahrenheit(float kelvin) {
    float fahrenheit = (kelvin * 9 / 5) - 459.67;
    return fahrenheit;
}

int main() {
    int choice;
    float temperature, convertedTemperature;

    printf("Welcome to the Unit Converter!\n");

    // Loop to keep the program running until the user chooses to exit
    while(1) {
        printf("\nPlease select an option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Celsius to Kelvin\n");
        printf("4. Kelvin to Celsius\n");
        printf("5. Fahrenheit to Kelvin\n");
        printf("6. Kelvin to Fahrenheit\n");
        printf("7. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        // Take the user's input temperature
        printf("Enter the temperature: ");
        scanf("%f", &temperature);

        switch(choice) {
            case 1:
                // Convert Celsius to Fahrenheit
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%f Celsius = %f Fahrenheit\n", temperature, convertedTemperature);
                break;

            case 2:
                // Convert Fahrenheit to Celsius
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%f Fahrenheit = %f Celsius\n", temperature, convertedTemperature);
                break;

            case 3:
                // Convert Celsius to Kelvin
                convertedTemperature = celsiusToKelvin(temperature);
                printf("%f Celsius = %f Kelvin\n", temperature, convertedTemperature);
                break;

            case 4:
                // Convert Kelvin to Celsius
                convertedTemperature = kelvinToCelsius(temperature);
                printf("%f Kelvin = %f Celsius\n", temperature, convertedTemperature);
                break;

            case 5:
                // Convert Fahrenheit to Kelvin
                convertedTemperature = fahrenheitToKelvin(temperature);
                printf("%f Fahrenheit = %f Kelvin\n", temperature, convertedTemperature);
                break;

            case 6:
                // Convert Kelvin to Fahrenheit
                convertedTemperature = kelvinToFahrenheit(temperature);
                printf("%f Kelvin = %f Fahrenheit\n", temperature, convertedTemperature);
                break;

            case 7:
                // Exit the program
                printf("Thank you for using the Unit Converter!\n");
                return 0;

            default:
                printf("Invalid choice, please select a number between 1 and 7.\n");
                break;
        }
    }
}