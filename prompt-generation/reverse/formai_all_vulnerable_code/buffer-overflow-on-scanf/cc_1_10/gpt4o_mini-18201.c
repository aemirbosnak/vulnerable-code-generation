//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DISCS 10

typedef struct {
    int top;
    int discs[MAX_DISCS];
} Tower;

Tower towers[3];
int moves = 0;

void initializeTowers(int numDiscs) {
    for (int i = 0; i < 3; i++) {
        towers[i].top = -1;
    }
    for (int i = numDiscs; i > 0; i--) {
        towers[0].discs[++towers[0].top] = i;
    }
}

void printTowers() {
    printf("\nCurrent Towers:\n");
    for (int i = 0; i < 3; i++) {
        printf("Tower %d: ", i + 1);
        for (int j = towers[i].top; j >= 0; j--) {
            printf("%d ", towers[i].discs[j]);
        }
        printf("\n");
    }
    printf("Moves: %d\n\n", moves);
}

int moveDisc(int from, int to) {
    if (towers[from].top == -1) {
        printf("Tower %d is empty! You can't move a disc from here.\n", from + 1);
        return 0;
    }
    if (towers[to].top != -1 && towers[from].discs[towers[from].top] > towers[to].discs[towers[to].top]) {
        printf("Invalid move! You cannot place a larger disc on top of a smaller one.\n");
        return 0;
    }

    towers[to].discs[++towers[to].top] = towers[from].discs[towers[from].top--];
    moves++;
    return 1;
}

int isGameWon(int numDiscs) {
    return towers[2].top == numDiscs - 1;
}

void playerMove(int player) {
    int from, to;
    printf("Player %d, enter the tower to move from (1-3): ", player);
    scanf("%d", &from);
    printf("Player %d, enter the tower to move to (1-3): ", player);
    scanf("%d", &to);

    from -= 1; // Convert to zero-indexed
    to -= 1;  // Convert to zero-indexed

    if (moveDisc(from, to)) {
        printTowers();
    }
}

int main() {
    int numPlayers, numDiscs;

    printf("Welcome to Multiplayer Tower of Hanoi Game!\n");
    
    printf("Enter the number of players (2-4): ");
    scanf("%d", &numPlayers);
    if (numPlayers < 2 || numPlayers > 4) {
        printf("Invalid number of players. Setting to 2 players.\n");
        numPlayers = 2;
    }

    printf("Enter the number of discs (1-10): ");
    scanf("%d", &numDiscs);
    if (numDiscs < 1 || numDiscs > MAX_DISCS) {
        printf("Invalid number of discs. Setting to 3 discs.\n");
        numDiscs = 3;
    }

    initializeTowers(numDiscs);
    printTowers();

    int currentPlayer = 1;
    while (!isGameWon(numDiscs)) {
        playerMove(currentPlayer);
        currentPlayer = (currentPlayer % numPlayers) + 1;  // Switch players
    }
    
    printf("Congratulations, Player %d! You've won the game in %d moves!\n", (currentPlayer - 1), moves);
    return 0;
}