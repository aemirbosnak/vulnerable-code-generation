//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: funny
#include <stdio.h>

void welcomeToTheTemperatureConverter() {
    printf("Welcome to the quirky Temperature Converter!\n");
    printf("Where Celsius tickles Fahrenheit and Kelvin does the cha-cha!\n");
    printf("Let's get this process simmering...\n\n");
}

void showMenu() {
    printf("Choose your conversion adventure:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit - you've had enough of this temperature nonsense!\n");
}

float celsiusToFahrenheit(float celsius) {
    printf("Turning Celsius into Fahrenheit... it's like magic!\n");
    return (celsius * 9.0 / 5.0) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    printf("Transforming Fahrenheit into Celsius... ask the sun for help!\n");
    return (fahrenheit - 32) * 5.0 / 9.0;
}

float celsiusToKelvin(float celsius) {
    printf("Converting Celsius to Kelvin... it's a hot ticket to another dimension!\n");
    return celsius + 273.15;
}

float fahrenheitToKelvin(float fahrenheit) {
    printf("Fahrenheit entering the Kelvin realm... it's being welcomed with open arms!\n");
    return (fahrenheit - 32) * 5.0 / 9.0 + 273.15;
}

float kelvinToCelsius(float kelvin) {
    printf("Bringing Kelvin back to the cozy land of Celsius...\n");
    return kelvin - 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    printf("Kelvin is now going to meet Fahrenheit... it’s a cultural exchange!\n");
    return (kelvin - 273.15) * 9.0 / 5.0 + 32;
}

void converter() {
    int choice;
    float input, result;
    do {
        showMenu();
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 6) {
            printf("Provide the temperature you want to convert: ");
            scanf("%f", &input);
        }

        switch (choice) {
            case 1:
                result = celsiusToFahrenheit(input);
                printf("%.2f Celsius is equal to %.2f Fahrenheit\n\n", input, result);
                break;
            case 2:
                result = fahrenheitToCelsius(input);
                printf("%.2f Fahrenheit is equal to %.2f Celsius\n\n", input, result);
                break;
            case 3:
                result = celsiusToKelvin(input);
                printf("%.2f Celsius is equal to %.2f Kelvin\n\n", input, result);
                break;
            case 4:
                result = fahrenheitToKelvin(input);
                printf("%.2f Fahrenheit is equal to %.2f Kelvin\n\n", input, result);
                break;
            case 5:
                result = kelvinToCelsius(input);
                printf("%.2f Kelvin is equal to %.2f Celsius\n\n", input, result);
                break;
            case 6:
                result = kelvinToFahrenheit(input);
                printf("%.2f Kelvin is equal to %.2f Fahrenheit\n\n", input, result);
                break;
            case 7:
                printf("Exiting... It’s been a hot minute, hasn’t it?\n");
                break;
            default:
                printf("Oops! Looks like you entered something that’s not on the menu. Try again!\n\n");
                break;
        }
    } while (choice != 7);
}

int main() {
    welcomeToTheTemperatureConverter();
    converter();
    printf("Thanks for stopping by the Temperature Converter! Come back when the heat is on!\n");
    return 0;
}