//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100
#define PI 3.14159265358979323846

int main() {
    int i, j;
    double x, y, angle, radius;
    char shape;

    // prompt user for shape
    printf("Enter shape (c for circle, s for square): ");
    scanf("%c", &shape);

    // generate shape
    switch(shape) {
        case 'c':
            // prompt user for circle parameters
            printf("Enter x-coordinate of center: ");
            scanf("%lf", &x);
            printf("Enter y-coordinate of center: ");
            scanf("%lf", &y);
            printf("Enter radius: ");
            scanf("%lf", &radius);

            // generate circle
            for(i = 0; i < SIZE; i++) {
                angle = 2 * PI * i / SIZE;
                printf("%.2lf %.2lf\n", x + radius * cos(angle), y + radius * sin(angle));
            }
            break;
        case's':
            // prompt user for square parameters
            printf("Enter x-coordinate of top-left corner: ");
            scanf("%lf", &x);
            printf("Enter y-coordinate of top-left corner: ");
            scanf("%lf", &y);
            printf("Enter side length: ");
            scanf("%lf", &radius);

            // generate square
            for(i = 0; i < SIZE; i++) {
                angle = 2 * PI * i / SIZE;
                printf("%.2lf %.2lf\n", x + radius * cos(angle), y + radius * sin(angle));
            }
            break;
        default:
            // invalid shape
            printf("Invalid shape entered.\n");
            exit(1);
    }

    return 0;
}