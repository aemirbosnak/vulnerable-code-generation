//FormAI DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>

// Function prototypes
void printMenu();
float convertLength(float, char, char); 
float convertTemperature(float, char, char);
float convertWeight(float, char, char);

int main()
{
    // Declare variables
    float value;
    char fromUnit, toUnit, category;
    int option;

    // Display main menu
    printf("Welcome to the Unit Converter\n\n");
    printMenu();

    // Get user input
    printf("\nEnter an option: ");
    scanf("%d", &option);

    // Evaluate user input
    switch (option)
    {
        case 1: // Length conversion
            printf("\nConversion category: Length\n");

            // Get conversion details
            printf("Enter the value to be converted: ");
            scanf("%f", &value);
            printf("Enter the unit to be converted from (e.g cm): ");
            scanf(" %c", &fromUnit);
            printf("Enter the unit to be converted to (e.g m): ");
            scanf(" %c", &toUnit);

            // Convert length and display result
            float lengthResult = convertLength(value, fromUnit, toUnit);
            printf("%.2f %c = %.2f %c\n", value, fromUnit, lengthResult, toUnit);
            break;

        case 2: // Temperature conversion
            printf("\nConversion category: Temperature\n");

            // Get conversion details
            printf("Enter the value to be converted: ");
            scanf("%f", &value);
            printf("Enter the unit to be converted from (e.g F): ");
            scanf(" %c", &fromUnit);
            printf("Enter the unit to be converted to (e.g C): ");
            scanf(" %c", &toUnit);

            // Convert temperature and display result
            float temperatureResult = convertTemperature(value, fromUnit, toUnit);
            printf("%.2f %c = %.2f %c\n", value, fromUnit, temperatureResult, toUnit);
            break;

        case 3: // Weight conversion
            printf("\nConversion category: Weight\n");

            // Get conversion details
            printf("Enter the value to be converted: ");
            scanf("%f", &value);
            printf("Enter the unit to be converted from (e.g kg): ");
            scanf(" %c", &fromUnit);
            printf("Enter the unit to be converted to (e.g g): ");
            scanf(" %c", &toUnit);

            // Convert weight and display result
            float weightResult = convertWeight(value, fromUnit, toUnit);
            printf("%.2f %c = %.2f %c\n", value, fromUnit, weightResult, toUnit);
            break;

        default: // Invalid option selected
            printf("\nInvalid option. Please select a valid option.\n\n");
            printMenu();
    }

    return 0;
}

// Function to print conversion categories and menu
void printMenu()
{
    printf("Select a conversion category:\n");
    printf("1. Length\n");
    printf("2. Temperature\n");
    printf("3. Weight\n");
}

// Function to convert length
float convertLength(float value, char fromUnit, char toUnit)
{
    float result;

    if (fromUnit == 'm' && toUnit == 'cm')
    {
        result = value * 100;
    }
    else if (fromUnit == 'cm' && toUnit == 'm')
    {
        result = value / 100;
    }
    else if (fromUnit == 'cm' && toUnit == 'mm')
    {
        result = value * 10;
    }
    else if (fromUnit == 'mm' && toUnit == 'cm')
    {
        result = value / 10;
    }
    else if (fromUnit == 'm' && toUnit == 'mm')
    {
        result = value * 1000;
    }
    else if (fromUnit == 'mm' && toUnit == 'm')
    {
        result = value / 1000;
    }
    else // Invalid conversion requested
    {
        printf("\nInvalid conversion from %c to %c\n", fromUnit, toUnit);
        result = 0;
    }

    return result;
}

// Function to convert temperature
float convertTemperature(float value, char fromUnit, char toUnit)
{
    float result;

    if (fromUnit == 'F' && toUnit == 'C')
    {
        result = (value - 32) * 5/9;
    }
    else if (fromUnit == 'C' && toUnit == 'F')
    {
        result = (value * 9/5) + 32;
    }
    else // Invalid conversion requested
    {
        printf("\nInvalid conversion from %c to %c\n", fromUnit, toUnit);
        result = 0;
    }

    return result;
}

// Function to convert weight
float convertWeight(float value, char fromUnit, char toUnit)
{
    float result;

    if (fromUnit == 'kg' && toUnit == 'g')
    {
        result = value * 1000;
    }
    else if (fromUnit == 'g' && toUnit == 'kg')
    {
        result = value / 1000;
    }
    else if (fromUnit == 'kg' && toUnit == 'lb')
    {
        result = value * 2.20462;
    }
    else if (fromUnit == 'lb' && toUnit == 'kg')
    {
        result = value / 2.20462;
    }
    else // Invalid conversion requested
    {
        printf("\nInvalid conversion from %c to %c\n", fromUnit, toUnit);
        result = 0;
    }

    return result;
}