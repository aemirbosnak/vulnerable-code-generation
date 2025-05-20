//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random shape
char* generateRandomShape() {
    srand(time(0));
    int randomNum = rand() % 5;
    switch(randomNum) {
        case 0:
            return "circle";
        case 1:
            return "square";
        case 2:
            return "rectangle";
        case 3:
            return "triangle";
        case 4:
            return "pentagon";
        default:
            return "";
    }
}

// Function to calculate area of circle
double calculateCircleArea(double radius) {
    return 3.14 * radius * radius;
}

// Function to calculate area of square
double calculateSquareArea(double side) {
    return side * side;
}

// Function to calculate area of rectangle
double calculateRectangleArea(double length, double breadth) {
    return length * breadth;
}

// Function to calculate area of triangle
double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

// Function to calculate area of pentagon
double calculatePentagonArea(double side) {
    double apothem = side / (2 * tan(36));
    double perimeter = side * 5;
    return 0.5 * apothem * perimeter;
}

int main() {
    char* shape = generateRandomShape();
    double area;
    printf("Welcome to the shape shifting program! Your randomly generated shape is a %s.\n", shape);
    if(strcmp(shape, "circle") == 0) {
        double radius;
        printf("Please enter the radius of the circle: ");
        scanf("%lf", &radius);
        area = calculateCircleArea(radius);
        printf("The area of the circle is: %lf\n", area);
    }
    else if(strcmp(shape, "square") == 0) {
        double side;
        printf("Please enter the length of one side of the square: ");
        scanf("%lf", &side);
        area = calculateSquareArea(side);
        printf("The area of the square is: %lf\n", area);
    }
    else if(strcmp(shape, "rectangle") == 0) {
        double length, breadth;
        printf("Please enter the length and breadth of the rectangle: ");
        scanf("%lf %lf", &length, &breadth);
        area = calculateRectangleArea(length, breadth);
        printf("The area of the rectangle is: %lf\n", area);
    }
    else if(strcmp(shape, "triangle") == 0) {
        double base, height;
        printf("Please enter the base and height of the triangle: ");
        scanf("%lf %lf", &base, &height);
        area = calculateTriangleArea(base, height);
        printf("The area of the triangle is: %lf\n", area);
    }
    else if(strcmp(shape, "pentagon") == 0) {
        double side;
        printf("Please enter the length of one side of the pentagon: ");
        scanf("%lf", &side);
        area = calculatePentagonArea(side);
        printf("The area of the pentagon is: %lf\n", area);
    }
    else {
        printf("Invalid shape generated.\n");
    }
    return 0;
}