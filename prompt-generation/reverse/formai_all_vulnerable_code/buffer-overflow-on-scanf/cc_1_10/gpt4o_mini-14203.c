//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Claude Shannon
#include <stdio.h>

// Function prototypes
void displayMenu();
float convertCtoF(float celsius);
float convertCtoK(float celsius);
float convertFtoC(float fahrenheit);
float convertFtoK(float fahrenheit);
float convertKtoC(float kelvin);
float convertKtoF(float kelvin);
void getUserInput(float *temperature, char *unit);

int main() {
    float temperature;
    char unit;

    printf("Welcome to the Temperature Converter!\n");
    
    while (1) {
        displayMenu();
        getUserInput(&temperature, &unit);

        float convertedTemperature;
        char convertedUnit[3];

        // Convert based on the provided unit
        switch (unit) {
            case 'C':
            case 'c':
                convertedTemperature = convertCtoF(temperature);
                sprintf(convertedUnit, "F");
                break;
            case 'F':
            case 'f':
                convertedTemperature = convertFtoC(temperature);
                sprintf(convertedUnit, "C");
                break;
            case 'K':
            case 'k':
                convertedTemperature = convertKtoC(temperature);
                sprintf(convertedUnit, "C");
                break;
            default:
                printf("Invalid unit entered. Please try again.\n");
                continue;
        }

        printf("Converted Temperature: %.2f %s\n", convertedTemperature, convertedUnit);
        printf("Would you like to convert another temperature? (Y/N): ");
        
        char choice;
        scanf(" %c", &choice);
        if (choice != 'Y' && choice != 'y') {
            break;
        }
    }

    printf("Thank you for using the Temperature Converter. Goodbye!\n");
    return 0;
}

void displayMenu() {
    printf("\nTemperature Conversion Menu:\n");
    printf("Choose the unit of the temperature:\n");
    printf("C - Celsius\n");
    printf("F - Fahrenheit\n");
    printf("K - Kelvin\n");
    printf("Enter your choice (C/F/K): ");
}

void getUserInput(float *temperature, char *unit) {
    printf("Enter the temperature value: ");
    scanf("%f", temperature);
    printf("Enter the unit of temperature (C/F/K): ");
    scanf(" %c", unit);
}

float convertCtoF(float celsius) {
    return (celsius * 9/5) + 32;
}

float convertCtoK(float celsius) {
    return celsius + 273.15;
}

float convertFtoC(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

float convertFtoK(float fahrenheit) {
    float celsius = convertFtoC(fahrenheit);
    return convertCtoK(celsius);
}

float convertKtoC(float kelvin) {
    return kelvin - 273.15;
}

float convertKtoF(float kelvin) {
    float celsius = convertKtoC(kelvin);
    return convertCtoF(celsius);
}