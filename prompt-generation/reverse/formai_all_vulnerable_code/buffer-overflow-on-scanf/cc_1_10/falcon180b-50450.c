//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double radius, area, perimeter, diameter;
    char choice;

    // Prompt user for initial values
    printf("Welcome to the Circle Calculator!\n");
    printf("Please enter the radius of a circle: ");
    scanf("%lf", &radius);

    // Calculate area, perimeter, and diameter
    area = PI * radius * radius;
    perimeter = 2 * PI * radius;
    diameter = 2 * radius;

    // Display initial values
    printf("\nInitial values:\n");
    printf("Radius: %lf\n", radius);
    printf("Area: %lf\n", area);
    printf("Perimeter: %lf\n", perimeter);
    printf("Diameter: %lf\n\n", diameter);

    // Main loop
    do {
        // Prompt user for choice
        printf("What would you like to do?\n");
        printf("1. Calculate area\n");
        printf("2. Calculate perimeter\n");
        printf("3. Calculate diameter\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        // Perform chosen calculation
        switch (choice) {
            case '1':
                printf("\nCalculating area...\n");
                area = PI * radius * radius;
                printf("Area: %lf\n\n", area);
                break;
            case '2':
                printf("\nCalculating perimeter...\n");
                perimeter = 2 * PI * radius;
                printf("Perimeter: %lf\n\n", perimeter);
                break;
            case '3':
                printf("\nCalculating diameter...\n");
                diameter = 2 * radius;
                printf("Diameter: %lf\n\n", diameter);
                break;
            case '4':
                printf("\nExiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }

    } while (choice!= '4');

    return 0;
}