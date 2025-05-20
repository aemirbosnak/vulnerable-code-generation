//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_DISKS 10
#define STACK_SIZE 100

struct tower {
    int top;
    struct tower *next;
};

struct tower *stack[3];

void push(struct tower **top_ref, int value) {
    struct tower *new_node = (struct tower *) malloc(sizeof(struct tower));
    if (!new_node) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->top = value;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(struct tower **top_ref) {
    struct tower *top = *top_ref;
    int value = top->top;
    *top_ref = top->next;
    free(top);
    return value;
}

void move_disk(int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from_rod, to_rod);
        return;
    }
    move_disk(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %d to rod %d\n", n, from_rod, to_rod);
    move_disk(n - 1, aux_rod, to_rod, from_rod);
}

void *thread_func(void *arg) {
    int i, j;
    for (i = 1; i <= MAX_DISKS; i++) {
        push(&stack[0], i);
    }
    for (i = MAX_DISKS; i >= 1; i--) {
        for (j = 0; j < 3; j++) {
            if (j!= 0 && j!= 2) {
                push(&stack[j], pop(&stack[0]));
            }
        }
        move_disk(i, 0, 2, 1);
        for (j = 0; j < 3; j++) {
            if (j!= 0 && j!= 2) {
                push(&stack[0], pop(&stack[j]));
            }
        }
    }
    return NULL;
}

int main() {
    pthread_t threads[3];
    int i;
    for (i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_func, NULL);
    }
    for (i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}