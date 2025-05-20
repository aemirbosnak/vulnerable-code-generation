//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char* name;
    double factor;
} unit;

int main() {
    unit length_units[] = {{"meters", 1.0}, {"centimeters", 0.01}, {"millimeters", 0.001}};
    unit weight_units[] = {{"kilograms", 1.0}, {"grams", 0.001}, {"ounces", 0.0283495}};
    unit volume_units[] = {{"liters", 1.0}, {"milliliters", 0.001}, {"cups", 0.236588}};

    int choice, i;
    double value, result;
    char unit_type;

    printf("Welcome to the Unit Converter!\n\n");

    while(1) {
        printf("\nPlease select a unit type:\n");
        printf("1. Length\n2. Weight\n3. Volume\n4. Exit\n");
        scanf("%d", &choice);

        if(choice == 4) {
            printf("Exiting...\n");
            break;
        }

        switch(choice) {
            case 1:
                unit_type = 'L';
                break;
            case 2:
                unit_type = 'W';
                break;
            case 3:
                unit_type = 'V';
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }

        printf("\nPlease enter a value:\n");
        scanf("%lf", &value);

        printf("\nPlease select a unit:\n");
        for(i=0; i<sizeof(length_units)/sizeof(unit); i++) {
            printf("%d. %s\n", i+1, length_units[i].name);
        }
        printf("\n");

        scanf("%d", &choice);
        printf("\n");

        result = value * length_units[choice-1].factor;

        if(unit_type == 'L') {
            printf("%.2lf %s is equal to:\n", value, length_units[choice-1].name);
        }
        else {
            printf("%.2lf %s is equal to:\n", result, length_units[choice-1].name);
        }

        printf("\n");
    }

    return 0;
}