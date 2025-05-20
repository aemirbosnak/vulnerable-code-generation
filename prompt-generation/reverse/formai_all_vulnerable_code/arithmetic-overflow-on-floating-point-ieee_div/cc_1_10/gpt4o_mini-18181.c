//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void displayMenu();
void performArithmeticOperations();
void calculateArea();
void calculateSquareArea();
void calculateCircleArea();
void calculateTriangleArea();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                performArithmeticOperations();
                break;
            case 2:
                calculateArea();
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

    } while (choice != 3);

    return 0;
}

void displayMenu() {
    printf("\n--- Arithmetic Program Menu ---\n");
    printf("1. Perform Arithmetic Operations\n");
    printf("2. Calculate Area of Shapes\n");
    printf("3. Exit\n");
}

void performArithmeticOperations() {
    double number1, number2;
    char operator;

    printf("Enter first number: ");
    scanf("%lf", &number1);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter second number: ");
    scanf("%lf", &number2);

    switch(operator) {
        case '+':
            printf("Result: %.2lf + %.2lf = %.2lf\n", number1, number2, number1 + number2);
            break;
        case '-':
            printf("Result: %.2lf - %.2lf = %.2lf\n", number1, number2, number1 - number2);
            break;
        case '*':
            printf("Result: %.2lf * %.2lf = %.2lf\n", number1, number2, number1 * number2);
            break;
        case '/':
            if (number2 != 0) {
                printf("Result: %.2lf / %.2lf = %.2lf\n", number1, number2, number1 / number2);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Invalid operator.\n");
            break;
    }
}

void calculateArea() {
    int shapeChoice;

    printf("\nChoose a shape to calculate the area:\n");
    printf("1. Square\n");
    printf("2. Circle\n");
    printf("3. Triangle\n");
    printf("Enter your choice: ");
    scanf("%d", &shapeChoice);

    switch(shapeChoice) {
        case 1:
            calculateSquareArea();
            break;
        case 2:
            calculateCircleArea();
            break;
        case 3:
            calculateTriangleArea();
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

void calculateSquareArea() {
    double side, area;
    printf("Enter the length of a side of the square: ");
    scanf("%lf", &side);
    area = side * side;
    printf("The area of the square is: %.2lf\n", area);
}

void calculateCircleArea() {
    double radius, area;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    area = M_PI * radius * radius;
    printf("The area of the circle is: %.2lf\n", area);
}

void calculateTriangleArea() {
    double base, height, area;
    printf("Enter the base of the triangle: ");
    scanf("%lf", &base);
    printf("Enter the height of the triangle: ");
    scanf("%lf", &height);
    area = 0.5 * base * height;
    printf("The area of the triangle is: %.2lf\n", area);
}