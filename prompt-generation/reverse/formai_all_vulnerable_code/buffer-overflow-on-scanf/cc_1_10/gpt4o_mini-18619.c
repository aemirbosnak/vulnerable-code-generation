//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: shocked
#include <stdio.h>

void displayIntro() {
    printf("=====================================\n");
    printf("    TEMPERATURE CONVERTER - WOW!     \n");
    printf("=====================================\n");
    printf("Welcome to the most amazing Temperature Converter you've ever seen!\n");
    printf("Are you ready to convert those pesky temperatures? Let's go! 😲\n");
    printf("=====================================\n");
}

void convertCelsiusToFahrenheit() {
    double celsius;
    printf("Enter temperature in Celsius (°C): ");
    scanf("%lf", &celsius);
    
    if (celsius < -273.15) {
        printf("😱 That's below absolute zero! Impossible!\n");
    } else {
        double fahrenheit = (celsius * 9/5) + 32;
        printf("Wow! %lf°C is equal to %lf°F!\n", celsius, fahrenheit);
    }
}

void convertFahrenheitToCelsius() {
    double fahrenheit;
    printf("Enter temperature in Fahrenheit (°F): ");
    scanf("%lf", &fahrenheit);
    
    if (fahrenheit < -459.67) {
        printf("😱 That's below absolute zero! Impossible!\n");
    } else {
        double celsius = (fahrenheit - 32) * 5/9;
        printf("Wow! %lf°F is equal to %lf°C!\n", fahrenheit, celsius);
    }
}

void showMenu() {
    printf("Choose your conversion option:\n");
    printf("1: Celsius to Fahrenheit 😲\n");
    printf("2: Fahrenheit to Celsius 😲\n");
    printf("3: Exit (Noooo! Don't go!) 😱\n");
}

int main() {
    int choice = 0;

    displayIntro();

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("😫 Uh-oh! That's not a number! Please try again!\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                convertCelsiusToFahrenheit();
                break;
            case 2:
                convertFahrenheitToCelsius();
                break;
            case 3:
                printf("😢 Thank you for using this program! Come back soon! Bye!\n");
                return 0;
            default:
                printf("😱 Oops! That's not a valid option! Try again!\n");
        }
        printf("\n"); // Adding a new line for better readability
    }

    return 0; // This line won't be reached, but good to include!
}