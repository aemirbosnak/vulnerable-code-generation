//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include <stdio.h>
#include <math.h>

// Function prototypes
float calculateCircleArea(float radius);
float calculateRectangleArea(float length, float width);
float calculateTriangleArea(float base, float height);
void displayMenu();

int main() {
    int choice;
    float radius, length, width, base, height;
    
    while (1) {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("You chose Circle.\n");
                printf("Enter the radius of the circle: ");
                scanf("%f", &radius);
                printf("The area of the circle is: %.2f\n", calculateCircleArea(radius));
                break;
                
            case 2:
                printf("You chose Rectangle.\n");
                printf("Enter the length and width of the rectangle: ");
                scanf("%f %f", &length, &width);
                printf("The area of the rectangle is: %.2f\n", calculateRectangleArea(length, width));
                break;
                
            case 3:
                printf("You chose Triangle.\n");
                printf("Enter the base and height of the triangle: ");
                scanf("%f %f", &base, &height);
                printf("The area of the triangle is: %.2f\n", calculateTriangleArea(base, height));
                break;
                
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }

        printf("\n"); // New line for better readability
    }

    return 0;
}

void displayMenu() {
    printf("---------- Area Calculator ----------\n");
    printf("1. Calculate area of a Circle\n");
    printf("2. Calculate area of a Rectangle\n");
    printf("3. Calculate area of a Triangle\n");
    printf("4. Exit\n");
    printf("-------------------------------------\n");
}

float calculateCircleArea(float radius) {
    return M_PI * radius * radius; // Area = π * r²
}

float calculateRectangleArea(float length, float width) {
    return length * width; // Area = length * width
}

float calculateTriangleArea(float base, float height) {
    return 0.5 * base * height; // Area = 0.5 * base * height
}