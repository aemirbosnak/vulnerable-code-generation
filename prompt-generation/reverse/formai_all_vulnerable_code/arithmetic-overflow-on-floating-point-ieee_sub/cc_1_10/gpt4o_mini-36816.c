//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Structure for a 2D Point
typedef struct {
    float x;
    float y;
} Point;

// Structure for a Circle
typedef struct {
    Point center;
    float radius;
} Circle;

// Structure for a Rectangle
typedef struct {
    Point topLeft;
    Point bottomRight;
} Rectangle;

// Function to create a new Circle
Circle* createCircle(float x, float y, float radius) {
    Circle* circle = (Circle*)malloc(sizeof(Circle));
    circle->center.x = x;
    circle->center.y = y;
    circle->radius = radius;
    return circle;
}

// Function to create a new Rectangle
Rectangle* createRectangle(float x1, float y1, float x2, float y2) {
    Rectangle* rect = (Rectangle*)malloc(sizeof(Rectangle));
    rect->topLeft.x = x1;
    rect->topLeft.y = y1;
    rect->bottomRight.x = x2;
    rect->bottomRight.y = y2;
    return rect;
}

// Function to display Circle characteristics
void displayCircle(Circle* circle) {
    printf("Circle:\n");
    printf("  Center: (%.2f, %.2f)\n", circle->center.x, circle->center.y);
    printf("  Radius: %.2f\n", circle->radius);
}

// Function to display Rectangle characteristics
void displayRectangle(Rectangle* rect) {
    printf("Rectangle:\n");
    printf("  Top Left: (%.2f, %.2f)\n", rect->topLeft.x, rect->topLeft.y);
    printf("  Bottom Right: (%.2f, %.2f)\n", rect->bottomRight.x, rect->bottomRight.y);
}

// Function to calculate the area of a Circle
float calculateCircleArea(Circle* circle) {
    return 3.14159 * circle->radius * circle->radius;
}

// Function to calculate the area of a Rectangle
float calculateRectangleArea(Rectangle* rect) {
    float width = rect->bottomRight.x - rect->topLeft.x;
    float height = rect->topLeft.y - rect->bottomRight.y;
    return width * height;
}

// Function to free Circle memory
void freeCircle(Circle* circle) {
    free(circle);
}

// Function to free Rectangle memory
void freeRectangle(Rectangle* rect) {
    free(rect);
}

// Main function to demonstrate the functionality
int main() {
    float circleX, circleY, circleR;
    printf("Enter Circle Center (x y) and Radius: ");
    scanf("%f %f %f", &circleX, &circleY, &circleR);

    Circle* myCircle = createCircle(circleX, circleY, circleR);
    displayCircle(myCircle);
    printf("Area of the Circle: %.2f\n", calculateCircleArea(myCircle));

    float rectX1, rectY1, rectX2, rectY2;
    printf("Enter Rectangle Top Left (x1 y1) and Bottom Right (x2 y2): ");
    scanf("%f %f %f %f", &rectX1, &rectY1, &rectX2, &rectY2);

    Rectangle* myRectangle = createRectangle(rectX1, rectY1, rectX2, rectY2);
    displayRectangle(myRectangle);
    printf("Area of the Rectangle: %.2f\n", calculateRectangleArea(myRectangle));

    // Cleanup
    freeCircle(myCircle);
    freeRectangle(myRectangle);

    return 0;
}