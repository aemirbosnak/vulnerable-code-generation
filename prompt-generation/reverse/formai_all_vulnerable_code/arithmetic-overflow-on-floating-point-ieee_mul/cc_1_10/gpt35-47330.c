//FormAI DATASET v1.0 Category: Unit converter ; Style: energetic
#include <stdio.h>

int main() {
    printf("Welcome to the Energetic Unit Converter!\n\n");
    printf("This program will convert units of distance, weight/ mass, and temperature.\n\n");

    printf("Enter the type of unit you wish to convert (D for distance, M for mass, or T for temperature): ");
    char unit_type;
    scanf("%c", &unit_type);

    // DISTANCE CONVERSION
    if(unit_type == 'D') {
        printf("\nYou have selected distance conversion\n\n");
        float distance_value;
        printf("Enter a value to convert (in kilometers): ");
        scanf("%f", &distance_value);
        printf("\n%.2f kilometers is equivalent to:\n", distance_value);
        printf("%.2f miles\n", distance_value * 0.621371);
        printf("%.2f feet\n", distance_value * 3280.84);
        printf("%.2f yards\n", distance_value * 1093.61);
        printf("%.2f meters\n", distance_value * 1000);
    }

    // MASS CONVERSION
    else if(unit_type == 'M') {
        printf("\nYou have selected weight/ mass conversion\n\n");
        float mass_value;
        printf("Enter a value to convert (in kilograms): ");
        scanf("%f", &mass_value);
        printf("\n%.2f kilograms is equivalent to:\n", mass_value);
        printf("%.2f pounds\n", mass_value * 2.20462);
        printf("%.2f ounces\n", mass_value * 35.274);
        printf("%.2f grams\n", mass_value * 1000);
    }

    // TEMPERATURE CONVERSION
    else if(unit_type == 'T') {
        printf("\nYou have selected temperature conversion\n\n");
        float temp_value;
        printf("Enter a value to convert (in Celsius): ");
        scanf("%f", &temp_value);
        printf("\n%.2f degrees Celsius is equivalent to:\n", temp_value);
        printf("%.2f degrees Fahrenheit\n", (temp_value * 1.8) + 32);
        printf("%.2f Kelvin\n", temp_value + 273.15);
    }

    else {
        printf("\nInvalid input, please enter D, M, or T only\n");
    }

    return 0;
}