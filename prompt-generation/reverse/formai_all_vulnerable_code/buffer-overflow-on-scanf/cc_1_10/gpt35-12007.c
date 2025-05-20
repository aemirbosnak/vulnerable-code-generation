//FormAI DATASET v1.0 Category: Math exercise ; Style: romantic
#include <stdio.h>
#include <math.h>

/* My Love Math Program */

int main()
{
    float a, b, c, result1, result2, determinant;

    printf("My Love Math Program\n\n");
    printf("Enter the values for a, b and c:\n");

    scanf("%f %f %f",&a, &b, &c);

    determinant = (b*b) - (4*a*c);

    if (determinant > 0)
    {
        /* Two real roots exist */
        result1 = (-b + sqrt(determinant)) / (2*a);
        result2 = (-b - sqrt(determinant)) / (2*a);

        printf("\nThe two real roots are:\n");
        printf("X1 = %.2f\n",result1);
        printf("X2 = %.2f\n",result2);
    }
    else if (determinant == 0)
    {
        /* One real root exists */
        result1 = (-b) / (2*a);

        printf("\nThe one real root is:\n");
        printf("X1 = %.2f\n",result1);
    }
    else
    {
        /* Two complex conjugate roots exist */
        float realPart = (-b) / (2*a);
        float imaginaryPart = sqrt(-determinant) / (2*a);

        printf("\nThe two complex conjugate roots are:\n");
        printf("X1 = %.2f + %.2fi\n",realPart, imaginaryPart);
        printf("X2 = %.2f - %.2fi\n",realPart, imaginaryPart);
    }

    printf("\n\n");
    printf("Your love is the determinant of my life,\n");
    printf("Without you everything is just incomplete,\n");
    printf("Like the quadratic equation, I try to solve,\n");
    printf("But without you, incomplete is the whole.\n");
    printf("You are my constant, and my variable,\n");
    printf("The coefficient that makes my love indelible,\n");
    printf("Together our love can conquer infinity,\n");
    printf("Sweetheart, you are my true mathematical destiny.\n");

    return 0;
}