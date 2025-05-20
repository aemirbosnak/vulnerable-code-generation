//FormAI DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to convert kilometers to miles
double kilometersToMiles(double kilometers) {
    return kilometers * 0.6213712;
}

// Function to convert miles to kilometers
double milesToKilometers(double miles) {
    return miles / 0.6213712;
}

int main() {
    int choice;
    double input, output;
    printf("Welcome to the unit converter!\n");

    do {
        // Display the menu
        printf("\nChoose an option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Kilometers to Miles\n");
        printf("4. Miles to Kilometers\n");
        printf("5. Quit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the temperature in Celsius: ");
                scanf("%lf", &input);
                output = celsiusToFahrenheit(input);
                printf("%.2lf Celsius = %.2lf Fahrenheit", input, output);
                break;
            case 2:
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%lf", &input);
                output = fahrenheitToCelsius(input);
                printf("%.2lf Fahrenheit = %.2lf Celsius", input, output);
                break;
            case 3:
                printf("Enter the distance in kilometers: ");
                scanf("%lf", &input);
                output = kilometersToMiles(input);
                printf("%.2lf Kilometers = %.2lf Miles", input, output);
                break;
            case 4:
                printf("Enter the distance in miles: ");
                scanf("%lf", &input);
                output = milesToKilometers(input);
                printf("%.2lf Miles = %.2lf Kilometers", input, output);
                break;
            case 5:
                printf("Thank you for using the unit converter!");
                break;
            default:
                printf("Invalid choice!");
        }

    } while(choice != 5);

    return 0;
}