//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: grateful
#include <stdio.h>
#include <math.h>

// Function declarations
float calculateCircleArea(float radius);
float calculateRectangleArea(float length, float width);
float calculateTriangleArea(float base, float height);

int main() {
    int choice;
    printf("Welcome to the Geometry Calculating Program!\n");
    printf("We are grateful for the beauty of shapes and their areas!\n");
    printf("Please choose a geometric shape to calculate its area:\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("Enter your choice (1-3): ");
    
    // Reading user input
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            float radius;
            printf("Please enter the radius of the circle: ");
            scanf("%f", &radius);
            
            // Area calculation
            float circleArea = calculateCircleArea(radius);
            printf("The area of the circle with radius %.2f is: %.2f\n", radius, circleArea);
            break;
        }
        case 2: {
            float length, width;
            printf("Please enter the length and width of the rectangle: ");
            scanf("%f %f", &length, &width);
            
            // Area calculation
            float rectangleArea = calculateRectangleArea(length, width);
            printf("The area of the rectangle with length %.2f and width %.2f is: %.2f\n", length, width, rectangleArea);
            break;
        }
        case 3: {
            float base, height;
            printf("Please enter the base and height of the triangle: ");
            scanf("%f %f", &base, &height);
            
            // Area calculation
            float triangleArea = calculateTriangleArea(base, height);
            printf("The area of the triangle with base %.2f and height %.2f is: %.2f\n", base, height, triangleArea);
            break;
        }
        default:
            printf("Thank you for visiting, please select a valid option next time!\n");
            break;
    }

    printf("We appreciate your curiosity in exploring the world of shapes. Have a wonderful day!\n");
    return 0;
}

// Function to calculate the area of a circle
float calculateCircleArea(float radius) {
    return M_PI * radius * radius;  // Area = π * r^2
}

// Function to calculate the area of a rectangle
float calculateRectangleArea(float length, float width) {
    return length * width;  // Area = length * width
}

// Function to calculate the area of a triangle
float calculateTriangleArea(float base, float height) {
    return (base * height) / 2;  // Area = (base * height) / 2
}