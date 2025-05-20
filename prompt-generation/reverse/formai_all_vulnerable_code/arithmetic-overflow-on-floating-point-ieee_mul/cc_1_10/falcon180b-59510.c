//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: protected
#include<stdio.h>
#include<math.h>

#define PI 3.14159265358979323846

int main() {
    double radius, area, perimeter;
    int choice;

    printf("Enter the radius: ");
    scanf("%lf", &radius);

    printf("Select an option:\n");
    printf("1. Area\n");
    printf("2. Perimeter\n");
    printf("3. Volume\n");
    printf("4. Surface Area\n");
    printf("5. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            area = PI * radius * radius;
            printf("The area of the circle is: %.2lf\n", area);
            break;

        case 2:
            perimeter = 2 * PI * radius;
            printf("The perimeter of the circle is: %.2lf\n", perimeter);
            break;

        case 3:
            printf("Enter the height of the cylinder: ");
            scanf("%lf", &radius);
            area = 2 * PI * radius * radius + 2 * PI * radius * radius;
            printf("The area of the cylinder is: %.2lf\n", area);
            break;

        case 4:
            printf("Enter the height of the cylinder: ");
            scanf("%lf", &radius);
            area = 2 * PI * radius * radius + 2 * PI * radius * radius + 2 * PI * radius;
            printf("The surface area of the cylinder is: %.2lf\n", area);
            break;

        case 5:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}