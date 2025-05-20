//FormAI DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>

int main() {
    printf("Welcome to the Unit Converter program!\n\n");

    double input;
    printf("Enter the value you want to convert: ");
    scanf("%lf", &input);

    int selection;
    printf("\nSelect an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    printf("5. Pounds to Kilograms\n");
    printf("6. Kilograms to Pounds\n");
    printf("Enter your choice: ");
    scanf("%d", &selection);

    double result;
    switch (selection) {
        case 1:
            result = input * 9 / 5 + 32;
            printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit\n", input, result);
            break;
        case 2:
            result = (input - 32) * 5 / 9;
            printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius\n", input, result);
            break;
        case 3:
            result = input / 1.609;
            printf("%.2lf kilometers is %.2lf miles\n", input, result);
            break;
        case 4:
            result = input * 1.609;
            printf("%.2lf miles is %.2lf kilometers\n", input, result);
            break;
        case 5:
            result = input / 2.2046;
            printf("%.2lf pounds is %.2lf kilograms\n", input, result);
            break;
        case 6:
            result = input * 2.2046;
            printf("%.2lf kilograms is %.2lf pounds\n", input, result);
            break;
        default:
            printf("Invalid option!\n");
            return 1;
    }

    printf("\nThank you for using the Unit Converter program.\n");

    return 0;
}