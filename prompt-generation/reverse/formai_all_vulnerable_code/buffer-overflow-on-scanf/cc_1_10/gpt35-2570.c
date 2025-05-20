//FormAI DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit)
{
    return ((fahrenheit - 32.0) * 5.0 / 9.0);
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius)
{
    return ((celsius * 9.0 / 5.0) + 32.0);
}

// Function to convert Miles to Kilometers
float miles_to_kilometers(float miles)
{
    return (miles * 1.60934);
}

// Function to convert Kilometers to Miles
float kilometers_to_miles(float kilometers)
{
    return (kilometers / 1.60934);
}

int main()
{
    int option;
    float value, result;
    char unit_from[20], unit_to[20];

    printf("Welcome to the Unit Converter!\n\n");

    do {
        printf("Please select an option:\n");
        printf("1. Fahrenheit to Celsius\n");
        printf("2. Celsius to Fahrenheit\n");
        printf("3. Miles to Kilometers\n");
        printf("4. Kilometers to Miles\n");
        printf("5. Quit\n");
        printf("Option: ");

        scanf("%d", &option);

        if (option == 5) {
            printf("\nGoodbye!\n");
            break;
        }

        printf("Enter the value you want to convert: ");
        scanf("%f", &value);

        printf("Enter the unit you are converting from: ");
        scanf("%s", unit_from);

        printf("Enter the unit you are converting to: ");
        scanf("%s", unit_to);

        // Fahrenheit to Celsius
        if (option == 1 && strcmp(unit_from, "F") == 0 && strcmp(unit_to, "C") == 0) {
            result = fahrenheit_to_celsius(value);
            printf("%.2f F = %.2f C\n", value, result);
        }
        // Celsius to Fahrenheit
        else if (option == 2 && strcmp(unit_from, "C") == 0 && strcmp(unit_to, "F") == 0) {
            result = celsius_to_fahrenheit(value);
            printf("%.2f C = %.2f F\n", value, result);
        }
        // Miles to Kilometers
        else if (option == 3 && strcmp(unit_from, "mi") == 0 && strcmp(unit_to, "km") == 0) {
            result = miles_to_kilometers(value);
            printf("%.2f mi = %.2f km\n", value, result);
        }
        // Kilometers to Miles
        else if (option == 4 && strcmp(unit_from, "km") == 0 && strcmp(unit_to, "mi") == 0) {
            result = kilometers_to_miles(value);
            printf("%.2f km = %.2f mi\n", value, result);
        }
        else {
            printf("Invalid option or units!\n");
        }
    } while (option != 5);

    return 0;
}