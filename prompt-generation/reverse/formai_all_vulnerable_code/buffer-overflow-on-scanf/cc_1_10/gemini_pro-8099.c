//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: sophisticated
#include <stdio.h>

// Function to move n disks from source to destination using an auxiliary rod
void towerOfHanoi(int n, char from, char to, char aux) {
    // If there is only one disk, move it directly from source to destination
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    // Move n-1 disks from source to auxiliary rod
    towerOfHanoi(n - 1, from, aux, to);

    // Move the remaining disk from source to destination
    printf("Move disk %d from %c to %c\n", n, from, to);

    // Move n-1 disks from auxiliary rod to destination
    towerOfHanoi(n - 1, aux, to, from);
}

// Function to print the initial state of the towers
void printTowers(char from, char to, char aux, int n) {
    for (int i = n; i >= 1; i--) {
        printf("%c", from);
    }
    printf(" | ");
    for (int i = n; i >= 1; i--) {
        printf("  ");
    }
    printf(" | ");
    for (int i = n; i >= 1; i--) {
        printf("%c", aux);
    }
    printf("\n");
}

// Function to print the final state of the towers
void printFinalTowers(char from, char to, char aux, int n) {
    for (int i = n; i >= 1; i--) {
        printf("  ");
    }
    printf(" | ");
    for (int i = n; i >= 1; i--) {
        printf("%c", to);
    }
    printf(" | ");
    for (int i = n; i >= 1; i--) {
        printf("  ");
    }
    printf("\n");
}

int main() {
    int n;

    // Get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Print the initial state of the towers
    printTowers('A', 'B', 'C', n);

    // Solve the Tower of Hanoi problem
    towerOfHanoi(n, 'A', 'B', 'C');

    // Print the final state of the towers
    printFinalTowers('A', 'B', 'C', n);

    return 0;
}