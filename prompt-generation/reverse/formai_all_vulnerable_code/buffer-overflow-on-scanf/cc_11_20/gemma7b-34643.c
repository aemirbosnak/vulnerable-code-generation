//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Cryptic
#include <stdio.h>
#include <math.h>

int main() {
    double d_num;
    double d_res;
    char c_unit;
    char c_conv_unit;

    printf("Enter the number: ");
    scanf("%lf", &d_num);

    printf("Enter the current unit: ");
    scanf(" %c", &c_unit);

    printf("Enter the conversion unit: ");
    scanf(" %c", &c_conv_unit);

    switch (c_unit) {
        case 'm':
            switch (c_conv_unit) {
                case 'km':
                    d_res = d_num * 1000;
                    break;
                case 'hg':
                    d_res = d_num * 1000000;
                    break;
                case 't':
                    d_res = d_num * 1000000000;
                    break;
            }
            break;
        case 'kg':
            switch (c_conv_unit) {
                case 'g':
                    d_res = d_num * 1000;
                    break;
                case 't':
                    d_res = d_num * 1000000;
                    break;
            }
            break;
        case 'l':
            switch (c_conv_unit) {
                case 'ml':
                    d_res = d_num * 1000;
                    break;
                case 'gal':
                    d_res = d_num * 3.785;
                    break;
            }
            break;
        default:
            printf("Invalid unit or conversion unit.\n");
    }

    if (d_res != 0) {
        printf("The result is: %.2lf %s.\n", d_res, c_conv_unit);
    }

    return 0;
}