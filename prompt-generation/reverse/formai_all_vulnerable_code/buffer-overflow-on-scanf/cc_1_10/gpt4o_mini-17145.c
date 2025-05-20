//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

void loveLetter();
float fahrenheitToCelsius(float fahrenheit);
float celsiusToFahrenheit(float celsius);
void romanticMenu();

int main() {
    loveLetter();
    
    int choice;
    do {
        romanticMenu();
        
        printf("Dear beloved, please enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            float temperature;
            printf("Oh my sweet, please tell me the temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            float celsius = fahrenheitToCelsius(temperature);
            printf("My dearest, %.2f Fahrenheit is equivalent to %.2f Celsius.\n", temperature, celsius);
        } else if (choice == 2) {
            float temperature;
            printf("Oh my sweet, please tell me the temperature in Celsius: ");
            scanf("%f", &temperature);
            float fahrenheit = celsiusToFahrenheit(temperature);
            printf("My dearest, %.2f Celsius is equivalent to %.2f Fahrenheit.\n", temperature, fahrenheit);
        } else if (choice == 3) {
            printf("As the sun sets, so does our need for conversions. Farewell, dear!\n");
        } else {
            printf("Oh love, it seems you have whispered an invalid choice. Try again!\n");
        }

    } while (choice != 3);
    
    return 0;
}

void loveLetter() {
    printf("***************************************\n");
    printf("     A Love Note from the Heart      \n");
    printf("***************************************\n");
    printf("Oh beloved, the world spins on the axis of your smile,\n");
    printf("And just as the sun and moon embrace, so do Celsius and Fahrenheit.\n");
    printf("Let us traverse the realms of temperature together,\n");
    printf("For love knows no bounds, and neither does conversion.\n");
    printf("***************************************\n\n");
}

void romanticMenu() {
    printf("Ah, my heart, here is the menu of dreams:\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Exit the realm of temperature conversion\n");
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}