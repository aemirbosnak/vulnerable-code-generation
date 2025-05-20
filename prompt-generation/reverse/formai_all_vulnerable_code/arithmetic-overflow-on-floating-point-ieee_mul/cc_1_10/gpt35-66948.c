//FormAI DATASET v1.0 Category: Scientific ; Style: bold
#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, result;
    int choice;

    printf("Scientific Calculator by [Your Name]\n\n");

    printf("Please select an operation:\n");
    printf("1. Square root\n");
    printf("2. Logarithm (base 10)\n");
    printf("3. Sine\n");
    printf("4. Cosine\n");
    printf("5. Tangent\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    printf("\nEnter the number: ");
    scanf("%lf", &x);

    switch(choice)
    {
        case 1:
            y = sqrt(x);
            printf("\nSquare root of %.2lf is %.2lf", x, y);
            break;

        case 2:
            y = log10(x);
            printf("\nLogarithm of %.2lf to the base 10 is %.2lf", x, y);
            break;

        case 3:
            result = sin(x * 3.14159265358979323846 / 180);
            printf("\nSine of %.2lf degrees is %.2lf", x, result);
            break;

        case 4:
            result = cos(x * 3.14159265358979323846 / 180);
            printf("\nCosine of %.2lf degrees is %.2lf", x, result);
            break;

        case 5:
            result = tan(x * 3.14159265358979323846 / 180);
            printf("\nTangent of %.2lf degrees is %.2lf", x, result);
            break;

        default:
            printf("\nInvalid choice. Please select from 1-5.");

    }

    printf("\n\nThank you for using the Scientific Calculator!");

    return 0;
}