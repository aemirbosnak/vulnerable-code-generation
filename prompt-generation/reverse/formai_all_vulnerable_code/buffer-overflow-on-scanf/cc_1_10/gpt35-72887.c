//FormAI DATASET v1.0 Category: Temperature Converter ; Style: standalone
#include <stdio.h>

// Function prototypes
void printInstructions();
float convertToFahrenheit(float celsius);
float convertToKelvin(float celsius);

// Main function
int main() {
    float celsius;
    char choice;

    do {
        // Display instructions to the user
        printInstructions();

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &celsius);
                printf("Temperature in Fahrenheit: %.2f\n\n", convertToFahrenheit(celsius));
                break;
            case '2':
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &celsius);
                printf("Temperature in Kelvin: %.2f\n\n", convertToKelvin(celsius));
                break;
            case '3':
                printf("Exiting the program...\n\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    } while(choice != '3');

    return 0;
}

// This function prints the instructions to the user
void printInstructions() {
    printf("\n\nWelcome to the Celsius Temperature Converter\n");
    printf("-------------------------------------------\n\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Celsius to Kelvin\n");
    printf("3. Quit the program\n\n");
}

// This function converts Celsius to Fahrenheit
float convertToFahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

// This function converts Celsius to Kelvin
float convertToKelvin(float celsius) {
    return celsius + 273.15;
}