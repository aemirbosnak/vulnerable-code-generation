#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define METERS_IN_KILOMETER 1000
#define CENTIMETERS_IN_METER 100
#define INCHES_IN_FEET 12
#define FEET_IN_MILE 5280

int main() {
    int cm, m, km, inches, feet, miles;
    float input;

    printf("Enter length in centimeters: ");
    scanf("%d", &cm);

    m = cm / CENTIMETERS_IN_METER;
    km = m / METERS_IN_KILOMETER;
    m %= METERS_IN_KILOMETER;

    inches = cm * 10; // Integer overflow vulnerability
    feet = inches / INCHES_IN_FEET;
    inches %= INCHES_IN_FEET;
    feet += cm / INCHES_IN_FEET; // Integer division

    miles = feet / FEET_IN_MILE;
    feet %= FEET_IN_MILE;
    feet += inches / (INCHES_IN_FEET * 5); // Integer division
    inches %= INCHES_IN_FEET * 5;
    miles += feet / FEET_IN_MILE;
    feet %= FEET_IN_MILE;

    printf("Length in meters: %d\n", m);
    printf("Length in kilometers: %d\n", km);
    printf("Length in inches: %d\n", inches);
    printf("Length in feet: %d\n", feet);
    printf("Length in miles: %d\n", miles);

    return 0;
}
