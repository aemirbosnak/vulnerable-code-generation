//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>
#include <math.h>

int main()
{
    int choice, unit_from, unit_to, quantity;
    float conversion_factor;

    printf("Welcome to the Unit Converter!\n");

    // Display available units
    printf("Available units:\n");
    printf("1. Kilograms\n");
    printf("2. Pounds\n");
    printf("3. Grams\n");
    printf("4. Tons\n");
    printf("5. Liters\n");
    printf("6. Cubic Meters\n");
    printf("7. Cubic Centimeters\n");
    printf("8. Milliliters\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Get the user's quantity
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    // Calculate the conversion factor based on the user's choice
    switch (choice)
    {
        case 1:
            conversion_factor = 1;
            break;
        case 2:
            conversion_factor = 2.2046;
            break;
        case 3:
            conversion_factor = 1000;
            break;
        case 4:
            conversion_factor = 1000000;
            break;
        case 5:
            conversion_factor = 1000;
            break;
        case 6:
            conversion_factor = 1000;
            break;
        case 7:
            conversion_factor = 1000;
            break;
        case 8:
            conversion_factor = 1000;
            break;
    }

    // Convert the quantity
    float converted_quantity = quantity * conversion_factor;

    // Display the converted quantity
    printf("The converted quantity is: %.2f %s\n", converted_quantity, unit_to);

    return 0;
}