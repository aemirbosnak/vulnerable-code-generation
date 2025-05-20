//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: relaxed
#include <stdio.h>

void printWelcomeMessage() {
    printf("Welcome to the Temperature Converter!\n");
    printf("Convert your temperatures with ease.\n");
    printf("You can convert between Celsius, Fahrenheit, and Kelvin.\n");
    printf("Just follow the prompts and let's have some fun with numbers!\n\n");
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
    return celsiusToKelvin(fahrenheitToCelsius(fahrenheit));
}

float kelvinToFahrenheit(float kelvin) {
    return celsiusToFahrenheit(kelvinToCelsius(kelvin));
}

void displayMenu() {
    printf("Choose your conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
}

int main() {
    printWelcomeMessage();

    int choice;
    float inputTemp, resultTemp;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Thank you for using the Temperature Converter. Goodbye!\n");
            break;
        }
        
        if (choice < 1 || choice > 7) {
            printf("Oops! That's not a valid choice. Please try again.\n");
            continue;
        }
        
        printf("Enter the temperature you want to convert: ");
        scanf("%f", &inputTemp);

        switch (choice) {
            case 1:
                resultTemp = celsiusToFahrenheit(inputTemp);
                printf("%.2f Celsius is %.2f Fahrenheit.\n\n", inputTemp, resultTemp);
                break;
            case 2:
                resultTemp = fahrenheitToCelsius(inputTemp);
                printf("%.2f Fahrenheit is %.2f Celsius.\n\n", inputTemp, resultTemp);
                break;
            case 3:
                resultTemp = celsiusToKelvin(inputTemp);
                printf("%.2f Celsius is %.2f Kelvin.\n\n", inputTemp, resultTemp);
                break;
            case 4:
                resultTemp = kelvinToCelsius(inputTemp);
                printf("%.2f Kelvin is %.2f Celsius.\n\n", inputTemp, resultTemp);
                break;
            case 5:
                resultTemp = fahrenheitToKelvin(inputTemp);
                printf("%.2f Fahrenheit is %.2f Kelvin.\n\n", inputTemp, resultTemp);
                break;
            case 6:
                resultTemp = kelvinToFahrenheit(inputTemp);
                printf("%.2f Kelvin is %.2f Fahrenheit.\n\n", inputTemp, resultTemp);
                break;
            default:
                printf("Hmm, something went wrong. Let's try that again!\n\n");
                break;
        }
    }

    return 0;
}