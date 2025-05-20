//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float temp;
    char choice;
    int validInput = 0;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter a temperature to convert: ");
    scanf("%f", &temp);

    // Check if input is valid
    if (temp < -273.15 || temp > 1000) {
        printf("Invalid input. Please enter a temperature between -273.15 and 1000.\n");
        return 1;
    }

    validInput = 1;

    // Prompt user for conversion choice
    printf("Please choose a conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    scanf(" %c", &choice);

    // Convert temperature
    switch (choice) {
        case '1':
            temp = (temp * 9/5) + 32;
            printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", temp, temp);
            break;
        case '2':
            temp = (temp - 32) * 5/9;
            printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", temp, temp);
            break;
        case '3':
            temp = temp + 273.15;
            printf("%.2f degrees Celsius is %.2f degrees Kelvin.\n", temp, temp);
            break;
        case '4':
            temp = temp - 273.15;
            printf("%.2f degrees Kelvin is %.2f degrees Celsius.\n", temp, temp);
            break;
        default:
            printf("Invalid choice. Please choose a valid conversion option.\n");
            return 1;
    }

    return 0;
}