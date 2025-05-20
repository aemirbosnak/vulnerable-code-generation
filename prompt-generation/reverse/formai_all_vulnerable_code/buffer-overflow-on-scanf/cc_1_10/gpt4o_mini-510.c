//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 5
#define BOARD_SIZE 10

typedef struct {
    char name[30];
    int position;
} Player;

void initializePlayers(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].position = 0;
    }
}

void printBoard(Player players[], int playerCount) {
    printf("\nBoard:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i);
        for (int j = 0; j < playerCount; j++) {
            if (players[j].position == i) {
                printf("[%s] ", players[j].name);
                goto next;
            }
        }
        printf(" - ");
    next:
        printf("\n");
    }
    printf("\n");
}

int rollDice() {
    return (rand() % 6) + 1; // Roll between 1 and 6
}

int movePlayer(Player *player, int diceRoll) {
    player->position += diceRoll;
    if (player->position >= BOARD_SIZE) {
        player->position = BOARD_SIZE - 1; // Not surpassing the last cell
        printf("%s reached the end of the board!\n", player->name);
        return 1; // Indicating player has reached the end
    }
    return 0; // Player hasn't reached the end
}

void playGame(Player players[], int playerCount) {
    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("----- Round %d -----\n", round);
        for (int currentPlayer = 0; currentPlayer < playerCount; currentPlayer++) {
            printf("%s's turn:\n", players[currentPlayer].name);
            int diceRoll = rollDice();
            printf("Rolled a %d!\n", diceRoll);
            if (movePlayer(&players[currentPlayer], diceRoll)) {
                printf("%s wins!\n", players[currentPlayer].name);
                return;
            }
            printBoard(players, playerCount);
        }
    }
    printf("Game over! No one reached the end.\n");
}

int main() {
    srand(time(NULL)); // Random seed
    Player players[MAX_PLAYERS];
    int playerCount;

    printf("Welcome to the Artistic Dice Game!\n");
    printf("How many players (2 - 4)? ");
    scanf("%d", &playerCount);
    if (playerCount < 2 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting...\n");
        return 1;
    }

    initializePlayers(players, playerCount);
    playGame(players, playerCount);

    printf("Thank you for playing!\n");
    return 0;
}