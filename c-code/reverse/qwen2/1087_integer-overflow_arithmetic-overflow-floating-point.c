#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <limits.h>

#define CM_TO_M 0.01
#define M_TO_KM 0.001
#define IN_TO_CM 2.54
#define FT_TO_IN 12
#define MI_TO_FT 5280

double convert(double value, double from_factor, double to_factor) {
    return value * (from_factor / to_factor);
}

int main() {
    int choice;
    double value;

    printf("Unit Converter\n");
    printf("1. cm to m\n");
    printf("2. m to km\n");
    printf("3. in to cm\n");
    printf("4. ft to in\n");
    printf("5. mi to ft\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value: ");
    scanf("%lf", &value);

    switch(choice) {
        case 1:
            printf("%.2f cm = %.2f m\n", value, convert(value, CM_TO_M, 1));
            break;
        case 2:
            printf("%.2f m = %.2f km\n", value, convert(value, M_TO_KM, 1));
            break;
        case 3:
            printf("%.2f in = %.2f cm\n", value, convert(value, IN_TO_CM, 1));
            break;
        case 4:
            printf("%.2f ft = %.2f in\n", value, convert(value, FT_TO_IN, 1));
            break;
        case 5:
            printf("%.2f mi = %.2f ft\n", value, convert(value, MI_TO_FT, 1));
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    return 0;
}
