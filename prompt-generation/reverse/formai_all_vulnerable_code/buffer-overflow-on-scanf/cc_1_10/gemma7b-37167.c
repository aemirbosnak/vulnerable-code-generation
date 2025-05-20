//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    double value;
    char operator;
    struct Calculator* next;
} Calculator;

void calculate(Calculator* calculator) {
    switch (calculator->operator) {
        case '+':
            calculator->value = calculator->next->value + calculator->value;
            break;
        case '-':
            calculator->value = calculator->next->value - calculator->value;
            break;
        case '*':
            calculator->value = calculator->next->value * calculator->value;
            break;
        case '/':
            if (calculator->next->value == 0) {
                printf("Cannot divide by zero\n");
                return;
            }
            calculator->value = calculator->next->value / calculator->value;
            break;
        default:
            printf("Invalid operator\n");
            return;
    }
    calculator->next = NULL;
}

int main() {
    Calculator* head = NULL;
    char input[MAX_BUFFER_SIZE];

    printf("Welcome to the Scientific Calculator!\n");

    // Loop until the user enters "q"
    while (1) {
        printf("Enter an expression (q to quit): ");
        scanf("%s", input);

        // Check if the user has entered "q"
        if (strcmp(input, "q") == 0) {
            break;
        }

        // Create a new calculator
        Calculator* newCalculator = (Calculator*) malloc(sizeof(Calculator));
        newCalculator->value = 0;
        newCalculator->operator = input[0];

        // Insert the new calculator into the linked list
        if (head == NULL) {
            head = newCalculator;
        } else {
            newCalculator->next = head;
            head = newCalculator;
        }

        // Calculate the expression
        calculate(head);

        // Print the result
        printf("Result: %.2lf\n", head->value);
    }

    return 0;
}