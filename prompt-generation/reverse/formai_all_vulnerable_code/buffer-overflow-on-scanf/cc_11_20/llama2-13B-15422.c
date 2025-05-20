//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_VALUE 100

struct unit {
    char name[20];
    int factor;
};

int main() {
    struct unit units[MAX_UNITS] = {
        {"inch", 1},
        {"foot", 12},
        {"yard", 36},
        {"mile", 5280},
        {"inch", 1},
        {"pound", 16},
        {"ounce", 16 / 128},
        {"gram", 1000},
        {"kilogram", 1000000},
        {"meter", 39.37},
        {"centimeter", 39.37 / 100},
        {"millimeter", 39.37 / 1000}
    };

    int choice;
    double value;

    do {
        printf("Welcome to the Unit Converter! \n");
        printf("Choose a unit to convert: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value in inches: ");
                scanf("%lf", &value);
                printf("That's %f feet\n", value * units[0].factor);
                break;
            case 2:
                printf("Enter the value in feet: ");
                scanf("%lf", &value);
                printf("That's %f inches\n", value * units[1].factor);
                break;
            case 3:
                printf("Enter the value in yards: ");
                scanf("%lf", &value);
                printf("That's %f miles\n", value * units[2].factor);
                break;
            case 4:
                printf("Enter the value in miles: ");
                scanf("%lf", &value);
                printf("That's %f yards\n", value * units[3].factor);
                break;
            case 5:
                printf("Enter the value in pounds: ");
                scanf("%lf", &value);
                printf("That's %f ounces\n", value * units[4].factor);
                break;
            case 6:
                printf("Enter the value in ounces: ");
                scanf("%lf", &value);
                printf("That's %f pounds\n", value * units[5].factor);
                break;
            case 7:
                printf("Enter the value in grams: ");
                scanf("%lf", &value);
                printf("That's %f kilograms\n", value * units[6].factor);
                break;
            case 8:
                printf("Enter the value in kilograms: ");
                scanf("%lf", &value);
                printf("That's %f grams\n", value * units[7].factor);
                break;
            case 9:
                printf("Enter the value in meters: ");
                scanf("%lf", &value);
                printf("That's %f centimeters\n", value * units[8].factor);
                break;
            case 10:
                printf("Enter the value in centimeters: ");
                scanf("%lf", &value);
                printf("That's %f meters\n", value * units[9].factor);
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}