//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: high level of detail
#include <stdio.h>
#include <math.h>

float distance(float x1, float y1, float x2, float y2);
float perimeter(float a, float b, float c);
float area(float a, float b, float c, float s);

int main()
{
    // Input coordinates of three points
    float x1, y1, x2, y2, x3, y3;
    printf("Enter coordinates of three points:\n");
    scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);
    
    // Calculate distances between each pair of points
    float a = distance(x1, y1, x2, y2);
    float b = distance(x2, y2, x3, y3);
    float c = distance(x3, y3, x1, y1);
    
    // Calculate perimeter and area using Heron's formula
    float p = perimeter(a, b, c);
    float s = p/2.0;
    float A = area(a, b, c, s);
    
    // Output results
    printf("Perimeter = %.2f\n", p);
    printf("Area = %.2f\n", A);
    
    return 0;
}

// Calculate distance between two points
float distance(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

// Calculate perimeter of triangle
float perimeter(float a, float b, float c)
{
    return a + b + c;
}

// Calculate area of triangle using Heron's formula
float area(float a, float b, float c, float s)
{
    return sqrt(s*(s-a)*(s-b)*(s-c));
}