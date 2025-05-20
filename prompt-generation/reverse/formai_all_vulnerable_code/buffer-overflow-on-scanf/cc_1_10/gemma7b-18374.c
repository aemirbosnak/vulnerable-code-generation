//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main()
{
    int n, i, j, k, l, m, x, y;
    float area, radius, perimeter, diameter;

    printf("Enter the number of polygons: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter the number of sides for polygon %d: ", i + 1);
        scanf("%d", &k);

        switch(k)
        {
            case 3:
                printf("Enter the side length of the triangle: ");
                scanf("%f", &x);

                area = 0.5 * x * x * sin(PI / 3);
                perimeter = 3 * x;
                diameter = x;
                break;

            case 4:
                printf("Enter the side length of the square: ");
                scanf("%f", &x);

                area = x * x;
                perimeter = 4 * x;
                diameter = x * sqrt(2);
                break;

            case 5:
                printf("Enter the side length of the pentagon: ");
                scanf("%f", &x);

                area = (5 * x * x) / 4 * sin(PI / 5);
                perimeter = 5 * x;
                diameter = x * sqrt(5) / 2;
                break;

            default:
                printf("Invalid number of sides.");
                break;
        }

        printf("Polygon %d has an area of %.2f square units.\n", i + 1, area);
        printf("The perimeter of the polygon is %.2f units.\n", perimeter);
        printf("The diameter of the polygon is %.2f units.\n", diameter);
        printf("\n");
    }

    return 0;
}