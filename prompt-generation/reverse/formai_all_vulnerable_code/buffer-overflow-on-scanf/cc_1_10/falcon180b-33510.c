//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

// Function to print the current state of the towers
void print_towers(int n, int from, int to, int aux) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == from)
            printf(" -> ");
        else if (i == to)
            printf(" <- ");
        else if (i == aux)
            printf(" -> ");
        else
            printf("   ");
    }
}

// Function to move n disks from from_rod to to_rod using aux_rod as auxiliary
void hanoi(int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from_rod, to_rod);
        return;
    }

    hanoi(n - 1, from_rod, aux_rod, to_rod);

    printf("Move disk %d from rod %d to rod %d\n", n, from_rod, to_rod);

    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Main function to run the program
int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    hanoi(n, 1, 3, 2);

    return 0;
}