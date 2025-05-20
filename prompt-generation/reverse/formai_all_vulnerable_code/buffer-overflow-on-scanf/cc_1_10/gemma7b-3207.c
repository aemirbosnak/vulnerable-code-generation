//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: accurate
#include <stdio.h>
#include <math.h>

int main()
{
    // Define variables
    double x, y, z, pi, area, perimeter, volume;
    int choice;

    // Initialize pi
    pi = 3.14159;

    // Display menu options
    printf("Enter 1 for Area of Circle\n");
    printf("Enter 2 for Perimeter of Circle\r");
    printf("Enter 3 for Volume of Cylinder\n");
    printf("Enter 4 for Exit\n");

    // Get user input
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Calculate based on user choice
    switch (choice)
    {
        case 1:
            printf("Enter the radius of the circle: ");
            scanf("%lf", &x);
            area = pi * x * x;
            printf("The area of the circle is: %.2lf square units.\n", area);
            break;

        case 2:
            printf("Enter the radius of the circle: ");
            scanf("%lf", &x);
            perimeter = 2 * pi * x;
            printf("The perimeter of the circle is: %.2lf units.\n", perimeter);
            break;

        case 3:
            printf("Enter the radius of the cylinder: ");
            scanf("%lf", &x);
            printf("Enter the height of the cylinder: ");
            scanf("%lf", &y);
            volume = pi * x * x * y;
            printf("The volume of the cylinder is: %.2lf cubic units.\n", volume);
            break;

        case 4:
            printf("Thank you for using this program.\n");
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}