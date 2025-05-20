//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159
#define EULER_NUMBER 2.71828

// Define a struct for each unit type
typedef struct {
    int value; // value of the unit in the base unit (e.g. meters)
    char name[20]; // name of the unit (e.g. "meters")
} Unit;

// Define an array to store all available units
Unit units[10] = {
    {1, "meters"},
    {100, "centimeters"},
    {1000, "millimeters"},
    {1000000, "kilometers"},
    {1000000000, "miles"},
    {6371, " kilometers (Earth radius)"},
    {400000000, "kilometers (Mars radius)"},
    {1495978707, "kilometers (distance from Earth to Moon)"},
    {139200000, "kilometers (distance from Earth to Sun)"}
};

// Function to convert between units
void convert(Unit from, Unit to) {
    int factor = 1;
    switch (from.value) {
        case 1: // meters
            factor = 1;
            break;
        case 100: // centimeters
            factor = 10;
            break;
        case 1000: // millimeters
            factor = 100;
            break;
        case 1000000: // kilometers
            factor = 1000000;
            break;
        case 6371: // kilometers (Earth radius)
            factor = 6371;
            break;
        case 400000000: // kilometers (Mars radius)
            factor = 400000000;
            break;
        case 1495978707: // kilometers (distance from Earth to Moon)
            factor = 1495978707;
            break;
        case 139200000: // kilometers (distance from Earth to Sun)
            factor = 139200000;
            break;
        default:
            printf("Invalid unit value\n");
            return;
    }
    to.value = from.value * factor;
}

int main() {
    int choice;
    Unit from, to;

    do {
        printf("Enter the value of the unit you want to convert (1-10): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 10) {
            printf("Invalid choice\n");
            continue;
        }

        printf("Enter the value of the unit you want to convert from (meters, centimeters, millimeters, kilometers, miles, Earth radius, Mars radius, distance from Earth to Moon, or distance from Earth to Sun): ");
        scanf("%d", &from.value);

        printf("Enter the value of the unit you want to convert to (meters, centimeters, millimeters, kilometers, miles, Earth radius, Mars radius, distance from Earth to Moon, or distance from Earth to Sun): ");
        scanf("%d", &to.value);

        convert(from, to);
        printf("Value in unit %s is %d\n", to.name, to.value);
    } while (1);

    return 0;
}