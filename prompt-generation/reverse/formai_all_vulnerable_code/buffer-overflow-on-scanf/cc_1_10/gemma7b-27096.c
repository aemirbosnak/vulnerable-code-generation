//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
// Survivors of the Wasteland C Unit Converter

#include <stdio.h>
#include <math.h>

void main()
{
    float imperial_units, metric_units;
    char unit_type;

    // Welcome the user to the wasteland
    printf("Greetings, traveler. You have stumbled upon the remnants of a once-great civilization. We have one thing to offer: our C Unit Converter.\n");

    // Get the user's input
    printf("Please enter the value you want to convert: ");
    scanf("%f", &imperial_units);

    // Get the user's desired unit type
    printf("Please enter the unit type you want to convert to (m, kg, L): ");
    scanf(" %c", &unit_type);

    // Convert the units
    switch (unit_type)
    {
        case 'm':
            metric_units = imperial_units * 1.613;
            break;
        case 'kg':
            metric_units = imperial_units * 0.45359;
            break;
        case 'L':
            metric_units = imperial_units * 1.05669;
            break;
        default:
            printf("Invalid unit type.\n");
            return;
    }

    // Display the converted units
    printf("Your converted units are: %.2f %s\n", metric_units, unit_type);

    // Offer the user a choice
    printf("Would you like to convert another unit? (Y/N): ");
    char answer;
    scanf(" %c", &answer);

    // Loop until the user decides to quit
    while (answer == 'Y')
    {
        printf("Please enter the value you want to convert: ");
        scanf("%f", &imperial_units);

        printf("Please enter the unit type you want to convert to (m, kg, L): ");
        scanf(" %c", &unit_type);

        switch (unit_type)
        {
            case 'm':
                metric_units = imperial_units * 1.613;
                break;
            case 'kg':
                metric_units = imperial_units * 0.45359;
                break;
            case 'L':
                metric_units = imperial_units * 1.05669;
                break;
            default:
                printf("Invalid unit type.\n");
                return;
        }

        printf("Your converted units are: %.2f %s\n", metric_units, unit_type);
        printf("Would you like to convert another unit? (Y/N): ");
        scanf(" %c", &answer);
    }

    // Farewell the user
    printf("May your journey be prosperous, traveler. We hope to see you again.\n");
}