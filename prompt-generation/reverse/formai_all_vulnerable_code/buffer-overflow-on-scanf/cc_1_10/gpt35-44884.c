//FormAI DATASET v1.0 Category: Unit converter ; Style: expert-level
#include<stdio.h>

float convertLength(float value, char unitFrom[], char unitTo[]) {
    float result;

    if (strcmp(unitFrom, "km") == 0) {
        if (strcmp(unitTo, "m") == 0) {
            result = value * 1000;
        } else if (strcmp(unitTo, "cm") == 0) {
            result = value * 100000;
        } else if (strcmp(unitTo, "ft") == 0) {
            result = value * 3280.84;
        } else {
            result = value;
        }
    } else if (strcmp(unitFrom, "m") == 0) {
        if (strcmp(unitTo, "km") == 0) {
            result = value / 1000;
        } else if (strcmp(unitTo, "cm") == 0) {
            result = value * 100;
        } else if (strcmp(unitTo, "ft") == 0) {
            result = value * 3.28084;
        } else {
            result = value;
        }
    } else if (strcmp(unitFrom, "cm") == 0) {
        if (strcmp(unitTo, "km") == 0) {
            result = value / 100000;
        } else if (strcmp(unitTo, "m") == 0) {
            result = value / 100;
        } else if (strcmp(unitTo, "ft") == 0) {
            result = value / 30.48;
        } else {
            result = value;
        }
    } else if (strcmp(unitFrom, "ft") == 0) {
        if (strcmp(unitTo, "km") == 0) {
            result = value / 3280.84;
        } else if (strcmp(unitTo, "m") == 0) {
            result = value / 3.28084;
        } else if (strcmp(unitTo, "cm") == 0) {
            result = value * 30.48;
        } else {
            result = value;
        }
    } else {
        result = value;
    }
    return result;
}

int main() {
    float inputValue;
    char inputUnit[10];
    char outputUnit[10];

    printf("Enter value to convert: ");
    scanf("%f", &inputValue);

    printf("Enter input unit (km, m, cm, ft): ");
    scanf("%s", inputUnit);

    printf("Enter output unit (km, m, cm, ft): ");
    scanf("%s", outputUnit);

    float result = convertLength(inputValue, inputUnit, outputUnit);
    printf("%f %s is equal to %f %s", inputValue, inputUnit, result, outputUnit);

    return 0;
}