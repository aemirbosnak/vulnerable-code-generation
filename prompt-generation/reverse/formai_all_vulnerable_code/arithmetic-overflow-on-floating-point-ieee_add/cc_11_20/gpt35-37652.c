//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: real-life
/*
 * This program calculates the area and perimeter of a triangle given the lengths of its three sides. 
 * It also determines if the triangle is equilateral, isosceles, or scalene.
 * User is asked to enter the length of each side of the triangle.
 */

#include <stdio.h>
#include <math.h>

int main()
{
    double side1, side2, side3;
    double perimeter, s, area;
    int is_equilateral = 0, is_isosceles = 0, is_scalene = 0;

    printf("Enter the length of side1: ");
    scanf("%lf", &side1);

    printf("Enter the length of side2: ");
    scanf("%lf", &side2);

    printf("Enter the length of side3: ");
    scanf("%lf", &side3);

    // Check if the given sides form a valid triangle
    if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1)
    {
        perimeter = side1 + side2 + side3;
        s = perimeter/2;
        area = sqrt(s*(s-side1)*(s-side2)*(s-side3));

        // Determine the type of triangle
        if (side1 == side2 && side2 == side3)
        {
            is_equilateral = 1;
        }
        else if (side1 == side2 || side1 == side3 || side2 == side3)
        {
            is_isosceles = 1;
        }
        else
        {
            is_scalene = 1;
        }

        // Print the results
        printf("Perimeter of triangle = %.2lf units\n", perimeter);
        printf("Area of triangle = %.2lf sq. units\n", area);

        if (is_equilateral)
        {
            printf("Triangle is equilateral.\n");
        }
        else if (is_isosceles)
        {
            printf("Triangle is isosceles.\n");
        }
        else if (is_scalene)
        {
            printf("Triangle is scalene.\n");
        }
    }
    else
    {
        printf("Invalid triangle.\n");
    }

    return 0;
}