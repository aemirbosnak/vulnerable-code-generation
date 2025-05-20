//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISCS 10

typedef struct {
    int discs[MAX_DISCS];
    int top;
    char name[20];
} Tower;

void initTower(Tower *tower, const char *name) {
    tower->top = -1;
    strncpy(tower->name, name, sizeof(tower->name) - 1);
}

int isTowerEmpty(Tower *tower) {
    return (tower->top == -1);
}

int isTowerFull(Tower *tower) {
    return (tower->top == MAX_DISCS - 1);
}

void pushTower(Tower *tower, int disc) {
    if (!isTowerFull(tower)) {
        tower->discs[++tower->top] = disc;
    }
}

int popTower(Tower *tower) {
    if (!isTowerEmpty(tower)) {
        return tower->discs[tower->top--];
    }
    return -1;
}

void printTower(Tower *tower) {
    printf("%s: ", tower->name);
    for (int i = tower->top; i >= 0; i--) {
        printf("|%d| ", tower->discs[i]);
    }
    printf("\n");
}

void moveDisc(Tower *source, Tower *target) {
    if (!isTowerEmpty(source)) {
        int disc = popTower(source);
        pushTower(target, disc);
        printf("Moved disc %d from %s to %s\n", disc, source->name, target->name);
    }
}

void hanoi(int n, Tower *source, Tower *target, Tower *aux) {
    if (n == 1) {
        moveDisc(source, target);
        return;
    }
    hanoi(n - 1, source, aux, target);
    moveDisc(source, target);
    hanoi(n - 1, aux, target, source);
}

void printTowers(Tower *towers, int numTowers) {
    for (int i = 0; i < numTowers; i++) {
        printTower(&towers[i]);
    }
    printf("\n");
}

void displayInstructions() {
    printf("Welcome to the Tower of Hanoi Game!\n");
    printf("Instructions: Move the discs from the source tower to the target tower\n");
    printf("while obeying the rules of the game.\n");
}

int main() {
    int numDiscs;
    Tower towers[3];

    displayInstructions();

    printf("Enter the number of discs (1 to %d): ", MAX_DISCS);
    scanf("%d", &numDiscs);

    if (numDiscs < 1 || numDiscs > MAX_DISCS) {
        printf("Invalid number of discs!\n");
        return 1;
    }

    // Initialize towers
    initTower(&towers[0], "Source");
    initTower(&towers[1], "Auxiliary");
    initTower(&towers[2], "Target");

    // Fill the source tower with discs
    for (int i = numDiscs; i >= 1; i--) {
        pushTower(&towers[0], i);
    }

    // Display initial state
    printf("Initial state of the towers:\n");
    printTowers(towers, 3);

    // Solve the Tower of Hanoi
    hanoi(numDiscs, &towers[0], &towers[2], &towers[1]);

    // Display final state
    printf("Final state of the towers:\n");
    printTowers(towers, 3);

    return 0;
}