//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, int a, int b, int c) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == a) {
            printf("A:");
        } else if (i == b) {
            printf("B:");
        } else if (i == c) {
            printf("C:");
        } else {
            printf("-");
        }
    }
    printf("\n");
}

// Function to move n disks from source to destination using buffer
void tower_of_hanoi(int n, char source, char dest, char buffer) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }

    tower_of_hanoi(n - 1, source, buffer, dest);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    tower_of_hanoi(n - 1, buffer, dest, source);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    printf("Initial state:\n");
    print_towers(n, 'A', 'C', 'B');

    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}