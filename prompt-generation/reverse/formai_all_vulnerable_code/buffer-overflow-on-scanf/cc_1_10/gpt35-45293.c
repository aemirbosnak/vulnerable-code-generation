//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multivariable
#include<stdio.h>

//Function to calculate area of a rectangle
float rect_area(float length, float breadth) {
    return length * breadth;
}

//Function to calculate area of a circle
float circle_area(float radius) {
    return 3.14 * radius * radius;
}

//Function to calculate area of a triangle
float triangle_area(float base, float height) {
    return 0.5 * base * height;
}

int main() {
    int choice;
    float area, length, breadth, radius, base, height;
    printf("Choose the shape for which you want to calculate area:\n");
    printf("1. Rectangle\n");
    printf("2. Circle\n");
    printf("3. Triangle\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter length and breadth of the rectangle:\n");
            scanf("%f %f", &length, &breadth);
            area = rect_area(length, breadth);
            printf("Area of the rectangle is %f\n", area);
            break;
        case 2:
            printf("Enter radius of the circle:\n");
            scanf("%f", &radius);
            area = circle_area(radius);
            printf("Area of the circle is %f\n", area);
            break;
        case 3:
            printf("Enter base and height of the triangle:\n");
            scanf("%f %f", &base, &height);
            area = triangle_area(base, height);
            printf("Area of the triangle is %f\n", area);
            break;
        default:
            printf("Invalid input\n");
            break;
    }
    return 0;
}