//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265358979323846

int main()
{
    double radius, area, perimeter, diameter;
    int choice;

    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    printf("\nMenu:\n");
    printf("1. Calculate area\n");
    printf("2. Calculate perimeter\n");
    printf("3. Calculate diameter\n");
    printf("4. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            area = PI * radius * radius;
            printf("\nThe area of the circle is: %.2lf", area);
            break;

        case 2:
            perimeter = 2 * PI * radius;
            printf("\nThe perimeter of the circle is: %.2lf", perimeter);
            break;

        case 3:
            diameter = 2 * radius;
            printf("\nThe diameter of the circle is: %.2lf", diameter);
            break;

        case 4:
            printf("\nExiting program...");
            break;

        default:
            printf("\nInvalid choice!");
            break;
    }

    return 0;
}