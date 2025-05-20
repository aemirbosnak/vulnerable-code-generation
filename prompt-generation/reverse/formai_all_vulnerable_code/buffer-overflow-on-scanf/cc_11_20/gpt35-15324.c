//FormAI DATASET v1.0 Category: Unit converter ; Style: excited
#include <stdio.h>

int main() {
    printf("Welcome to the Ultimate Unit Converter!\n");
    printf("With this program, you can convert between metric and imperial units with ease!\n");
    printf("Enter the unit you wish to convert from:\n");
    printf("1 - Centimeters\n2 - Meters\n3 - Kilometers\n4 - Inches\n5 - Feet\n6 - Miles\n");
    int from;
    scanf("%d", &from);
    printf("Enter the unit you wish to convert to:\n");
    printf("1 - Centimeters\n2 - Meters\n3 - Kilometers\n4 - Inches\n5 - Feet\n6 - Miles\n");
    int to;
    scanf("%d", &to);
    printf("Enter the value to convert:\n");
    double value;
    scanf("%lf", &value);

    switch(from) {
        case 1: // Centimeters
            value /= 100; // Convert to meters
            break;
        case 2: // Meters
            break;
        case 3: // Kilometers
            value *= 1000; // Convert to meters
            break;
        case 4: // Inches
            value *= 0.0254; // Convert to meters
            break;
        case 5: // Feet
            value *= 0.3048; // Convert to meters
            break;
        case 6: // Miles
            value *= 1609.34; // Convert to meters
            break;
        default:
            printf("Invalid input!\n");
            return 0;
    }

    switch(to) {
        case 1: // Centimeters
            value *= 100; // Convert to centimeters
            break;
        case 2: // Meters
            break;
        case 3: // Kilometers
            value /= 1000; // Convert to kilometers
            break;
        case 4: // Inches
            value /= 0.0254; // Convert to inches
            break;
        case 5: // Feet
            value /= 0.3048; // Convert to feet
            break;
        case 6: // Miles
            value /= 1609.34; // Convert to miles
            break;
        default:
            printf("Invalid input!\n");
            return 0;
    }

    printf("The converted value is: %lf\n", value);
    printf("Thank you for using the Ultimate Unit Converter!\n");

    return 0;
}