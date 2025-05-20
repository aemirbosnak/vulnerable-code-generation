//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int position;
    int history[10];
    int history_index;
} Calculator;

void calculator_init(Calculator *calc) {
    calc->position = 0;
    calc->history_index = 0;
}

void calculator_add(Calculator *calc, int number) {
    calc->buffer[calc->position++] = number + '0';
    calc->history[calc->history_index++] = number;
}

void calculator_subtract(Calculator *calc, int number) {
    if (calc->position > 0) {
        calc->buffer[calc->position++] = number + '0';
        calc->history[calc->history_index++] = number;
    } else {
        printf("Error: Subtracting from an empty buffer.\n");
    }
}

void calculator_multiply(Calculator *calc, int number) {
    calc->buffer[calc->position++] = number + '0';
    calc->history[calc->history_index++] = number;
}

void calculator_divide(Calculator *calc, int number) {
    if (calc->position > 0) {
        calc->buffer[calc->position++] = number + '0';
        calc->history[calc->history_index++] = number;
    } else {
        printf("Error: Dividing from an empty buffer.\n");
    }
}

void calculator_clear(Calculator *calc) {
    calc->position = 0;
    calc->history_index = 0;
}

int main() {
    Calculator calc;
    calculator_init(&calc);

    char command;
    int number;

    printf("Enter a command (add, subtract, multiply, divide, clear): ");
    scanf("%c", &command);

    switch (command) {
        case 'a':
            printf("Enter an integer: ");
            scanf("%d", &number);
            calculator_add(&calc, number);
            break;
        case 's':
            printf("Enter an integer: ");
            scanf("%d", &number);
            calculator_subtract(&calc, number);
            break;
        case 'm':
            printf("Enter an integer: ");
            scanf("%d", &number);
            calculator_multiply(&calc, number);
            break;
        case 'd':
            printf("Enter an integer: ");
            scanf("%d", &number);
            calculator_divide(&calc, number);
            break;
        case 'c':
            calculator_clear(&calc);
            break;
        default:
            printf("Invalid command.\n");
    }

    printf("History: ");
    for (int i = 0; i < calc.history_index; i++) {
        printf("%d ", calc.history[i]);
    }

    printf("\n");

    return 0;
}