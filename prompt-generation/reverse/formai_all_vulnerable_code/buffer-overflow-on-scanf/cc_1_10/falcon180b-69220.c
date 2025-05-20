//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: systematic
#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 1000000

void push(int *stack, int *top, int value) {
    if (*top >= MAX - 1) {
        printf("\nStack Overflow");
        return;
    } else {
        (*top)++;
        stack[*top] = value;
    }
}

int pop(int *stack, int *top) {
    if (*top <= 0) {
        printf("\nStack Underflow");
        return -1;
    } else {
        int value = stack[*top];
        (*top)--;
        return value;
    }
}

int peek(int *stack, int *top) {
    if (*top <= 0) {
        printf("\nStack is Empty");
        return -1;
    } else {
        int value = stack[*top];
        return value;
    }
}

void display(int *stack, int *top) {
    if (*top <= 0) {
        printf("\nStack is Empty");
        return;
    } else {
        printf("\nStack: ");
        for (int i = (*top); i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int stack[MAX], top = -1;
    char choice;
    do {
        printf("\nEnter your choice:\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int value;
                printf("\nEnter the value to be pushed: ");
                scanf("%d", &value);
                push(stack, &top, value);
                break;
            }
            case 2: {
                int value = pop(stack, &top);
                if (value!= -1) {
                    printf("\nPopped value: %d", value);
                }
                break;
            }
            case 3: {
                int value = peek(stack, &top);
                if (value!= -1) {
                    printf("\nPeeked value: %d", value);
                }
                break;
            }
            case 4: {
                display(stack, &top);
                break;
            }
            case 5: {
                printf("\nExiting...\n");
                break;
            }
            default: {
                printf("\nInvalid choice");
            }
        }
    } while (choice!= 5);
    return 0;
}