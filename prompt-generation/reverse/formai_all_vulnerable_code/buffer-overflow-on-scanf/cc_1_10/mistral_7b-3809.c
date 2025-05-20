//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char name[20];
    float unit;
} Converter;

Converter converters[] = {
    {"Mile", 1609.34},
    {"Kilometer", 1},
    {"Gallon", 3.78541},
    {"Liter", 0.264172},
    {"Pound", 0.453592},
    {"Kilogram", 2.20462},
    {"Fahrenheit", 1.8},
    {"Celsius", 1}
};

int findConverterIndex(char *name) {
    for (int i = 0; i < 8; i++) {
        if (strcmp(converters[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void convertUnit(int index1, float value, int index2) {
    float result;
    if (index1 > 7 && index2 > 7) {
        printf("Surprisingly, you tried to convert two unusual units! Let's stick to the basics.\n");
        return;
    }
    if (index1 > 7) {
        result = value * converters[index1].unit / converters[index2].unit;
        printf("%.2f %s is equal to %.2f %s\n", value, converters[index1].name, result, converters[index2].name);
    } else {
        result = value * converters[index2].unit / converters[index1].unit;
        printf("%.2f %s is equal to %.2f %s\n", value, converters[index2].name, result, converters[index1].name);
    }
}

int main() {
    char from[20], to[20];
    float value;

    printf("Welcome to the C Unit Converter Surprise!\n");
    printf("Enter the unit you want to convert from: ");
    scanf("%s", from);
    int indexFrom = findConverterIndex(from);

    if (indexFrom == -1) {
        printf("Uh oh! That unit is not supported.\n");
        return 1;
    }

    printf("Enter the value you want to convert: ");
    scanf("%f", &value);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", to);
    int indexTo = findConverterIndex(to);

    if (indexTo == -1) {
        printf("Oops! That unit is not supported.\n");
        return 1;
    }

    convertUnit(indexFrom, value, indexTo);

    return 0;
}