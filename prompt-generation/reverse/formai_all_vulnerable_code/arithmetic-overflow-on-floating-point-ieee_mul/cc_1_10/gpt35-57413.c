//FormAI DATASET v1.0 Category: Arithmetic ; Style: complex
#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979323846

//Function Declaration
int add(int, int);
double sub(double, double);
float multiply(float, float);
long divide(long, long);
double power(double, double);
double factorial(double);

int main()
{
    //Variable Declaration
    int a = 5, b = 6, sum;
    double c = 7.5, d = 3.2, difference;
    float e = 12.33, f = 4.44, product;
    long g = 100, h = 20, quotient;
    double num = 6, exponent = 3, result, fact_num = 5, fact_result;

    //Addition
    sum = add(a, b);
    printf("The sum of %d and %d is %d\n", a, b, sum);

    //Subtraction
    difference = sub(c, d);
    printf("The difference between %lf and %lf is %lf\n", c, d, difference);

    //Multiplication
    product = multiply(e, f);
    printf("The product of %f and %f is %f\n", e, f, product);

    //Division
    quotient = divide(g, h);
    printf("The quotient of %ld and %ld is %ld\n", g, h, quotient);

    //Power calculation
    result = power(num, exponent);
    printf("%lf raised to the power of %lf is %lf\n", num, exponent, result);

    //Factorial calculation
    fact_result = factorial(fact_num);
    printf("Factorial of %lf is %lf\n", fact_num, fact_result);

    return 0;
}

//Addition Function
int add(int x, int y)
{
    return x + y;
}

//Subtraction Function
double sub(double x, double y)
{
    return x - y;
}

//Multiplication Function
float multiply(float x, float y)
{
    return x * y;
}

//Division Function
long divide(long x, long y)
{
    return x / y;
}

//Power Function
double power(double x, double y)
{
    return pow(x, y);
}

//Factorial Function
double factorial(double x)
{
    double fact = 1;
    int i;

    for (i = 1; i <= x; i++)
    {
        fact = fact * i;
    }

    return fact;
}