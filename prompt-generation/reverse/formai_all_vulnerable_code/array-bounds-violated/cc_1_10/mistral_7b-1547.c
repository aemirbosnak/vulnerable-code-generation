//MISTRAL-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DISKS 10
#define MIN_STICK 1
#define MAX_STICK 3

typedef struct {
    int top;
} stick;

stick sticks[MAX_STICK] = {0};

void hanoi(int n, int from, int to, int aux);
void print_sticks();
void move_disk(int from, int to);

int main() {
    srand(time(NULL));
    int i;

    for (i = NUM_DISKS; i > 0; i--) {
        sticks[MIN_STICK].top++;
        sticks[MIN_STICK].top += rand() % 3 - 1;
        sticks[MAX_STICK].top += i;
    }

    printf("Let's play Hanoi with %d disks and sticks %d, %d and %d!\n", NUM_DISKS, MIN_STICK, MAX_STICK, MAX_STICK);
    print_sticks();

    hanoi(NUM_DISKS, MIN_STICK, MAX_STICK, (MAX_STICK + 1) % MAX_STICK);

    print_sticks();
    printf("Hurray, we moved all the disks to stick %d!\n", MAX_STICK);

    return 0;
}

void hanoi(int n, int from, int to, int aux) {
    if (n > 0) {
        move_disk(from, aux);
        hanoi(n - 1, aux, to, from);
        move_disk(aux, to);
    }
}

void print_sticks() {
    int i;
    printf("Current state of sticks:\n");

    for (i = MIN_STICK; i <= MAX_STICK; i++) {
        printf("Stick %d: ", i);

        for (; sticks[i].top > 0; sticks[i].top--) {
            printf("Disk %d ", sticks[i].top);
        }

        printf("\n");
    }
}

void move_disk(int from, int to) {
    if (sticks[from].top > 0 && sticks[to].top <= 0) {
        sticks[to].top++;
        sticks[from].top--;
        printf("Moved disk %d from stick %d to stick %d\n", sticks[from].top, from, to);
    } else {
        printf("Ups, can't move the disk from stick %d to stick %d now. Try again!\n", from, to);
    }
}