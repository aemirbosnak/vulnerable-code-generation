//Falcon-180B DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10
#define MAX_SCORE 100

// Struct to hold player information
typedef struct {
    char name[20];
    int score;
} Player;

// Function to initialize the game
void initGame(Player players[]) {
    int i;
    for (i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
    printf("\n");
}

// Function to display the scoreboard
void displayScoreboard(Player players[]) {
    int i;
    printf("\nScoreboard:\n");
    for (i = 0; i < MAX_PLAYERS; i++) {
        printf("%d. %s - %d points\n", i + 1, players[i].name, players[i].score);
    }
    printf("\n");
}

// Function to roll the dice
int rollDice() {
    return rand() % 6 + 1;
}

// Function to play one round of the game
void playRound(Player players[]) {
    int i, j, maxScore = 0;
    for (i = 0; i < MAX_PLAYERS; i++) {
        players[i].score += rollDice() + rollDice();
        if (players[i].score > maxScore) {
            maxScore = players[i].score;
        }
    }
    for (j = 0; j < MAX_PLAYERS; j++) {
        if (players[j].score == maxScore) {
            printf("%s wins the round with %d points!\n", players[j].name, maxScore);
        } else {
            printf("%s scores %d points.\n", players[j].name, players[j].score);
        }
    }
}

// Function to play multiple rounds of the game
void playGame(Player players[]) {
    int i;
    for (i = 0; i < MAX_ROUNDS; i++) {
        playRound(players);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    initGame(players);
    srand(time(NULL));
    playGame(players);
    return 0;
}