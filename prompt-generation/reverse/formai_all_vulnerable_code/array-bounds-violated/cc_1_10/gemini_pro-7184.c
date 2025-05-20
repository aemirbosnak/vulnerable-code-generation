//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_OPS 100

typedef enum {
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_POW,
    OP_SIN,
    OP_COS,
    OP_TAN,
    OP_LN,
    OP_LOG10,
    OP_SQRT
} op_t;

typedef struct {
    op_t op;
    double arg;
} op_arg_t;

typedef struct {
    size_t num_ops;
    op_arg_t ops[MAX_OPS];
} calc_t;

calc_t *calc_new() {
    calc_t *calc = malloc(sizeof(calc_t));
    if (calc == NULL) {
        return NULL;
    }

    calc->num_ops = 0;
    return calc;
}

void calc_free(calc_t *calc) {
    free(calc);
}

int calc_push(calc_t *calc, op_t op, double arg) {
    if (calc->num_ops == MAX_OPS) {
        return -1;
    }

    calc->ops[calc->num_ops].op = op;
    calc->ops[calc->num_ops].arg = arg;
    calc->num_ops++;

    return 0;
}

double calc_eval(calc_t *calc) {
    double stack[MAX_OPS];
    size_t stack_ptr = 0;

    for (size_t i = 0; i < calc->num_ops; i++) {
        op_arg_t *op_arg = &calc->ops[i];

        switch (op_arg->op) {
            case OP_ADD:
                stack[stack_ptr - 1] += op_arg->arg;
                break;
            case OP_SUB:
                stack[stack_ptr - 1] -= op_arg->arg;
                break;
            case OP_MUL:
                stack[stack_ptr - 1] *= op_arg->arg;
                break;
            case OP_DIV:
                stack[stack_ptr - 1] /= op_arg->arg;
                break;
            case OP_POW:
                stack[stack_ptr - 1] = pow(stack[stack_ptr - 1], op_arg->arg);
                break;
            case OP_SIN:
                stack[stack_ptr++] = sin(op_arg->arg);
                break;
            case OP_COS:
                stack[stack_ptr++] = cos(op_arg->arg);
                break;
            case OP_TAN:
                stack[stack_ptr++] = tan(op_arg->arg);
                break;
            case OP_LN:
                stack[stack_ptr++] = log(op_arg->arg);
                break;
            case OP_LOG10:
                stack[stack_ptr++] = log10(op_arg->arg);
                break;
            case OP_SQRT:
                stack[stack_ptr++] = sqrt(op_arg->arg);
                break;
        }
    }

    return stack[stack_ptr - 1];
}

int main() {
    calc_t *calc = calc_new();
    if (calc == NULL) {
        return EXIT_FAILURE;
    }

    calc_push(calc, OP_ADD, 1.0);
    calc_push(calc, OP_ADD, 2.0);
    calc_push(calc, OP_MUL, 3.0);

    printf("Result: %f\n", calc_eval(calc));

    calc_free(calc);

    return EXIT_SUCCESS;
}