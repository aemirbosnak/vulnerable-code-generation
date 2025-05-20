//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_choice = 0;
    char unit_from = ' ';
    char unit_to = ' ';

    // Display the available units
    printf("Available units:\n");
    printf("1. Liters\n");
    printf("2. Gallons\n");
    printf("3. Cups\n");
    printf("4. Milliliters\n");
    printf("5. Quarts\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &num_choice);

    // Get the user's unit conversion choices
    printf("Enter the unit you are converting from: ");
    scanf(" %c", &unit_from);

    printf("Enter the unit you are converting to: ");
    scanf(" %c", &unit_to);

    // Convert the units
    double conversion_factor = 0;
    switch (num_choice)
    {
        case 1:
            conversion_factor = 1000;
            break;
        case 2:
            conversion_factor = 3.785;
            break;
        case 3:
            conversion_factor = 0.25;
            break;
        case 4:
            conversion_factor = 1000;
            break;
        case 5:
            conversion_factor = 4.0;
            break;
    }

    // Calculate the converted volume
    double volume = 0;
    printf("Enter the volume: ");
    scanf("%lf", &volume);

    double converted_volume = volume * conversion_factor;

    // Display the converted volume
    printf("The converted volume is: %.2lf %s\n", converted_volume, unit_to);

    return 0;
}