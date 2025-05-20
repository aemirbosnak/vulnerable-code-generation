//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to calculate the area of a circle
double circle_area(double radius) {
    return PI * radius * radius;
}

// Function to calculate the circumference of a circle
double circle_circumference(double radius) {
    return 2 * PI * radius;
}

// Function to calculate the volume of a sphere
double sphere_volume(double radius) {
    return (4.0 / 3.0) * PI * radius * radius * radius;
}

// Function to calculate the surface area of a sphere
double sphere_surface_area(double radius) {
    return 4 * PI * radius * radius;
}

int main() {
    double radius;
    char choice;

    printf("Enter the radius of the circle or sphere: ");
    scanf("%lf", &radius);

    do {
        printf("\n");
        printf("1. Area of circle\n");
        printf("2. Circumference of circle\n");
        printf("3. Volume of sphere\n");
        printf("4. Surface area of sphere\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            printf("The area of the circle is %lf\n", circle_area(radius));
            break;
        case '2':
            printf("The circumference of the circle is %lf\n", circle_circumference(radius));
            break;
        case '3':
            printf("The volume of the sphere is %lf\n", sphere_volume(radius));
            break;
        case '4':
            printf("The surface area of the sphere is %lf\n", sphere_surface_area(radius));
            break;
        case '5':
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    } while (choice!= '5');

    return 0;
}