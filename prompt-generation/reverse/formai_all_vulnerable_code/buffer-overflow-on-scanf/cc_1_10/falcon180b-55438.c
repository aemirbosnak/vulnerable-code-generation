//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define DICE_SIDES 6
#define WINNING_SCORE 100

typedef struct {
    char name[20];
    int score;
    int turn;
} Player;

void rollDice(int* dice) {
    *dice = rand() % DICE_SIDES + 1;
}

void printDice(int dice) {
    printf("You rolled a %d!\n", dice);
}

int main() {
    srand(time(NULL));
    int numPlayers;
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    Player players[MAX_PLAYERS];

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
        players[i].turn = 0;
    }

    int currentPlayer = 0;
    int currentScore = 0;

    while (currentScore < WINNING_SCORE && currentPlayer < numPlayers) {
        printf("Player %s's turn.\n", players[currentPlayer].name);
        rollDice(&currentScore);
        currentScore += players[currentPlayer].turn;
        printDice(currentScore);

        if (currentScore >= WINNING_SCORE) {
            printf("Congratulations, %s has won the game!\n", players[currentPlayer].name);
            break;
        }

        currentPlayer = (currentPlayer + 1) % numPlayers;
        players[currentPlayer].turn++;
    }

    return 0;
}