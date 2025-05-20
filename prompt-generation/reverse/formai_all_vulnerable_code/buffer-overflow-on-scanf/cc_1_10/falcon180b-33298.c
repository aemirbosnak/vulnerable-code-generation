//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

void print_disks(int disks, int from, int to, int aux) {
    int i;
    for (i = 0; i < disks; i++) {
        if (i == from) {
            printf("*");
        } else if (i == to) {
            printf("*");
        } else if (i == aux) {
            printf("*");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

void move_disk(int n, int from, int to, int aux) {
    if (n == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from, to);
        return;
    }
    move_disk(n - 1, from, aux, to);
    printf("Move disk %d from rod %d to rod %d\n", n, from, to);
    move_disk(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks!\n");
        return 1;
    }

    srand(time(NULL));
    int from = rand() % 3;
    int to = rand() % 3;
    int aux = rand() % 3;

    while (from == to || aux == to) {
        from = rand() % 3;
        to = rand() % 3;
        aux = rand() % 3;
    }

    printf("The disks are initially on rod %d\n", from + 1);
    print_disks(n, from, to, aux);

    move_disk(n, from, to, aux);

    return 0;
}