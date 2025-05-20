//FormAI DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Kilometers to Miles
double kilometersToMiles(double kilometers) {
    return kilometers * 0.621371;
}

// Function to convert Miles to Kilometers
double milesToKilometers(double miles) {
    return miles * 1.60934;
}

// Function to convert Pounds to Kilograms
double poundsToKilograms(double pounds) {
    return pounds / 2.20462;
}

// Function to convert Kilograms to Pounds
double kilogramsToPounds(double kilograms) {
    return kilograms * 2.20462;
}

int main() {
    int choice;
    double input, output;

    printf("Welcome to the Statistical Unit Converter\n");

    while (1) {
        printf("\nConvert:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Kilometers to Miles\n");
        printf("4. Miles to Kilometers\n");
        printf("5. Pounds to Kilograms\n");
        printf("6. Kilograms to Pounds\n");
        printf("7. Quit\n");

        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("\nThank you for using the Statistical Unit Converter\n");
            break;
        }

        printf("\nEnter the value you want to convert: ");
        scanf("%lf", &input);

        switch (choice) {
            case 1:
                output = celsiusToFahrenheit(input);
                printf("%.2lf Celsius is equal to %.2lf Fahrenheit\n", input, output);
                break;
            case 2:
                output = fahrenheitToCelsius(input);
                printf("%.2lf Fahrenheit is equal to %.2lf Celsius\n", input, output);
                break;
            case 3:
                output = kilometersToMiles(input);
                printf("%.2lf Kilometers is equal to %.2lf Miles\n", input, output);
                break;
            case 4:
                output = milesToKilometers(input);
                printf("%.2lf Miles is equal to %.2lf Kilometers\n", input, output);
                break;
            case 5:
                output = poundsToKilograms(input);
                printf("%.2lf Pounds is equal to %.2lf Kilograms\n", input, output);
                break;
            case 6:
                output = kilogramsToPounds(input);
                printf("%.2lf Kilograms is equal to %.2lf Pounds\n", input, output);
                break;
            default:
                printf("Invalid choice! Please enter a value between 1 and 7.\n");
        }
    }

    return 0;
}