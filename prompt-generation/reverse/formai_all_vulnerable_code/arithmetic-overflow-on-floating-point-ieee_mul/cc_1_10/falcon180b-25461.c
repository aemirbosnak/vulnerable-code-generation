//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef enum {
    CELSIUS = 0,
    FAHRENHEIT = 1
} TemperatureScale;

typedef struct {
    double value;
    TemperatureScale scale;
} Temperature;

Temperature convertTemperature(Temperature temperature, TemperatureScale fromScale, TemperatureScale toScale) {
    if (fromScale == toScale) {
        return temperature;
    }

    double convertedValue = 0.0;

    switch (fromScale) {
        case CELSIUS:
            switch (toScale) {
                case CELSIUS:
                    convertedValue = temperature.value;
                    break;
                case FAHRENHEIT:
                    convertedValue = (temperature.value * 9.0 / 5.0) + 32.0;
                    break;
            }
            break;
        case FAHRENHEIT:
            switch (toScale) {
                case CELSIUS:
                    convertedValue = (temperature.value - 32.0) * 5.0 / 9.0;
                    break;
                case FAHRENHEIT:
                    convertedValue = temperature.value;
                    break;
            }
            break;
    }

    Temperature result;
    result.value = convertedValue;
    result.scale = toScale;

    return result;
}

void printTemperature(Temperature temperature) {
    if (temperature.scale == CELSIUS) {
        printf("%.2f°C\n", temperature.value);
    } else {
        printf("%.2f°F\n", temperature.value);
    }
}

int main() {
    Temperature currentTemperature;
    Temperature targetTemperature;

    printf("Enter current temperature: ");
    scanf("%lf", &currentTemperature.value);
    printf("Enter temperature scale (C/F): ");
    scanf(" %c", &currentTemperature.scale);

    printf("Enter target temperature: ");
    scanf("%lf", &targetTemperature.value);
    printf("Enter temperature scale (C/F): ");
    scanf(" %c", &targetTemperature.scale);

    if (currentTemperature.scale!= targetTemperature.scale) {
        currentTemperature = convertTemperature(currentTemperature, currentTemperature.scale, targetTemperature.scale);
        targetTemperature = convertTemperature(targetTemperature, targetTemperature.scale, currentTemperature.scale);
    }

    double temperatureDifference = targetTemperature.value - currentTemperature.value;

    if (temperatureDifference > 0.0) {
        printf("The current temperature is %.2f°%c below the target temperature.\n", temperatureDifference, targetTemperature.scale == CELSIUS? 'C' : 'F');
    } else if (temperatureDifference < 0.0) {
        printf("The current temperature is %.2f°%c above the target temperature.\n", temperatureDifference, targetTemperature.scale == CELSIUS? 'C' : 'F');
    } else {
        printf("The current temperature is at the target temperature.\n");
    }

    return 0;
}