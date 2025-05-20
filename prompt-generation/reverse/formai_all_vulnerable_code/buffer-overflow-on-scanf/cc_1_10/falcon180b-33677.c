//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100
#define NUM_FUNCTIONS 10

typedef struct {
    char *name;
    int (*func)(int, int);
} Function;

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int power(int a, int b);
int square_root(int a);

Function functions[NUM_FUNCTIONS] = {
    {"+", add},
    {"-", subtract},
    {"*", multiply},
    {"/", divide},
    {"^", power},
    {"sqrt", square_root}
};

int main() {
    char input[MAX_SIZE];
    int num1, num2, result, choice;
    char operation[MAX_SIZE];

    printf("Enter first number: ");
    scanf("%s", input);
    num1 = atoi(input);

    printf("Enter second number: ");
    scanf("%s", input);
    num2 = atoi(input);

    printf("Enter operation (+, -, *, /, ^, sqrt): ");
    scanf("%s", operation);

    for (int i = 0; i < NUM_FUNCTIONS; i++) {
        if (strcmp(operation, functions[i].name) == 0) {
            result = functions[i].func(num1, num2);
            printf("Result: %d\n", result);
            return 0;
        }
    }

    printf("Invalid operation.\n");
    return 1;
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
        printf("Error: Division by zero.\n");
        return 0;
    }
    return a / b;
}

int power(int a, int b) {
    return pow(a, b);
}

int square_root(int a) {
    return sqrt(a);
}