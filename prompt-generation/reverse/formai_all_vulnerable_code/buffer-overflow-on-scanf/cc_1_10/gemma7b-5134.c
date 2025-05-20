//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, unit_from, unit_to;
    float value;

    // Welcome to the Post-Apocalyptic Unit Converter
    printf("Welcome to the Post-Apocalyptic Unit Converter!\n");

    // Display available units
    printf("Available units:\n");
    printf("1. Bar (Old)\n");
    printf("2. Lit (New)\n");
    printf("3. Stone\n");
    printf("4. Scrap Metal\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Get the value to be converted
    printf("Enter the value to be converted: ");
    scanf("%f", &value);

    // Convert the unit
    switch (choice)
    {
        case 1:
            unit_from = 1;
            unit_to = 2;
            break;
        case 2:
            unit_from = 2;
            unit_to = 3;
            break;
        case 3:
            unit_from = 3;
            unit_to = 4;
            break;
        case 4:
            unit_from = 4;
            unit_to = 1;
            break;
        default:
            printf("Invalid choice.\n");
            exit(1);
    }

    // Convert the value
    float converted_value = value * (unit_to / unit_from);

    // Display the converted value
    printf("The converted value is: %.2f %s.\n", converted_value, unit_to);
}