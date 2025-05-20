//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

void push(char *stack, int *top, char element) {
    if (*top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[*top] = element;
    (*top)++;
}

char pop(char *stack, int *top) {
    if (*top <= 0) {
        printf("Stack Underflow\n");
        exit(1);
    }
    char element = stack[*top - 1];
    (*top)--;
    return element;
}

int isEmpty(int *top) {
    return (*top == 0);
}

void display(char *stack, int *top) {
    printf("Stack: ");
    for (int i = 0; i <= *top; i++) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

int main() {
    char stack[MAX_SIZE];
    int top = -1;
    char input[MAX_SIZE];
    int i = 0;

    printf("Enter a binary number: ");
    scanf("%s", input);

    for (int j = strlen(input) - 1; j >= 0; j--) {
        if (!isdigit(input[j])) {
            printf("Invalid binary number\n");
            exit(1);
        }
        push(stack, &top, input[j] - '0');
    }

    printf("Decimal equivalent: ");
    while (!isEmpty(top)) {
        int digit = pop(stack, top) - '0';
        int power = 0;
        while (digit > 0) {
            int reminder = digit % 10;
            push(stack, &top, reminder);
            digit /= 10;
            power++;
        }
        for (int k = 0; k < power; k++) {
            int num = pop(stack, top);
            int product = num * (int)pow(2, power - 1 - k);
            push(stack, &top, product + '0');
        }
    }

    display(stack, top);

    return 0;
}