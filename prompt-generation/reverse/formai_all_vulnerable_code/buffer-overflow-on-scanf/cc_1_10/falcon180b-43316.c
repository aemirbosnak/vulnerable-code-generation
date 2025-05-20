//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double radius;
    double height;
} Cylinder;

typedef struct {
    double base;
    double height;
} Triangle;

typedef struct {
    double sideA;
    double sideB;
    double sideC;
} Square;

double getCylinderVolume(Cylinder cylinder) {
    return PI * cylinder.radius * cylinder.radius * cylinder.height;
}

double getTriangleArea(Triangle triangle) {
    return 0.5 * triangle.base * triangle.height;
}

double getSquareArea(Square square) {
    return square.sideA * square.sideB;
}

int main() {
    Cylinder cylinder;
    Triangle triangle;
    Square square;

    printf("Enter the radius and height of the cylinder: ");
    scanf("%lf %lf", &cylinder.radius, &cylinder.height);
    printf("The volume of the cylinder is %.2lf\n", getCylinderVolume(cylinder));

    printf("Enter the base and height of the triangle: ");
    scanf("%lf %lf", &triangle.base, &triangle.height);
    printf("The area of the triangle is %.2lf\n", getTriangleArea(triangle));

    printf("Enter the side lengths of the square: ");
    scanf("%lf %lf %lf", &square.sideA, &square.sideB, &square.sideC);
    printf("The area of the square is %.2lf\n", getSquareArea(square));

    return 0;
}