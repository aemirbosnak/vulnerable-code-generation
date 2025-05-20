//FormAI DATASET v1.0 Category: Unit converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

double convertCelsiusToFahrenheit(double celsius);
double convertFahrenheitToCelsius(double fahrenheit);
double convertMilesToKilometers(double miles);
double convertKilometersToMiles(double kilometers);

int main() {
    int choice;
    double input;

    do {
        printf("\nWelcome to the Unit Converter Program\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Miles to Kilometers\n");
        printf("4. Kilometers to Miles\n");
        printf("5. Quit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the temperature in Celsius: ");
                scanf("%lf", &input);
                printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit\n", input, convertCelsiusToFahrenheit(input));
                break;
            case 2:
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%lf", &input);
                printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius\n", input, convertFahrenheitToCelsius(input));
                break;
            case 3:
                printf("Enter the distance in miles: ");
                scanf("%lf", &input);
                printf("%.2lf miles is equal to %.2lf kilometers\n", input, convertMilesToKilometers(input));
                break;
            case 4:
                printf("Enter the distance in kilometers: ");
                scanf("%lf", &input);
                printf("%.2lf kilometers is equal to %.2lf miles\n", input, convertKilometersToMiles(input));
                break;
            case 5:
                printf("Thank you for using the Unit Converter Program\n");
                return 0;
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    } while (1);
}

double convertCelsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double convertFahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double convertMilesToKilometers(double miles) {
    return miles * 1.60934;
}

double convertKilometersToMiles(double kilometers) {
    return kilometers / 1.60934;
}