//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {

    // Declare variables
    double length, width, area, volume, perimeter;
    char unit;

    // Prompt user to enter length, width, and unit
    printf("Enter length: ");
    scanf("%lf", &length);
    printf("Enter width: ");
    scanf("%lf", &width);
    printf("Enter unit (m, cm, mm, in, ft, yd): ");
    scanf(" %c", &unit);

    // Convert length and width to meters
    if (unit =='m') {
        length = length;
        width = width;
    } else if (unit == 'cm') {
        length = length / 100;
        width = width / 100;
    } else if (unit =='mm') {
        length = length / 1000;
        width = width / 1000;
    } else if (unit == 'in') {
        length = length / 39.3701;
        width = width / 39.3701;
    } else if (unit == 'ft') {
        length = length / 3.28084;
        width = width / 3.28084;
    } else if (unit == 'yd') {
        length = length / 1.09361;
        width = width / 1.09361;
    } else {
        printf("Invalid unit entered.\n");
        return 0;
    }

    // Calculate area and perimeter
    area = length * width;
    perimeter = 2 * (length + width);

    // Convert area and perimeter to requested unit
    if (unit =='m') {
        area = area;
        perimeter = perimeter;
    } else if (unit == 'cm') {
        area = area * 100;
        perimeter = perimeter * 100;
    } else if (unit =='mm') {
        area = area * 1000;
        perimeter = perimeter * 1000;
    } else if (unit == 'in') {
        area = area * 1550.0031;
        perimeter = perimeter * 1550.0031;
    } else if (unit == 'ft') {
        area = area * 10.764;
        perimeter = perimeter * 10.764;
    } else if (unit == 'yd') {
        area = area * 1.19599;
        perimeter = perimeter * 1.19599;
    } else {
        printf("Invalid unit entered.\n");
        return 0;
    }

    // Print results
    printf("Area: %.2lf %c^2\n", area, unit);
    printf("Perimeter: %.2lf %c\n", perimeter, unit);

    return 0;
}