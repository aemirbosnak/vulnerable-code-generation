//Code Llama-13B DATASET v1.0 Category: Geometric algorithms ; Style: invasive
/*
 * Geometric Algorithms Example Program
 *
 * This program demonstrates how to use geometric algorithms
 * to perform various geometric calculations.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

/*
 * Function to calculate the area of a circle
 *
 * @param r: The radius of the circle
 * @return: The area of the circle
 */
float circleArea(float r) {
    return PI * r * r;
}

/*
 * Function to calculate the area of a rectangle
 *
 * @param w: The width of the rectangle
 * @param h: The height of the rectangle
 * @return: The area of the rectangle
 */
float rectArea(float w, float h) {
    return w * h;
}

/*
 * Function to calculate the area of a triangle
 *
 * @param b: The base of the triangle
 * @param h: The height of the triangle
 * @return: The area of the triangle
 */
float triArea(float b, float h) {
    return (b * h) / 2;
}

/*
 * Function to calculate the area of a polygon
 *
 * @param n: The number of sides of the polygon
 * @param r: The radius of the polygon
 * @return: The area of the polygon
 */
float polyArea(int n, float r) {
    return (n * r * r) / (4 * tan(PI / n));
}

/*
 * Function to calculate the area of a sphere
 *
 * @param r: The radius of the sphere
 * @return: The area of the sphere
 */
float sphereArea(float r) {
    return 4 * PI * r * r;
}

/*
 * Function to calculate the area of a cylinder
 *
 * @param r: The radius of the cylinder
 * @param h: The height of the cylinder
 * @return: The area of the cylinder
 */
float cylinderArea(float r, float h) {
    return 2 * PI * r * (r + h);
}

/*
 * Function to calculate the area of a cone
 *
 * @param r: The radius of the cone
 * @param h: The height of the cone
 * @return: The area of the cone
 */
float coneArea(float r, float h) {
    return PI * r * (r + sqrt(h * h + r * r));
}

int main() {
    float r = 5;
    float w = 10;
    float h = 10;
    float b = 10;
    int n = 5;

    printf("Circle area: %f\n", circleArea(r));
    printf("Rectangle area: %f\n", rectArea(w, h));
    printf("Triangle area: %f\n", triArea(b, h));
    printf("Polygon area: %f\n", polyArea(n, r));
    printf("Sphere area: %f\n", sphereArea(r));
    printf("Cylinder area: %f\n", cylinderArea(r, h));
    printf("Cone area: %f\n", coneArea(r, h));

    return 0;
}