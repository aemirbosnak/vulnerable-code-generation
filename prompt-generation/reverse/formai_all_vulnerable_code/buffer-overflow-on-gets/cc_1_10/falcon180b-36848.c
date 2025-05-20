//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 100

typedef struct {
    char unit[MAX_LENGTH];
    double multiplier;
} Unit;

Unit units[] = {{"meters", 1}, {"kilometers", 1000}, {"centimeters", 0.01}, {"millimeters", 0.001}, {"inches", 0.0254}, {"feet", 0.3048}, {"yards", 0.9144}, {"miles", 160934.4}};
int numOfUnits = sizeof(units)/sizeof(units[0]);

void displayMenu() {
    printf("\n");
    printf("Unit Converter\n");
    printf("-----------------\n");
    printf("1. Meters to other units\n");
    printf("2. Other units to meters\n");
    printf("3. Quit\n");
    printf("\n");
}

int main() {
    char choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch(choice) {
            case '1':
                printf("Enter the value to convert: ");
                double value = atof(gets());
                printf("Enter the unit to convert from (e.g. meters): ");
                char fromUnit[MAX_LENGTH];
                scanf("%s", fromUnit);
                int index = -1;
                for(int i=0; i<numOfUnits; i++) {
                    if(strcmp(fromUnit, units[i].unit) == 0) {
                        index = i;
                        break;
                    }
                }
                if(index == -1) {
                    printf("Invalid unit.\n");
                } else {
                    for(int i=0; i<numOfUnits; i++) {
                        printf("%s = %.2f\n", units[i].unit, value*units[i].multiplier/units[i].multiplier);
                    }
                }
                break;
            case '2':
                printf("Enter the value to convert: ");
                double value2 = atof(gets());
                printf("Enter the unit to convert to (e.g. meters): ");
                char toUnit[MAX_LENGTH];
                scanf("%s", toUnit);
                int index2 = -1;
                for(int i=0; i<numOfUnits; i++) {
                    if(strcmp(toUnit, units[i].unit) == 0) {
                        index2 = i;
                        break;
                    }
                }
                if(index2 == -1) {
                    printf("Invalid unit.\n");
                } else {
                    printf("%s = %.2f\n", toUnit, value2*units[index2].multiplier);
                }
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '3');
    return 0;
}