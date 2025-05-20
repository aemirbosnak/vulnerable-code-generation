//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void add(int a, int b);
void subtract(int a, int b);
void multiply(int a, int b);
void divide(int a, int b);

int main() {
    int choice;
    printf("Welcome to the Calculator Plugin!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    switch(choice) {
        case 1:
            add(num1, num2);
            break;
        case 2:
            subtract(num1, num2);
            break;
        case 3:
            multiply(num1, num2);
            break;
        case 4:
            divide(num1, num2);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

// Function definitions
void add(int a, int b) {
    printf("The sum of %d and %d is %d.\n", a, b, a+b);
}

void subtract(int a, int b) {
    printf("The difference between %d and %d is %d.\n", a, b, a-b);
}

void multiply(int a, int b) {
    printf("The product of %d and %d is %d.\n", a, b, a*b);
}

void divide(int a, int b) {
    if(b == 0) {
        printf("Cannot divide by zero!\n");
    } else {
        printf("The quotient of %d and %d is %d.\n", a, b, a/b);
    }
}