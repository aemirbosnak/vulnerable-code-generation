//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_CONVERTER_MAX_LENGTH 20

typedef struct {
    char name[UNIT_CONVERTER_MAX_LENGTH];
    double value;
} unit_converter_t;

unit_converter_t units[] = {
    {"cm", 10},
    {"m", 100},
    {"km", 100000},
    {"mm", 1},
    {"inch", 2.54},
    {"foot", 12},
    {"yard", 36},
    {"mile", 5280},
    {"kg", 1000},
    {"g", 0.001},
    {"lb", 0.45359237},
    {"oz", 0.0283495},
    {"pound", 453.59237},
    {"ton", 1000000}
};

int main() {
    int choice;
    char input[UNIT_CONVERTER_MAX_LENGTH];
    double output;

    printf("Welcome to the Unit Converter! \n");
    printf("Choose a unit to convert: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a length in cm: ");
            scanf("%s", input);
            output = (double)units[0].value * atof(input);
            printf("That's %f meters\n", output);
            break;
        case 2:
            printf("Enter a length in m: ");
            scanf("%s", input);
            output = (double)units[1].value * atof(input);
            printf("That's %f kilometers\n", output);
            break;
        case 3:
            printf("Enter a length in km: ");
            scanf("%s", input);
            output = (double)units[2].value * atof(input);
            printf("That's %f millimeters\n", output);
            break;
        case 4:
            printf("Enter a length in mm: ");
            scanf("%s", input);
            output = (double)units[3].value * atof(input);
            printf("That's %f inches\n", output);
            break;
        case 5:
            printf("Enter a length in inch: ");
            scanf("%s", input);
            output = (double)units[4].value * atof(input);
            printf("That's %f feet\n", output);
            break;
        case 6:
            printf("Enter a length in foot: ");
            scanf("%s", input);
            output = (double)units[5].value * atof(input);
            printf("That's %f yards\n", output);
            break;
        case 7:
            printf("Enter a length in yard: ");
            scanf("%s", input);
            output = (double)units[6].value * atof(input);
            printf("That's %f miles\n", output);
            break;
        case 8:
            printf("Enter a length in mile: ");
            scanf("%s", input);
            output = (double)units[7].value * atof(input);
            printf("That's %f kilograms\n", output);
            break;
        case 9:
            printf("Enter a mass in kg: ");
            scanf("%s", input);
            output = (double)units[8].value * atof(input);
            printf("That's %f grams\n", output);
            break;
        case 10:
            printf("Enter a mass in g: ");
            scanf("%s", input);
            output = (double)units[9].value * atof(input);
            printf("That's %f pounds\n", output);
            break;
        case 11:
            printf("Enter a mass in lb: ");
            scanf("%s", input);
            output = (double)units[10].value * atof(input);
            printf("That's %f ounces\n", output);
            break;
        case 12:
            printf("Enter a mass in oz: ");
            scanf("%s", input);
            output = (double)units[11].value * atof(input);
            printf("That's %f tons\n", output);
            break;
        default:
            printf("Invalid input. Please try again\n");
            break;
    }
    return 0;
}