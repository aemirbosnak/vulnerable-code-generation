//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod);
void moveDisk(int n, char from_rod, char to_rod);
void printSolution(int n, char from_rod, char to_rod, char aux_rod);

int main() {
    int n;
    char from_rod, to_rod, aux_rod;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Enter the starting rod: ");
    scanf(" %c", &from_rod);
    printf("Enter the ending rod: ");
    scanf(" %c", &to_rod);
    printf("Enter the auxiliary rod: ");
    scanf(" %c", &aux_rod);
    srand(time(NULL)); // Seed the random number generator with current time
    towerOfHanoi(n, from_rod, to_rod, aux_rod);
    return 0;
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }
    int smaller = n - 1;
    towerOfHanoi(smaller, from_rod, aux_rod, to_rod);
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    towerOfHanoi(smaller, aux_rod, to_rod, from_rod);
}

void moveDisk(int n, char from_rod, char to_rod) {
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
}

void printSolution(int n, char from_rod, char to_rod, char aux_rod) {
    printf("The solution for %d disks and rods %c, %c and %c is:\n", n, from_rod, to_rod, aux_rod);
    printf("1. Move disk 1 from %c to %c\n", from_rod, to_rod);
    for (int i = 2; i <= n; i++) {
        printf("2. Move disk %d from %c to %c\n", i, from_rod, aux_rod);
        printf("3. Move disk %d from %c to %c\n", i, aux_rod, to_rod);
        printf("4. Move disk %d from %c to %c\n", i - 1, to_rod, aux_rod);
    }
    printf("5. Move disk %d from %c to %c\n", n, aux_rod, to_rod);
}