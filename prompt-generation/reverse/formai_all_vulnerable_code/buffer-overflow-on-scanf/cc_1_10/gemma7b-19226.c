//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

int main()
{
    int n, i, j, k, l, r, x, y, z;
    float area, perimeter, radius;

    printf("Enter the number of polygons:");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter the number of vertices:");
        scanf("%d", &k);

        switch(k)
        {
            case 3:
                printf("Enter the coordinates of the vertices:");
                scanf("%d %d", &x, &y);

                radius = sqrtf((x - x) * (x - x) + (y - y) * (y - y)) / 2;
                area = M_PI * radius * radius;
                perimeter = 2 * M_PI * radius;

                printf("The area of the triangle is: %.2f\n", area);
                printf("The perimeter of the triangle is: %.2f\n", perimeter);
                break;

            case 4:
                printf("Enter the coordinates of the vertices:");
                scanf("%d %d", &x, &y);

                radius = sqrtf((x - x) * (x - x) + (y - y) * (y - y)) / 2;
                area = M_PI * radius * radius;
                perimeter = 2 * M_PI * radius;

                printf("The area of the square is: %.2f\n", area);
                printf("The perimeter of the square is: %.2f\n", perimeter);
                break;

            default:
                printf("Invalid number of vertices\n");
                break;
        }
    }

    return 0;
}