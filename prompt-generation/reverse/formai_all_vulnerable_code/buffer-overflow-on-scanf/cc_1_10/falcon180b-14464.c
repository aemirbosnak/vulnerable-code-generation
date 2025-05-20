//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: systematic
#include<stdio.h>
#include<string.h>
#include<math.h>
#define TRUE 1
#define FALSE 0
#define MAX_CONVERSION_TYPES 10

typedef struct {
    char fromUnit[20];
    char toUnit[20];
    double conversionFactor;
} ConversionType;

ConversionType conversionTypes[MAX_CONVERSION_TYPES];
int numConversionTypes = 0;

void addConversionType(char* fromUnit, char* toUnit, double conversionFactor) {
    strcpy(conversionTypes[numConversionTypes].fromUnit, fromUnit);
    strcpy(conversionTypes[numConversionTypes].toUnit, toUnit);
    conversionTypes[numConversionTypes].conversionFactor = conversionFactor;
    numConversionTypes++;
}

void displayConversionTypes() {
    printf("Available conversion types:\n");
    for(int i=0; i<numConversionTypes; i++) {
        printf("%s to %s\n", conversionTypes[i].fromUnit, conversionTypes[i].toUnit);
    }
}

int main() {
    char fromUnit[20], toUnit[20];
    double value, result;
    int choice;

    addConversionType("meters", "feet", 3.28084);
    addConversionType("meters", "inches", 39.3701);
    addConversionType("meters", "yards", 1.09361);
    addConversionType("meters", "miles", 0.000621371);
    addConversionType("meters", "kilometers", 1);
    addConversionType("meters", "centimeters", 100);
    addConversionType("meters", "millimeters", 1000);
    addConversionType("meters", "micrometers", 1000000);
    addConversionType("meters", "nanometers", 1000000000);
    addConversionType("meters", "picometers", 100000000000);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit of the value: ");
    scanf("%s", fromUnit);

    printf("Enter the unit to convert to: ");
    scanf("%s", toUnit);

    for(int i=0; i<numConversionTypes; i++) {
        if(strcmp(fromUnit, conversionTypes[i].fromUnit) == 0 && strcmp(toUnit, conversionTypes[i].toUnit) == 0) {
            result = value * conversionTypes[i].conversionFactor;
            printf("Result: %.2lf %s = %.2lf %s\n", value, fromUnit, result, toUnit);
            return 0;
        }
    }

    printf("Invalid conversion type.\n");
    return 0;
}