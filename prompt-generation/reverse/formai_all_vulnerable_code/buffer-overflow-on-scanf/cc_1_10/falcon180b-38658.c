//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    int choice;
    double radius, area, perimeter, diameter;

    printf("Welcome to the Circle Calculator!\n\n");

    while(1) {
        printf("Enter your choice:\n");
        printf("1. Calculate area\n");
        printf("2. Calculate perimeter\n");
        printf("3. Calculate diameter\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the radius of the circle: ");
                scanf("%lf", &radius);
                area = PI * radius * radius;
                printf("The area of the circle is: %.2lf\n", area);
                break;

            case 2:
                printf("Enter the radius of the circle: ");
                scanf("%lf", &radius);
                perimeter = 2 * PI * radius;
                printf("The perimeter of the circle is: %.2lf\n", perimeter);
                break;

            case 3:
                printf("Enter the radius of the circle: ");
                scanf("%lf", &radius);
                diameter = 2 * radius;
                printf("The diameter of the circle is: %.2lf\n", diameter);
                break;

            case 4:
                printf("Thank you for using the Circle Calculator!");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}