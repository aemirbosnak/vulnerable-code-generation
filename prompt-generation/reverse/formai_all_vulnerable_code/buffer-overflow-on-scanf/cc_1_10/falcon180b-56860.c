//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159

int main() {
    float radius, area, circumference;
    char unit;

    printf("Enter the radius of a circle: ");
    scanf("%f", &radius);

    // Convert radius to area
    area = PI * radius * radius;

    // Convert radius to circumference
    circumference = 2 * PI * radius;

    // Ask user for unit of measurement
    printf("Enter unit of measurement (m/s/kg/K): ");
    scanf(" %c", &unit);

    // Convert area to given unit
    switch(unit) {
        case'm':
            printf("The area of the circle is %.2f square meters.\n", area);
            break;
        case's':
            printf("The area of the circle is %.2f square seconds.\n", area);
            break;
        case 'kg':
            printf("The area of the circle is %.2f square kilograms.\n", area);
            break;
        case 'K':
            printf("The area of the circle is %.2f square Kelvins.\n", area);
            break;
        default:
            printf("Invalid unit of measurement.\n");
            return 0;
    }

    // Convert circumference to given unit
    switch(unit) {
        case'm':
            printf("The circumference of the circle is %.2f meters.\n", circumference);
            break;
        case's':
            printf("The circumference of the circle is %.2f seconds.\n", circumference);
            break;
        case 'kg':
            printf("The circumference of the circle is %.2f kilograms.\n", circumference);
            break;
        case 'K':
            printf("The circumference of the circle is %.2f Kelvins.\n", circumference);
            break;
        default:
            printf("Invalid unit of measurement.\n");
            return 0;
    }

    return 0;
}