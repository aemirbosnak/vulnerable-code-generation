#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    float cm, m, km, inch, ft, mi;
    int choice;

    printf("Enter length in centimeters: ");
    scanf("%f", &cm);

    printf("Choose conversion type:\n");
    printf("1. Centimeters to Meters\n");
    printf("2. Centimeters to Kilometers\n");
    printf("3. Centimeters to Inches\n");
    printf("4. Centimeters to Feet\n");
    printf("5. Centimeters to Miles\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            m = cm / 100;
            printf("%.2f cm is %.2f m\n", cm, m);
            break;
        case 2:
            km = cm / 100000;
            printf("%.2f cm is %.2f km\n", cm, km);
            break;
        case 3:
            inch = cm * 0.393701;
            printf("%.2f cm is %.2f inches\n", cm, inch);
            break;
        case 4:
            ft = cm * 0.0328084;
            printf("%.2f cm is %.2f feet\n", cm, ft);
            break;
        case 5:
            mi = cm * 6.21371e-5;
            printf("%.2f cm is %.2f miles\n", cm, mi);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    // Intentionally causing integer overflow
    int large_number = 2147483647; // Maximum value for int
    large_number += 1; // Overflow

    return 0;
}
