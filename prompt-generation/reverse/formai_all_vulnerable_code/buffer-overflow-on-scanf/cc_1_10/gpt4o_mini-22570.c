//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: surprised
#include <stdio.h>

void displayMenu() {
    printf("====================================\n");
    printf("        Temperature Converter        \n");
    printf("====================================\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
    printf("====================================\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0 + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}

int main() {
    int choice;
    float inputTemp, outputTemp;

    do {
        displayMenu();
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 7) {
            if (choice != 7)
                printf("Whoa! That's an invalid choice. Please try again.\n");
            continue;
        }

        if (choice != 7) {
            printf("Enter the temperature: ");
            scanf("%f", &inputTemp);
        }

        switch (choice) {
            case 1:
                outputTemp = celsiusToFahrenheit(inputTemp);
                printf("Surprisingly! %.2f Celsius is %.2f Fahrenheit\n", inputTemp, outputTemp);
                break;
            case 2:
                outputTemp = celsiusToKelvin(inputTemp);
                printf("Wow! %.2f Celsius is %.2f Kelvin\n", inputTemp, outputTemp);
                break;
            case 3:
                outputTemp = fahrenheitToCelsius(inputTemp);
                printf("Incredible! %.2f Fahrenheit is %.2f Celsius\n", inputTemp, outputTemp);
                break;
            case 4:
                outputTemp = fahrenheitToKelvin(inputTemp);
                printf("Amazing! %.2f Fahrenheit is %.2f Kelvin\n", inputTemp, outputTemp);
                break;
            case 5:
                outputTemp = kelvinToCelsius(inputTemp);
                printf("Wowza! %.2f Kelvin is %.2f Celsius\n", inputTemp, outputTemp);
                break;
            case 6:
                outputTemp = kelvinToFahrenheit(inputTemp);
                printf("Surprising! %.2f Kelvin is %.2f Fahrenheit\n", inputTemp, outputTemp);
                break;
            case 7:
                printf("Thank you for using the Temperature Converter! Bye!\n");
                break;
            default:
                printf("Oops! Something went wrong.\n");
                break;
        }

        printf("\n");
    } while (choice != 7);

    return 0;
}