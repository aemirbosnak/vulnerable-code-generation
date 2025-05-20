//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

// Function to display menu
void displayMenu() {
    printf("\n\n");
    printf("********* TEMPERATURE MONITOR *********\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("\n");
}

// Function to get user choice from menu
int getUserChoice() {
    int choice = 0;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to get Celsius temperature from user
float getCelsius() {
    float celsius = 0;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    return celsius;
}

// Function to get Fahrenheit temperature from user
float getFahrenheit() {
    float fahrenheit = 0;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    return fahrenheit;
}

// Main function
int main() {
    int choice;
    float celsius, fahrenheit;
    time_t currentTime;
    struct tm *localTime;

    srand(time(NULL));

    do {
        // Get current time
        time(&currentTime);
        localTime = localtime(&currentTime);

        // Display menu
        displayMenu();

        // Get user choice
        choice = getUserChoice();

        switch(choice) {
            case 1: // Convert Celsius to Fahrenheit
                // Get Celsius temperature from user
                celsius = getCelsius();
                // Convert Celsius to Fahrenheit and display result
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, celsiusToFahrenheit(celsius));
                break;

            case 2: // Convert Fahrenheit to Celsius
                // Get Fahrenheit temperature from user
                fahrenheit = getFahrenheit();
                // Convert Fahrenheit to Celsius and display result
                printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, fahrenheitToCelsius(fahrenheit));
                break;

            case 3: // Exit
                printf("Exiting program...\n");
                break;

            default: // Invalid choice
                printf("Invalid choice! Please try again.\n");
        }

    } while(TRUE);

    return 0;
}