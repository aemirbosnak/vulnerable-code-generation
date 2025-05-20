//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: enthusiastic
#include<stdio.h>
#include<math.h>

// Function to compute the area of a triangle using Heron's Formula
double triangle_area(double a, double b, double c) 
{
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Function to compute the circumradius of a triangle
double circumradius(double a, double b, double c) 
{
    return (a * b * c) / (4.0 * triangle_area(a, b, c));
}

// Function to compute the inradius of a triangle
double inradius(double a, double b, double c) 
{
    return triangle_area(a, b, c) / (0.5 * (a + b + c));
}

int main() 
{
    // Take user input for the side lengths of a triangle
    double a, b, c;
    printf("Enter the side lengths of the triangle:\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Compute and print the area of the triangle
    double area = triangle_area(a, b, c);
    printf("The area of the triangle is: %lf\n", area);

    // Compute and print the circumradius of the triangle
    double radius_c = circumradius(a, b, c);
    printf("The circumradius of the triangle is: %lf\n", radius_c);

    // Compute and print the inradius of the triangle
    double radius_i = inradius(a, b, c);
    printf("The inradius of the triangle is: %lf\n", radius_i);

    // Check if the triangle is acute, right, or obtuse
    double aa = a*a, bb = b*b, cc = c*c;
    if (aa + bb < cc || bb + cc < aa || cc + aa < bb) 
    {
        printf("The triangle is obtuse.\n");
    } 
    else if (aa + bb == cc || bb + cc == aa || cc + aa == bb) 
    {
        printf("The triangle is right.\n");
    } 
    else 
    {
        printf("The triangle is acute.\n");
    }

    return 0;
}