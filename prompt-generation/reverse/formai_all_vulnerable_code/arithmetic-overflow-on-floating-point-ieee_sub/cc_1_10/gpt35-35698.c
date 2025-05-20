//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include<stdio.h>
#include<math.h>

#define PI 3.141592653589

// Function to find the distance between two points in 2D space
double find_distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Function to find the area of a circle given the radius
double find_circle_area(double radius) {
    return PI * radius * radius;
}

// Function to find the area of a triangle given its three sides
double find_triangle_area(double side1, double side2, double side3) {
    double s = (side1 + side2 + side3) / 2.0;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

// Main function
int main() {
    double x1, y1, x2, y2, radius, side1, side2, side3;
    
    // Get input values from the user
    printf("Enter the x and y coordinates of point 1: ");
    scanf("%lf %lf", &x1, &y1);
    
    printf("Enter the x and y coordinates of point 2: ");
    scanf("%lf %lf", &x2, &y2);
    
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    
    printf("Enter the length of side 1 of the triangle: ");
    scanf("%lf", &side1);
    
    printf("Enter the length of side 2 of the triangle: ");
    scanf("%lf", &side2);
    
    printf("Enter the length of side 3 of the triangle: ");
    scanf("%lf", &side3);
    
    // Find the distance between the two points
    double distance = find_distance(x1, y1, x2, y2);
    printf("\nThe distance between the two points is: %lf\n", distance);
    
    // Find the area of the circle
    double circle_area = find_circle_area(radius);
    printf("\nThe area of the circle is: %lf\n", circle_area);
    
    // Find the area of the triangle
    double triangle_area = find_triangle_area(side1, side2, side3);
    printf("\nThe area of the triangle is: %lf\n", triangle_area);
    
    return 0;
}