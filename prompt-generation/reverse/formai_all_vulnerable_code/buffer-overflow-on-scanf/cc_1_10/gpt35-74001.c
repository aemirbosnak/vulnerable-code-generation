//FormAI DATASET v1.0 Category: Math exercise ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, determinant, root1, root2, realPart, imaginaryPart;

    printf("Enter coefficients a, b and c: ");
    scanf("%f %f %f", &a, &b, &c);

    determinant = b * b - 4 * a * c;

    // Real and Different Roots
    if (determinant > 0) {
        root1 = (-b + sqrt(determinant)) / (2 * a);
        root2 = (-b - sqrt(determinant)) / (2 * a);

        printf("Root1 = %.2f \n", root1);
        printf("Root2 = %.2f \n", root2);
    }

    // Real and Same Roots
    else if (determinant == 0) {
        root1 = root2 = -b / (2 * a);
        printf("Root1 = Root2 = %.2f;", root1);
    }

    // Imaginary Roots
    else {
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-determinant) / (2 * a);
        printf("Root1 = %.2f+%.2fi \n", realPart, imaginaryPart);
        printf("Root2 = %.2f-%.2fi \n", realPart, imaginaryPart);
    }

    //Calculate the average of root1 and root2
    float average = (root1 + root2) / 2;

    //Calculate standard deviation using the formula sqrt( 1/2 * ((root1-average)^2 + (root2-average)^2) )
    float stdDeviation = sqrt(0.5*((root1 - average)*(root1 - average) + 
                             (root2 - average)*(root2 - average)));

    //Calculate correlation coefficient using the formula (root1*root2 - average*average)/ (stdDeviation*stdDeviation)
    float correlation = (root1 * root2 - average * average) / (stdDeviation * stdDeviation);

    printf("The average of the roots is: %.2f \n", average);
    printf("The standard deviation of the roots is: %.2f \n", stdDeviation);
    printf("The correlation coefficient between the roots is: %.2f \n", correlation);

    return 0;
}