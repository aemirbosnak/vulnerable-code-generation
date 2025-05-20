//Gemma-7B DATASET v1.0 Category: Educational ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void morph_shapes(int argc, char *argv[])
{
    int choice, shape, sides, i, x, y;

    printf("Welcome to the Shape Morphing Machine!\n");
    printf("Please select an option:\n");
    printf("1. Triangle\n");
    printf("2. Square\n");
    printf("3. Circle\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the number of sides for the triangle: ");
            scanf("%d", &sides);
            printf("Enter the dimensions of the triangle (x and y): ");
            scanf("%d %d", &x, &y);
            for (i = 0; i < sides; i++)
            {
                printf("Side %d: %.2lf\n", i + 1, (x * i) / sides + y);
            }
            break;

        case 2:
            printf("Enter the side length of the square: ");
            scanf("%d", &sides);
            for (i = 0; i < sides; i++)
            {
                printf("Side %d: %.2lf\n", i + 1, sides);
            }
            break;

        case 3:
            printf("Enter the radius of the circle: ");
            scanf("%d", &x);
            printf("Circumference: %.2lf\n", 2 * 3.14159 * x);
            printf("Area: %.2lf\n", 3.14159 * x * x);
            break;
    }

    return;
}

int main()
{
    morph_shapes(0, NULL);

    return 0;
}