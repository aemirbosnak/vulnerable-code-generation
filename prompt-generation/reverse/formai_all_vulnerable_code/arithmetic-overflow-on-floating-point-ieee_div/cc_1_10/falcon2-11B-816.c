//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct calculator {
    double x;
    double y;
    int operator;
} Calculator;

void add(Calculator *c) {
    c->x += c->y;
    c->operator = 0;
}

void subtract(Calculator *c) {
    c->x -= c->y;
    c->operator = 1;
}

void multiply(Calculator *c) {
    c->x *= c->y;
    c->operator = 2;
}

void divide(Calculator *c) {
    c->x /= c->y;
    c->operator = 3;
}

void display(Calculator *c) {
    printf("x = %lf\n", c->x);
}

int main() {
    Calculator calc;
    calc.x = 10.0;
    calc.y = 2.0;
    calc.operator = 0;

    while(calc.operator!= 4) {
        printf("Enter operation: (+, -, *, /, %)\n");
        scanf("%d", &calc.operator);

        if(calc.operator == 1) {
            printf("Subtract: ");
            scanf("%lf", &calc.y);
            subtract(&calc);
        } else if(calc.operator == 2) {
            printf("Multiply: ");
            scanf("%lf", &calc.y);
            multiply(&calc);
        } else if(calc.operator == 3) {
            printf("Divide: ");
            scanf("%lf", &calc.y);
            divide(&calc);
        } else if(calc.operator == 4) {
            display(&calc);
            break;
        }

        printf("Result: ");
        display(&calc);
    }

    return 0;
}