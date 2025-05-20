//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

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

void print_operations() {
    printf("Available operations:\n");
    for (int i = 0; i < sizeof(operations) / sizeof(Operation); i++) {
        printf("%s\n", operations[i].name);
    }
}

int main() {
    char input[MAX_SIZE];
    int a, b, result;
    char operation[3];

    printf("Enter an expression in the format 'number operation number'\n");
    printf("For example: '5 + 3'\n");
    fgets(input, MAX_SIZE, stdin);

    sscanf(input, "%s %s %d %d", operation, operation + 1, &a, &b);

    for (int i = 0; i < sizeof(operations) / sizeof(Operation); i++) {
        if (strcmp(operation, operations[i].name) == 0) {
            result = (*operations[i].func)(a, b);
            printf("Result: %d\n", result);
            return 0;
        }
    }

    printf("Invalid operation\n");
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
        printf("Error: Division by zero\n");
        return 0;
    }
    return a / b;
}