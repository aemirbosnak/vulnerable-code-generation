//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

typedef enum {
    CM_TO_INCH,
    INCH_TO_CM,
    KG_TO_POUND,
    POUND_TO_KG,
    CELSIUS_TO_FAHRENHEIT,
    FAHRENHEIT_TO_CELSIUS
} ConversionType;

typedef struct {
    ConversionType type;
    double value;
    char *unitFrom;
    char *unitTo;
} Conversion;

Conversion conversions[] = {
    {CM_TO_INCH, 2.54, "cm", "in"},
    {INCH_TO_CM, 2.54, "in", "cm"},
    {KG_TO_POUND, 2.205, "kg", "lb"},
    {POUND_TO_KG, 0.4536, "lb", "kg"},
    {CELSIUS_TO_FAHRENHEIT, 1.8, "°C", "°F"},
    {FAHRENHEIT_TO_CELSIUS, 0.5556, "°F", "°C"}
};

bool is_valid_conversion(ConversionType type) {
    return type >= 0 && type < ARRAY_SIZE(conversions);
}

double convert(ConversionType type, double value) {
    if (!is_valid_conversion(type)) {
        return -1.0;
    }
    return value * conversions[type].value;
}

void print_conversion_table() {
    printf("Conversion Table:\n");
    for (int i = 0; i < ARRAY_SIZE(conversions); i++) {
        printf("%s to %s: %.2f\n", conversions[i].unitFrom, conversions[i].unitTo, conversions[i].value);
    }
}

void print_usage() {
    printf("Usage: unit_converter [conversion type] [value] [unit from] [unit to]\n");
    printf("Conversion types:\n");
    for (int i = 0; i < ARRAY_SIZE(conversions); i++) {
        printf("%d: %s to %s\n", conversions[i].type, conversions[i].unitFrom, conversions[i].unitTo);
    }
    printf("Units:\n");
    printf("cm: centimeters\n");
    printf("in: inches\n");
    printf("kg: kilograms\n");
    printf("lb: pounds\n");
    printf("°C: degrees Celsius\n");
    printf("°F: degrees Fahrenheit\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        print_usage();
        return EXIT_FAILURE;
    }

    ConversionType type;
    int type_index = atoi(argv[1]);
    if (!is_valid_conversion(type_index)) {
        printf("Invalid conversion type: %s\n", argv[1]);
        print_usage();
        return EXIT_FAILURE;
    }
    type = conversions[type_index].type;

    double value = atof(argv[2]);
    char *unitFrom = argv[3];
    char *unitTo = argv[4];

    double result = convert(type, value);
    if (result < 0.0) {
        printf("Invalid conversion: %s to %s\n", unitFrom, unitTo);
        return EXIT_FAILURE;
    }

    printf("%.2f %s is equal to %.2f %s\n", value, unitFrom, result, unitTo);

    return EXIT_SUCCESS;
}