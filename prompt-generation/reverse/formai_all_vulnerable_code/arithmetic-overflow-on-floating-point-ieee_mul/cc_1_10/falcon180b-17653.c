//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * (9.0/5.0)) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * (5.0/9.0);
}

// Function to print the menu
void printMenu() {
    printf("\n");
    printf("Temperature Monitor Menu\n");
    printf("---------------------------------\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("---------------------------------\n");
}

// Function to validate user input
int validateInput(int choice) {
    if(choice < 1 || choice > 3) {
        printf("Invalid choice! Please try again.\n");
        return FALSE;
    }
    return TRUE;
}

// Function to get user input
int getInput() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to get Celsius temperature from user
double getCelsius() {
    double celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    return celsius;
}

// Function to get Fahrenheit temperature from user
double getFahrenheit() {
    double fahrenheit;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);
    return fahrenheit;
}

int main() {
    int choice;
    double celsius, fahrenheit;
    int validInput = TRUE;
    char choiceStr[10];

    do {
        validInput = TRUE;
        printMenu();
        choice = getInput();

        switch(choice) {
            case 1:
                celsius = getCelsius();
                printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, celsiusToFahrenheit(celsius));
                break;
            case 2:
                fahrenheit = getFahrenheit();
                printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahrenheit, fahrenheitToCelsius(fahrenheit));
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                validInput = FALSE;
                printf("Invalid choice! Please try again.\n");
        }

    } while(validInput);

    return 0;
}