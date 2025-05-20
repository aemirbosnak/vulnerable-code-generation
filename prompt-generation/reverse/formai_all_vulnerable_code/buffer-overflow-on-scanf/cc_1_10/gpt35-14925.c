//FormAI DATASET v1.0 Category: Unit converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

double feet_to_meters(double feet) {
    return feet * 0.3048;
}

double meters_to_feet(double meters) {
    return meters / 0.3048;
}

double pounds_to_kilograms(double pounds) {
    return pounds * 0.453592;
}

double kilograms_to_pounds(double kilograms) {
    return kilograms / 0.453592;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double celsius_to_fahrenheit(double celsius) {
    return celsius * 9 / 5 + 32;
}

int main() {
    int option;
    double value;

    printf("Welcome to the Unit Conversion Program!\n\n");

    while (1) {
        printf("Choose an option:\n");
        printf("1. Feet to Meters\n");
        printf("2. Meters to Feet\n");
        printf("3. Pounds to Kilograms\n");
        printf("4. Kilograms to Pounds\n");
        printf("5. Fahrenheit to Celsius\n");
        printf("6. Celsius to Fahrenheit\n");
        printf("7. Quit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &option);

        if (option == 7) {
            printf("\nThank you for using the Unit Conversion Program.\n");
            break;
        }

        printf("Enter a value: ");
        scanf("%lf", &value);

        double result;

        switch (option) {
            case 1:
                result = feet_to_meters(value);
                printf("%.2lf feet is %.2lf meters.\n\n", value, result);
                break;
            case 2:
                result = meters_to_feet(value);
                printf("%.2lf meters is %.2lf feet.\n\n", value, result);
                break;
            case 3:
                result = pounds_to_kilograms(value);
                printf("%.2lf pounds is %.2lf kilograms.\n\n", value, result);
                break;
            case 4:
                result = kilograms_to_pounds(value);
                printf("%.2lf kilograms is %.2lf pounds.\n\n", value, result);
                break;
            case 5:
                result = fahrenheit_to_celsius(value);
                printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius.\n\n", value, result);
                break;
            case 6:
                result = celsius_to_fahrenheit(value);
                printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit.\n\n", value, result);
                break;
            default:
                printf("Invalid option. Please try again.\n\n");
                break;
        }
    }

    return 0;
}