//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function Prototype
double convert(double num, char from, char to);

int main() {
    char from, to;
    double num;

    printf("Enter the number to convert: ");
    scanf("%lf", &num);

    printf("Enter the unit to convert from (e.g. 'kg','m', 'l'): ");
    scanf(" %c", &from);

    printf("Enter the unit to convert to (e.g. 'lb', 'ft', 'gal'): ");
    scanf(" %c", &to);

    double result = convert(num, from, to);

    printf("%.2lf %c is equal to %.2lf %c\n", num, from, result, to);

    return 0;
}

// Function to convert units
double convert(double num, char from, char to) {
    switch(from) {
        case'm':
            switch(to) {
                case 'ft':
                    return num * 3.28084;
                case 'in':
                    return num * 39.3701;
                default:
                    printf("Invalid conversion.\n");
                    exit(1);
            }
        case 'kg':
            switch(to) {
                case 'lb':
                    return num * 2.20462;
                default:
                    printf("Invalid conversion.\n");
                    exit(1);
            }
        case 'l':
            switch(to) {
                case 'gal':
                    return num * 0.264172;
                default:
                    printf("Invalid conversion.\n");
                    exit(1);
            }
        default:
            printf("Invalid conversion.\n");
            exit(1);
    }
}