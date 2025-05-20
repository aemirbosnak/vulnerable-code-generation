//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayWelcomeMessage() {
    printf("🎉 Welcome to the Cheerful Area Calculator! 🎉\n");
    printf("Let's calculate the area of your favorite geometric shapes! 💖\n");
    printf("----------------------------------------------------\n");
}

void showMenu() {
    printf("Please select a shape to calculate the area:\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
}

double calculateCircleArea(double radius) {
    return M_PI * radius * radius;
}

double calculateRectangleArea(double length, double width) {
    return length * width;
}

double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

void processInput(int choice) {
    if (choice == 1) {
        double radius;
        printf("Enter the radius of the circle: ");
        scanf("%lf", &radius);
        printf("The area of the circle with radius %.2lf is: %.2lf\n", radius, calculateCircleArea(radius));
    } else if (choice == 2) {
        double length, width;
        printf("Enter the length of the rectangle: ");
        scanf("%lf", &length);
        printf("Enter the width of the rectangle: ");
        scanf("%lf", &width);
        printf("The area of the rectangle with length %.2lf and width %.2lf is: %.2lf\n", 
               length, width, calculateRectangleArea(length, width));
    } else if (choice == 3) {
        double base, height;
        printf("Enter the base of the triangle: ");
        scanf("%lf", &base);
        printf("Enter the height of the triangle: ");
        scanf("%lf", &height);
        printf("The area of the triangle with base %.2lf and height %.2lf is: %.2lf\n", 
               base, height, calculateTriangleArea(base, height));
    } else if (choice == 4) {
        printf("Thank you for using the Cheerful Area Calculator! Goodbye! 🌈\n");
        exit(0);
    } else {
        printf("😮 Oops! That's not a valid choice. Please try again!\n");
    }
}

int main() {
    int choice;
    
    displayWelcomeMessage();
    
    while (1) {
        showMenu();
        scanf("%d", &choice);
        processInput(choice);
        printf("\n----------------------------------------------\n");
    }
    
    return 0;
}