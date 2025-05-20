#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define MAX_STACK_SIZE 100

int main() {
    char buffer[MAX_INPUT_SIZE];
    int num1 = 0, num2 = 1, stack[MAX_STACK_SIZE], top = -1;
    char operation;

    scanf("%s", buffer);

    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] >= '0' && buffer[i] <= '9') {
            if (top == -1)
                stack[++top] = buffer[i] - '0';
            else
                stack[++top] = stack[top] * 10 + buffer[i] - '0';
        } else if (top > 0) {
            operation = buffer[i];
            num2 = stack[top--];

            switch (operation) {
                case '+':
                    num1 += num2;
                    break;
                case '-':
                    num1 -= num2;
                    break;
                case '*':
                    num1 *= num2;
                    break;
                case '/':
                    num1 /= num2;
                    break;
            }
        }
    }

    printf("Result: %d\n", num1);

    return 0;
}
