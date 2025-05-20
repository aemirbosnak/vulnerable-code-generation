//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char *name;
    double factor;
} unit;

unit units[] = {
    {"m", 1.0},
    {"km", 1000.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 160934.4},
    {"l", 1.0},
    {"ml", 0.001},
    {"fl oz", 0.0295735},
    {"gal", 3.78541},
    {"kg", 1.0},
    {"g", 0.001},
    {"lb", 0.453592},
    {"oz", 0.0283495},
    {"C", 1.0},
    {"F", 1.8},
    {"K", 1.0},
};

int main() {
    int i, j, k;
    char input[100], output[100], *ptr;
    double value, result;

    printf("Enter a value to convert:\n");
    scanf("%s", input);

    if (isdigit(input[0])) {
        value = atof(input);
        printf("Enter the unit you want to convert from:\n");
        scanf("%s", input);
        i = 0;
        while (units[i].name!= NULL && strcmp(units[i].name, input)!= 0) {
            i++;
        }
        if (units[i].name!= NULL) {
            printf("Enter the unit you want to convert to:\n");
            scanf("%s", output);
            j = 0;
            while (units[j].name!= NULL && strcmp(units[j].name, output)!= 0) {
                j++;
            }
            if (units[j].name!= NULL) {
                result = value * units[i].factor / units[j].factor;
                printf("%.2f %s = %.2f %s\n", value, input, result, output);
            } else {
                printf("Invalid unit.\n");
            }
        } else {
            printf("Invalid unit.\n");
        }
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}