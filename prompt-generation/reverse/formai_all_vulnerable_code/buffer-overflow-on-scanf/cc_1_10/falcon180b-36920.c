//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, int from, int to, int aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("->");
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("->");
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("\n");
    int j = n - 1;
    while (j >= 0) {
        if (j == from) {
            printf(" ");
        } else if (j == to) {
            printf("X");
        } else if (j == aux) {
            printf("A");
        } else {
            printf(" ");
        }
        j--;
    }
}

// Function to move n disks from from_rod to to_rod using aux_rod
void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n > MAX_DISKS) {
        printf("Sorry, the maximum number of disks is %d.\n", MAX_DISKS);
        return 1;
    }
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}