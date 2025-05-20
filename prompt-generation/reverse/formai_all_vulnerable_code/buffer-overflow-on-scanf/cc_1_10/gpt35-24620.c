//FormAI DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>

/* Conversion Functions */
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = celsius * 1.8 + 32.0;
    return fahrenheit;
}

float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32.0) / 1.8;
    return celsius;
}

float celsiusToKelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

float kelvinToCelsius(float kelvin) {
    float celsius = kelvin - 273.15;
    return celsius;
}

float fahrenheitToKelvin(float fahrenheit) {
    float celsius = fahrenheitToCelsius(fahrenheit);
    float kelvin = celsiusToKelvin(celsius);
    return kelvin;
}

float kelvinToFahrenheit(float kelvin) {
    float celsius = kelvinToCelsius(kelvin);
    float fahrenheit = celsiusToFahrenheit(celsius);
    return fahrenheit;
}

/* Conversion Menu */
void conversionMenu() {
    int option;
    float inputValue, outputValue;

    printf("Select the conversion option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    scanf("%d", &option);

    /* Input Prompt */
    printf("Enter the input value: ");
    scanf("%f", &inputValue);

    /* Option Selection */
    switch(option) {
        case 1:
            outputValue = celsiusToFahrenheit(inputValue);
            printf("%.2f Celsius = %.2f Fahrenheit\n", inputValue, outputValue);
            break;
        case 2:
            outputValue = fahrenheitToCelsius(inputValue);
            printf("%.2f Fahrenheit = %.2f Celsius\n", inputValue, outputValue);
            break;
        case 3:
            outputValue = celsiusToKelvin(inputValue);
            printf("%.2f Celsius = %.2f Kelvin\n", inputValue, outputValue);
            break;
        case 4:
            outputValue = kelvinToCelsius(inputValue);
            printf("%.2f Kelvin = %.2f Celsius\n", inputValue, outputValue);
            break;
        case 5:
            outputValue = fahrenheitToKelvin(inputValue);
            printf("%.2f Fahrenheit = %.2f Kelvin\n", inputValue, outputValue);
            break;
        case 6:
            outputValue = kelvinToFahrenheit(inputValue);
            printf("%.2f Kelvin = %.2f Fahrenheit\n", inputValue, outputValue);
            break;
        default:
            printf("Invalid option selected!\n");
    }
}

/* Main Function */
int main() {
    conversionMenu();
    return 0;
}