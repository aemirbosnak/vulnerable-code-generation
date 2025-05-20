#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int stack[MAX_SIZE], top = -1;
    char buffer[10];
    int num1, num2, result;
    char op;

    while (1) {
        printf("Enter operation (+, -, *, /) or 'q' to quit: ");
        scanf("%s", buffer);
        if (buffer[0] == 'q') break;

        switch (buffer[0]) {
            case '+':
                num1 = stack[top--];
                num2 = stack[top--];
                result = num1 + num2;
                stack[++top] = result;
                break;
            case '-':
                num1 = stack[top--];
                num2 = stack[top--];
                result = num2 - num1;
                stack[++top] = result;
                break;
            case '*':
                num1 = stack[top--];
                num2 = stack[top--];
                result = num1 * num2;
                stack[++top] = result;
                break;
            case '/':
                num1 = stack[top--];
                num2 = stack[top--];
                result = num2 / num1;
                stack[++top] = result;
                break;
            default:
                printf("Invalid operation\n");
                continue;
        }
    }

    return 0;
}
