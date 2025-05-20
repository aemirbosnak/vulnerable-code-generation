//FormAI DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

double convert_length(double value, int from_unit, int to_unit) {
    double inch = 0.0, cm = 0.0, m = 0.0, ft = 0.0, result = 0.0;
    switch(from_unit) {
        case 1: // cm
            cm = value;
            inch = value / 2.54;
            m = value / 100.0;
            ft = inch / 12.0;
            break;
        case 2: // inch
            inch = value;
            cm = value * 2.54;
            m = cm / 100.0;
            ft = inch / 12.0;
            break;
        case 3: // m
            m = value;
            cm = value * 100.0;
            inch = cm / 2.54;
            ft = inch / 12.0;
            break;
        case 4: // ft
            ft = value;
            inch = value * 12.0;
            cm = inch * 2.54;
            m = cm / 100.0;
            break;
    }
    switch(to_unit) {
        case 1: // cm
            result = cm;
            break;
        case 2: // inch
            result = inch;
            break;
        case 3: // m
            result = m;
            break;
        case 4: // ft
            result = ft;
            break;
    }
    return result;
}

int main() {

    double value = 0.0;
    int from_unit = 0, to_unit = 0;

    // Input the data
    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);
    printf("Enter the unit you want to convert from:\n");
    printf("\t1. Centimeter (cm)\n");
    printf("\t2. Inch (in)\n");
    printf("\t3. Meter (m)\n");
    printf("\t4. Foot (ft)\n");
    scanf("%d", &from_unit);
    printf("Enter the unit you want to convert to:\n");
    printf("\t1. Centimeter (cm)\n");
    printf("\t2. Inch (in)\n");
    printf("\t3. Meter (m)\n");
    printf("\t4. Foot (ft)\n");
    scanf("%d", &to_unit);

    // Calculate the result and display it
    double result = convert_length(value, from_unit, to_unit);
    printf("\nResult: %.2lf", result);

    return 0;
}