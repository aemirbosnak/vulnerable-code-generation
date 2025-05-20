//FormAI DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>

int main() {

    int optionConversion, value;
    float convertedValue;

    printf("\nWelcome to the Unit Conversion program! \n\n");
    printf("Choose the type of conversion you want:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Miles to Kilometers\n");
    printf("3. Pounds to Kilograms\n");
    printf("4. Inches to Centimeters\n");
    printf("\nEnter your choice: ");
    scanf("%d", &optionConversion);

    switch (optionConversion) {
        case 1:
            printf("\nYou have chosen Celsius to Fahrenheit conversion.\n");
            printf("Enter temperature in Celsius: ");
            scanf("%d", &value);

            convertedValue = (value * 9 / 5) + 32;

            printf("%d Celsius is equal to %.2f Fahrenheit.\n", value, convertedValue);
            break;

        case 2:
            printf("\nYou have chosen Miles to Kilometers conversion.\n");
            printf("Enter distance in Miles: ");
            scanf("%d", &value);

            convertedValue = value * 1.60934;

            printf("%d Miles is equal to %.2f Kilometers.\n", value, convertedValue);
            break;

        case 3:
            printf("\nYou have chosen Pounds to Kilograms conversion.\n");
            printf("Enter weight in Pounds: ");
            scanf("%d", &value);

            convertedValue = value * 0.453592;

            printf("%d Pounds is equal to %.2f Kilograms.\n", value, convertedValue);
            break;

        case 4:
            printf("\nYou have chosen Inches to Centimeters conversion.\n");
            printf("Enter length in Inches: ");
            scanf("%d", &value);

            convertedValue = value * 2.54;

            printf("%d Inches is equal to %.2f Centimeters.\n", value, convertedValue);
            break;

        default:
            printf("\nInvalid input. Please try again.\n");
    }

    printf("\nThank you for using the Unit Conversion program!\n");

    return 0;

}