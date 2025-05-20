//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: relaxed
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a rectangle
float calculateRectangleArea(float width, float height) {
    return width * height;
}

// Function to calculate the area of a circle
float calculateCircleArea(float radius) {
    return M_PI * radius * radius;
}

// Function to calculate the area of a triangle
float calculateTriangleArea(float base, float height) {
    return 0.5 * base * height;
}

// Main function
int main() {
    int choice;
    float area;

    // Display options to the user
    printf("Welcome to the Geometric Area Calculator!\n");
    printf("Please choose a shape to calculate the area:\n");
    printf("1. Rectangle\n");
    printf("2. Circle\n");
    printf("3. Triangle\n");
    printf("Enter your choice (1-3): ");
    
    // Get user choice
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            float width, height;
            printf("You chose Rectangle. Enter width: ");
            scanf("%f", &width);
            printf("Enter height: ");
            scanf("%f", &height);
            area = calculateRectangleArea(width, height);
            printf("The area of the rectangle is: %.2f\n", area);
            break;
        }
        case 2: {
            float radius;
            printf("You chose Circle. Enter radius: ");
            scanf("%f", &radius);
            area = calculateCircleArea(radius);
            printf("The area of the circle is: %.2f\n", area);
            break;
        }
        case 3: {
            float base, height;
            printf("You chose Triangle. Enter base: ");
            scanf("%f", &base);
            printf("Enter height: ");
            scanf("%f", &height);
            area = calculateTriangleArea(base, height);
            printf("The area of the triangle is: %.2f\n", area);
            break;
        }
        default:
            printf("Invalid choice! Please run the program again and select a valid option.\n");
    }

    printf("Thank you for using the Geometric Area Calculator! Goodbye!\n");
    return 0;
}