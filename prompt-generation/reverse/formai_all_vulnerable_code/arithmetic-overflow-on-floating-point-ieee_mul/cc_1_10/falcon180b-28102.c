//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to get input from user
float getInput(char* message) {
    float input;
    printf("%s", message);
    scanf("%f", &input);
    return input;
}

// Function to print menu
void printMenu() {
    printf("\n");
    printf("Temperature Converter\n");
    printf("---------------------\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

// Function to perform conversion
void convert(int choice, float input) {
    switch(choice) {
        case 1: // Celsius to Fahrenheit
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", input, celsiusToFahrenheit(input));
            break;
        case 2: // Fahrenheit to Celsius
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", input, fahrenheitToCelsius(input));
            break;
        case 3: // Exit
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

int main() {
    float input;
    int choice;

    do {
        printMenu();
        choice = getInput("Enter your choice: ");
        input = getInput("Enter the temperature: ");
        convert(choice, input);
    } while(choice!= 3);

    return 0;
}