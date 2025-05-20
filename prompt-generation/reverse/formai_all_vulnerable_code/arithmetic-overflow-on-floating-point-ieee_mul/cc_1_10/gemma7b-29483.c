//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

int main()
{
    int n, i, j, k, l, m, x, y, z;
    double a, b, c, d, e, f, g, h, radius, area, perimeter;
    char ch;

    printf("Enter the number of shapes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the type of shape (circle/square/triangle): ");
        scanf("%s", &ch);

        switch (ch)
        {
            case 'c':
                printf("Enter the radius of the circle: ");
                scanf("%lf", &radius);

                area = M_PI * radius * radius;
                perimeter = 2 * M_PI * radius;

                printf("The area of the circle is: %.2lf square units.\n", area);
                printf("The perimeter of the circle is: %.2lf units.\n", perimeter);
                break;

            case 's':
                printf("Enter the side length of the square: ");
                scanf("%lf", &a);

                area = a * a;
                perimeter = 4 * a;

                printf("The area of the square is: %.2lf square units.\n", area);
                printf("The perimeter of the square is: %.2lf units.\n", perimeter);
                break;

            case 't':
                printf("Enter the base of the triangle: ");
                scanf("%lf", &b);

                printf("Enter the height of the triangle: ");
                scanf("%lf", &c);

                area = 0.5 * b * c;
                perimeter = b + c + sqrt(b * b + 4 * c * c);

                printf("The area of the triangle is: %.2lf square units.\n", area);
                printf("The perimeter of the triangle is: %.2lf units.\n", perimeter);
                break;
        }
    }

    return 0;
}