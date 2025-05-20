//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void push(char *stack, int *top, char c) {
    if ((*top) == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(0);
    } else {
        (*top)++;
        stack[*top] = c;
    }
}

char pop(char *stack, int *top) {
    char c;
    if ((*top) == -1) {
        printf("Stack Underflow\n");
        exit(0);
    } else {
        c = stack[*top];
        (*top)--;
        return c;
    }
}

void display(char *stack, int top) {
    if (top == -1)
        printf("Stack is Empty\n");
    else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--)
            printf("%c", stack[i]);
        printf("\n");
    }
}

int main() {
    char stack[MAX_SIZE];
    int top = -1;

    printf("Enter the binary number: ");
    scanf("%s", stack);

    int decimal = 0;
    int power = 0;

    for (int i = strlen(stack) - 1; i >= 0; i--) {
        if (stack[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    printf("The decimal equivalent of the binary number is: %d\n", decimal);

    return 0;
}