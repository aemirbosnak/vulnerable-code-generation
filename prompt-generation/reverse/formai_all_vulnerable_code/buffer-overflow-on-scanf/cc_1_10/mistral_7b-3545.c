//MISTRAL-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char symbol;
    double value;
    int is_operation;
} token;

token stack[100];
int top = -1;

void push(token t) {
    stack[++top] = t;
}

token pop() {
    return stack[top--];
}

void apply_operation(char op) {
    token a = pop();
    token b = pop();

    switch (op) {
        case '+':
            push((token){'+', a.value + b.value, 0});
            break;
        case '-':
            push((token){'-', a.value - b.value, 0});
            break;
        case '*':
            push((token){'*', a.value * b.value, 0});
            break;
        case '/':
            push((token){'/', a.value / b.value, 0});
            break;
        case '^':
            push((token){'^', pow(a.value, b.value), 0});
            break;
        case 's': // square root
            push((token){'s', sqrt(a.value), 0});
            break;
        case 'c': // clear stack
            top = -1;
            break;
        default:
            printf("Error: Unknown operation %c\n", op);
            exit(1);
    }
}

int is_number(char c) {
    return (c >= '0' && c <= '9') || c == '.' || c == '-';
}

int main() {
    char expression[100];
    int i, len;
    token t;

    printf("Romeo: Enter your mathematical expression, dear Juliet:\n");
    scanf("%s", expression);

    len = strlen(expression);

    for (i = 0; i < len; i++) {
        t.symbol = expression[i];

        if (is_number(t.symbol)) {
            t.value = strtod(&expression[i], NULL);
            push(t);
        } else if (t.symbol == ' ') {
            // ignore spaces
        } else {
            apply_operation(t.symbol);
        }
    }

    if (top < 0) {
        printf("Error: Empty expression\n");
        exit(1);
    }

    printf("Juliet: The result is %.2lf\n", stack[0].value);

    return 0;
}