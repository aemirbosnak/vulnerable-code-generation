//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

void unit_converter()
{
    int choice;
    float value;
    char unit_from, unit_to;

    // Display the available units
    printf("Available units: kg, g, lb, t, ml, l, fl oz\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Get the user's value
    printf("Enter the value: ");
    scanf("%f", &value);

    // Get the user's unit of origin
    printf("Enter the unit of origin: ");
    scanf(" %c", &unit_from);

    // Get the user's unit of destination
    printf("Enter the unit of destination: ");
    scanf(" %c", &unit_to);

    // Convert the unit
    float converted_value = 0;

    switch (choice)
    {
        case 1:
            converted_value = value * 1000;
            unit_to = 'kg';
            break;
        case 2:
            converted_value = value * 1000;
            unit_to = 'g';
            break;
        case 3:
            converted_value = value * 2.2046;
            unit_to = 'lb';
            break;
        case 4:
            converted_value = value * 1000000;
            unit_to = 't';
            break;
        case 5:
            converted_value = value * 1000;
            unit_to = 'ml';
            break;
        case 6:
            converted_value = value * 1000;
            unit_to = 'l';
            break;
        case 7:
            converted_value = value * 0.0352;
            unit_to = 'fl oz';
            break;
    }

    // Print the converted value
    printf("The converted value is: %.2f %s\n", converted_value, unit_to);
}

int main()
{
    unit_converter();

    return 0;
}