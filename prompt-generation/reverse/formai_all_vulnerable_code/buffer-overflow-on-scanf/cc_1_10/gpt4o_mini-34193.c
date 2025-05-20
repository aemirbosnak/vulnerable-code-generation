//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: puzzling
#include <stdio.h>

// Function prototypes
void displayMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float celsiusToKelvin(float celsius);
float kelvinToCelsius(float kelvin);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToFahrenheit(float kelvin);
void treasureHunt(float temperature, char unit);

int main() {
    int choice;
    float temperature;

    printf("Welcome to the Temperature Converter! Solve the riddle to unveil the treasure!\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice < 1 || choice > 6) {
            printf("Invalid choice! Try again, brave adventurer.\n");
            continue;
        }

        printf("Enter the temperature you wish to convert: ");
        scanf("%f", &temperature);

        switch (choice) {
            case 1:
                printf("Celsius: %.2f => Fahrenheit: %.2f\n", temperature, celsiusToFahrenheit(temperature));
                treasureHunt(temperature, 'C');
                break;
            case 2:
                printf("Fahrenheit: %.2f => Celsius: %.2f\n", temperature, fahrenheitToCelsius(temperature));
                treasureHunt(temperature, 'F');
                break;
            case 3:
                printf("Celsius: %.2f => Kelvin: %.2f\n", temperature, celsiusToKelvin(temperature));
                treasureHunt(temperature, 'C');
                break;
            case 4:
                printf("Kelvin: %.2f => Celsius: %.2f\n", temperature, kelvinToCelsius(temperature));
                treasureHunt(temperature, 'K');
                break;
            case 5:
                printf("Fahrenheit: %.2f => Kelvin: %.2f\n", temperature, fahrenheitToKelvin(temperature));
                treasureHunt(temperature, 'F');
                break;
            case 6:
                printf("Kelvin: %.2f => Fahrenheit: %.2f\n", temperature, kelvinToFahrenheit(temperature));
                treasureHunt(temperature, 'K');
                break;
            default:
                printf("This should never happen – the adventure must go on!\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\nChoose your adventure:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
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

void treasureHunt(float temperature, char unit) {
    if (unit == 'C') {
        if (temperature < 0) {
            printf("Oh! You've uncovered the treasure of frost! ❄️\n");
        } else if (temperature > 30) {
            printf("The tropical gold awaits you! 🌴\n");
        } else {
            printf("You've found a hidden gem in temperate lands! 🌤️\n");
        }
    } else if (unit == 'F') {
        if (temperature < 32) {
            printf("You found the secret icy cavern! 🥶\n");
        } else if (temperature > 86) {
            printf("The blazing inferno of treasure awaits! 🔥\n");
        } else {
            printf("Your journey lies in the realm of cozy warmth! 🌈\n");
        }
    } else if (unit == 'K') {
        if (temperature < 273.15) {
            printf("A mystical cold treasure has been revealed! 🌌\n");
        } else if (temperature > 303.15) {
            printf("You've discovered the hot springs of hidden wealth! 💰\n");
        } else {
            printf("You've unearthed a peaceful hidden treasure! 📦\n");
        }
    }
}