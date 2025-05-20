//FormAI DATASET v1.0 Category: Temperature Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

float convertToFahrenheit(float celsius);
float convertToKelvin(float celsius);
void menu();

int main() {
    float celsius;
    int choice;
    char exitChar = 'n';
    do {
        menu(); //Call menu function
        scanf("%d", &choice); //Read user input
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);
        switch (choice) {
            case 1:
                printf("%.2f Celsius is equivalent to %.2f Fahrenheit\n", celsius, convertToFahrenheit(celsius));
                break;
            case 2:
                printf("%.2f Celsius is equivalent to %.2f Kelvin\n", celsius, convertToKelvin(celsius));
                break;
            case 3:
                exitChar = 'y';
                break;
            default:
                printf("Invalid input. Please try again!\n");
        }
        if (exitChar == 'n') {
            printf("Do you want to convert again? (Y/N): ");
            scanf(" %c", &exitChar);
        }
        printf("\n");
    } while (exitChar != 'n');

    return 0;
}

//Function to convert Celsius to Fahrenheit
float convertToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

//Function to convert Celsius to Kelvin
float convertToKelvin(float celsius) {
    return celsius + 273.15;
}

//Function to display menu
void menu() {
    printf("Choose conversion type:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}