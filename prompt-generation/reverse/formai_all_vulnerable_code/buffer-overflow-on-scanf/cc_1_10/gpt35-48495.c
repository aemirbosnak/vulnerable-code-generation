//FormAI DATASET v1.0 Category: Unit converter ; Style: introspective
#include <stdio.h>

// function prototypes
void displayMenu();
float convertTemperature(int choice, float temperature);

int main() {
    int choice;
    float temperature, convertedTemperature;

    displayMenu(); // display the menu options
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice != 4) {
        printf("Enter the temperature: ");
        scanf("%f", &temperature);

        convertedTemperature = convertTemperature(choice, temperature);

        printf("The converted temperature is: %.2f\n\n", convertedTemperature);

        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    printf("Thank you for using the unit converter program.\n");

    return 0;
}

// function to display the menu options
void displayMenu() {
    printf("=========================\n");
    printf("         MAIN MENU\n");
    printf("=========================\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Quit the program\n");
}

// function to convert the temperature based on the user's choice
float convertTemperature(int choice, float temperature) {
    float convertedTemperature;

    switch (choice) {
        case 1: // Celsius to Fahrenheit
            convertedTemperature = (temperature * 9/5) + 32;
            break;
        case 2: // Fahrenheit to Celsius
            convertedTemperature = (temperature - 32) * 5/9;
            break;
        case 3: // Celsius to Kelvin
            convertedTemperature = temperature + 273.15;
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return convertedTemperature;
}