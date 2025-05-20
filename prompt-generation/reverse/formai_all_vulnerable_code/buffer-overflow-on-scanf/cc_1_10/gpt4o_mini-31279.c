//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: cheerful
#include <stdio.h>

// Function Prototypes
void displayWelcomeMessage();
void displayOptions();
char getConversionChoice();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void displayConversionResult(float result, char choice);
void displayGoodbyeMessage();

int main() {
    displayWelcomeMessage();
    
    char choice;
    float temperature;
    
    do {
        displayOptions();
        choice = getConversionChoice();
        
        if (choice == '1') {
            printf("Yay! Let's convert Celsius to Fahrenheit! 🎉\n");
            printf("Please enter the temperature in Celsius: ");
            scanf("%f", &temperature);
            float convertedTemperature = celsiusToFahrenheit(temperature);
            displayConversionResult(convertedTemperature, choice);
        } else if (choice == '2') {
            printf("Woohoo! Now let's convert Fahrenheit to Celsius! 🌞\n");
            printf("Please enter the temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            float convertedTemperature = fahrenheitToCelsius(temperature);
            displayConversionResult(convertedTemperature, choice);
        } else if (choice != '3') {
            printf("Hmm, that's not a valid option! Please try again! 😅\n");
        }
        
    } while (choice != '3');

    displayGoodbyeMessage();
    return 0;
}

// Function Definitions
void displayWelcomeMessage() {
    printf("🌟 Welcome to the Temperature Converter! 🌟\n");
    printf("We'll help you change temperatures from Celsius to Fahrenheit and vice versa!\n");
    printf("Let's have some fun with numbers! 🎈\n\n");
}

void displayOptions() {
    printf("What would you like to do? 🤔\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Please enter your choice (1, 2, or 3): ");
}

char getConversionChoice() {
    char choice;
    scanf(" %c", &choice);  // Notice the space before %c - it consumes any whitespace
    return choice;
}

float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9.0/5.0) + 32.0;
    return fahrenheit;
}

float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32.0) * 5.0/9.0;
    return celsius;
}

void displayConversionResult(float result, char choice) {
    if (choice == '1') {
        printf("🎊 Hooray! The converted temperature is: %.2f°F\n\n", result);
    } else if (choice == '2') {
        printf("🎉 Yay! The converted temperature is: %.2f°C\n\n", result);
    }
}

void displayGoodbyeMessage() {
    printf("Thank you for using the Temperature Converter! 🌈\n");
    printf("Stay warm or cool, depending on the weather! ❄️☀️\n");
    printf("Goodbye and have a fantastic day! 🌟\n");
}