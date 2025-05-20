//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: standalone
#include <stdio.h>
#include <math.h>

int main() {
    // Define variables
    double x, y, z, area, perimeter, radius;
    int choice;

    // Menu options
    printf("Select an option:\n");
    printf("1. Calculate area of a circle\n");
    printf("2. Calculate perimeter of a circle\n");
    printf("3. Calculate radius of a circle\n");
    printf("4. Exit\n");

    // Get user input
    scanf("%d", &choice);

    // Switch case for different options
    switch (choice) {
        case 1:
            // Formula to calculate area of a circle
            printf("Enter the radius of the circle: ");
            scanf("%lf", &radius);
            area = M_PI * radius * radius;
            printf("The area of the circle is: %.2lf square units.\n", area);
            break;

        case 2:
            // Formula to calculate perimeter of a circle
            printf("Enter the radius of the circle: ");
            scanf("%lf", &radius);
            perimeter = 2 * M_PI * radius;
            printf("The perimeter of the circle is: %.2lf units.\n", perimeter);
            break;

        case 3:
            // Formula to calculate radius of a circle
            printf("Enter the area of the circle: ");
            scanf("%lf", &area);
            radius = sqrt(area / M_PI);
            printf("The radius of the circle is: %.2lf units.\n", radius);
            break;

        case 4:
            // Exit the program
            printf("Thank you for using the program. Goodbye!\n");
            break;

        default:
            // Invalid input
            printf("Invalid input. Please select a valid option.\n");
    }

    return 0;
}