//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CONVERSION_FACTOR_FEET_TO_METRES 0.3048
#define CONVERSION_FACTOR_METRES_TO_FEET 3.28084

typedef enum {
    FEET,
    METRES
} Unit;

typedef struct {
    double value;
    Unit unit;
} Measurement;

Measurement convert(Measurement measurement, Unit target_unit) {
    Measurement converted_measurement;
    if (measurement.unit == FEET && target_unit == METRES) {
        converted_measurement.value = measurement.value * CONVERSION_FACTOR_FEET_TO_METRES;
        converted_measurement.unit = METRES;
    } else if (measurement.unit == METRES && target_unit == FEET) {
        converted_measurement.value = measurement.value * CONVERSION_FACTOR_METRES_TO_FEET;
        converted_measurement.unit = FEET;
    } else {
        converted_measurement.value = measurement.value;
        converted_measurement.unit = measurement.unit;
    }
    return converted_measurement;
}

int main() {
    Measurement measurement;
    Unit target_unit;
    char input[100];
    double input_value;
    int input_unit;

    printf("Enter the value to be converted: ");
    scanf("%lf", &input_value);

    printf("Enter the unit of the value (0 for Feet, 1 for Metres): ");
    scanf("%d", &input_unit);

    printf("Enter the target unit (0 for Feet, 1 for Metres): ");
    scanf("%d", &target_unit);

    measurement.value = input_value;
    measurement.unit = input_unit == 0 ? FEET : METRES;
    target_unit = target_unit == 0 ? FEET : METRES;

    Measurement converted_measurement = convert(measurement, target_unit);

    printf("The converted value is: %.2lf %s\n", converted_measurement.value, converted_measurement.unit == FEET ? "feet" : "metres");

    return 0;
}