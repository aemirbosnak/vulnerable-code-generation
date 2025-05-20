//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define NUM_CONVERSIONS 10

typedef struct {
    char *name;
    double (*convert)(double);
} Conversion;

double convert_meters_to_feet(double meters) {
    return meters * 3.28084;
}

double convert_meters_to_yards(double meters) {
    return meters * 1.09361;
}

double convert_meters_to_miles(double meters) {
    return meters * 0.000621371;
}

double convert_meters_to_kilometers(double meters) {
    return meters / 1000;
}

double convert_meters_to_centimeters(double meters) {
    return meters * 100;
}

double convert_meters_to_millimeters(double meters) {
    return meters * 1000;
}

double convert_meters_to_inches(double meters) {
    return meters * 39.3701;
}

double convert_meters_to_pixels(double meters) {
    return meters * 3.7795;
}

double convert_meters_to_points(double meters) {
    return meters * 72;
}

Conversion conversions[] = {
    {"meters to feet", convert_meters_to_feet},
    {"meters to yards", convert_meters_to_yards},
    {"meters to miles", convert_meters_to_miles},
    {"meters to kilometers", convert_meters_to_kilometers},
    {"meters to centimeters", convert_meters_to_centimeters},
    {"meters to millimeters", convert_meters_to_millimeters},
    {"meters to inches", convert_meters_to_inches},
    {"meters to pixels", convert_meters_to_pixels},
    {"meters to points", convert_meters_to_points},
};

void print_conversions() {
    printf("Available conversions:\n");
    for (int i = 0; i < NUM_CONVERSIONS; i++) {
        printf("%s\n", conversions[i].name);
    }
}

int main() {
    print_conversions();

    double input_value;
    int conversion_index;

    printf("Enter a value to convert: ");
    scanf("%lf", &input_value);

    printf("Enter the index of the conversion to use: ");
    scanf("%d", &conversion_index);

    if (conversion_index >= 0 && conversion_index < NUM_CONVERSIONS) {
        double result = conversions[conversion_index].convert(input_value);
        printf("%.2f meters is %.2f %s\n", input_value, result, conversions[conversion_index].name);
    } else {
        printf("Invalid conversion index\n");
    }

    return 0;
}