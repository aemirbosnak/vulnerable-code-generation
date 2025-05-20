//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void moveDisk(int from_rod, int to_rod) {
    printf("Move disk from rod %c to rod %c\n", from_rod + 'A', to_rod + 'A');
    // Simulate a delay for visual effect
    sleep(1);
}

void hanoi(int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
        moveDisk(from_rod, to_rod);
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    moveDisk(from_rod, to_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

void printInstructions() {
    printf("Welcome to the Tower of Hanoi Solver!\n");
    printf("Instructions:\n");
    printf("1. You will input the number of disks.\n");
    printf("2. The solution will be displayed step by step.\n");
    printf("3. Each move will be displayed with a short delay for better visibility.\n");
    printf("Let's begin!\n\n");
}

int getNumberOfDisks() {
    int disks;
    printf("Enter the number of disks (1 - 10): ");
    scanf("%d", &disks);
    
    if (disks < 1 || disks > 10) {
        printf("Invalid number of disks. Please enter a value between 1 and 10.\n");
        return getNumberOfDisks();
    }
    return disks;
}

int main() {
    printInstructions();
    int numDisks = getNumberOfDisks();

    printf("\nSolving Tower of Hanoi for %d disks...\n\n", numDisks);
    hanoi(numDisks, 0, 2, 1);  // 0 = A, 1 = B, 2 = C
    printf("\nSolution completed!\n");

    return 0;
}