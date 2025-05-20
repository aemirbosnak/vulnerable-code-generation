//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: inquisitive
#include <stdio.h>

// Function prototypes
void displayMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float celsiusToKelvin(float celsius);
float kelvinToCelsius(float kelvin);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToFahrenheit(float kelvin);

int main() {
    int choice;
    float temperature, convertedTemperature;

    printf("Welcome to the Temperature Converter!\n");
    printf("Let's explore the fascinating world of temperature conversions together!\n");
    
    do {
        displayMenu();
        printf("\nWhat conversion would you like to perform? (1-5, 0 to Exit): ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Thank you for using the Temperature Converter. Goodbye!\n");
            break;
        }
        
        switch (choice) {
            case 1:
                printf("You've chosen Celsius to Fahrenheit. What's the Celsius temperature you want to convert? ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("The temperature in Fahrenheit is: %.2f°F\n", convertedTemperature);
                break;
            case 2:
                printf("You wish to convert Fahrenheit to Celsius. Please enter the Fahrenheit temperature: ");
                scanf("%f", &temperature);
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("The temperature in Celsius is: %.2f°C\n", convertedTemperature);
                break;
            case 3:
                printf("Converting Celsius to Kelvin! What's your Celsius temperature? ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToKelvin(temperature);
                printf("The temperature in Kelvin is: %.2fK\n", convertedTemperature);
                break;
            case 4:
                printf("How exciting! You want to convert Kelvin to Celsius. Please enter the temperature in Kelvin: ");
                scanf("%f", &temperature);
                convertedTemperature = kelvinToCelsius(temperature);
                printf("The temperature in Celsius is: %.2f°C\n", convertedTemperature);
                break;
            case 5:
                printf("Let's convert Fahrenheit to Kelvin. What Fahrenheit temperature do you have? ");
                scanf("%f", &temperature);
                convertedTemperature = fahrenheitToKelvin(temperature);
                printf("The temperature in Kelvin is: %.2fK\n", convertedTemperature);
                break;
            default:
                printf("Hmm, it seems like you've entered an invalid option. Please try again!\n");
        }
    } while (1);

    return 0;
}

void displayMenu() {
    printf("\nTemperature Conversion Options:\n");
    printf("1: Celsius to Fahrenheit\n");
    printf("2: Fahrenheit to Celsius\n");
    printf("3: Celsius to Kelvin\n");
    printf("4: Kelvin to Celsius\n");
    printf("5: Fahrenheit to Kelvin\n");
    printf("0: Exit\n");
    printf("Would you like to revisit any conversion? Please let me know!\n");
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
    return (fahrenheit - 32.0) * 5.0 / 9.0 + 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}