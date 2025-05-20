//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// Constants
#define MAX_SIZE 100

// Function to get a valid integer from the user
int getInteger(char *prompt) {
    int number;
    char input[MAX_SIZE];

    // Keep prompting the user until a valid integer is entered
    do {
        printf("%s", prompt);
        scanf("%s", input);
    } while (! (strcmp(input, "1") == 0 
                    || strcmp(input, "2") == 0
                    || strcmp(input, "3") == 0
                    || strcmp(input, "4") == 0));        

    number = atoi(input);
    return number;
}

// Function to calculate the area of a circle
double calculateCircleArea(double radius) {
    double area;

    area = M_PI * radius * radius;
    return area;
}

// Function to calculate the area of a square
double calculateSquareArea(double side) {
    double area;

    area = side * side;
    return area;
}

// Function to calculate the area of a triangle
double calculateTriangleArea(double base, double height) {
    double area;

    area = 0.5 * base * height;
    return area;
}

// Main function
int main() {
    int choice;
    double radius, side, base, height, area;

    // Display a menu of options to the user
    printf("Please select an option:\n");
    printf("1. Calculate the area of a circle\n");
    printf("2. Calculate the area of a square\n");
    printf("3. Calculate the area of a triangle\n");
    printf("4. Quit\n");

    // Get the user's choice
    choice = getInteger("Enter your choice: ");

    // Calculate the area based on the user's choice
    switch (choice) {
        case 1:
            printf("Enter the radius of the circle: ");
            scanf("%lf", &radius);
            area = calculateCircleArea(radius);
            printf("The area of the circle is: %lf\n", area);
            break;
        case 2:
            printf("Enter the side length of the square: ");
            scanf("%lf", &side);
            area = calculateSquareArea(side);
            printf("The area of the square is: %lf\n", area);
            break;
        case 3:
            printf("Enter the base of the triangle: ");
            scanf("%lf", &base);
            printf("Enter the height of the triangle: ");
            scanf("%lf", &height);
            area = calculateTriangleArea(base, height);
            printf("The area of the triangle is: %lf\n", area);
            break;
        case 4:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
    }

    return 0;
}