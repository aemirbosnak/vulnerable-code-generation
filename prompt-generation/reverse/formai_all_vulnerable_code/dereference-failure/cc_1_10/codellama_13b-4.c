//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scalable
/*
 * Scientific Calculator Implementation in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the possible functions
enum function {
    ADD,
    SUB,
    MUL,
    DIV,
    POW
};

// Define the expression structure
typedef struct {
    enum function func;
    double num1;
    double num2;
} expr;

// Define the stack structure
typedef struct {
    expr* exprs;
    int size;
    int capacity;
} stack;

// Initialize the stack
void init_stack(stack* s) {
    s->exprs = malloc(sizeof(expr) * 10);
    s->size = 0;
    s->capacity = 10;
}

// Push an expression onto the stack
void push(stack* s, expr e) {
    if (s->size >= s->capacity) {
        s->capacity *= 2;
        s->exprs = realloc(s->exprs, s->capacity * sizeof(expr));
    }
    s->exprs[s->size] = e;
    s->size++;
}

// Pop an expression from the stack
expr pop(stack* s) {
    if (s->size == 0) {
        return (expr) {0, 0, 0};
    }
    s->size--;
    return s->exprs[s->size];
}

// Evaluate the expression
double evaluate(expr e) {
    switch (e.func) {
        case ADD:
            return e.num1 + e.num2;
        case SUB:
            return e.num1 - e.num2;
        case MUL:
            return e.num1 * e.num2;
        case DIV:
            return e.num1 / e.num2;
        case POW:
            return pow(e.num1, e.num2);
        default:
            return 0;
    }
}

// Print the expression
void print_expr(expr e) {
    switch (e.func) {
        case ADD:
            printf("%.2lf + %.2lf", e.num1, e.num2);
            break;
        case SUB:
            printf("%.2lf - %.2lf", e.num1, e.num2);
            break;
        case MUL:
            printf("%.2lf * %.2lf", e.num1, e.num2);
            break;
        case DIV:
            printf("%.2lf / %.2lf", e.num1, e.num2);
            break;
        case POW:
            printf("%.2lf^%.2lf", e.num1, e.num2);
            break;
        default:
            printf("Invalid expression");
    }
}

// Print the stack
void print_stack(stack* s) {
    for (int i = 0; i < s->size; i++) {
        print_expr(s->exprs[i]);
        printf("\n");
    }
}

int main() {
    stack s;
    init_stack(&s);

    push(&s, (expr) {ADD, 3, 4});
    push(&s, (expr) {MUL, 5, 6});
    push(&s, (expr) {POW, 2, 3});

    print_stack(&s);

    return 0;
}