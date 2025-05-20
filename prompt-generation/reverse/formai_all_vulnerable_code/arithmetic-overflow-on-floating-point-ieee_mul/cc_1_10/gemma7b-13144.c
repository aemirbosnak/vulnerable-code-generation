//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define the conversion factor for each unit
const int km_to_miles = 0.621371;
const int kg_to_pounds = 2.20462;
const int l_to_qt = 1.05669;

int main()
{
    int choice;
    float value;
    char unit_from, unit_to;

    // Display the available conversions
    printf("Available conversions:\n");
    printf("1. Kilometers to Miles\n");
    printf("2. Kilograms to Pounds\n");
    printf("3. Liters to Quarts\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Get the user's value
    printf("Enter the value: ");
    scanf("%f", &value);

    // Get the user's units
    printf("Enter the unit you are converting from: ");
    scanf(" %c", &unit_from);

    // Get the user's desired units
    printf("Enter the unit you want to convert to: ");
    scanf(" %c", &unit_to);

    // Convert the value
    switch (choice)
    {
        case 1:
            value *= km_to_miles;
            break;
        case 2:
            value *= kg_to_pounds;
            break;
        case 3:
            value *= l_to_qt;
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    // Display the converted value
    printf("The converted value is: %.2f %s.\n", value, unit_to);

    return 0;
}