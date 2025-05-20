//FormAI DATASET v1.0 Category: Unit converter ; Style: Alan Touring
#include <stdio.h>

int main() {

    int choice;
    double value, result;

    printf("Welcome to the Unit Converter program!\n");
    printf("\nPlease choose an option from the following:\n");

    printf("\n1. Convert Celsius to Fahrenheit.");
    printf("\n2. Convert Fahrenheit to Celsius.");
    printf("\n3. Convert Kilograms to Pounds.");
    printf("\n4. Convert Pounds to Kilograms.\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1: //Convert Celsius to Fahrenheit
            printf("\nEnter the Celsius value: ");
            scanf("%lf", &value);
            result = (value * 9/5) + 32;
            printf("\n%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit!", value, result);
            break;

        case 2: //Convert Fahrenheit to Celsius
            printf("\nEnter the Fahrenheit value: ");
            scanf("%lf", &value);
            result = (value - 32) * 5/9;
            printf("\n%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius!", value, result);
            break;

        case 3: //Convert Kilograms to Pounds
            printf("\nEnter the Kilogram value: ");
            scanf("%lf", &value);
            result = value * 2.20462;
            printf("\n%.2lf Kilograms is equal to %.2lf Pounds!", value, result);
            break;

        case 4: //Convert Pounds to Kilograms
            printf("\nEnter the Pound value: ");
            scanf("%lf", &value);
            result = value * 0.453592;
            printf("\n%.2lf Pounds is equal to %.2lf Kilograms!", value, result);
            break;

        default:
            printf("\nInvalid Choice! Please try again!");
            break;

    }

    printf("\nThanks for using our unit converter program!");

    return 0;

}