//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: introspective
#include <stdio.h>
#include <math.h>

void computeCircle(double radius) {
    double area = M_PI * radius * radius;
    double perimeter = 2 * M_PI * radius;
    printf("For a Circle with radius %.2f:\n", radius);
    printf(" - Area: %.2f\n", area);
    printf(" - Perimeter (Circumference): %.2f\n", perimeter);
}

void computeRectangle(double length, double width) {
    double area = length * width;
    double perimeter = 2 * (length + width);
    printf("For a Rectangle with length %.2f and width %.2f:\n", length, width);
    printf(" - Area: %.2f\n", area);
    printf(" - Perimeter: %.2f\n", perimeter);
}

void computeTriangle(double base, double height, double side1, double side2) {
    double area = (base * height) / 2;
    double perimeter = base + side1 + side2;
    printf("For a Triangle with base %.2f, height %.2f, side1 %.2f and side2 %.2f:\n", base, height, side1, side2);
    printf(" - Area: %.2f\n", area);
    printf(" - Perimeter: %.2f\n", perimeter);
}

int main() {
    int choice;
    double radius, length, width, base, height, side1, side2;
   
    while(1) {
        printf("\nWelcome to the Geometry Calculator!\n");
        printf("1. Calculate Circle Area and Perimeter\n");
        printf("2. Calculate Rectangle Area and Perimeter\n");
        printf("3. Calculate Triangle Area and Perimeter\n");
        printf("4. Exit\n");
        printf("Please enter your choice (1-4): ");
        
        // Check if input is valid
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch(choice) {
            case 1:
                printf("Enter the radius of the circle: ");
                if (scanf("%lf", &radius) != 1 || radius < 0) {
                    printf("Invalid input. Radius must be a positive number.\n");
                    while(getchar() != '\n'); // Clear the input buffer
                    continue;
                }
                computeCircle(radius);
                break;

            case 2:
                printf("Enter the length of the rectangle: ");
                if (scanf("%lf", &length) != 1 || length < 0) {
                    printf("Invalid input. Length must be a positive number.\n");
                    while(getchar() != '\n');
                    continue;
                }
                printf("Enter the width of the rectangle: ");
                if (scanf("%lf", &width) != 1 || width < 0) {
                    printf("Invalid input. Width must be a positive number.\n");
                    while(getchar() != '\n');
                    continue;
                }
                computeRectangle(length, width);
                break;

            case 3:
                printf("Enter the base of the triangle: ");
                if (scanf("%lf", &base) != 1 || base < 0) {
                    printf("Invalid input. Base must be a positive number.\n");
                    while(getchar() != '\n');
                    continue;
                }
                printf("Enter the height of the triangle: ");
                if (scanf("%lf", &height) != 1 || height < 0) {
                    printf("Invalid input. Height must be a positive number.\n");
                    while(getchar() != '\n');
                    continue;
                }
                printf("Enter the first side of the triangle: ");
                if (scanf("%lf", &side1) != 1 || side1 < 0) {
                    printf("Invalid input. Sides must be positive numbers.\n");
                    while(getchar() != '\n');
                    continue;
                }
                printf("Enter the second side of the triangle: ");
                if (scanf("%lf", &side2) != 1 || side2 < 0) {
                    printf("Invalid input. Sides must be positive numbers.\n");
                    while(getchar() != '\n');
                    continue;
                }
                computeTriangle(base, height, side1, side2);
                break;

            case 4:
                printf("Thank you for using the Geometry Calculator. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please select a number between 1 and 4.\n");
        }
    }
    
    return 0; // This return statement is not strictly necessary, as the program will exit naturally
}