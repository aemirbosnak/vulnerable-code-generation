//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: grateful
#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j, k, l, m, x, y, z;
    float a, b, c, d, e, f, g, h, pi, area, perimeter;

    printf("Thank you for joining me on this mathematical journey, my friend!\n");

    // Let's calculate the area and perimeter of a rectangle.

    printf("Please enter the length of the rectangle: ");
    scanf("%f", &a);

    printf("Please enter the width of the rectangle: ");
    scanf("%f", &b);

    area = a * b;
    perimeter = 2 * (a + b);

    printf("The area of the rectangle is: %.2f square units.\n", area);
    printf("The perimeter of the rectangle is: %.2f units.\n", perimeter);

    // Now, let's calculate the area of a circle.

    printf("Would you like to calculate the area of a circle? (Y/N): ");
    scanf("%c", &x);

    if (x == 'Y')
    {
        printf("Please enter the radius of the circle: ");
        scanf("%f", &y);

        pi = 3.14159;
        area = pi * y * y;

        printf("The area of the circle is: %.2f square units.\n", area);
    }

    // Let's calculate the hypotenuse of a right triangle.

    printf("Would you like to calculate the hypotenuse of a right triangle? (Y/N): ");
    scanf("%c", &z);

    if (z == 'Y')
    {
        printf("Please enter the length of the first side: ");
        scanf("%f", &k);

        printf("Please enter the length of the second side: ");
        scanf("%f", &l);

        h = sqrt(k * k + l * l);

        printf("The hypotenuse of the right triangle is: %.2f units.\n", h);
    }

    // Thank you for joining me on this journey.

    printf("Thank you for participating in this mathematical adventure. I hope you enjoyed it!\n");

    return 0;
}