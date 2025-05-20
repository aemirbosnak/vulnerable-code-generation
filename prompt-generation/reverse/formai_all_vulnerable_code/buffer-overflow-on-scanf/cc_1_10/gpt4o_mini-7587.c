//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BINGO_SIZE 5
#define MAX_PLAYERS 10
#define TOTAL_NUMBERS 75

typedef struct {
    int card[BINGO_SIZE][BINGO_SIZE];
    bool marked[BINGO_SIZE][BINGO_SIZE];
    char name[50];
} Player;

void fillCard(Player *player) {
    int usedNumbers[TOTAL_NUMBERS] = {0};
    int num;

    for (int j = 0; j < BINGO_SIZE; j++) {
        int colBase = j * 15 + 1;
        for (int i = 0; i < BINGO_SIZE; i++) {
            do {
                num = rand() % 15 + colBase;
            } while (usedNumbers[num - 1]);
            usedNumbers[num - 1] = 1;
            player->card[i][j] = num;
            player->marked[i][j] = false;
        }
    }
}

void printCard(Player *player) {
    printf("%s's Bingo Card:\n", player->name);
    printf("----------------------\n");
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (player->marked[i][j]) {
                printf("[ X ] ");
            } else {
                printf("[%2d] ", player->card[i][j]);
            }
        }
        printf("\n");
    }
    printf("----------------------\n");
}

bool checkWin(Player *player) {
    // Check rows
    for (int i = 0; i < BINGO_SIZE; i++) {
        bool rowWin = true;
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (!player->marked[i][j]) {
                rowWin = false;
                break;
            }
        }
        if (rowWin) return true;
    }
    
    // Check columns
    for (int j = 0; j < BINGO_SIZE; j++) {
        bool colWin = true;
        for (int i = 0; i < BINGO_SIZE; i++) {
            if (!player->marked[i][j]) {
                colWin = false;
                break;
            }
        }
        if (colWin) return true;
    }

    // Check diagonals
    bool diagWin1 = true, diagWin2 = true;
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (!player->marked[i][i]) diagWin1 = false;
        if (!player->marked[i][BINGO_SIZE - 1 - i]) diagWin2 = false;
    }
    return diagWin1 || diagWin2;
}

void drawNumber(int *drawnNumbers, int *numCount) {
    int num;
    do {
        num = rand() % TOTAL_NUMBERS + 1;
    } while (drawnNumbers[num - 1]);
    drawnNumbers[num - 1] = 1;
    (*numCount)++;
    printf("Number drawn: %2d\n", num);
}

void markNumber(Player *player, int number) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (player->card[i][j] == number) {
                player->marked[i][j] = true;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int numPlayers;
    int drawnNumbers[TOTAL_NUMBERS] = {0};
    int numCount = 0;
    
    printf("Welcome to the Bingo Simulator!\n");
    printf("-------------------------------\n");
    printf("Enter the number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        fillCard(&players[i]);
    }

    printf("\nGame Start!\n");
    while (true) {
        drawNumber(drawnNumbers, &numCount);

        for (int i = 0; i < numPlayers; i++) {
            markNumber(&players[i], drawnNumbers[numCount - 1]);
            if (checkWin(&players[i])) {
                printCard(&players[i]);
                printf("%s wins the game!\n", players[i].name);
                return 0;
            }
            printCard(&players[i]);
        }
        printf("\n");
    }
}