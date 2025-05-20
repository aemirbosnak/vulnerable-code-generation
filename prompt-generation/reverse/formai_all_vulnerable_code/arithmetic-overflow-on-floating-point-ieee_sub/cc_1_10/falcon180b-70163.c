//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Alan Turing
#include<stdio.h>
#include<math.h>

/* Define a function to generate the Fibonacci sequence */
void Fibonacci(int n)
{
    int i;
    int term1 = 0;
    int term2 = 1;
    int nextTerm = 0;

    printf("Fibonacci sequence up to %d terms:\n", n);
    printf("0");

    for(i = 1; i < n; i++)
    {
        nextTerm = term1 + term2;
        term1 = term2;
        term2 = nextTerm;
        printf("%d", nextTerm);
    }
}

/* Define a function to solve a quadratic equation */
void QuadraticEquation(double a, double b, double c)
{
    double discriminant;
    double root1, root2;

    discriminant = b*b - 4*a*c;

    if(discriminant > 0)
    {
        root1 = (-b + sqrt(discriminant)) / (2*a);
        root2 = (-b - sqrt(discriminant)) / (2*a);
        printf("The roots are real and different: %lf and %lf\n", root1, root2);
    }
    else if(discriminant == 0)
    {
        root1 = root2 = -b / (2*a);
        printf("The roots are real and equal: %lf\n", root1);
    }
    else
    {
        double realPart, imaginaryPart;
        realPart = -b / (2*a);
        imaginaryPart = sqrt(-discriminant) / (2*a);
        printf("The roots are complex and different: %lf + %lfi and %lf - %lfi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }
}

/* Define a function to calculate the factorial of a number */
long long Factorial(int n)
{
    long long fact = 1;
    int i;

    for(i = 1; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}

int main()
{
    int n;
    double a, b, c;

    printf("Enter the number of terms for the Fibonacci sequence: ");
    scanf("%d", &n);
    Fibonacci(n);

    printf("\nEnter the coefficients a, b and c of a quadratic equation: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    QuadraticEquation(a, b, c);

    printf("\nEnter a non-negative integer: ");
    scanf("%d", &n);
    printf("The factorial of %d is %lld\n", n, Factorial(n));

    return 0;
}