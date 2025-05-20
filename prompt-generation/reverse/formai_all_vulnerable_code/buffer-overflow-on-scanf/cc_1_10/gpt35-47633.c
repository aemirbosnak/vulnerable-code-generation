//FormAI DATASET v1.0 Category: Unit converter ; Style: immersive
#include <stdio.h>
#include <string.h>

// Function to convert distance
float distanceConverter(float value, char fromUnit[], char toUnit[])
{
    float result;
    if(strcmp(fromUnit, "m") == 0 && strcmp(toUnit, "ft") == 0)
        result = value * 3.28;
    else if(strcmp(fromUnit, "ft") == 0 && strcmp(toUnit, "m") == 0)
        result = value / 3.28;
    else if(strcmp(fromUnit, "km") == 0 && strcmp(toUnit, "mi") == 0)
        result = value / 1.609;
    else if(strcmp(fromUnit, "mi") == 0 && strcmp(toUnit, "km") == 0)
        result = value * 1.609;
    else
        result = value;
    return result;
}

// Function to convert weight
float weightConverter(float value, char fromUnit[], char toUnit[])
{
    float result;
    if(strcmp(fromUnit, "kg") == 0 && strcmp(toUnit, "lb") == 0)
        result = value * 2.205;
    else if(strcmp(fromUnit, "lb") == 0 && strcmp(toUnit, "kg") == 0)
        result = value / 2.205;
    else if(strcmp(fromUnit, "g") == 0 && strcmp(toUnit, "oz") == 0)
        result = value / 28.35;
    else if(strcmp(fromUnit, "oz") == 0 && strcmp(toUnit, "g") == 0)
        result = value * 28.35;
    else
        result = value;
    return result;
}

int main()
{
    // Introduction
    printf("=== Unit Converter ===\n");
    printf("This program converts between different units of measurement.\n");

    // Ask for user input
    char fromUnit[5], toUnit[5];
    float value;
    printf("\nEnter value: ");
    scanf("%f", &value);
    printf("From unit (e.g. m, ft, km, mi, kg, lb, g, oz): ");
    scanf("%s", fromUnit);
    printf("To unit (e.g. m, ft, km, mi, kg, lb, g, oz): ");
    scanf("%s", toUnit);

    // Convert distance or weight
    float result;
    if(strcmp(fromUnit, "m") == 0 || strcmp(fromUnit, "ft") == 0 || strcmp(fromUnit, "km") == 0 || strcmp(fromUnit, "mi") == 0)
        result = distanceConverter(value, fromUnit, toUnit);
    else if(strcmp(fromUnit, "kg") == 0 || strcmp(fromUnit, "lb") == 0 || strcmp(fromUnit, "g") == 0 || strcmp(fromUnit, "oz") == 0)
        result = weightConverter(value, fromUnit, toUnit);
    else
        result = value;

    // Output result
    printf("\n%.2f %s = %.2f %s\n", value, fromUnit, result, toUnit);

    // Goodbye message
    printf("\nThank you for using the Unit Converter!\n");

    return 0;
}