//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>

void lengthConversion(double value, int choice) {
    switch (choice) {
        case 1: // Meters to Feet
            printf("%.2f meters = %.2f feet\n", value, value * 3.28084);
            break;
        case 2: // Feet to Meters
            printf("%.2f feet = %.2f meters\n", value, value / 3.28084);
            break;
        case 3: // Kilometers to Miles
            printf("%.2f kilometers = %.2f miles\n", value, value * 0.621371);
            break;
        case 4: // Miles to Kilometers
            printf("%.2f miles = %.2f kilometers\n", value, value / 0.621371);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void temperatureConversion(double value, int choice) {
    switch (choice) {
        case 1: // Celsius to Fahrenheit
            printf("%.2f Celsius = %.2f Fahrenheit\n", value, (value * 9/5) + 32);
            break;
        case 2: // Fahrenheit to Celsius
            printf("%.2f Fahrenheit = %.2f Celsius\n", value, (value - 32) * 5/9);
            break;
        case 3: // Kelvin to Celsius
            printf("%.2f Kelvin = %.2f Celsius\n", value, value - 273.15);
            break;
        case 4: // Celsius to Kelvin
            printf("%.2f Celsius = %.2f Kelvin\n", value, value + 273.15);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void weightConversion(double value, int choice) {
    switch (choice) {
        case 1: // Kilograms to Pounds
            printf("%.2f kilograms = %.2f pounds\n", value, value * 2.20462);
            break;
        case 2: // Pounds to Kilograms
            printf("%.2f pounds = %.2f kilograms\n", value, value / 2.20462);
            break;
        case 3: // Grams to Ounces
            printf("%.2f grams = %.2f ounces\n", value, value * 0.035274);
            break;
        case 4: // Ounces to Grams
            printf("%.2f ounces = %.2f grams\n", value, value / 0.035274);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void volumeConversion(double value, int choice) {
    switch (choice) {
        case 1: // Liters to Gallons
            printf("%.2f liters = %.2f gallons\n", value, value * 0.264172);
            break;
        case 2: // Gallons to Liters
            printf("%.2f gallons = %.2f liters\n", value, value / 0.264172);
            break;
        case 3: // Milliliters to Fluid Ounces
            printf("%.2f milliliters = %.2f fluid ounces\n", value, value * 0.033814);
            break;
        case 4: // Fluid Ounces to Milliliters
            printf("%.2f fluid ounces = %.2f milliliters\n", value, value / 0.033814);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

int main() {
    int category, conversionType;
    double value;

    while (1) {
        printf("Welcome to the Unit Converter!\n");
        printf("Choose a category to convert:\n");
        printf("1. Length\n");
        printf("2. Temperature\n");
        printf("3. Weight\n");
        printf("4. Volume\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &category);
        
        if (category == 5) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
        
        printf("Enter the value to convert: ");
        scanf("%lf", &value);
        
        switch (category) {
            case 1:
                printf("Choose conversion type:\n");
                printf("1. Meters to Feet\n");
                printf("2. Feet to Meters\n");
                printf("3. Kilometers to Miles\n");
                printf("4. Miles to Kilometers\n");
                printf("Enter choice: ");
                scanf("%d", &conversionType);
                lengthConversion(value, conversionType);
                break;
            case 2:
                printf("Choose conversion type:\n");
                printf("1. Celsius to Fahrenheit\n");
                printf("2. Fahrenheit to Celsius\n");
                printf("3. Kelvin to Celsius\n");
                printf("4. Celsius to Kelvin\n");
                printf("Enter choice: ");
                scanf("%d", &conversionType);
                temperatureConversion(value, conversionType);
                break;
            case 3:
                printf("Choose conversion type:\n");
                printf("1. Kilograms to Pounds\n");
                printf("2. Pounds to Kilograms\n");
                printf("3. Grams to Ounces\n");
                printf("4. Ounces to Grams\n");
                printf("Enter choice: ");
                scanf("%d", &conversionType);
                weightConversion(value, conversionType);
                break;
            case 4:
                printf("Choose conversion type:\n");
                printf("1. Liters to Gallons\n");
                printf("2. Gallons to Liters\n");
                printf("3. Milliliters to Fluid Ounces\n");
                printf("4. Fluid Ounces to Milliliters\n");
                printf("Enter choice: ");
                scanf("%d", &conversionType);
                volumeConversion(value, conversionType);
                break;
            default:
                printf("Invalid category choice!\n");
        }
        printf("\n");
    }

    return 0;
}