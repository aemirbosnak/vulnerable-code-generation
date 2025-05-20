//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1024

int main()
{
    int n, i, j, k;
    double x, y, z, r, area, perimeter;
    char str[MAX_SIZE];

    printf("Enter the number of shapes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the shape type (circle/rectangle): ");
        scanf("%s", str);

        if (strcmp(str, "circle") == 0)
        {
            printf("Enter the radius: ");
            scanf("%lf", &r);

            area = M_PI * r * r;
            perimeter = 2 * M_PI * r;

            printf("The area of the circle is: %.2lf square units.\n", area);
            printf("The perimeter of the circle is: %.2lf units.\n", perimeter);
        }
        else if (strcmp(str, "rectangle") == 0)
        {
            printf("Enter the length: ");
            scanf("%lf", &x);

            printf("Enter the width: ");
            scanf("%lf", &y);

            area = x * y;
            perimeter = 2 * (x + y);

            printf("The area of the rectangle is: %.2lf square units.\n", area);
            printf("The perimeter of the rectangle is: %.2lf units.\n", perimeter);
        }
        else
        {
            printf("Invalid shape type.\n");
        }
    }

    return 0;
}