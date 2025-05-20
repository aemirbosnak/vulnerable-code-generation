//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

typedef struct {
    int disks[MAX_DISKS];
    int top;
} Tower;

void initializeTower(Tower *tower, int numDisks) {
    tower->top = numDisks - 1;
    for (int i = 0; i < numDisks; i++) {
        tower->disks[i] = numDisks - i;
    }
}

void printTowers(Tower A, Tower B, Tower C, int numDisks) {
    printf("\nTowers State:\n");
    printf("A: ");
    for (int i = 0; i < numDisks; i++) {
        if (i <= A.top) printf("%d ", A.disks[i]);
    }
    printf("\nB: ");
    for (int i = 0; i < numDisks; i++) {
        if (i <= B.top) printf("%d ", B.disks[i]);
    }
    printf("\nC: ");
    for (int i = 0; i < numDisks; i++) {
        if (i <= C.top) printf("%d ", C.disks[i]);
    }
    printf("\n");
}

int moveDisk(Tower *source, Tower *destination) {
    if (source->top < 0) {
        printf("Source Tower is empty!\n");
        return 0;
    }
    if (destination->top >= MAX_DISKS - 1) {
        printf("Destination Tower is full!\n");
        return 0;
    }
    
    int disk = source->disks[source->top--];
    if (destination->top >= 0 && disk > destination->disks[destination->top]) {
        printf("Cannot place disk %d on disk %d!\n", disk, destination->disks[destination->top]);
        source->top++;
        return 0;
    }
    
    destination->disks[++destination->top] = disk;
    return 1;
}

void playGame(int numDisks) {
    Tower A, B, C;
    initializeTower(&A, numDisks);
    B.top = -1;  // B is empty
    C.top = -1;  // C is empty
    
    int currentPlayer = 1;
    int moveSuccess;
    int from, to;

    while (C.top != numDisks - 1) {
        printTowers(A, B, C, numDisks);
        printf("Player %d's Turn. Move Disk from Tower (1: A, 2: B, 3: C) to Tower: ", currentPlayer);
        scanf("%d %d", &from, &to);

        Tower *src;
        Tower *dest;

        switch (from) {
            case 1: src = &A; break;
            case 2: src = &B; break;
            case 3: src = &C; break;
            default: 
                printf("Invalid Tower!\n");
                continue;
        }

        switch (to) {
            case 1: dest = &A; break;
            case 2: dest = &B; break;
            case 3: dest = &C; break;
            default: 
                printf("Invalid Tower!\n");
                continue;
        }

        moveSuccess = moveDisk(src, dest);
        if (moveSuccess) {
            currentPlayer = (currentPlayer == 1) ? 2 : 1; // Switch player turn
        }
    }
    
    printf("Congratulations! Player %d has completed the Tower of Hanoi!\n", currentPlayer);
}

int main() {
    int numDisks;
    printf("Welcome to the Multiplayer Tower of Hanoi!\n");
    printf("Enter the number of disks (1 - %d): ", MAX_DISKS);
    scanf("%d", &numDisks);

    if (numDisks < 1 || numDisks > MAX_DISKS) {
        printf("Invalid number of disks!\n");
        return 1;
    }

    playGame(numDisks);
    return 0;
}