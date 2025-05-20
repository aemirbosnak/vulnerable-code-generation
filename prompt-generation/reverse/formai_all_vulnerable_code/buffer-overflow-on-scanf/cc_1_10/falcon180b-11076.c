//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    char *name;
    double factor;
} unit_t;

int main() {
    unit_t units[] = {{"m", 1.0}, {"km", 1000.0}, {"cm", 0.01}, {"mm", 0.001}, {"in", 0.0254}, {"ft", 0.3048}, {"yd", 0.9144}, {"mi", 160934.4}, {"l", 1.0}, {"ml", 0.001}, {"fl.oz", 0.0295735}, {"gal", 3.78541}};
    int num_units = sizeof(units) / sizeof(units[0]);
    char input[100];
    double value, result = 0.0;
    int from_unit, to_unit;
    
    printf("Enter a value to convert: ");
    scanf("%lf", &value);
    
    printf("Enter the unit of the value: ");
    scanf("%s", input);
    
    from_unit = -1;
    for (int i = 0; i < num_units; i++) {
        if (strcmp(input, units[i].name) == 0) {
            from_unit = i;
            break;
        }
    }
    
    if (from_unit == -1) {
        printf("Invalid unit.\n");
        return 1;
    }
    
    printf("Enter the unit to convert to: ");
    scanf("%s", input);
    
    to_unit = -1;
    for (int i = 0; i < num_units; i++) {
        if (strcmp(input, units[i].name) == 0) {
            to_unit = i;
            break;
        }
    }
    
    if (to_unit == -1) {
        printf("Invalid unit.\n");
        return 1;
    }
    
    for (int i = 0; i < num_units; i++) {
        if (i == from_unit || i == to_unit)
            continue;
        
        result += value * units[i].factor;
    }
    
    printf("Result: %.2lf %s = %.2lf %s\n", value, units[from_unit].name, result, units[to_unit].name);
    
    return 0;
}