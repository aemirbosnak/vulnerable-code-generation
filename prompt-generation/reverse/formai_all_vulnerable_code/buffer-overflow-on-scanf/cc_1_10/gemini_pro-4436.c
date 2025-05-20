//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void clearInputBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ; // do nothing
}

// Temperature converter function
double convertTemperature(double tempIn, bool isCelsius, char convTo) {
    double tempOut;
    if (isCelsius && convTo == 'F') { // Celsius to Fahrenheit
        tempOut = (tempIn * 9 / 5) + 32;
    }
    else if (!isCelsius && convTo == 'C') { // Fahrenheit to Celsius
        tempOut = (tempIn - 32) * 5 / 9;
    }
    else { // Invalid conversion
        printf("Invalid conversion. Please try again.\n");
        tempOut = 0; // default value
    }
    return tempOut;
}

// Main function
int main() {
    // Declare variables
    double tempIn;
    char isCelsius, convTo;
    bool isValidInput;

    // Welcome message
    printf("Hello there! Welcome to the Cheerful Temperature Converter!\n");
    printf("Let's get you started with converting a temperature.\n");

    // Get input temperature
    printf("Please enter the temperature you want to convert: ");
    scanf("%lf", &tempIn);

    // Get input temperature scale (Celsius or Fahrenheit)
    printf("Is the temperature in Celsius (C) or Fahrenheit (F)? ");
    scanf(" %c", &isCelsius);
    isCelsius = (isCelsius == 'C' || isCelsius == 'c'); // convert to lowercase and check if valid

    // Get input conversion scale (Celsius or Fahrenheit)
    printf("What temperature scale do you want to convert to: Celsius (C) or Fahrenheit (F)? ");
    scanf(" %c", &convTo);
    convTo = (convTo == 'C' || convTo == 'c' || convTo == 'F' || convTo == 'f'); // convert to lowercase and check if valid

    // Check if input is valid
    isValidInput = (isCelsius && (convTo == 'F' || convTo == 'f')) || (!isCelsius && (convTo == 'C' || convTo == 'c'));
    if (!isValidInput) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    // Clear input buffer
    clearInputBuffer();

    // Convert temperature
    double tempOut = convertTemperature(tempIn, isCelsius, convTo);

    // Display the converted temperature
    printf("The converted temperature is: %.2f%c\n", tempOut, convTo);

    // Farewell message
    printf("Thank you for using the Cheerful Temperature Converter! Have a sunny day!\n");

    return 0;
}