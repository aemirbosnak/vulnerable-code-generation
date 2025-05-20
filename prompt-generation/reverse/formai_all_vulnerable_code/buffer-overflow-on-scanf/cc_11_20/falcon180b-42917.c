//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_MAX 10
#define UNIT_MIN -1

typedef struct {
    char *name;
    int value;
    char *symbol;
} unit;

unit units[UNIT_MAX] = {
    {"meter", 1, "m"},
    {"kilometer", 1000, "km"},
    {"centimeter", 0.01, "cm"},
    {"millimeter", 0.001, "mm"},
    {"inch", 0.0254, "in"},
    {"foot", 0.3048, "ft"},
    {"yard", 0.9144, "yd"},
    {"mile", 160934.4, "mi"},
    {"liter", 1, "L"},
    {"gallon", 3.78541, "gal"}
};

int main() {
    int choice;
    double value, result;
    char unit_from[20], unit_to[20];
    printf("Welcome to the Unit Converter!\n");
    printf("Enter 1 to convert length units\n");
    printf("Enter 2 to convert volume units\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter the unit you want to convert from: ");
            scanf("%s", unit_from);
            printf("Enter the unit you want to convert to: ");
            scanf("%s", unit_to);
            printf("Enter the value you want to convert: ");
            scanf("%lf", &value);
            for(int i=0; i<UNIT_MAX; i++) {
                if(strcmp(units[i].name, unit_from) == 0) {
                    for(int j=0; j<UNIT_MAX; j++) {
                        if(strcmp(units[j].name, unit_to) == 0) {
                            result = value * units[i].value / units[j].value;
                            printf("%.2lf %s is equal to %.2lf %s\n", value, units[i].symbol, result, units[j].symbol);
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        case 2:
            printf("Enter the unit you want to convert from: ");
            scanf("%s", unit_from);
            printf("Enter the unit you want to convert to: ");
            scanf("%s", unit_to);
            printf("Enter the value you want to convert: ");
            scanf("%lf", &value);
            for(int i=0; i<UNIT_MAX; i++) {
                if(strcmp(units[i].name, unit_from) == 0) {
                    for(int j=0; j<UNIT_MAX; j++) {
                        if(strcmp(units[j].name, unit_to) == 0) {
                            result = value * units[i].value / units[j].value;
                            printf("%.2lf %s is equal to %.2lf %s\n", value, units[i].symbol, result, units[j].symbol);
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}