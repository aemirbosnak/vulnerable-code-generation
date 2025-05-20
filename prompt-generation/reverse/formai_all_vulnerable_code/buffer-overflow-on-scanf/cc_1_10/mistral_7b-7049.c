//MISTRAL-7B DATASET v1.0 Category: Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 50
#define MIN_VALID_NUM 1
#define MAX_VALID_NUM 10

typedef struct {
    char op;
    int num1;
    int num2;
} CalcOperation;

void inputErrorMessage() {
    printf("Error: Invalid input. Please enter a valid number or operator.\n");
}

int validateInputNumber(int input) {
    if (input < MIN_VALID_NUM || input > MAX_VALID_NUM) {
        inputErrorMessage();
        return 0;
    }
    return input;
}

char validateInputOperator(char input) {
    if (input != '+' && input != '-' && input != '*' && input != '/') {
        inputErrorMessage();
        return 0;
    }
    return input;
}

int performOperation(CalcOperation op) {
    switch (op.op) {
        case '+':
            return op.num1 + op.num2;
        case '-':
            return op.num1 - op.num2;
        case '*':
            return op.num1 * op.num2;
        case '/':
            if (op.num2 == 0) {
                inputErrorMessage();
                return 0;
            }
            return op.num1 / op.num2;
    }
    return 0;
}

int main() {
    char operator;
    int num1, num2;
    CalcOperation calcOperation;

    printf("Welcome to the Simple Calculator!\n");

    while (1) {
        printf("Enter the first number: ");
        scanf("%d", &num1);
        num1 = validateInputNumber(num1);

        printf("Enter an operator (+, -, *, /): ");
        scanf(" %c", &operator);
        operator = validateInputOperator(operator);

        if (operator != 0) {
            calcOperation.op = operator;
            printf("Enter the second number: ");
            scanf("%d", &num2);
            num2 = validateInputNumber(num2);

            calcOperation.num1 = num1;
            calcOperation.num2 = num2;

            int result = performOperation(calcOperation);
            printf("Result: %d\n", result);
        }

        printf("Do you want to continue? (Y/N): ");
        char continueInput;
        scanf(" %c", &continueInput);

        if (continueInput != 'Y') {
            break;
        }
    }

    return 0;
}