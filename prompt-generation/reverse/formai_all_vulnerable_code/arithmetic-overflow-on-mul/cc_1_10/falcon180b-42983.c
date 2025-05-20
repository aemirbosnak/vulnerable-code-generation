//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform arithmetic operations
void arithmetic(int a, int b, char operation) {
    int result;
    switch(operation) {
        case '+':
            result = a + b;
            printf("Result: %d\n", result);
            break;
        case '-':
            result = a - b;
            printf("Result: %d\n", result);
            break;
        case '*':
            result = a * b;
            printf("Result: %d\n", result);
            break;
        case '/':
            if(b == 0) {
                printf("Error! Division by zero is not allowed.\n");
            } else {
                result = a / b;
                printf("Result: %d\n", result);
            }
            break;
        default:
            printf("Invalid operation!\n");
    }
}

int main() {
    int num1, num2, choice;
    char operation;

    // Menu-driven program to perform arithmetic operations
    printf("Arithmetic Operations Menu\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            printf("Enter the operation (+, -, *, /): ");
            scanf(" %c", &operation);
            arithmetic(num1, num2, operation);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            printf("Enter the operation (+, -, *, /): ");
            scanf(" %c", &operation);
            arithmetic(num1, num2, operation);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            printf("Enter the operation (+, -, *, /): ");
            scanf(" %c", &operation);
            arithmetic(num1, num2, operation);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            printf("Enter the operation (+, -, *, /): ");
            scanf(" %c", &operation);
            arithmetic(num1, num2, operation);
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}