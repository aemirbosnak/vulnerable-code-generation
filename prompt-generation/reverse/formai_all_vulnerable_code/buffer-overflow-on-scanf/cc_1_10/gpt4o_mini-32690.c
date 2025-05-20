//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: realistic
#include <stdio.h>

// Function to display the menu
void displayMenu() {
    printf("*************************************\n");
    printf("      Temperature Converter          \n");
    printf("*************************************\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
    printf("*************************************\n");
    printf("Choose an option (0-6): ");
}

// Function for converting Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function for converting Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function for converting Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

// Function for converting Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

// Function for converting Fahrenheit to Kelvin
float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0 + 273.15;
}

// Function for converting Kelvin to Fahrenheit
float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}

// Main function
int main() {
    int option;
    float inputTemp;
    float outputTemp;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        if (option == 0) {
            printf("Exiting the Temperature Converter. Goodbye!\n");
            break;
        }

        if (option < 1 || option > 6) {
            printf("Invalid option! Please select a valid option.\n");
            continue;
        }

        printf("Enter the temperature: ");
        scanf("%f", &inputTemp);

        switch (option) {
            case 1:
                // Celsius to Fahrenheit
                outputTemp = celsiusToFahrenheit(inputTemp);
                printf("%.2f Celsius is %.2f Fahrenheit\n", inputTemp, outputTemp);
                break;

            case 2:
                // Fahrenheit to Celsius
                outputTemp = fahrenheitToCelsius(inputTemp);
                printf("%.2f Fahrenheit is %.2f Celsius\n", inputTemp, outputTemp);
                break;

            case 3:
                // Celsius to Kelvin
                outputTemp = celsiusToKelvin(inputTemp);
                printf("%.2f Celsius is %.2f Kelvin\n", inputTemp, outputTemp);
                break;

            case 4:
                // Kelvin to Celsius
                outputTemp = kelvinToCelsius(inputTemp);
                printf("%.2f Kelvin is %.2f Celsius\n", inputTemp, outputTemp);
                break;

            case 5:
                // Fahrenheit to Kelvin
                outputTemp = fahrenheitToKelvin(inputTemp);
                printf("%.2f Fahrenheit is %.2f Kelvin\n", inputTemp, outputTemp);
                break;

            case 6:
                // Kelvin to Fahrenheit
                outputTemp = kelvinToFahrenheit(inputTemp);
                printf("%.2f Kelvin is %.2f Fahrenheit\n", inputTemp, outputTemp);
                break;

            default:
                printf("Error: Invalid option. Please try again.\n");
                break;
        }

        printf("\nPress Enter to continue...\n");
        getchar(); // Clear the buffer and wait for user input
        getchar(); // Wait for Enter key
    }

    return 0;
}