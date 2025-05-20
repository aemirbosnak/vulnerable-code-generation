//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERTERS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double factor;
    int from_unit;
    int to_unit;
} converter;

int num_converters = 0;
converter converters[MAX_CONVERTERS];

int add_converter(char* name, double factor, int from_unit, int to_unit) {
    if (num_converters >= MAX_CONVERTERS) {
        printf("Error: Too many converters.\n");
        return -1;
    }

    strcpy(converters[num_converters].name, name);
    converters[num_converters].factor = factor;
    converters[num_converters].from_unit = from_unit;
    converters[num_converters].to_unit = to_unit;

    num_converters++;

    return 0;
}

int main() {
    add_converter("Length", 1.0, 0, 1);
    add_converter("Weight", 1.0, 2, 3);
    add_converter("Volume", 1.0, 4, 5);

    int choice;
    do {
        printf("\n");
        printf("1. Length\n");
        printf("2. Weight\n");
        printf("3. Volume\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            printf("Enter the value to convert: ");
            double value;
            scanf("%lf", &value);

            int from_unit, to_unit;
            if (choice == 1) {
                from_unit = 0;
                to_unit = 1;
            } else if (choice == 2) {
                from_unit = 2;
                to_unit = 3;
            } else {
                from_unit = 4;
                to_unit = 5;
            }

            for (int i = 0; i < num_converters; i++) {
                if (converters[i].from_unit == from_unit && converters[i].to_unit == to_unit) {
                    printf("%.2lf %s = %.2lf %s\n", value, converters[i].name, value * converters[i].factor, converters[i].name);
                    break;
                }
            }
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}