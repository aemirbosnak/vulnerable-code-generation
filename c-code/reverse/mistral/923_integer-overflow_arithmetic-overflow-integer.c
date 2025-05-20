#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    char op;
    int a, b, result = 0;

    scanf("%d", &a);

    while ((op = getchar()) != '\n') {
        scanf("%d", &b);
        switch (op) {
            case '+':
                result += b;
                break;
            case '-':
                result -= b;
                break;
            case '*':
                result *= b;
                break;
            case '/':
                if (b == 0) {
                    printf("Error: Division by zero.\n");
                    return 1;
                }
                result /= b;
                break;
            default:
                printf("Error: Invalid operator.\n");
                return 1;
        }
    }

    printf("Result: %d\n", result);
    return 0;
}
