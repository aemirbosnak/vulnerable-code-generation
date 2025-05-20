//FormAI DATASET v1.0 Category: Unit converter ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    float measurement;
    char unit;
    
    printf("Enter a measurement: ");
    scanf("%f", &measurement);
    
    printf("Enter the unit of measurement (m, cm, km, mi, yd, ft, in): ");
    scanf(" %c", &unit);
    
    switch(unit) {
        case 'm':
            printf("%.2f m = %.2f cm\n", measurement, measurement * 100);
            printf("%.2f m = %.2f km\n", measurement, measurement / 1000);
            printf("%.2f m = %.2f mi\n", measurement, measurement / 1609.34);
            printf("%.2f m = %.2f yd\n", measurement, measurement * 1.09361);
            printf("%.2f m = %.2f ft\n", measurement, measurement * 3.28084);
            printf("%.2f m = %.2f in\n", measurement, measurement * 39.3701);
            break;
        case 'cm':
            printf("%.2f cm = %.2f m\n", measurement, measurement / 100);
            printf("%.2f cm = %.2f km\n", measurement, measurement / 100000);
            printf("%.2f cm = %.2f mi\n", measurement, measurement / 160934);
            printf("%.2f cm = %.2f yd\n", measurement, measurement / 91.44);
            printf("%.2f cm = %.2f ft\n", measurement, measurement / 30.48);
            printf("%.2f cm = %.2f in\n", measurement, measurement / 2.54);
            break;
        case 'km':
            printf("%.2f km = %.2f m\n", measurement, measurement * 1000);
            printf("%.2f km = %.2f cm\n", measurement, measurement * 100000);
            printf("%.2f km = %.2f mi\n", measurement, measurement / 1.60934);
            printf("%.2f km = %.2f yd\n", measurement, measurement * 1093.61);
            printf("%.2f km = %.2f ft\n", measurement, measurement * 3280.84);
            printf("%.2f km = %.2f in\n", measurement, measurement * 39370.1);
            break;
        case 'mi':
            printf("%.2f mi = %.2f m\n", measurement, measurement * 1609.34);
            printf("%.2f mi = %.2f cm\n", measurement, measurement * 160934);
            printf("%.2f mi = %.2f km\n", measurement, measurement * 1.60934);
            printf("%.2f mi = %.2f yd\n", measurement, measurement * 1760);
            printf("%.2f mi = %.2f ft\n", measurement, measurement * 5280);
            printf("%.2f mi = %.2f in\n", measurement, measurement * 63360);
            break;
        case 'yd':
            printf("%.2f yd = %.2f m\n", measurement, measurement / 1.09361);
            printf("%.2f yd = %.2f cm\n", measurement, measurement * 91.44);
            printf("%.2f yd = %.2f km\n", measurement, measurement / 1093.61);
            printf("%.2f yd = %.2f mi\n", measurement, measurement / 1760);
            printf("%.2f yd = %.2f ft\n", measurement, measurement * 3);
            printf("%.2f yd = %.2f in\n", measurement, measurement * 36);
            break;
        case 'ft':
            printf("%.2f ft = %.2f m\n", measurement, measurement / 3.28084);
            printf("%.2f ft = %.2f cm\n", measurement, measurement * 30.48);
            printf("%.2f ft = %.2f km\n", measurement, measurement / 3280.84);
            printf("%.2f ft = %.2f mi\n", measurement, measurement / 5280);
            printf("%.2f ft = %.2f yd\n", measurement, measurement / 3);
            printf("%.2f ft = %.2f in\n", measurement, measurement * 12);
            break;
        case 'in':
            printf("%.2f in = %.2f m\n", measurement, measurement / 39.3701);
            printf("%.2f in = %.2f cm\n", measurement, measurement * 2.54);
            printf("%.2f in = %.2f km\n", measurement, measurement / 39370.1);
            printf("%.2f in = %.2f mi\n", measurement, measurement / 63360);
            printf("%.2f in = %.2f yd\n", measurement, measurement / 36);
            printf("%.2f in = %.2f ft\n", measurement, measurement / 12);
            break;
        default:
            printf("Invalid unit of measurement. Please enter one of the following: m, cm, km, mi, yd, ft, in.\n");
            break;
    }
    
    return 0;
}