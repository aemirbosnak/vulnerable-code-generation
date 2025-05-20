//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10
#define MOVE_DELAY 100000

void move_disk(int n, char from, char to, char aux) {
    printf("Move disk %d from %c to %c\n", n, from, to);
    printf("Using %c as auxiliary\n", aux);
}

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        move_disk(n, from, to, aux);
        return;
    }

    hanoi(n - 1, from, aux, to);
    move_disk(n, from, to, aux);
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    char from, to, aux;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    printf("Enter start rod: ");
    scanf(" %c", &from);

    printf("Enter end rod: ");
    scanf(" %c", &to);

    printf("Enter auxiliary rod: ");
    scanf(" %c", &aux);

    srand(time(NULL));
    int delay = rand() % MOVE_DELAY;

    printf("Solving Tower of Hanoi problem with %d disks...\n", n);
    hanoi(n, from, to, aux);

    printf("\nProblem solved!\n");
    return 0;
}