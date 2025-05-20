//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the disks on the peg
void print_disks(int peg, int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", peg - i);
    }
}

// Function to move the disk from source to target
void move_disk(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }

    move_disk(n - 1, source, auxiliary, target);
    printf("Move disk %d from %c to %c\n", n, source, target);
    move_disk(n - 1, auxiliary, target, source);
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }

    tower_of_hanoi(n - 1, source, auxiliary, target);
    printf("Move disk %d from %c to %c\n", n, source, target);
    tower_of_hanoi(n - 1, auxiliary, target, source);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}