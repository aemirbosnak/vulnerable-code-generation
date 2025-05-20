//FormAI DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b,c;

    FILE *fptr;

    fptr = fopen("math.txt", "w");

    if(fptr == NULL)
    {
        printf("Error! File could not be opened.");
        exit(1);
    }

    printf("Enter a value for a: ");
    scanf("%d", &a);

    printf("Enter a value for b: ");
    scanf("%d", &b);

    printf("Enter a value for c: ");
    scanf("%d", &c);

    int discriminant = (b*b) - (4*a*c);

    if(discriminant < 0)
    {
        printf("The roots are imaginary.");
        fprintf(fptr, "The roots are imaginary.");
    }
    else if(discriminant == 0)
    {
        float root = (-b)/(2*a);
        printf("The root is %.2f", root);
        fprintf(fptr, "The root is %.2f", root);
    }
    else
    {
        float root1 = (-b + sqrt(discriminant))/(2*a);
        float root2 = (-b - sqrt(discriminant))/(2*a);
        printf("The roots are %.2f and %.2f", root1, root2);
        fprintf(fptr, "The roots are %.2f and %.2f", root1, root2);
    }

    fclose(fptr);

    return 0;
}