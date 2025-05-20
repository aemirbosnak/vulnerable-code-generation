//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUMBERS 100
#define MAX_OPERATORS 100
#define MAX_OPERAND_SIZE 100

int numbers[MAX_NUMBERS];
char operators[MAX_OPERATORS][MAX_OPERAND_SIZE];
int num_operators;
int num_numbers;
int current_operator;

void push_number(int num) {
    if (num_numbers >= MAX_NUMBERS) {
        printf("Error: Too many numbers!\n");
        exit(1);
    }
    numbers[num_numbers++] = num;
}

void push_operator(char op) {
    if (num_operators >= MAX_OPERATORS) {
        printf("Error: Too many operators!\n");
        exit(1);
    }
    strcpy(operators[num_operators++], op);
}

int evaluate_expression() {
    int result = numbers[--num_numbers];
    char op = operators[--num_operators][0];

    while (op!= '\0') {
        if (op == '+') {
            result += numbers[--num_numbers];
        } else if (op == '-') {
            result -= numbers[--num_numbers];
        } else if (op == '*') {
            result *= numbers[--num_numbers];
        } else if (op == '/') {
            if (numbers[--num_numbers] == 0) {
                printf("Error: Division by zero!\n");
                exit(1);
            }
            result /= numbers[num_numbers];
        }
        op = operators[--num_operators][0];
    }

    return result;
}

int main() {
    srand(time(NULL));

    int num1, num2;
    char op;

    printf("Welcome to the Happy Calculator!\n\n");

    while (1) {
        printf("Enter two numbers separated by an operator (+, -, *, /):\n");
        scanf("%d %c %d", &num1, &op, &num2);

        push_number(num1);
        push_number(num2);
        push_operator(op);

        if (num_operators == 1 && num_numbers == 2) {
            int result = evaluate_expression();
            printf("Result: %d\n\n", result);
        } else {
            printf("Invalid input. Please try again.\n\n");
        }
    }

    return 0;
}