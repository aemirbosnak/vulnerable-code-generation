//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_TEMP 500

typedef struct TempConv {
    double fahrenheit;
    double celsius;
    double rankine;
} TempConv;

TempConv convertTemp(double temp, int from, int to) {
    TempConv conv;

    switch (from) {
        case 0:
            conv.celsius = (temp - 32) * 5 / 9;
            break;
        case 1:
            conv.fahrenheit = (temp * 9 / 5) + 32;
            break;
        case 2:
            conv.rankine = temp + 491.67;
            break;
    }

    switch (to) {
        case 0:
            conv.fahrenheit = (conv.celsius * 9 / 5) + 32;
            break;
        case 1:
            conv.celsius = (conv.fahrenheit - 32) * 5 / 9;
            break;
        case 2:
            conv.rankine = conv.celsius + 273.15;
            break;
    }

    return conv;
}

int main() {
    double temp;
    int from, to;

    printf("Enter the temperature: ");
    scanf("%lf", &temp);

    printf("Enter the conversion from (0: Celsius, 1: Fahrenheit, 2: Rankine): ");
    scanf("%d", &from);

    printf("Enter the conversion to (0: Celsius, 1: Fahrenheit, 2: Rankine): ");
    scanf("%d", &to);

    TempConv conv = convertTemp(temp, from, to);

    printf("The converted temperature is: %.2lf %s", conv.celsius, "Celsius");
    printf("\nThe converted temperature is: %.2lf %s", conv.fahrenheit, "Fahrenheit");
    printf("\nThe converted temperature is: %.2lf %s", conv.rankine, "Rankine");

    return 0;
}