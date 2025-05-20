//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void printMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float celsiusToKelvin(float celsius);
float kelvinToCelsius(float kelvin);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToFahrenheit(float kelvin);

// Configurable Constants
#define MAX_CONVERSIONS 100

// Struct to hold temperature conversion logs
typedef struct {
    char operation[50];
    float input;
    float result;
} ConversionLog;

// Global array to hold conversion logs
ConversionLog logs[MAX_CONVERSIONS];
int logCount = 0;

// Function Definitions
void printMenu() {
    printf("\nTemperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. View Conversion History\n");
    printf("8. Exit\n");
    printf("Choose an option: ");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}

void logConversion(const char* operation, float input, float result) {
    if (logCount < MAX_CONVERSIONS) {
        snprintf(logs[logCount].operation, sizeof(logs[logCount].operation), "%s", operation);
        logs[logCount].input = input;
        logs[logCount].result = result;
        logCount++;
    } else {
        printf("Conversion log is full!\n");
    }
}

void printConversionHistory() {
    if (logCount == 0) {
        printf("\nNo conversion history available.\n");
        return;
    }
    
    printf("\nConversion History\n");
    for (int i = 0; i < logCount; i++) {
        printf("%d. %s: %.2f = %.2f\n",
            i + 1,
            logs[i].operation,
            logs[i].input,
            logs[i].result);
    }
}

int main() {
    int choice;
    float input, result;
    
    while (1) {
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &input);
                result = celsiusToFahrenheit(input);
                printf("%.2f Celsius = %.2f Fahrenheit\n", input, result);
                logConversion("Celsius to Fahrenheit", input, result);
                break;
            
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &input);
                result = fahrenheitToCelsius(input);
                printf("%.2f Fahrenheit = %.2f Celsius\n", input, result);
                logConversion("Fahrenheit to Celsius", input, result);
                break;

            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &input);
                result = celsiusToKelvin(input);
                printf("%.2f Celsius = %.2f Kelvin\n", input, result);
                logConversion("Celsius to Kelvin", input, result);
                break;

            case 4:
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &input);
                result = kelvinToCelsius(input);
                printf("%.2f Kelvin = %.2f Celsius\n", input, result);
                logConversion("Kelvin to Celsius", input, result);
                break;

            case 5:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &input);
                result = fahrenheitToKelvin(input);
                printf("%.2f Fahrenheit = %.2f Kelvin\n", input, result);
                logConversion("Fahrenheit to Kelvin", input, result);
                break;

            case 6:
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &input);
                result = kelvinToFahrenheit(input);
                printf("%.2f Kelvin = %.2f Fahrenheit\n", input, result);
                logConversion("Kelvin to Fahrenheit", input, result);
                break;

            case 7:
                printConversionHistory();
                break;

            case 8:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}