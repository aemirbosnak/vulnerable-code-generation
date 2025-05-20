//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: accurate
#include <stdio.h>

// Function prototypes
void add(int a, int b);
void subtract(int a, int b);
void multiply(int a, int b);
void divide(int a, int b);
void calculateCircleArea(float radius);
void calculateRectangleArea(float length, float width);

int main() {
    int num1, num2, operation;
    float radius, length, width;

    printf("Welcome to the C Arithmetic Program\n");
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Calculate Circle Area\n");
    printf("6. Calculate Rectangle Area\n");
    printf("Please enter your choice (1-6): ");
    scanf("%d", &operation);

    switch (operation) {
        case 1:
            printf("Enter two integers for addition: ");
            scanf("%d %d", &num1, &num2);
            add(num1, num2);
            break;
        case 2:
            printf("Enter two integers for subtraction: ");
            scanf("%d %d", &num1, &num2);
            subtract(num1, num2);
            break;
        case 3:
            printf("Enter two integers for multiplication: ");
            scanf("%d %d", &num1, &num2);
            multiply(num1, num2);
            break;
        case 4:
            printf("Enter two integers for division: ");
            scanf("%d %d", &num1, &num2);
            if (num2 != 0) {
                divide(num1, num2);
            } else {
                printf("Error: Division by zero is undefined.\n");
            }
            break;
        case 5:
            printf("Enter radius of the circle: ");
            scanf("%f", &radius);
            calculateCircleArea(radius);
            break;
        case 6:
            printf("Enter length and width of the rectangle: ");
            scanf("%f %f", &length, &width);
            calculateRectangleArea(length, width);
            break;
        default:
            printf("Invalid operation selected. Please try again.\n");
            break;
    }

    printf("Thank you for using the C Arithmetic Program!\n");
    return 0;
}

void add(int a, int b) {
    printf("Result of Addition: %d + %d = %d\n", a, b, a + b);
}

void subtract(int a, int b) {
    printf("Result of Subtraction: %d - %d = %d\n", a, b, a - b);
}

void multiply(int a, int b) {
    printf("Result of Multiplication: %d * %d = %d\n", a, b, a * b);
}

void divide(int a, int b) {
    printf("Result of Division: %d / %d = %.2f\n", a, b, (float)a / b);
}

void calculateCircleArea(float radius) {
    const float pi = 3.14159;
    float area = pi * radius * radius;
    printf("Area of the circle with radius %.2f: %.2f\n", radius, area);
}

void calculateRectangleArea(float length, float width) {
    float area = length * width;
    printf("Area of the rectangle with length %.2f and width %.2f: %.2f\n", length, width, area);
}