//FormAI DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>

enum unit_type { DISTANCE, WEIGHT, TEMPERATURE };

void displayOptions(enum unit_type unit);
float distanceToMeters(float value, int unit);
float weightToKilograms(float value, int unit);
float temperatureToCelsius(float value, int unit);

int main() {
    int option;
    float value;

    printf("Welcome to the Ultimate Unit Converter!\n");
    printf("Choose an option:\n");
    printf("1. Distance\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    scanf("%d", &option);

    switch (option) {
        case DISTANCE:
            displayOptions(DISTANCE);
            scanf("%f", &value);

            printf("%.2f meters\n", distanceToMeters(value, option));
            printf("%.2f meters\n", distanceToMeters(value, option+1));
            printf("%.2f meters\n", distanceToMeters(value, option+2));
            break;

        case WEIGHT:
            displayOptions(WEIGHT);
            scanf("%f", &value);

            printf("%.2f kilograms\n", weightToKilograms(value, option));
            printf("%.2f kilograms\n", weightToKilograms(value, option+1));
            printf("%.2f kilograms\n", weightToKilograms(value, option+2));
            break;

        case TEMPERATURE:
            displayOptions(TEMPERATURE);
            scanf("%f", &value);

            printf("%.2f degrees Celsius\n", temperatureToCelsius(value, option));
            printf("%.2f degrees Celsius\n", temperatureToCelsius(value, option+1));
            printf("%.2f degrees Celsius\n", temperatureToCelsius(value, option+2));
            break;

        default:
            printf("Invalid option. Please try again.\n");
            break;
    }

    return 0;
}

void displayOptions(enum unit_type unit) {
    if (unit == DISTANCE) {
        printf("Choose a unit:\n");
        printf("1. Centimeters\n");
        printf("2. Inches\n");
        printf("3. Feet\n");
    } else if (unit == WEIGHT) {
        printf("Choose a unit:\n");
        printf("1. Grams\n");
        printf("2. Ounces\n");
        printf("3. Pounds\n");
    } else if (unit == TEMPERATURE) {
        printf("Choose a unit:\n");
        printf("1. Fahrenheit\n");
        printf("2. Kelvin\n");
        printf("3. Rankine\n");
    }
}

float distanceToMeters(float value, int unit) {
    if (unit == 1) {
        return value / 100;
    } else if (unit == 2) {
        return value * 0.0254;
    } else {
        return value * 0.3048;
    }
}

float weightToKilograms(float value, int unit) {
    if (unit == 1) {
        return value / 1000;
    } else if (unit == 2) {
        return value * 0.02835;
    } else {
        return value * 0.453592;
    }
}

float temperatureToCelsius(float value, int unit) {
    if (unit == 1) {
        return (value - 32) * 5/9;
    } else if (unit == 2) {
        return value - 273.15;
    } else {
        return (value - 491.67) * 5/9;
    }
}