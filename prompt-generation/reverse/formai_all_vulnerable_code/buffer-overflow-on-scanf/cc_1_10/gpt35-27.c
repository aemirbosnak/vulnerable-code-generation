//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: decentralized
#include <stdio.h>
#include <math.h>

typedef struct Calculator {
    double current_ans;
    char current_op;
} Calculator;

Calculator calculator = {0, '\0'};

void clear_calculator() {
    calculator.current_ans = 0;
    calculator.current_op = '\0';
}

double process_operation(char op, double a, double b) {
    switch(op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return pow(a, b);
        default:
            return 0;
    }
}

void run_calculator() {
    double num;
    char op;

    while(1) {
        printf("Enter a number: ");
        scanf("%lf", &num);

        if(calculator.current_op == '\0') {
            calculator.current_ans = num;
        } else {
            calculator.current_ans = process_operation(calculator.current_op, calculator.current_ans, num);
        }
        
        printf("Current answer: %lf\n", calculator.current_ans);

        printf("Enter an operator (+, -, *, /, ^): ");
        scanf(" %c", &op);

        if(op == '=') {
            printf("Final answer: %lf\n", calculator.current_ans);
            clear_calculator();
            continue;
        }

        calculator.current_op = op;
    }
}

int main() {
    run_calculator();

    return 0;
}