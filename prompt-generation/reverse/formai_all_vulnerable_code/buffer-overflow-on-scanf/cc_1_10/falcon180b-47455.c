//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("%c: ", from);
    for (i = 0; i < n; i++) {
        if (i < n - 1) {
            printf("%d ", i + 1);
        } else {
            printf("%d\n", i + 1);
        }
    }
    printf("%c: ", to);
    for (i = n - 1; i >= 0; i--) {
        if (i > 0) {
            printf("%d ", i + 1);
        } else {
            printf("%d\n", i + 1);
        }
    }
    printf("%c: ", aux);
    for (i = 0; i < n; i++) {
        if (i < n - 1) {
            printf("%d ", i + 1);
        } else {
            printf("%d\n", i + 1);
        }
    }
}

// Function to move n disks from from_rod to to_rod using aux_rod
void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }
    hanoi(n, 'A', 'C', 'B');
    return 0;
}