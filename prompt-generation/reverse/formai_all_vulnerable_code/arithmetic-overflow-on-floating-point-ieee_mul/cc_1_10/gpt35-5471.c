//FormAI DATASET v1.0 Category: Error handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the shape-shifting error handling program!\n");
    printf("Enter your choice of shape: 1.Circle 2.Square 3.Triangle\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
        {
            // Circle Error Handling
            printf("Enter the radius of the circle: ");
            double radius;
            scanf("%lf", &radius);

            if (radius <= 0)
            {
                printf("Error: Invalid radius entered!\n");
                return EXIT_FAILURE;
            }
            else
            {
                double area = 3.14 * radius * radius;
                printf("The area of the circle is: %lf", area);
            }
            break;
        }

        case 2:
        {
            // Square Error Handling
            printf("Enter the side length of the square: ");
            double side;
            scanf("%lf", &side);

            if (side <= 0)
            {
                printf("Error: Invalid side length entered!\n");
                return EXIT_FAILURE;
            }
            else
            {
                double area = side * side;
                printf("The area of the square is: %lf", area);
            }
            break;
        }

        case 3:
        {
            // Triangle Error Handling
            printf("Enter the base and height of the triangle: ");

            double base, height;
            scanf("%lf %lf", &base, &height);

            if (base <= 0 || height <= 0)
            {
                printf("Error: Invalid base or height entered!\n");
                return EXIT_FAILURE;
            }
            else
            {
                double area = (base * height) / 2;
                printf("The area of the triangle is: %lf", area);
            }
            break;
        }

        default:
        {
            printf("Error: Invalid choice entered!\n");
            return EXIT_FAILURE;
        }
    }

    printf("\nThank you for using the shape-shifting error handling program!\n");
    return EXIT_SUCCESS;
}