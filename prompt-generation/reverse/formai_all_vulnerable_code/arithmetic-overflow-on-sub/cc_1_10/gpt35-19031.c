//FormAI DATASET v1.0 Category: Arithmetic ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

/* Welcome to the Future of Arithmetic */
/* Let's create a program that can solve complex equations instantly and with zero errors */

/* First, let's define our equation format */
struct equation {
    int operand1;
    char operator;
    int operand2;
};

/* Now, let's create our arithmetic functions for addition, subtraction, multiplication and division */
int addition(int op1, int op2) {
    return op1 + op2;
}

int subtraction(int op1, int op2) {
    return op1 - op2;
}

int multiplication(int op1, int op2) {
    return op1 * op2;
}

int division(int op1, int op2) {
    if(op2 == 0) {
        printf("Error: Division by zero is not allowed\n");
        exit(0);
    }
    return op1 / op2;
}

/* Next, let's create our function for solving equations */
int solver(struct equation eq) {
    switch(eq.operator) {
        case '+':
            return addition(eq.operand1, eq.operand2);
        case '-':
            return subtraction(eq.operand1, eq.operand2);
        case '*':
            return multiplication(eq.operand1, eq.operand2);
        case '/':
            return division(eq.operand1, eq.operand2);
        default:
            printf("Error: Invalid Operator\n");
            exit(0);
    }
}

int main() {
    printf("Welcome to the Future of Arithmetic\n");
    printf("Enter an equation in the format operand operator operand\n");

    /* Let's take the user input equation */
    struct equation eq;
    scanf("%d %c %d", &eq.operand1, &eq.operator, &eq.operand2);

    /* Let's solve the equation */
    int result = solver(eq);
    printf("The result is %d\n", result);

    return 0;
}