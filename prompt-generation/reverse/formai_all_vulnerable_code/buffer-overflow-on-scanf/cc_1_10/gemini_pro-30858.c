//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double num;
    char op;
} stack;

stack s[100];
int top = -1;

void push(double num) {
    s[++top].num = num;
}

double pop() {
    return s[top--].num;
}

char peek() {
    return s[top].op;
}

int main() {
    char c;
    double a, b;
    while ((c = getchar()) != 'q') {
        switch (c) {
            case '+':
                b = pop();
                a = pop();
                push(a + b);
                break;
            case '-':
                b = pop();
                a = pop();
                push(a - b);
                break;
            case '*':
                b = pop();
                a = pop();
                push(a * b);
                break;
            case '/':
                b = pop();
                a = pop();
                push(a / b);
                break;
            case '^':
                b = pop();
                a = pop();
                push(pow(a, b));
                break;
            case '%':
                b = pop();
                a = pop();
                push(fmod(a, b));
                break;
            case 's':
                push(sin(pop()));
                break;
            case 'c':
                push(cos(pop()));
                break;
            case 't':
                push(tan(pop()));
                break;
            case 'l':
                push(log10(pop()));
                break;
            case 'p':
                push(PI);
                break;
            case 'e':
                push(2.71828182845904523536);
                break;
            default:
                ungetc(c, stdin);
                scanf("%lf", &a);
                push(a);
                break;
        }
        printf("%.9lf\n", s[top].num);
    }
    return 0;
}