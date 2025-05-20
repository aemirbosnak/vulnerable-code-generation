//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: unmistakable
#include <stdio.h>
#include <math.h>

// function to calculate distance between two points
float distance(float x1, float y1, float x2, float y2)
{
    float dist = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    return dist;
}

// function to calculate area of a rectangle
float rectangle_area(float length, float breadth)
{
    float area = length * breadth;
    return area;
}

// function to calculate area of a triangle
float triangle_area(float base, float height)
{
    float area = (base * height)/2;
    return area;
}

int main()
{
    // coordinates of four points
    float x1, y1, x2, y2, x3, y3, x4, y4;

    printf("Enter x-coordinate of first point: ");
    scanf("%f", &x1);
    printf("Enter y-coordinate of first point: ");
    scanf("%f", &y1);
    printf("Enter x-coordinate of second point: ");
    scanf("%f", &x2);
    printf("Enter y-coordinate of second point: ");
    scanf("%f", &y2);
    printf("Enter x-coordinate of third point: ");
    scanf("%f", &x3);
    printf("Enter y-coordinate of third point: ");
    scanf("%f", &y3);
    printf("Enter x-coordinate of fourth point: ");
    scanf("%f", &x4);
    printf("Enter y-coordinate of fourth point: ");
    scanf("%f", &y4);

    // distance between two points
    float dist1 = distance(x1, y1, x2, y2);
    float dist2 = distance(x2, y2, x3, y3);
    float dist3 = distance(x3, y3, x4, y4);
    float dist4 = distance(x4, y4, x1, y1);

    // checking if it is a rectangle
    if(dist1==dist3 && dist2==dist4)
    {
        printf("It is a rectangle.\n");

        // area of rectangle
        float area_rect = rectangle_area(dist1, dist2);
        printf("Area of the rectangle is %.2f sq units.\n", area_rect);

        // perimeter of rectangle
        float perimeter_rect = 2 * (dist1 + dist2);
        printf("Perimeter of the rectangle is %.2f units.\n", perimeter_rect);
    }

    // checking if it is a triangle
    else if(dist1==dist2 && dist2==dist3 && dist3==dist4)
    {
        printf("It is a square.\n");

        // area of square
        float area_square = dist1 * dist2;
        printf("Area of the square is %.2f sq units.\n", area_square);

        // perimeter of square
        float perimeter_square = 4 * dist1;
        printf("Perimeter of the square is %.2f units.\n", perimeter_square);
    }

    // if neither, then it is none of the above
    else
        printf("It is neither a rectangle nor a square.\n");

    return 0;
}