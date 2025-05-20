//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: Sherlock Holmes
#include<stdio.h>
#include<math.h>

#define PI 3.1416

int main()
{
    int choice;
    double length,breadth,area,perimeter;

    printf("\n\nWelcome to Sherlock's Geometric Calculations!\n");
    printf("Enter your choice:\n");
    printf("1. Calculate area of rectangle\n");
    printf("2. Calculate perimeter of rectangle\n");
    printf("3. Calculate area of circle\n");
    printf("4. Calculate perimeter of circle\n");

    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("\nEnter length and breadth of rectangle: ");
            scanf("%lf %lf",&length,&breadth);

            area = length*breadth;
            perimeter = 2*(length+breadth);

            printf("\nArea of rectangle = %.2lf\n",area);
            printf("Perimeter of rectangle = %.2lf\n",perimeter);

            break;

        case 2:
            printf("\nEnter length and breadth of rectangle: ");
            scanf("%lf %lf",&length,&breadth);

            perimeter = 2*(length+breadth);

            printf("\nPerimeter of rectangle = %.2lf\n",perimeter);

            break;

        case 3:
            printf("\nEnter radius of circle: ");
            scanf("%lf",&length);

            area = PI*length*length;
            perimeter = 2*PI*length;

            printf("\nArea of circle = %.2lf\n",area);
            printf("Perimeter of circle = %.2lf\n",perimeter);

            break;

        case 4:
            printf("\nEnter radius of circle: ");
            scanf("%lf",&length);

            perimeter = 2*PI*length;

            printf("\nPerimeter of circle = %.2lf\n",perimeter);

            break;

        default:
            printf("\nInvalid choice!");
    }

    return 0;
}