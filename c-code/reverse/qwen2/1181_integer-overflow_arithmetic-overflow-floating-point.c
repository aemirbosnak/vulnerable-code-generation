#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    float value;
    char from_unit[20], to_unit[20];
    
    printf("Enter the value: ");
    scanf("%f", &value);
    
    printf("Enter the unit to convert from (m, km, cm, mm, ft, in): ");
    scanf("%s", from_unit);
    
    printf("Enter the unit to convert to (m, km, cm, mm, ft, in): ");
    scanf("%s", to_unit);
    
    if (strcmp(from_unit, "m") == 0) {
        if (strcmp(to_unit, "km") == 0)
            printf("%.2f\n", value / 1000.0);
        else if (strcmp(to_unit, "cm") == 0)
            printf("%.2f\n", value * 100.0);
        else if (strcmp(to_unit, "mm") == 0)
            printf("%.2f\n", value * 1000.0);
        else if (strcmp(to_unit, "ft") == 0)
            printf("%.2f\n", value * 3.28084);
        else if (strcmp(to_unit, "in") == 0)
            printf("%.2f\n", value * 39.3701);
    } else if (strcmp(from_unit, "km") == 0) {
        if (strcmp(to_unit, "m") == 0)
            printf("%.2f\n", value * 1000.0);
        // Add other conversions here...
    }
    // Add more conditions for other units...
    
    return 0;
}
