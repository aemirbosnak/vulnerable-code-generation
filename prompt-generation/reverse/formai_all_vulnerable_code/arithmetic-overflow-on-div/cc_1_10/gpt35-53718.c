//FormAI DATASET v1.0 Category: Arithmetic ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
   return a+b;
}

int subtract(int a, int b) {
   return a-b;
}

int multiply(int a, int b) {
    return a*b;
}

int divide(int a, int b) {
    if(b==0) {
        printf("Error: Division by zero");
        exit(0);
    }
    else {
        return a/b;
    }
}

int main() {
    int a, b;
    char operator;
    int result;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch(operator) {
        case '+':
            result = add(a, b);
            printf("%d + %d = %d\n", a, b, result);
            break;

        case '-':
            result = subtract(a, b);
            printf("%d - %d = %d\n", a, b, result);
            break;

        case '*':
            result = multiply(a, b);
            printf("%d * %d = %d\n", a, b, result);
            break;

        case '/':
            result = divide(a, b);
            printf("%d / %d = %d\n", a, b, result);
            break;

        default:
            printf("Error: Invalid operator");
            break;
    }

    return 0;
}