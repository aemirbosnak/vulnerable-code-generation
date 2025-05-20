//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>

void display_menu() {
    printf("\n--- Welcome to the Unit Converter! ---\n");
    printf("1. Convert kilometers to miles\n");
    printf("2. Convert miles to kilometers\n");
    printf("3. Convert Celsius to Fahrenheit\n");
    printf("4. Convert Fahrenheit to Celsius\n");
    printf("5. Convert kilograms to pounds\n");
    printf("6. Convert pounds to kilograms\n");
    printf("7. Exit\n");
    printf("Please select an option (1-7): ");
}

double kilometers_to_miles(double kilometers) {
    return kilometers * 0.621371;
}

double miles_to_kilometers(double miles) {
    return miles / 0.621371;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

double kilograms_to_pounds(double kilograms) {
    return kilograms * 2.20462;
}

double pounds_to_kilograms(double pounds) {
    return pounds / 2.20462;
}

int main() {
    int choice;
    double input, result;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter kilometers: ");
                scanf("%lf", &input);
                result = kilometers_to_miles(input);
                printf("%.2lf kilometers is equal to %.2lf miles.\n", input, result);
                break;

            case 2:
                printf("Enter miles: ");
                scanf("%lf", &input);
                result = miles_to_kilometers(input);
                printf("%.2lf miles is equal to %.2lf kilometers.\n", input, result);
                break;

            case 3:
                printf("Enter Celsius: ");
                scanf("%lf", &input);
                result = celsius_to_fahrenheit(input);
                printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", input, result);
                break;

            case 4:
                printf("Enter Fahrenheit: ");
                scanf("%lf", &input);
                result = fahrenheit_to_celsius(input);
                printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", input, result);
                break;

            case 5:
                printf("Enter kilograms: ");
                scanf("%lf", &input);
                result = kilograms_to_pounds(input);
                printf("%.2lf kilograms is equal to %.2lf pounds.\n", input, result);
                break;

            case 6:
                printf("Enter pounds: ");
                scanf("%lf", &input);
                result = pounds_to_kilograms(input);
                printf("%.2lf pounds is equal to %.2lf kilograms.\n", input, result);
                break;

            case 7:
                printf("Thank you for using the Unit Converter. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}