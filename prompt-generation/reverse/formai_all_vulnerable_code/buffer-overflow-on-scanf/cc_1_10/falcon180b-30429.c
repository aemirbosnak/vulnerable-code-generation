//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <locale.h>

#define MAX_CONVERSIONS 1000
#define MAX_CONVERSION_LENGTH 100

typedef struct {
    char* input;
    char* output;
    double value;
} Conversion;

Conversion conversions[MAX_CONVERSIONS];
int numConversions = 0;

void addConversion(char* input, char* output, double value) {
    conversions[numConversions].input = input;
    conversions[numConversions].output = output;
    conversions[numConversions].value = value;
    numConversions++;
}

int main() {
    setlocale(LC_ALL, "");
    addConversion("m", "meters", 1.0);
    addConversion("ft", "feet", 0.3048);
    addConversion("in", "inches", 0.0254);
    addConversion("yd", "yards", 0.9144);
    addConversion("mi", "miles", 160934.4);
    addConversion("km", "kilometers", 1000.0);
    addConversion("kg", "kilograms", 1.0);
    addConversion("lb", "pounds", 0.453592);
    addConversion("oz", "ounces", 0.0283495);
    addConversion("l", "liters", 1.0);
    addConversion("gal", "gallons", 3.78541);
    addConversion("c", "celsius", 1.0);
    addConversion("f", "fahrenheit", 1.8);
    addConversion("k", "kelvin", 1.0);

    char input[MAX_CONVERSION_LENGTH];
    char output[MAX_CONVERSION_LENGTH];
    double value;

    printf("Enter input value: ");
    scanf("%s", input);

    int i = 0;
    while (i < numConversions) {
        if (strcasecmp(input, conversions[i].input) == 0) {
            printf("Enter output unit: ");
            scanf("%s", output);

            if (strcasecmp(output, conversions[i].output) == 0) {
                value = conversions[i].value * atof(input);
                printf("%s %s = %.2f %s\n", input, output, value, output);
            } else {
                printf("Invalid output unit.\n");
            }

            break;
        } else {
            i++;
        }
    }

    if (i == numConversions) {
        printf("Invalid input unit.\n");
    }

    return 0;
}