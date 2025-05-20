//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include <stdio.h>
#include <math.h>

// Function declarations
void displayWelcomeMessage();
void calculateTriangleArea();
void calculateRectangleArea();
void calculateCircleArea();
void displayGoodbyeMessage();

int main() {
    int choice;

    displayWelcomeMessage();

    while (1) {
        // Menu for the user
        printf("Choose a shape to explore:\n");
        printf("1. Triangle\n");
        printf("2. Rectangle\n");
        printf("3. Circle\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculateTriangleArea();
                break;
            case 2:
                calculateRectangleArea();
                break;
            case 3:
                calculateCircleArea();
                break;
            case 4:
                displayGoodbyeMessage();
                return 0; // Exit the program
            default:
                printf("Invalid choice, please try again.\n");
        }
        printf("\n"); // New line for better readability
    }

    return 0;
}

void displayWelcomeMessage() {
    printf("************************\n");
    printf("*  Welcome to Geometry  *\n");
    printf("************************\n");
    printf("Explore the wonders of shapes and their areas!\n");
}

void calculateTriangleArea() {
    float base, height, area;
    printf("You chose Triangle!\n");

    // User inputs for triangle dimensions
    printf("Enter base length: ");
    scanf("%f", &base);
    printf("Enter height length: ");
    scanf("%f", &height);

    area = (base * height) / 2;
    printf("The area of the triangle is: %.2f\n", area);
}

void calculateRectangleArea() {
    float length, width, area;
    printf("You chose Rectangle!\n");

    // User inputs for rectangle dimensions
    printf("Enter length: ");
    scanf("%f", &length);
    printf("Enter width: ");
    scanf("%f", &width);

    area = length * width;
    printf("The area of the rectangle is: %.2f\n", area);
}

void calculateCircleArea() {
    float radius, area;
    const float pi = 3.14159;
    
    printf("You chose Circle!\n");

    // User input for circle radius
    printf("Enter radius: ");
    scanf("%f", &radius);

    area = pi * radius * radius;
    printf("The area of the circle is: %.2f\n", area);
}

void displayGoodbyeMessage() {
    printf("Thank you for exploring geometry with us!\n");
    printf("Goodbye and keep exploring!\n");
    printf("*******************************\n");
}