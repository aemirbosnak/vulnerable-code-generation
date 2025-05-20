//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayMenu();
void performAddition();
void performSubtraction();
void performMultiplication();
void performDivision();
void performModulus();
void performSquare();
void performCube();

int main() {
    int choice;

    // Seed the random number generator
    srand(time(0));

    do {
        displayMenu();
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
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
                performSquare();
                break;
            case 7:
                performCube();
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("******* Arithmetic Operations Menu *******\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Square of a number\n");
    printf("7. Cube of a number\n");
    printf("0. Exit\n");
    printf("*********************************************\n");
}

void performAddition() {
    int a, b, sum;

    printf("Enter two integers for addition:\n");
    scanf("%d %d", &a, &b);
    sum = a + b;
    printf("The sum of %d and %d is: %d\n", a, b, sum);
}

void performSubtraction() {
    int a, b, difference;

    printf("Enter two integers for subtraction:\n");
    scanf("%d %d", &a, &b);
    difference = a - b;
    printf("The difference between %d and %d is: %d\n", a, b, difference);
}

void performMultiplication() {
    int a, b, product;

    printf("Enter two integers for multiplication:\n");
    scanf("%d %d", &a, &b);
    product = a * b;
    printf("The product of %d and %d is: %d\n", a, b, product);
}

void performDivision() {
    float a, b, quotient;

    printf("Enter two numbers for division:\n");
    scanf("%f %f", &a, &b);
    if (b != 0) {
        quotient = a / b;
        printf("The quotient of %.2f and %.2f is: %.2f\n", a, b, quotient);
    } else {
        printf("Error: Division by zero is not allowed.\n");
    }
}

void performModulus() {
    int a, b, remainder;

    printf("Enter two integers for modulus:\n");
    scanf("%d %d", &a, &b);
    if (b != 0) {
        remainder = a % b;
        printf("The modulus of %d and %d is: %d\n", a, b, remainder);
    } else {
        printf("Error: Division by zero is not allowed.\n");
    }
}

void performSquare() {
    int a, square;

    printf("Enter an integer to find its square:\n");
    scanf("%d", &a);
    square = a * a;
    printf("The square of %d is: %d\n", a, square);
}

void performCube() {
    int a, cube;

    printf("Enter an integer to find its cube:\n");
    scanf("%d", &a);
    cube = a * a * a;
    printf("The cube of %d is: %d\n", a, cube);
}