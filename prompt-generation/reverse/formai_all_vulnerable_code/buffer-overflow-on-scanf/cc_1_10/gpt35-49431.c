//FormAI DATASET v1.0 Category: Unit converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

void printMenu(); // function to print the conversion options menu
double convertMetersToFeet(double); // function to convert meters to feet
double convertKilogramsToPounds(double); // function to convert kilograms to pounds
double convertCelsiusToFahrenheit(double); // function to convert celsius to fahrenheit

int main() {
    int option;
    double value, result;

    printMenu();
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter value in meters: ");
            scanf("%lf", &value);
            result = convertMetersToFeet(value);
            printf("%.2lf meters is equal to %.2lf feet.\n", value, result);
            break;
        case 2:
            printf("Enter value in kilograms: ");
            scanf("%lf", &value);
            result = convertKilogramsToPounds(value);
            printf("%.2lf kilograms is equal to %.2lf pounds.\n", value, result);
            break;
        case 3:
            printf("Enter value in celsius: ");
            scanf("%lf", &value);
            result = convertCelsiusToFahrenheit(value);
            printf("%.2lf celsius is equal to %.2lf fahrenheit.\n", value, result);
            break;
        default:
            printf("Invalid option selected. Please try again.\n");
            break;
    }

    return 0;
}

void printMenu() {
    printf("Select an option to convert:\n");
    printf("1. Meters to Feet\n");
    printf("2. Kilograms to Pounds\n");
    printf("3. Celsius to Fahrenheit\n");
}

double convertMetersToFeet(double meters) {
    double feet = meters * 3.281;
    return feet;
}

double convertKilogramsToPounds(double kg) {
    double pounds = kg * 2.205;
    return pounds;
}

double convertCelsiusToFahrenheit(double celsius) {
    double fahrenheit = celsius * 1.8 + 32;
    return fahrenheit;
}