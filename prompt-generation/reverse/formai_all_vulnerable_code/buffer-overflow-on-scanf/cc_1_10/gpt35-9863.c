//FormAI DATASET v1.0 Category: Unit converter ; Style: decentralized
#include <stdio.h>

typedef enum {
    UNIT_KM, UNIT_MILES, UNIT_KG, UNIT_LBS, UNIT_CELCIUS, UNIT_FAHRENHEIT
} Unit;

float convert(Unit from_unit, Unit to_unit, float value);

int main(void) {

    float value, converted_value;
    int option, from_unit, to_unit;

    printf("Welcome to the Unit Converter!\n");

    do {
        printf("\nChoose the conversion you'd like to perform:\n");
        printf("1. Kilometers to Miles\n");
        printf("2. Miles to Kilometers\n");
        printf("3. Kilograms to Pounds\n");
        printf("4. Pounds to Kilograms\n");
        printf("5. Celsius to Fahrenheit\n");
        printf("6. Fahrenheit to Celsius\n");
        printf("7. Quit\n");

        scanf("%d", &option);

        if (option == 7) {
            break;
        }

        printf("Enter the value you'd like to convert: ");
        scanf("%f", &value);

        printf("What unit is this value in?\n");
        printf("0 for Kilometers, 1 for Miles,\n");
        printf("2 for Kilograms, 3 for Pounds,\n");
        printf("4 for Celsius, 5 for Fahrenheit\n");

        scanf("%d", &from_unit);

        printf("What unit would you like to convert to?\n");
        printf("0 for Kilometers, 1 for Miles,\n");
        printf("2 for Kilograms, 3 for Pounds,\n");
        printf("4 for Celsius, 5 for Fahrenheit\n");

        scanf("%d", &to_unit);

        converted_value = convert((Unit) from_unit, (Unit) to_unit, value);

        printf("Your converted value is %.3f\n", converted_value);

    } while (option != 7);

    printf("Thank you for using the Unit Converter!\n");

    return 0;
}

float convert(Unit from_unit, Unit to_unit, float value) {

    float result = 0.0;

    switch (from_unit) {
        case UNIT_KM:
            if (to_unit == UNIT_MILES) {
                result = value * 0.621371;
            }
            break;
        case UNIT_MILES:
            if (to_unit == UNIT_KM) {
                result = value * 1.60934;
            }
            break;
        case UNIT_KG:
            if (to_unit == UNIT_LBS) {
                result = value * 2.20462;
            }
            break;
        case UNIT_LBS:
            if (to_unit == UNIT_KG) {
                result = value * 0.453592;
            }
            break;
        case UNIT_CELCIUS:
            if (to_unit == UNIT_FAHRENHEIT) {
                result = (value * (9.0/5.0)) + 32.0;
            }
            break;
        case UNIT_FAHRENHEIT:
            if (to_unit == UNIT_CELCIUS) {
                result = (value - 32.0) * (5.0/9.0);
            }
            break;
        default:
            printf("Invalid input\n");
            break;
    }

    return result;
}