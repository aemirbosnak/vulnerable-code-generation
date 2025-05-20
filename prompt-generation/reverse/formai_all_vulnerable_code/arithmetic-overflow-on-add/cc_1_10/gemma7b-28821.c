//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    int history[10];
    int hist_pos;
} Calculator;

Calculator calc;

void calculator_init() {
    calc.pos = 0;
    calc.hist_pos = 0;
    memset(calc.buffer, 0, MAX_BUFFER_SIZE);
    memset(calc.history, 0, 10 * sizeof(int));
}

void calculator_add(int num) {
    if (calc.pos >= MAX_BUFFER_SIZE - 1) {
        return;
    }
    calc.buffer[calc.pos++] = num + '0';
}

void calculator_clear() {
    calc.pos = 0;
    memset(calc.buffer, 0, MAX_BUFFER_SIZE);
}

void calculator_history(int idx) {
    if (idx >= calc.hist_pos) {
        return;
    }
    printf("%d ", calc.history[idx]);
}

int main() {
    calculator_init();

    char cmd;
    int num1, num2;

    while (1) {
        printf("Enter command (add, clear, history, exit): ");
        scanf(" %c", &cmd);

        switch (cmd) {
            case 'a':
                printf("Enter two numbers: ");
                scanf(" %d %d ", &num1, &num2);
                calculator_add(num1);
                calculator_add(num2);
                break;
            case 'c':
                calculator_clear();
                break;
            case 'h':
                printf("History: ");
                for (int i = 0; i < calc.hist_pos; i++) {
                    calculator_history(i);
                }
                break;
            case 'e':
                exit(0);
            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}