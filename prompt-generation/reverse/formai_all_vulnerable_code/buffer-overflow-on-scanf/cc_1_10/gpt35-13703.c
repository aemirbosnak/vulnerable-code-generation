//FormAI DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float input_value, output_value;
    int choice;

    printf("Welcome to the Unit Converter!\n\n");

    // displaying the conversion menu
    printf("Choose the conversion that you want:\n");
    printf("1. Inches to Centimeters\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Exit\n");

    // getting the user's choice
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        // Inches to Centimeters Conversion
        case 1:
            printf("\nEnter the value in Inches: ");
            scanf("%f", &input_value);
            output_value = input_value * 2.54;    // 1 inch = 2.54 centimeters
            printf("\n%.2f Inches = %.2f Centimeters\n", input_value, output_value);
            break;

        // Pounds to Kilograms Conversion
        case 2:
            printf("\nEnter the value in Pounds: ");
            scanf("%f", &input_value);
            output_value = input_value * 0.453592;    // 1 pound = 0.453592 kilograms
            printf("\n%.2f Pounds = %.2f Kilograms\n", input_value, output_value);
            break;

        // Miles to Kilometers Conversion
        case 3:
            printf("\nEnter the value in Miles: ");
            scanf("%f", &input_value);
            output_value = input_value * 1.60934;    // 1 mile = 1.60934 kilometers
            printf("\n%.2f Miles = %.2f Kilometers\n", input_value, output_value);
            break;

        // Exit
        case 4:
            printf("\nThank you for using the Unit Converter. Goodbye!\n");
            exit(0);
            break;

        // Invalid Choice
        default:
            printf("\nInvalid Choice! Please try again.\n");
            break;
    }

    return 0;
}