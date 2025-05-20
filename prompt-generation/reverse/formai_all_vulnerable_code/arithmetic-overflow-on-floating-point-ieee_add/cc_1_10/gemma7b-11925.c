//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    double value;
    char operator;
    struct Calculator* next;
} Calculator;

void calculate(Calculator* calculator) {
    double result = 0;
    switch (calculator->operator) {
        case '+':
            result = calculator->value + calculator->next->value;
            break;
        case '-':
            result = calculator->value - calculator->next->value;
            break;
        case '*':
            result = calculator->value * calculator->next->value;
            break;
        case '/':
            result = calculator->value / calculator->next->value;
            break;
    }
    calculator->value = result;
}

int main() {
    Calculator* head = NULL;
    char buffer[MAX_BUFFER_SIZE];

    printf("Enter an expression: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the expression and create a linked list of calculators
    Calculator* calculator = NULL;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (calculator == NULL) {
            calculator = malloc(sizeof(Calculator));
            head = calculator;
        } else {
            calculator = malloc(sizeof(Calculator));
            calculator->next = head;
            head = calculator;
        }

        calculator->value = buffer[i] - '0';
        calculator->operator = buffer[i+1];
    }

    // Calculate the result
    calculate(head);

    // Print the result
    printf("The result is: %f\n", head->value);

    return 0;
}