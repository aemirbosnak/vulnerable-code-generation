//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main()
{
    float radius;
    float area;
    int choice;

    // Display menu options
    printf("Please select an option:\n");
    printf("1. Calculate the area of a circle.\n");
    printf("2. Calculate the circumference of a circle.\n");
    printf("3. Calculate the diameter of a circle.\n");

    // Get user input
    scanf("Enter your choice: ", &choice);

    // Switch case to handle user input
    switch (choice)
    {
        case 1:
            // Get the radius of the circle
            printf("Enter the radius of the circle: ");
            scanf("%f", &radius);

            // Calculate the area of the circle
            area = PI * radius * radius;

            // Display the area of the circle
            printf("The area of the circle is: %.2f square units.\n", area);
            break;

        case 2:
            // Get the radius of the circle
            printf("Enter the radius of the circle: ");
            scanf("%f", &radius);

            // Calculate the circumference of the circle
            area = 2 * PI * radius;

            // Display the circumference of the circle
            printf("The circumference of the circle is: %.2f units.\n", area);
            break;

        case 3:
            // Get the diameter of the circle
            printf("Enter the diameter of the circle: ");
            scanf("%f", &radius);

            // Calculate the radius of the circle
            radius = radius / 2;

            // Calculate the area of the circle
            area = PI * radius * radius;

            // Display the area of the circle
            printf("The area of the circle is: %.2f square units.\n", area);
            break;

        default:
            // Invalid input
            printf("Invalid input. Please try again.\n");
            break;
    }

    return 0;
}