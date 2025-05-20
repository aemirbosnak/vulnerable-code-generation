//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
 char unit[20];
 float factor;
} converter;

converter converters[] = {
 {"miles", 0.0001892845},
 {"kilometers", 1.609344},
 {"pounds", 0.453592},
 {"kilograms", 2.20462},
 {"ounces", 0.035274},
 {"grams", 35.274},
 {"liters", 0.264172},
 {"gallons", 3.78541},
 {"square feet", 0.092903},
 {"square meters", 10.7639},
 {"cubic feet", 0.0283168},
 {"cubic meters", 35.3147}
};

int main() {
 char fromUnit[20], toUnit[20];
 float value, result;
 int i;

 printf("\nUnit Converter\n");
 printf("------------------------\n");
 printf("Enter the value and unit to convert from: ");
 scanf("%s%f", fromUnit, &value);

 printf("Enter the unit to convert to: ");
 scanf("%s", toUnit);

 for (i = 0; i < 13; i++) {
 if (strcmp(converters[i].unit, fromUnit) == 0) {
 value *= converters[i].factor;
 break;
 }
 }

 for (i = 0; i < 13; i++) {
 if (strcmp(converters[i].unit, toUnit) == 0) {
 result = value / converters[i].factor;
 break;
 }
 }

 printf("\n%0.2f %s is equal to %0.2f %s\n", value, fromUnit, result, toUnit);

 return 0;
}