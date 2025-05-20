//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_TURNS 10
#define BOARD_SIZE 10

typedef struct {
    char name[30];
    int position;
    int score;
} Player;

void initializePlayers(Player players[], int count);
void printBoard(Player players[], int count);
void rollDice(Player *player);
int checkWinner(Player players[], int count);
void playGame(Player players[], int count);

int main() {
    int playerCount;
    Player players[MAX_PLAYERS];

    printf("Welcome to the C Table Game!\n");
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    
    if (playerCount < 1 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    initializePlayers(players, playerCount);
    playGame(players, playerCount);

    return 0;
}

void initializePlayers(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].position = 0;
        players[i].score = 0;
    }
}

void printBoard(Player players[], int count) {
    printf("\n--- Game Board ---\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for (int i = 0; i < count; i++) {
        printf("%s: ", players[i].name);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (players[i].position == j) {
                printf("P ");
            } else {
                printf("- ");
            }
        }
        printf(" | Score: %d\n", players[i].score);
    }
    printf("\n");
}

void rollDice(Player *player) {
    int roll = (rand() % 6) + 1;
    printf("%s rolls a %d\n", player->name, roll);
    player->position += roll;
    if (player->position >= BOARD_SIZE) {
        player->position = BOARD_SIZE - 1;
    }
    player->score += roll;
}

int checkWinner(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        if (players[i].position == BOARD_SIZE - 1) {
            return i; // Return index of winning player
        }
    }
    return -1; // No winner yet
}

void playGame(Player players[], int count) {
    srand(time(0));
    int turns = 0;

    while (turns < MAX_TURNS) {
        for (int i = 0; i < count; i++) {
            rollDice(&players[i]);
            printBoard(players, count);

            int winnerIndex = checkWinner(players, count);
            if (winnerIndex != -1) {
                printf("Congratulations %s! You've won the game with a score of %d!\n", 
                        players[winnerIndex].name, players[winnerIndex].score);
                return;
            }
        }
        turns++;
    }
    
    printf("Game over! No winner in %d turns.\n", MAX_TURNS);
}