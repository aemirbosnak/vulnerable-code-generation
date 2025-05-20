//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include <stdio.h>

// Function to calculate the area of a square
void squareArea(int sideLength) {
    int area = sideLength * sideLength;
    printf("The area of the square is: %d\n", area);
}

// Function to calculate the area of a circle
void circleArea(int radius) {
    float pi = 3.14;
    float area = pi * radius * radius;
    printf("The area of the circle is: %.2f\n", area);
}

int main() {
    printf("Welcome to the geometry calculator!\n");

    // Ask the user which shape they want to calculate the area of
    printf("Which shape do you want to calculate the area of? Enter '1' for a square or '2' for a circle: ");
    int shapeChoice;
    scanf("%d", &shapeChoice);

    // Calculate the area of the chosen shape
    switch (shapeChoice) {
        case 1:
            // Ask the user for the side length of the square 
            printf("What is the length of the side of the square? ");
            int sideLength;
            scanf("%d", &sideLength);

            // Call the squareArea function to calculate the area of the square
            squareArea(sideLength);
            break;
        
        case 2:
            // Ask the user for the radius of the circle 
            printf("What is the radius of the circle? ");
            int radius;
            scanf("%d", &radius);

            // Call the circleArea function to calculate the area of the circle
            circleArea(radius);
            break;
        
        default:
            printf("Invalid input. Please enter '1' for a square or '2' for a circle.\n");
            break;
    }

    printf("Thank you for using the geometry calculator!\n");

    return 0;
}