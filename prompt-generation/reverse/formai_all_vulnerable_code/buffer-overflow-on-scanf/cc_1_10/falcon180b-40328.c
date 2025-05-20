//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FIB 1000

int fibonacci[MAX_FIB];
int top = 0;

void push(int value) {
    if (top == MAX_FIB) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    fibonacci[++top] = value;
}

int pop() {
    if (top == 0) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return fibonacci[top--];
}

int main() {
    int n, i, choice;

    srand(time(NULL));
    for (i = 0; i < 2; i++)
        push(rand() % 100);

    do {
        printf("\n");
        printf("1. Generate random number\n");
        printf("2. Display stack\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            push(rand() % 100);
            break;
        case 2:
            for (i = top; i >= 0; i--)
                printf("%d ", fibonacci[i]);
            printf("\n");
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (1);

    return 0;
}