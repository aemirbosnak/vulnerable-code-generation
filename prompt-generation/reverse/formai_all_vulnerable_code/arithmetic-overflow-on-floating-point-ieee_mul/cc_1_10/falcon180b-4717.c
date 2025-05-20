//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double value;
    char* unit;
} UnitValue;

void printUnitValue(UnitValue uv) {
    printf("%f %s\n", uv.value, uv.unit);
}

UnitValue createUnitValue(double value, char* unit) {
    UnitValue uv;
    uv.value = value;
    uv.unit = unit;
    return uv;
}

UnitValue addUnitValues(UnitValue uv1, UnitValue uv2) {
    if (strcmp(uv1.unit, uv2.unit)!= 0) {
        printf("Error: cannot add values with different units.\n");
        exit(1);
    }
    UnitValue result;
    result.value = uv1.value + uv2.value;
    result.unit = uv1.unit;
    return result;
}

UnitValue subtractUnitValues(UnitValue uv1, UnitValue uv2) {
    if (strcmp(uv1.unit, uv2.unit)!= 0) {
        printf("Error: cannot subtract values with different units.\n");
        exit(1);
    }
    UnitValue result;
    result.value = uv1.value - uv2.value;
    result.unit = uv1.unit;
    return result;
}

UnitValue multiplyUnitValueByScalar(UnitValue uv, double scalar) {
    UnitValue result;
    result.value = uv.value * scalar;
    result.unit = uv.unit;
    return result;
}

UnitValue divideUnitValueByScalar(UnitValue uv, double scalar) {
    UnitValue result;
    result.value = uv.value / scalar;
    result.unit = uv.unit;
    return result;
}

int main() {
    double value1, value2;
    char unit1[10], unit2[10];

    printf("Enter the first value and its unit: ");
    scanf("%lf %s", &value1, unit1);

    printf("Enter the second value and its unit: ");
    scanf("%lf %s", &value2, unit2);

    UnitValue uv1 = createUnitValue(value1, unit1);
    UnitValue uv2 = createUnitValue(value2, unit2);

    if (strcmp(uv1.unit, uv2.unit) == 0) {
        UnitValue result = addUnitValues(uv1, uv2);
        printUnitValue(result);

        result = subtractUnitValues(uv1, uv2);
        printUnitValue(result);

        result = multiplyUnitValueByScalar(uv1, 2.0);
        printUnitValue(result);

        result = divideUnitValueByScalar(uv1, 2.0);
        printUnitValue(result);
    } else {
        printf("Error: cannot perform operations on values with different units.\n");
    }

    return 0;
}