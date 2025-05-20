//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol;
    void (*function)(int, int, int*);
} Operation;

void add(int a, int b, int* result) {
    *result = a + b;
}

void subtract(int a, int b, int* result) {
    *result = a - b;
}

void multiply(int a, int b, int* result) {
    *result = a * b;
}

void divide(int a, int b, int* result) {
    if (b != 0) {
        *result = a / b;
    } else {
        printf("Error: Division by zero is not allowed.\n");
        exit(EXIT_FAILURE);
    }
}

Operation operations[] = {
    {'+', add},
    {'-', subtract},
    {'*', multiply},
    {'/', divide}
};

int main() {
    int num1, num2, result;
    char operationSymbol;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Enter the arithmetic operation symbol (+, -, *, /): ");
    scanf(" %c", &operationSymbol);

    for (int i = 0; i < 4; i++) {
        if (operations[i].symbol == operationSymbol) {
            operations[i].function(num1, num2, &result);
            break;
        }
    }

    printf("The result of the arithmetic operation is: %d\n", result);

    // Shape shifting based on the arithmetic operation
    switch (operationSymbol) {
        case '+':
            printf("+---------------------\n");
            printf("| Addition           |\n");
            printf("|---------------------|\n");
            printf("| %d + %d = %d        |\n", num1, num2, result);
            printf("|---------------------|\n");
            printf("+---------------------\n");
            break;
        case '-':
            printf("---================----\n");
            printf("| Subtraction          |\n");
            printf("|---------------------|\n");
            printf("| %d - %d = %d         |\n", num1, num2, result);
            printf("|---------------------|\n");
            printf("---================----\n");
            break;
        case '*':
            printf("*---------------------*\n");
            printf("| Multiplication        |\n");
            printf("|---------------------|\n");
            printf("| %d * %d = %d         |\n", num1, num2, result);
            printf("|---------------------|\n");
            printf("*---------------------*\n");
            break;
        case '/':
            printf("/---------------------\\\n");
            printf("| Division             |\n");
            printf("|---------------------|\n");
            printf("| %d / %d = %d         |\n", num1, num2, result);
            printf("|---------------------|\n");
            printf("/---------------------\\\n");
            break;
    }

    return 0;
}