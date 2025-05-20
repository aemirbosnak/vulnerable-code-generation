//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include<stdio.h>
#include<math.h>

int main()
{
    double x, y, z, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6, x7, y7, z7, x8, y8, z8, x9, y9, z9, x10, y10, z10;
    int count = 0;
    char choice;

    printf("Welcome to the world of 3D shapes!\n");

    do
    {
        printf("\nEnter your choice:\n");
        printf("1. Sphere\n2. Cube\n3. Cylinder\n4. Cone\n5. Pyramid\n6. Exit\n");
        scanf("%c", &choice);

        switch(choice)
        {
            case '1':
                printf("\nEnter the radius of the sphere: ");
                scanf("%lf", &x);
                printf("\nThe surface area of the sphere is %.2lf", 4*3.14159*x*x);
                printf("\nThe volume of the sphere is %.2lf", (4/3)*3.14159*x*x*x);
                break;

            case '2':
                printf("\nEnter the side length of the cube: ");
                scanf("%lf", &x);
                printf("\nThe surface area of the cube is %.2lf", 6*x*x);
                printf("\nThe volume of the cube is %.2lf", x*x*x);
                break;

            case '3':
                printf("\nEnter the height of the cylinder: ");
                scanf("%lf", &x);
                printf("\nEnter the radius of the cylinder: ");
                scanf("%lf", &y);
                printf("\nThe surface area of the cylinder is %.2lf", 2*3.14159*y*x + 2*3.14159*y*y);
                printf("\nThe volume of the cylinder is %.2lf", 3.14159*y*y*x);
                break;

            case '4':
                printf("\nEnter the height of the cone: ");
                scanf("%lf", &x);
                printf("\nEnter the radius of the cone: ");
                scanf("%lf", &y);
                printf("\nThe surface area of the cone is %.2lf", 3.14159*y*x + 3.14159*y*y);
                printf("\nThe volume of the cone is %.2lf", (1/3)*3.14159*y*y*x);
                break;

            case '5':
                printf("\nEnter the height of the pyramid: ");
                scanf("%lf", &x);
                printf("\nEnter the base length of the pyramid: ");
                scanf("%lf", &y);
                printf("\nEnter the base width of the pyramid: ");
                scanf("%lf", &z);
                printf("\nThe surface area of the pyramid is %.2lf", 2*y*z + 2*x*z + 2*x*y);
                printf("\nThe volume of the pyramid is %.2lf", (1/3)*x*y*z);
                break;

            case '6':
                printf("\nExiting program...");
                break;

            default:
                printf("\nInvalid choice!");
        }

        printf("\n\n");

    }while(count < 10);

    return 0;
}