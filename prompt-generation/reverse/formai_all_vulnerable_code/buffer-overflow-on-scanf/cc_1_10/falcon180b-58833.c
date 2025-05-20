//Falcon-180B DATASET v1.0 Category: Error handling ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265358979323846

int main(int argc, char *argv[])
{
    double radius, area, circumference;
    char choice;

    printf("Enter the value of radius: ");
    scanf("%lf", &radius);

    if (radius <= 0)
    {
        printf("Invalid input! Please enter a valid radius.\n");
        exit(1);
    }

    printf("Enter your choice:\n");
    printf("1. Area\n");
    printf("2. Circumference\n");
    printf("3. Both\n");
    scanf(" %c", &choice);

    switch(choice)
    {
        case '1':
            area = PI * radius * radius;
            printf("Area of circle with radius %.2lf is: %.2lf\n", radius, area);
            break;

        case '2':
            circumference = 2 * PI * radius;
            printf("Circumference of circle with radius %.2lf is: %.2lf\n", radius, circumference);
            break;

        case '3':
            area = PI * radius * radius;
            circumference = 2 * PI * radius;

            printf("Area of circle with radius %.2lf is: %.2lf\n", radius, area);
            printf("Circumference of circle with radius %.2lf is: %.2lf\n", radius, circumference);
            break;

        default:
            printf("Invalid choice! Please enter a valid choice.\n");
            exit(1);
    }

    return 0;
}