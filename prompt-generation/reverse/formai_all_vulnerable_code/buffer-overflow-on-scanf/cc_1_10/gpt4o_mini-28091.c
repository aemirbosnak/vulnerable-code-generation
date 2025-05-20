//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define BINGO_SIZE 5
#define MAX_NUMBER 75
#define MAX_PLAYERS 4

typedef struct {
    int card[BINGO_SIZE][BINGO_SIZE];
    int marked[BINGO_SIZE][BINGO_SIZE];
    char name[50];
} Player;

void initializeCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    int numbers[MAX_NUMBER + 1] = {0}; // To track used numbers
    int num;

    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            do {
                num = rand() % MAX_NUMBER + 1;
            } while (numbers[num]); // Ensure unique numbers
            card[i][j] = num;
            numbers[num] = 1; // Mark as used
        }
    }
    card[2][2] = 0; // Free space in the center
}

void printCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    printf("B   I   N   G   O\n");
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card[i][j] == 0)
                printf(" *  ");
            else
                printf("%-3d ", card[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void markNumber(Player *player, int number) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (player->card[i][j] == number) {
                player->marked[i][j] = 1; // Mark as found
            }
        }
    }
}

int checkWin(Player *player) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        // Check rows and columns
        if ((player->marked[i][0] && player->marked[i][1] && player->marked[i][2] && player->marked[i][3] && player->marked[i][4]) ||
            (player->marked[0][i] && player->marked[1][i] && player->marked[2][i] && player->marked[3][i] && player->marked[4][i])) {
            return 1; // Win found
        }
    }
    // Check diagonals
    if ((player->marked[0][0] && player->marked[1][1] && player->marked[2][2] && player->marked[3][3] && player->marked[4][4]) ||
        (player->marked[0][4] && player->marked[1][3] && player->marked[2][2] && player->marked[3][1] && player->marked[4][0])) {
        return 1; // Win found
    }
    return 0; // No win
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int playerCount, numberDrawn, drawCount = 0;

    // User input for player count
    printf("Welcome to the Cyberpunk Bingo Arena!\n");
    printf("How many players? (Max %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    if (playerCount > MAX_PLAYERS) playerCount = MAX_PLAYERS;

    // Initialize cards for each player
    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        initializeCard(players[i].card);
        for (int j = 0; j < BINGO_SIZE; j++)
            for (int k = 0; k < BINGO_SIZE; k++)
                players[i].marked[j][k] = 0; // Initialize marked
        printf("\n%s's Bingo Card:\n", players[i].name);
        printCard(players[i].card);
    }

    // The Bingo game loop
    while (1) {
        usleep(500000); // Pause for effect
        numberDrawn = rand() % MAX_NUMBER + 1;
        printf("Number drawn: %d\n", numberDrawn);

        // Mark the drawn number for each player
        for (int i = 0; i < playerCount; i++) {
            markNumber(&players[i], numberDrawn);
            if (checkWin(&players[i])) {
                printf("%s shouts BINGO!\n", players[i].name);
                return 0; // Game ends
            }
        }
        drawCount++;
        if (drawCount > 100) { // End after 100 draws to avoid infinite loop
            printf("Too many draws, the game is over!\n");
            break;
        }
    }
    return 0;
}