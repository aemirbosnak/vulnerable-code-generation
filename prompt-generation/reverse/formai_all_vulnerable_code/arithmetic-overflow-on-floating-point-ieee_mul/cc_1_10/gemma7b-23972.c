//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: sophisticated
#include <stdio.h>
#include <math.h>

int main()
{
    // Define variables
    double x, y, z, pi, area, perimeter, volume;
    int choice;

    // Initialize constants
    pi = 3.14159;

    // Display menu options
    printf("Choose an option:\n");
    printf("1. Calculate Area of a Circle\n");
    printf("2. Calculate Perimeter of a Circle\n");
    printf("3. Calculate Volume of a Sphere\n");
    printf("Enter your choice: ");

    // Get user input
    scanf("%d", &choice);

    // Switch case to handle user input
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
            printf("Enter the radius of the sphere: ");
            scanf("%lf", &x);
            volume = (4 / 3) * pi * x * x * x;
            printf("The volume of the sphere is: %.2lf cubic units.\n", volume);
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}