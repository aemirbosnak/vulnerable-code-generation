//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: shape shifting
#include <stdio.h>

#define MAX_SIZE 100

// Function prototypes
void displayMenu();
void performAddition();
void performSubtraction();
void performMultiplication();
void performDivision();
void performModulus();
void calculateCircleArea();
void calculateRectangleArea();
void calculateTriangleArea();

int main() {
    int choice;

    printf("Shape Shifting Arithmetic Program\n");
    do {
        displayMenu();
        printf("Enter your choice (1-9, 0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            case 1:
                performAddition();
                break;
            case 2:
                performSubtraction();
                break;
            case 3:
                performMultiplication();
                break;
            case 4:
                performDivision();
                break;
            case 5:
                performModulus();
                break;
            case 6:
                calculateCircleArea();
                break;
            case 7:
                calculateRectangleArea();
                break;
            case 8:
                calculateTriangleArea();
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

        printf("\n");

    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Calculate Area of Circle\n");
    printf("7. Calculate Area of Rectangle\n");
    printf("8. Calculate Area of Triangle\n");
    printf("0. Exit\n");
}

void performAddition() {
    int a, b;
    printf("Enter two numbers for addition: ");
    scanf("%d %d", &a, &b);
    printf("Result: %d + %d = %d\n", a, b, a + b);
}

void performSubtraction() {
    int a, b;
    printf("Enter two numbers for subtraction: ");
    scanf("%d %d", &a, &b);
    printf("Result: %d - %d = %d\n", a, b, a - b);
}

void performMultiplication() {
    int a, b;
    printf("Enter two numbers for multiplication: ");
    scanf("%d %d", &a, &b);
    printf("Result: %d * %d = %d\n", a, b, a * b);
}

void performDivision() {
    float a, b;
    printf("Enter two numbers for division: ");
    scanf("%f %f", &a, &b);
    if (b != 0) {
        printf("Result: %.2f / %.2f = %.2f\n", a, b, a / b);
    } else {
        printf("Error: Division by zero is not allowed.\n");
    }
}

void performModulus() {
    int a, b;
    printf("Enter two integers for modulus: ");
    scanf("%d %d", &a, &b);
    if (b != 0) {
        printf("Result: %d %% %d = %d\n", a, b, a % b);
    } else {
        printf("Error: Division by zero is not allowed.\n");
    }
}

void calculateCircleArea() {
    float radius, area;
    const float pi = 3.14159;
    printf("Enter radius of the circle: ");
    scanf("%f", &radius);
    area = pi * radius * radius;
    printf("Area of the circle with radius %.2f is %.2f\n", radius, area);
}

void calculateRectangleArea() {
    float length, width, area;
    printf("Enter length and width of the rectangle: ");
    scanf("%f %f", &length, &width);
    area = length * width;
    printf("Area of the rectangle with length %.2f and width %.2f is %.2f\n", length, width, area);
}

void calculateTriangleArea() {
    float base, height, area;
    printf("Enter base and height of the triangle: ");
    scanf("%f %f", &base, &height);
    area = 0.5 * base * height;
    printf("Area of the triangle with base %.2f and height %.2f is %.2f\n", base, height, area);
}