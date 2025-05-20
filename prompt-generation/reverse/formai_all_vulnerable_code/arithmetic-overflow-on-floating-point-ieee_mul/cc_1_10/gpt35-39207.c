//FormAI DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>

float convertTemperature(float temperature, char fromUnit, char toUnit);
float convertDistance(float distance, char fromUnit, char toUnit);
float convertMass(float mass, char fromUnit, char toUnit);
float convertTime(float time, char fromUnit, char toUnit);

int main() {
    float value;
    char fromUnit, toUnit;

    // Conversion of temperature
    printf("Enter a temperature value: ");
    scanf("%f", &value);
    printf("Enter the unit of temperature (C/F/K): ");
    scanf(" %c", &fromUnit);
    printf("Enter the unit to convert to (C/F/K): ");
    scanf(" %c", &toUnit);

    float convertedTemperature = convertTemperature(value, fromUnit, toUnit);
    printf("Converted temperature: %.2f %c = %.2f %c\n", value, fromUnit, convertedTemperature, toUnit);

    // Conversion of distance
    printf("Enter a distance value: ");
    scanf("%f", &value);
    printf("Enter the unit of distance (M/FT/IN/CM/KM/MI): ");
    scanf(" %c", &fromUnit);
    printf("Enter the unit to convert to (M/FT/IN/CM/KM/MI): ");
    scanf(" %c", &toUnit);

    float convertedDistance = convertDistance(value, fromUnit, toUnit);
    printf("Converted distance: %.2f %c = %.2f %c\n", value, fromUnit, convertedDistance, toUnit);

    // Conversion of mass
    printf("Enter a mass value: ");
    scanf("%f", &value);
    printf("Enter the unit of mass (KG/LB/OZ/G): ");
    scanf(" %c", &fromUnit);
    printf("Enter the unit to convert to (KG/LB/OZ/G): ");
    scanf(" %c", &toUnit);

    float convertedMass = convertMass(value, fromUnit, toUnit);
    printf("Converted mass: %.2f %c = %.2f %c\n", value, fromUnit, convertedMass, toUnit);

    // Conversion of time
    printf("Enter a time value: ");
    scanf("%f", &value);
    printf("Enter the unit of time (SEC/MIN/HR): ");
    scanf(" %c", &fromUnit);
    printf("Enter the unit to convert to (SEC/MIN/HR): ");
    scanf(" %c", &toUnit);

    float convertedTime = convertTime(value, fromUnit, toUnit);
    printf("Converted time: %.2f %c = %.2f %c\n", value, fromUnit, convertedTime, toUnit);

    return 0;
}

float convertTemperature(float temperature, char fromUnit, char toUnit) {
    if (fromUnit == 'F') {
        temperature = (temperature - 32) / 1.8;
    } else if (fromUnit == 'K') {
        temperature -= 273.15;
    }

    if (toUnit == 'F') {
        temperature = (temperature * 1.8) + 32;
    } else if (toUnit == 'K') {
        temperature += 273.15;
    }

    return temperature;
}

float convertDistance(float distance, char fromUnit, char toUnit) {
    if (fromUnit == 'IN') {
        distance /= 39.37;
    } else if (fromUnit == 'FT') {
        distance /= 3.281;
    } else if (fromUnit == 'CM') {
        distance /= 100;
    } else if (fromUnit == 'KM') {
        distance *= 1000;
    } else if (fromUnit == 'MI') {
        distance *= 1609.344;
    }

    if (toUnit == 'IN') {
        distance *= 39.37;
    } else if (toUnit == 'FT') {
        distance *= 3.281;
    } else if (toUnit == 'CM') {
        distance *= 100;
    } else if (toUnit == 'KM') {
        distance /= 1000;
    } else if (toUnit == 'MI') {
        distance /= 1609.344;
    }

    return distance;
}

float convertMass(float mass, char fromUnit, char toUnit) {
    if (fromUnit == 'LB') {
        mass /= 2.20462;
    } else if (fromUnit == 'OZ') {
        mass /= 35.274;
    } else if (fromUnit == 'G') {
        mass /= 1000;
    }

    if (toUnit == 'LB') {
        mass *= 2.20462;
    } else if (toUnit == 'OZ') {
        mass *= 35.274;
    } else if (toUnit == 'G') {
        mass *= 1000;
    }

    return mass;
}

float convertTime(float time, char fromUnit, char toUnit) {
    if (fromUnit == 'MIN') {
        time *= 60;
    } else if (fromUnit == 'HR') {
        time *= 3600;
    }

    if (toUnit == 'MIN') {
        time /= 60;
    } else if (toUnit == 'HR') {
        time /= 3600;
    }

    return time;
}