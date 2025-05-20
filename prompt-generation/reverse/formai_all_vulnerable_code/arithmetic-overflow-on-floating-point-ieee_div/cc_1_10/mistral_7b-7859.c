//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char unit[3];
    float conversion_factor;
} UnitConversion;

UnitConversion units[] = {
    {"mile", 1.609344},
    {"pound", 0.453592},
    {"gallon", 3.78541},
    {"fahrenheit", 0.55556},
    {"inch", 2.54}
};

void print_menu() {
    int i;

    printf("*************************************************\n");
    printf("*                 UNIT CONVERTER                 *\n");
    printf("*                    VER 1.0                    *\n");
    printf("*************************************************\n");
    printf("\n");
    printf("Supported Units:\n");
    printf("1. mile -> kilometers (miles to km)\n");
    printf("2. pound -> kilograms (pounds to kg)\n");
    printf("3. gallon -> liters (gallons to ltr)\n");
    printf("4. fahrenheit -> celsius (fahrenheit to cel)\n");
    printf("5. inch -> centimeters (inches to cm)\n");
    printf("\n");
    printf("Enter the number of the unit conversion you want to perform: ");

    for (i = 0; i < sizeof(units) / sizeof(UnitConversion); i++) {
        printf("%d. %s\n", i + 1, units[i].unit);
    }
}

int main() {
    int choice;
    float value, result;
    char src_unit[3], dest_unit[3];

    while (1) {
        print_menu();
        scanf("%d%s%s%f", &choice, src_unit, dest_unit, &value);

        if (choice < 1 || choice > 6) {
            printf("Invalid choice! Please choose a valid option.\n");
            continue;
        }

        if (strcmp(src_unit, units[choice - 1].unit) == 0) {
            printf("Invalid source unit! Please choose a different source unit.\n");
            continue;
        }

        result = value * units[choice - 1].conversion_factor;

        if (strcmp(dest_unit, units[choice - 1].unit) == 0) {
            printf("%.2f %s is equal to %.2f %s\n", value, src_unit, result, dest_unit);
        } else {
            for (int i = 0; i < sizeof(units) / sizeof(UnitConversion); i++) {
                if (strcmp(dest_unit, units[i].unit) == 0) {
                    printf("%.2f %s is equal to %.2f %s\n", value, src_unit, result / units[i].conversion_factor, dest_unit);
                    break;
                }
            }
        }
    }

    return 0;
}