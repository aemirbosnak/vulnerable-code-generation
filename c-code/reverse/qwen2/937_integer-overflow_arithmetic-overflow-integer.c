#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256

int main() {
    char input[MAX_INPUT];
    printf("Enter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin);
    int result = eval(input);
    printf("Result: %d\n", result);
    return 0;
}

int eval(char *expr) {
    int num1, num2, result = 0;
    char op;
    sscanf(expr, "%d %c %d", &num1, &op, &num2);
    switch (op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': if (num2 != 0) result = num1 / num2; break;
        default: printf("Invalid operator\n"); exit(1);
    }
    return result;
}
