//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PI 3.14159
#define INF 1e100

// Define a struct for a unit of measurement
struct unit {
    char name[20];
    double factor;
};

// Define some units
struct unit units[] = {
    {"inch", 1.0},
    {"foot", 12.0},
    {"yard", 36.0},
    {"mile", 5280.0},
    {"kilogram", 1.0},
    {"gram", 0.001},
    {"pound", 2.20462},
    {"ounce", 0.0283495},
    {"liter", 1.0},
    {"gallon", 3.785},
    {"cup", 0.2366},
    {"teaspoon", 0.0625},
    {" tablespoon", 0.125}
};

// Define a function to convert between units
void convert(struct unit from, struct unit to, double value) {
    double factor = to.factor / from.factor;
    value *= factor;
    printf("Converting %s to %s: %f\n", from.name, to.name, value);
}

int main() {
    int choice;
    double value;

    // Menu for selecting the conversion operation
    printf("Welcome to the Unit Converter!\n");
    printf("1. Convert distance\n");
    printf("2. Convert weight\n");
    printf("3. Convert volume\n");
    printf("4. Convert temperature\n");
    printf("5. Quit\n");
    scanf("%d", &choice);

    // Get the value to be converted
    switch (choice) {
        case 1:
            printf("Enter a distance in inches: ");
            scanf("%lf", &value);
            convert(units[0], units[1], value);
            break;
        case 2:
            printf("Enter a weight in kilograms: ");
            scanf("%lf", &value);
            convert(units[4], units[3], value);
            break;
        case 3:
            printf("Enter a volume in liters: ");
            scanf("%lf", &value);
            convert(units[6], units[5], value);
            break;
        case 4:
            printf("Enter a temperature in Celsius: ");
            scanf("%lf", &value);
            convert(units[8], units[7], value);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}