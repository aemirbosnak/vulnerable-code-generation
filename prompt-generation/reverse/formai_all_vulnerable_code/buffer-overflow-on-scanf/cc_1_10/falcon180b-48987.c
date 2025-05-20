//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10
#define DELAY 100000 // in microseconds

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("%c", from);
    for (i = 0; i < n - 1; i++) {
        printf(" ");
    }
    printf("%c\n", to);
    for (i = 0; i < n - 1; i++) {
        printf(" ");
    }
    printf("%c", aux);
}

// Function to move a disk from one tower to another
void move_disk(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    move_disk(n - 1, from, aux, to);

    printf("Move disk %d from %c to %c\n", n, from, to);

    move_disk(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    printf("Solving Tower of Hanoi problem with %d disks...\n", n);
    srand(time(NULL));
    int delay = rand() % DELAY;
    usleep(delay);

    move_disk(n, 'A', 'C', 'B');

    return 0;
}