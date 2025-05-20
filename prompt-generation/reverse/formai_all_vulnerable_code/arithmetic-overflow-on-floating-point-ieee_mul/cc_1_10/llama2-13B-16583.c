//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define UNIT_COUNT 12

typedef struct unit {
    char name[20];
    double factor;
} unit_t;

unit_t units[UNIT_COUNT] = {
    {"foot", 0.3048},
    {"inch", 0.0254},
    {"yard", 0.9144},
    {"mile", 1.609344},
    {"kilogram", 0.001},
    {"gram", 0.001},
    {"pound", 0.453592},
    {"ounce", 0.0283495},
    {"temperature", 0.01},
    {"celsius", 1.8},
    {"farenheit", 1.8 * 9/5 + 32},
    {"second", 1},
    {"minute", 60},
    {"hour", 3600}
};

int main() {
    int choice;
    double value;
    char unit_input[20];

    printf("Welcome to Unitastic! Please choose a unit to convert:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Time\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a length value: ");
            scanf("%lf", &value);
            printf("You entered %lf feet, which is %lf inches or %lf yards\n", value * units[0].factor, value * units[1].factor, value * units[2].factor);
            break;
        case 2:
            printf("Enter a weight value: ");
            scanf("%lf", &value);
            printf("You entered %lf kilograms, which is %lf grams or %lf pounds\n", value, value * units[3].factor, value * units[4].factor);
            break;
        case 3:
            printf("Enter a temperature value: ");
            scanf("%lf", &value);
            printf("You entered %lf celsius, which is %lf farenheit\n", value, value * units[6].factor + 32);
            break;
        case 4:
            printf("Enter a time value: ");
            scanf("%lf", &value);
            printf("You entered %lf seconds, which is %lf minutes or %lf hours\n", value, value * units[8].factor / 60, value * units[9].factor / 3600);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}