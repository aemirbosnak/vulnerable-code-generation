//FormAI DATASET v1.0 Category: Math exercise ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Function prototypes */
double areaOfTriangle(double base, double height);
bool isPositive(double num);
double getPositiveInput(char *message);

int main(void) {
    double base1, height1, base2, height2, area1, area2;

    /* Get base and height for first triangle */
    printf("Enter base and height of first triangle.\n");
    base1 = getPositiveInput("Base: ");
    height1 = getPositiveInput("Height: ");

    /* Get base and height for second triangle */
    printf("\nEnter base and height of second triangle.\n");
    base2 = getPositiveInput("Base: ");
    height2 = getPositiveInput("Height: ");

    /* Calculate area of both triangles */
    area1 = areaOfTriangle(base1, height1);
    area2 = areaOfTriangle(base2, height2);

    /* Compare areas and print result */
    printf("\nArea of first triangle is %.2lf\n", area1);
    printf("Area of second triangle is %.2lf\n", area2);

    if (area1 > area2) {
        printf("The first triangle is larger than the second triangle.\n");
    } else if (area1 == area2) {
        printf("The two triangles have the same area.\n");
    } else {
        printf("The second triangle is larger than the first triangle.\n");
    }

    return 0;
}

/**
 * Calculates area of a triangle
 *
 * @param base The base of the triangle
 * @param height The height of the triangle
 * @return The area of the triangle
 */
double areaOfTriangle(double base, double height) {
    return 0.5 * base * height;
}

/**
 * Checks if a number is positive
 *
 * @param num The number to check
 * @return true if the number is positive, false otherwise
 */
bool isPositive(double num) {
    return num > 0;
}

/**
 * Gets a positive number from user input
 *
 * @param message Message to prompt user
 * @return A positive number input by the user
 */
double getPositiveInput(char *message) {
    double num;

    while (true) {
        printf("%s", message);
        scanf("%lf", &num);

        if (isPositive(num)) {
            return num;
        } else {
            printf("Invalid input! Please enter a positive number.\n");
        }
    }
}