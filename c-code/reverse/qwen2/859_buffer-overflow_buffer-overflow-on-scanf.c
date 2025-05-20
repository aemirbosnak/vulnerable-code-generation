#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    double num;
    char src_unit[20], tgt_unit[20];
    
    printf("Enter the number: ");
    scanf("%lf", &num);
    
    printf("Enter the source unit (kg, g, lb, oz, ml, l, km, mi): ");
    scanf("%s", src_unit);
    
    printf("Enter the target unit (kg, g, lb, oz, ml, l, km, mi): ");
    scanf("%s", tgt_unit);
    
    if (strcmp(src_unit, "kg") == 0) {
        if (strcmp(tgt_unit, "g") == 0)
            printf("%.2f\n", num * 1000);
        else if (strcmp(tgt_unit, "lb") == 0)
            printf("%.2f\n", num * 2.20462);
        else if (strcmp(tgt_unit, "oz") == 0)
            printf("%.2f\n", num * 35.274);
        else if (strcmp(tgt_unit, "ml") == 0)
            printf("%.2f\n", num * 1000000);
        else if (strcmp(tgt_unit, "l") == 0)
            printf("%.2f\n", num * 1000);
        else if (strcmp(tgt_unit, "km") == 0)
            printf("%.2f\n", num / 1000);
        else if (strcmp(tgt_unit, "mi") == 0)
            printf("%.2f\n", num * 0.000621371);
    } else if (strcmp(src_unit, "g") == 0) {
        // Add other cases similarly
    }
    // Add other source units similarly
    
    return 0;
}
