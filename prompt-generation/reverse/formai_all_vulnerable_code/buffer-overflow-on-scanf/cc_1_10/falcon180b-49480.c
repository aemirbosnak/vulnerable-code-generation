//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERTER 5

typedef struct {
    char from[10];
    char to[10];
    double factor;
} converter;

converter converters[MAX_CONVERTER] = {
    {"m", "km", 0.001},
    {"km", "m", 1000},
    {"kg", "lb", 2.20462},
    {"lb", "kg", 0.453592},
    {"l", "gal", 3.78541}
};

int main() {
    char input[20];
    char from[10];
    char to[10];
    double num, result;
    int i;

    printf("Welcome to the Ada Lovelace Unit Converter!\n");
    printf("Please enter the unit you want to convert from: ");
    scanf("%s", input);

    for (i = 0; i < MAX_CONVERTER; i++) {
        if (strcmp(input, converters[i].from) == 0) {
            break;
        }
    }

    if (i == MAX_CONVERTER) {
        printf("Sorry, %s is not a valid unit.\n", input);
        return 0;
    }

    printf("Please enter the number you want to convert: ");
    scanf("%lf", &num);

    printf("Please enter the unit you want to convert to: ");
    scanf("%s", to);

    for (i = 0; i < MAX_CONVERTER; i++) {
        if (strcmp(to, converters[i].to) == 0) {
            break;
        }
    }

    if (i == MAX_CONVERTER) {
        printf("Sorry, %s is not a valid unit.\n", to);
        return 0;
    }

    result = num * converters[i].factor;

    printf("%lf %s = %lf %s\n", num, from, result, to);

    return 0;
}