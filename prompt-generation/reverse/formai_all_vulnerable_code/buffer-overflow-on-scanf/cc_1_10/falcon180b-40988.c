//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define RADIUS 6371.0

int main(int argc, char *argv[]) {
    double lat1, lon1, lat2, lon2, distance;
    int choice;

    printf("Welcome to the Turing Temperature Converter!\n");
    printf("Please enter your choice:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &distance);
            distance = (distance * 9.0/5.0) + 32.0;
            printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit.\n", distance, distance);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &distance);
            distance = (distance - 32.0) * 5.0/9.0;
            printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius.\n", distance, distance);
            break;
        case 3:
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &distance);
            distance = distance - 273.15;
            printf("%.2lf Kelvin is %.2lf degrees Celsius.\n", distance, distance);
            break;
        case 4:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &distance);
            distance = distance + 273.15;
            printf("%.2lf degrees Celsius is %.2lf Kelvin.\n", distance, distance);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}