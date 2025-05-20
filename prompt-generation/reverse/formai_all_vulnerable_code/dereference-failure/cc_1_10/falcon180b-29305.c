//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int (*func)(int, int);
} operation;

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

int power(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int square_root(int n) {
    if (n < 0) {
        printf("Error: Square root of negative number\n");
        exit(1);
    }
    return sqrt(n);
}

int modulo(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        exit(1);
    }
    return a % b;
}

int main() {
    char input[MAX_SIZE];
    int num1, num2, result;
    char operation_symbol;

    operation operations[] = {{"+", add}, {"-", subtract}, {"*", multiply}, {"/", divide}, {"^", power}, {"!", factorial}, {"#", square_root}, {"%", modulo}};

    printf("Enter an expression in the format 'number operator number'\n");
    fgets(input, MAX_SIZE, stdin);

    num1 = atoi(strtok(input, " "));
    operation_symbol = tolower(strtok(NULL, " "));
    num2 = atoi(strtok(NULL, " "));

    for (int i = 0; i < sizeof(operations) / sizeof(operation); i++) {
        if (strcmp(operations[i].name, operation_symbol) == 0) {
            result = operations[i].func(num1, num2);
            printf("Result: %d\n", result);
            return 0;
        }
    }

    printf("Error: Invalid operator\n");
    return 1;
}