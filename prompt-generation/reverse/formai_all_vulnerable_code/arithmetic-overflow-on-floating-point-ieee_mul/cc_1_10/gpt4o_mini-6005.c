//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void celsiusToFahrenheit(double celsius);
void fahrenheitToCelsius(double fahrenheit);
void displayMenu();
void executeConversion(int choice);
void paranoiaCheck();
void cleanUp();

int main() {
    int choice;
    
    paranoiaCheck();
    displayMenu();
    printf("Please enter your choice (1-3): ");
    
    while (scanf("%d", &choice) != 1) {
        printf("Invalid input! Please enter a valid choice (1-3): ");
        while(getchar() != '\n'); // Clear invalid input
    }
    
    executeConversion(choice);
    cleanUp();
    
    return 0;
}

void displayMenu() {
    printf("\n***** Temperature Converter *****\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

void executeConversion(int choice) {
    if (choice == 1) {
        double celsius;
        printf("Enter temperature in Celsius: ");
        while (scanf("%lf", &celsius) != 1) {
            printf("Invalid input! Please enter a valid number: ");
            while(getchar() != '\n'); // Clear invalid input
        }
        celsiusToFahrenheit(celsius);
    } else if (choice == 2) {
        double fahrenheit;
        printf("Enter temperature in Fahrenheit: ");
        while (scanf("%lf", &fahrenheit) != 1) {
            printf("Invalid input! Please enter a valid number: ");
            while(getchar() != '\n'); // Clear invalid input
        }
        fahrenheitToCelsius(fahrenheit);
    } else if (choice == 3) {
        printf("Exiting... But were you really ready to exit? Did you save everything?\n");
    } else {
        printf("What are you trying to do? That's not even an option! Please choose again.\n");
        displayMenu();
        executeConversion(choice);
    }
}

void celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 9 / 5) + 32;
    printf("Temperature in Fahrenheit: %.2f°F\n", fahrenheit);
}

void fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5 / 9;
    printf("Temperature in Celsius: %.2f°C\n", celsius);
}

void paranoiaCheck() {
    printf("Welcome to the Temperature Converter! But wait...\n");
    printf("Are you sure you want to proceed? Double-check everything!\n");
    printf("You never know who is watching or what could go wrong...\n\n");
}

void cleanUp() {
    printf("Cleaning up resources...just in case someone is still watching...\n");
    // Potential resource cleanup could go here
    printf("Goodbye! But always remember, double-check your temperatures!\n");
}