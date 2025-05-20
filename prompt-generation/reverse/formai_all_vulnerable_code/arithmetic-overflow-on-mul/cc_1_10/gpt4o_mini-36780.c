//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define LIGHT_SPEED 299792458 // Speed of light in meters per second
#define EARTH_GRAVITY 9.80665 // Gravitational acceleration on Earth in m/s²

typedef enum {
    METERS,
    KILOMETERS,
    MILES,
    LIGHT_YEARS,
} DistanceUnit;

typedef enum {
    GRAMS,
    KILOGRAMS,
    POUNDS,
    TONS,
} WeightUnit;

void displayDistanceMenu() {
    printf("\n--- Distance Unit Converter ---\n");
    printf("1. Meters\n");
    printf("2. Kilometers\n");
    printf("3. Miles\n");
    printf("4. Light Years\n");
    printf("Select a distance unit (1-4): ");
}

void displayWeightMenu() {
    printf("\n--- Weight Unit Converter ---\n");
    printf("1. Grams\n");
    printf("2. Kilograms\n");
    printf("3. Pounds\n");
    printf("4. Tons\n");
    printf("Select a weight unit (1-4): ");
}

double convertDistance(double value, DistanceUnit fromUnit, DistanceUnit toUnit) {
    double meters;

    // Convert input to meters
    switch (fromUnit) {
        case METERS:
            meters = value;
            break;
        case KILOMETERS:
            meters = value * 1000;
            break;
        case MILES:
            meters = value * 1609.34;
            break;
        case LIGHT_YEARS:
            meters = value * LIGHT_SPEED * 31557600; // Light-year conversion based on the speed of light
            break;
    }

    // Convert to target unit
    switch (toUnit) {
        case METERS:
            return meters;
        case KILOMETERS:
            return meters / 1000;
        case MILES:
            return meters / 1609.34;
        case LIGHT_YEARS:
            return meters / (LIGHT_SPEED * 31557600);
    }

    return 0; // Default return (should not reach here)
}

double convertWeight(double value, WeightUnit fromUnit, WeightUnit toUnit) {
    double grams;

    // Convert input to grams
    switch (fromUnit) {
        case GRAMS:
            grams = value;
            break;
        case KILOGRAMS:
            grams = value * 1000;
            break;
        case POUNDS:
            grams = value * 453.592;
            break;
        case TONS:
            grams = value * 1e6;
            break;
    }

    // Convert to target unit
    switch (toUnit) {
        case GRAMS:
            return grams;
        case KILOGRAMS:
            return grams / 1000;
        case POUNDS:
            return grams / 453.592;
        case TONS:
            return grams / 1e6;
    }

    return 0; // Default return (should not reach here)
}

int main() {
    int choice;
    double value, result;
    DistanceUnit fromDist, toDist;
    WeightUnit fromWeight, toWeight;

    printf("Welcome to the Futuristic C Unit Converter!\n");
    printf("-------------------------------------------------\n");

    while (1) {
        printf("\nSelect conversion type:\n");
        printf("1. Distance\n");
        printf("2. Weight\n");
        printf("0. Exit\n");
        printf("Your choice (0-2): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the unit converter. Farewell, traveler!\n");
            break;
        } else if (choice == 1) {
            displayDistanceMenu();
            scanf("%d", &fromDist);
            fromDist--; // Adjust for 0-based indexing

            displayDistanceMenu();
            scanf("%d", &toDist);
            toDist--; // Adjust for 0-based indexing

            printf("Enter the distance value to convert: ");
            scanf("%lf", &value);

            result = convertDistance(value, fromDist, toDist);
            printf("Converted distance: %.10f\n", result);
        } else if (choice == 2) {
            displayWeightMenu();
            scanf("%d", &fromWeight);
            fromWeight--; // Adjust for 0-based indexing

            displayWeightMenu();
            scanf("%d", &toWeight);
            toWeight--; // Adjust for 0-based indexing

            printf("Enter the weight value to convert: ");
            scanf("%lf", &value);

            result = convertWeight(value, fromWeight, toWeight);
            printf("Converted weight: %.10f\n", result);
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}