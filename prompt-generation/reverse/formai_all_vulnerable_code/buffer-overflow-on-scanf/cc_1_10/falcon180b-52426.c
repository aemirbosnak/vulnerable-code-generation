//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

char tower[MAX_DISKS];

void push(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        tower[to] = 'A';
        return;
    }

    push(n-1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    tower[to] = 'A';
}

void pull(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        tower[to] = 'A';
        return;
    }

    pull(n-1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    tower[to] = 'A';
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n > 0 && n <= MAX_DISKS) {
        printf("Initial configuration:\n");
        for (int i = n; i > 0; i--) {
            printf("Move disk %d from %c to %c\n", i, 'A', 'C');
        }

        char from = 'C';
        char to = 'B';
        char aux = 'A';

        push(n, from, to, aux);
        printf("\n");

        for (int i = n; i > 0; i--) {
            printf("Move disk %d from %c to %c\n", i, from, to);
        }

        printf("\nFinal configuration:\n");
        for (int i = n; i > 0; i--) {
            printf("Move disk %d from %c to %c\n", i, 'A', 'C');
        }

        pull(n, from, to, aux);
    } else {
        printf("Invalid number of disks.\n");
    }

    return 0;
}