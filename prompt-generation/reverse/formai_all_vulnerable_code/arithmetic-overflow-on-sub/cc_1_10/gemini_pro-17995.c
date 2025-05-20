//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

struct stack {
    int *arr;
    int size;
    int top;
};

void push(struct stack *s, int val) {
    if (s->top == s->size - 1) {
        s->size *= 2;
        s->arr = realloc(s->arr, sizeof(int) * s->size);
    }
    s->arr[++s->top] = val;
}

int pop(struct stack *s) {
    return s->arr[s->top--];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct stack **towers = malloc(sizeof(struct stack *) * m);
    for (int i = 0; i < m; i++) {
        towers[i] = malloc(sizeof(struct stack));
        towers[i]->arr = malloc(sizeof(int) * 10000);
        towers[i]->size = 10000;
        towers[i]->top = -1;
    }

    for (int i = n; i >= 1; i--) {
        push(towers[0], i);
    }

    int moves = 0;
    while (moves < m * n) {
        for (int i = 0; i < m; i++) {
            int min = towers[i]->arr[towers[i]->top], min_idx = i;
            for (int j = i + 1; j < m; j++) {
                if (towers[j]->arr[towers[j]->top] < min) {
                    min = towers[j]->arr[towers[j]->top];
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                push(towers[min_idx], pop(towers[i]));
                moves++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        while (towers[i]->top != -1) {
            printf("%d ", pop(towers[i]));
        }
        printf("\n");
    }

    return 0;
}