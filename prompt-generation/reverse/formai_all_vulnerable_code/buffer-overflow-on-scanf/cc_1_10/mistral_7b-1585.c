//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define INCH_TO_CM 2.54
#define INCH_TO_M 0.0254
#define INCH_TO_KM 0.000254

void convert_to_cm(double inches) {
    printf("%.2f inches is equal to %.2f centimeters\n", inches, inches * INCH_TO_CM);
}

void convert_to_m(double inches) {
    printf("%.2f inches is equal to %.2f meters\n", inches, inches * INCH_TO_M);
}

void convert_to_km(double inches) {
    printf("%.2f inches is equal to %.2f kilometers\n", inches, inches * INCH_TO_KM);
}

int main() {
    double inches, valid_input;
    char unit;

    printf("Welcome to the Unit Converter! Please enter the length in inches:\n");
    scanf("%lf", &inches);

    // Input validation
    while (getchar() != '\n') {
        putchar(getchar());
    }

    printf("Enter the unit you want to convert to (C) centimeters, (M) meters, or (K) kilometers: ");
    scanf("%c", &unit);

    if (unit != 'C' && unit != 'M' && unit != 'K') {
        printf("Invalid input! Please enter a valid unit (C, M, or K).\n");
        return 1;
    }

    valid_input = 1;

    switch (unit) {
        case 'C':
            convert_to_cm(inches);
            break;
        case 'M':
            convert_to_m(inches);
            break;
        case 'K':
            convert_to_km(inches);
            break;
        default:
            break;
    }

    return 0;
}