//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function Prototypes
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod);
void printTowers(int n, char towers[]);

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    char towers[num_disks];
    for (int i = 0; i < num_disks; i++) {
        towers[i] = 'A';
    }
    printf("Initial state:\n");
    printTowers(num_disks, towers);
    towerOfHanoi(num_disks, 'A', 'C', 'B');
    printf("\nFinal state:\n");
    printTowers(num_disks, towers);
    return 0;
}

// Recursive function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Function to print the current state of the towers
void printTowers(int n, char towers[]) {
    printf("Rod A: ");
    for (int i = 0; i < n; i++) {
        if (towers[i] == 'A') {
            printf("%d ", i + 1);
        }
    }
    printf("\nRod B: ");
    for (int i = 0; i < n; i++) {
        if (towers[i] == 'B') {
            printf("%d ", i + 1);
        }
    }
    printf("\nRod C: ");
    for (int i = 0; i < n; i++) {
        if (towers[i] == 'C') {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}