//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define NUM_OPERATORS 5
#define NUM_FUNCTIONS 10

typedef struct {
    char *name;
    int (*func)(int, int);
} function_t;

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
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

function_t functions[NUM_FUNCTIONS] = {
    {"add", add},
    {"subtract", subtract},
    {"multiply", multiply},
    {"divide", divide},
    {"power", power}
};

int main() {
    char input[MAX_INPUT_SIZE];
    int num1, num2, operator;
    int result;

    printf("Post-Apocalyptic Scientific Calculator\n");
    printf("-------------------------------------\n");

    while (1) {
        printf("Enter an expression (e.g. 5 + 3): ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        num1 = atoi(strtok(input, " "));
        operator = atoi(strtok(NULL, " "));
        num2 = atoi(strtok(NULL, " "));

        result = functions[operator - 1].func(num1, num2);
        printf("Result: %d\n", result);
    }

    return 0;
}