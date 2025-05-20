//FormAI DATASET v1.0 Category: Educational ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
} operation;

typedef struct {
    int num1, num2;
    operation op;
} equation;

int get_num_from_input(char prompt[]) {
    int num = 0;
    printf("%s", prompt);
    scanf("%d", &num);
    return num;
}

operation get_operation_from_input() {
    int op_num = 0;
    printf("Choose an operation: \n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division");
    scanf("%d", &op_num);

    switch (op_num) {
        case 1:
            return ADDITION;
        case 2:
            return SUBTRACTION;
        case 3:
            return MULTIPLICATION;
        case 4:
            return DIVISION;
        default:
            printf("Invalid operation number.\n");
            exit(1);
    }
}

void perform_equation(equation eq) {
    int result = 0;

    switch (eq.op) {
        case ADDITION:
            result = eq.num1 + eq.num2;
            break;
        case SUBTRACTION:
            result = eq.num1 - eq.num2;
            break;
        case MULTIPLICATION:
            result = eq.num1 * eq.num2;
            break;
        case DIVISION:
            if (eq.num2 == 0) {
                printf("Cannot divide by zero.\n");
                exit(1);
            }
            result = eq.num1 / eq.num2;
            break;
        default:
            printf("Invalid operation.\n");
            exit(1);
    }

    printf("The result of the equation is: %d\n", result);
}

int main() {
    equation eq;
    eq.num1 = get_num_from_input("Enter first number: ");
    eq.num2 = get_num_from_input("Enter second number: ");
    eq.op = get_operation_from_input();
    perform_equation(eq);

    return 0;
}