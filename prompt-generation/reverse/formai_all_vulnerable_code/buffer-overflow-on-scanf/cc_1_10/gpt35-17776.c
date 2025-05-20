//FormAI DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void printInstructions();
float convertTemperature(float temp, char fromScale, char toScale);
float convertDistance(float dist, char fromUnit, char toUnit);
float convertWeight(float weight, char fromUnit, char toUnit);

int main() {
    int choice;
    char continueChoice;
    do {
        printf("=== UNIT CONVERTER ===\n");
        printf("1. Temperature\n");
        printf("2. Distance\n");
        printf("3. Weight\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            // temperature conversion
            case 1:
                printf("=== TEMPERATURE CONVERSION ===\n");
                printInstructions();
                float temp, convertedTemp;
                char fromScale, toScale;

                printf("Enter the temperature: ");
                scanf("%f", &temp);
                printf("Enter the scale of the temperature (C/F/K): ");
                scanf(" %c", &fromScale);
                printf("Enter the desired scale of the temperature (C/F/K): ");
                scanf(" %c", &toScale);

                convertedTemp = convertTemperature(temp, fromScale, toScale);
                printf("%.2f %c is %.2f %c\n", temp, fromScale, convertedTemp, toScale);
                break;
            
            // distance conversion
            case 2:
                printf("=== DISTANCE CONVERSION ===\n");
                printInstructions();
                float dist, convertedDist;
                char fromUnit, toUnit;

                printf("Enter the distance: ");
                scanf("%f", &dist);
                printf("Enter the unit of distance (m/km/cm/miles): ");
                scanf(" %c", &fromUnit);
                printf("Enter the desired unit of distance (m/km/cm/miles): ");
                scanf(" %c", &toUnit);

                convertedDist = convertDistance(dist, fromUnit, toUnit);
                printf("%.2f %c is %.2f %c\n", dist, fromUnit, convertedDist, toUnit);
                break;
            
            // weight conversion
            case 3:
                printf("=== WEIGHT CONVERSION ===\n");
                printInstructions();
                float weight, convertedWeight;
                char fromWeightUnit, toWeightUnit;

                printf("Enter the weight: ");
                scanf("%f", &weight);
                printf("Enter the unit of weight (g/kg/lb/oz): ");
                scanf(" %c", &fromWeightUnit);
                printf("Enter the desired unit of weight (g/kg/lb/oz): ");
                scanf(" %c", &toWeightUnit);

                convertedWeight = convertWeight(weight, fromWeightUnit, toWeightUnit);
                printf("%.2f %c is %.2f %c\n", weight, fromWeightUnit, convertedWeight, toWeightUnit);
                break;
            
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &continueChoice);
    } while (continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}

void printInstructions() {
    printf("Temperature scales: C - Celsius, F - Fahrenheit, K - Kelvin\n");
    printf("Distance units: m - meters, km - kilometers, cm - centimeters, miles\n");
    printf("Weight units: g - grams, kg - kilograms, lb - pounds, oz - ounces\n");
}

float convertTemperature(float temp, char fromScale, char toScale) {
    float convertedTemp;
    // convert to Celsius
    if (fromScale == 'F') {
        convertedTemp = (temp - 32) * 5 / 9;
    } else if (fromScale == 'K') {
        convertedTemp = temp - 273.15;
    } else {
        convertedTemp = temp;
    }
    // convert from Celsius to desired scale
    if (toScale == 'F') {
        convertedTemp = convertedTemp * 9 / 5 + 32;
    } else if (toScale == 'K') {
        convertedTemp = convertedTemp + 273.15;
    }
    return convertedTemp;
}

float convertDistance(float dist, char fromUnit, char toUnit) {
    float convertedDist;
    // convert to meters
    if (fromUnit == 'km') {
        convertedDist = dist * 1000;
    } else if (fromUnit == 'cm') {
        convertedDist = dist / 100;
    } else if (fromUnit == 'miles') {
        convertedDist = dist * 1609.344;
    } else {
        convertedDist = dist;
    }
    // convert from meters to desired unit
    if (toUnit == 'km') {
        convertedDist = convertedDist / 1000;
    } else if (toUnit == 'cm') {
        convertedDist = convertedDist * 100;
    } else if (toUnit == 'miles') {
        convertedDist = convertedDist / 1609.344;
    }
    return convertedDist;
}

float convertWeight(float weight, char fromUnit, char toUnit) {
    float convertedWeight;
    // convert to grams
    if (fromUnit == 'kg') {
        convertedWeight = weight * 1000;
    } else if (fromUnit == 'lb') {
        convertedWeight = weight * 453.592;
    } else if (fromUnit == 'oz') {
        convertedWeight = weight * 28.34952;
    } else {
        convertedWeight = weight;
    }
    // convert from grams to desired unit
    if (toUnit == 'kg') {
        convertedWeight = convertedWeight / 1000;
    } else if (toUnit == 'lb') {
        convertedWeight = convertedWeight / 453.592;
    } else if (toUnit == 'oz') {
        convertedWeight = convertedWeight / 28.34952;
    }
    return convertedWeight;
}