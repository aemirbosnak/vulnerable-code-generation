//FormAI DATASET v1.0 Category: Unit converter ; Style: imaginative
#include<stdio.h>

void main()
{
    float input, output;
    int choice_from, choice_to;

    printf("Welcome to our unit converter program!\n\n");

    // Displaying the available options
    printf("Available Options:\n");
    printf("1. Feet to Meters\n");
    printf("2. Miles to Kilometers\n");
    printf("3. Pounds to Kilograms\n");
    printf("4. Gallons to Liters\n");
    printf("5. Inches to Centimeters\n\n");

    // Taking input from the user
    printf("Enter the number of the conversion you want to perform: ");
    scanf("%d", &choice_from);

    printf("Enter the unit value you want to convert: ");
    scanf("%f", &input);

    printf("Enter the number of the conversion you want to convert to: ");
    scanf("%d", &choice_to);

    // Performing the conversion based on user input
    switch (choice_from)
    {
        case 1: // Feet to Meters
            output = input * 0.3048;
            break;

        case 2: // Miles to Kilometers
            output = input * 1.60934;
            break;

        case 3: // Pounds to Kilograms
            output = input * 0.453592;
            break;

        case 4: // Gallons to Liters
            output = input * 3.78541;
            break;

        case 5: // Inches to Centimeters
            output = input * 2.54;
            break;

        default:
            printf("Invalid Choice!");
            return;
            break;
    }

    // Displaying the output
    switch (choice_to)
    {
        case 1: // Meters to Feet
            output = output / 0.3048;
            printf("%.2f Feet = %.2f Meters\n", input, output);
            break;

        case 2: // Kilometers to Miles
            output = output / 1.60934;
            printf("%.2f Miles = %.2f Kilometers\n", input, output);
            break;

        case 3: // Kilograms to Pounds
            output = output / 0.453592;
            printf("%.2f Pounds = %.2f Kilograms\n", input, output);
            break;

        case 4: // Liters to Gallons
            output = output / 3.78541;
            printf("%.2f Gallons = %.2f Liters\n", input, output);
            break;

        case 5: // Centimeters to Inches
            output = output / 2.54;
            printf("%.2f Inches = %.2f Centimeters\n", input, output);
            break;

        default:
            printf("Invalid Choice!");
            return;
            break;
    }

    printf("\nThank you for using our unit converter program!");
}