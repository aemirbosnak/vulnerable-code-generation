//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the elements of an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to print the current state of the towers
void printTowers(int n, int from, int to, int aux) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == from) {
            printf("From: ");
        } else if (i == to) {
            printf("To: ");
        } else if (i == aux) {
            printf("Aux: ");
        } else {
            printf("   ");
        }
    }
    printf("\n");
}

// Function to move a disk from one tower to another
void moveDisk(int n, int from, int to, int aux) {
    if (n == 1) {
        printf("Move disk 1 from %d to %d\n", from, to);
        return;
    }

    moveDisk(n - 1, from, aux, to);

    printf("Move disk %d from %d to %d\n", n, from, to);

    moveDisk(n - 1, aux, to, from);
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        printf("Move disk 1 from %d to %d\n", from, to);
        return;
    }

    hanoi(n - 1, from, aux, to);

    printf("Move disk %d from %d to %d\n", n, from, to);

    hanoi(n - 1, aux, to, from);
}

int main() {
    int n, i;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    int from = 0, to = 2, aux = 1;

    // Print the initial state of the towers
    printf("Initial state:\n");
    printTowers(n, from, to, aux);

    // Solve the problem
    hanoi(n, from, to, aux);

    // Print the final state of the towers
    printf("Final state:\n");
    printTowers(n, from, to, aux);

    return 0;
}