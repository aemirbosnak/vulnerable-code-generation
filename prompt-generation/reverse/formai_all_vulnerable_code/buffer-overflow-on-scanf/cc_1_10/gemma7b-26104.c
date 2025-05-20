//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, x, y, z;
    char c;

    printf("Enter the number of shapes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the shape type (C, R, T, H): ");
        scanf(" %c", &c);

        switch (c)
        {
            case 'C':
                printf("Enter the number of circles: ");
                scanf("%d", &x);

                for (j = 0; j < x; j++)
                {
                    printf("Enter the radius of the circle: ");
                    scanf("%d", &y);

                    printf("Draw a circle of radius %d.\n", y);
                }
                break;

            case 'R':
                printf("Enter the number of rectangles: ");
                scanf("%d", &x);

                for (j = 0; j < x; j++)
                {
                    printf("Enter the length of the rectangle: ");
                    scanf("%d", &y);

                    printf("Enter the width of the rectangle: ");
                    scanf("%d", &z);

                    printf("Draw a rectangle of length %d, width %d.\n", y, z);
                }
                break;

            case 'T':
                printf("Enter the number of triangles: ");
                scanf("%d", &x);

                for (j = 0; j < x; j++)
                {
                    printf("Enter the length of the triangle: ");
                    scanf("%d", &y);

                    printf("Enter the height of the triangle: ");
                    scanf("%d", &z);

                    printf("Draw a triangle of length %d, height %d.\n", y, z);
                }
                break;

            case 'H':
                printf("Enter the number of hexagons: ");
                scanf("%d", &x);

                for (j = 0; j < x; j++)
                {
                    printf("Enter the radius of the hexagon: ");
                    scanf("%d", &y);

                    printf("Draw a hexagon of radius %d.\n", y);
                }
                break;
        }
    }

    return 0;
}