//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef struct {
    char *name;
    int (*func)(int, int);
} Operation;

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

Operation operations[] = {
    {"+", add},
    {"-", subtract},
    {"*", multiply},
    {"/", divide}
};

int main() {
    int num1, num2, choice, result;
    char operation[3];

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation[0]);
    operation[1] = '\0';

    choice = 0;
    for (int i = 0; i < 4; i++) {
        if (strcmp(operation, operations[i].name) == 0) {
            choice = i;
            break;
        }
    }

    result = (*operations[choice].func)(num1, num2);

    printf("Result: %d\n", result);

    return 0;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        exit(1);
    }
    return a / b;
}