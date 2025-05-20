//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: genius
#include <stdio.h>
#include <math.h>

#define PI 3.1415926535

int main() {
    double value;
    int unit_from, unit_to;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the unit you want to convert from (1 - km, 2 - m, 3 - cm): ");
    scanf("%d", &unit_from);

    printf("Enter the unit you want to convert to (4 - km, 5 - m, 6 - cm): ");
    scanf("%d", &unit_to);

    switch (unit_from) {
        case 1:
            switch (unit_to) {
                case 4:
                    printf("%lf km = %lf m", value, value * 1000);
                    break;
                case 5:
                    printf("%lf km = %lf m", value, value * 1000);
                    break;
                case 6:
                    printf("%lf km = %lf cm", value, value * 1000000);
                    break;
            }
            break;
        case 2:
            switch (unit_to) {
                case 4:
                    printf("%lf m = %lf km", value, value / 1000);
                    break;
                case 5:
                    printf("%lf m = %lf m", value, value * 1000);
                    break;
                case 6:
                    printf("%lf m = %lf cm", value, value * 1000);
                    break;
            }
            break;
        case 3:
            switch (unit_to) {
                case 4:
                    printf("%lf cm = %lf km", value, value / 1000000);
                    break;
                case 5:
                    printf("%lf cm = %lf m", value, value / 1000);
                    break;
                case 6:
                    printf("%lf cm = %lf cm", value, value * 1000);
                    break;
            }
            break;
    }

    return 0;
}