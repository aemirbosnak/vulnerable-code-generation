//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: complex
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n--- Mathematical Operations Menu ---\n");
    printf("1. Matrix Multiplication\n");
    printf("2. Fibonacci Sequence\n");
    printf("3. Basic Calculator\n");
    printf("4. Exit\n");
    printf("-------------------------------------\n");
    printf("Please choose an option (1 - 4): ");
}

void matrixMultiplication() {
    int r1, c1, r2, c2;
    printf("\nEnter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible (columns of first != rows of second)!\n");
        return;
    }

    int matrix1[r1][c1], matrix2[r2][c2], result[r1][c2];
    
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &matrix1[i][j]);

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &matrix2[i][j]);

    // Initialize the result matrix to 0
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            result[i][j] = 0;

    // Matrix multiplication
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                result[i][j] += matrix1[i][k] * matrix2[k][j];

    printf("Resultant Matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }
}

void fibonacciSequence() {
    int n;
    printf("\nEnter the number of Fibonacci terms to generate: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("At least one term should be specified!\n");
        return;
    }

    long long a = 0, b = 1;
    printf("Fibonacci Sequence:\n");
    for (int i = 1; i <= n; i++) {
        printf("%lld ", a);
        long long next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

void basicCalculator() {
    double num1, num2;
    char operation;
    printf("\nEnter first number: ");
    scanf("%lf", &num1);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operation);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (operation) {
        case '+':
            printf("Result: %.2lf\n", num1 + num2);
            break;
        case '-':
            printf("Result: %.2lf\n", num1 - num2);
            break;
        case '*':
            printf("Result: %.2lf\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("Result: %.2lf\n", num1 / num2);
            else
                printf("Error: Division by zero!\n");
            break;
        default:
            printf("Invalid operator!\n");
            break;
    }
}

int main() {
    int option;
    do {
        displayMenu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                matrixMultiplication();
                break;
            case 2:
                fibonacciSequence();
                break;
            case 3:
                basicCalculator();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (option != 4);
    return 0;
}