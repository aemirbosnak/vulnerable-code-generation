//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int player;
    int score;
    int dice[2];
    int rolls;
    int turn;
    char name[20];
} player;

int main() {
    srand(time(NULL));

    player players[3];
    int i;

    for (i = 0; i < 3; i++) {
        players[i].player = i + 1;
        players[i].score = 0;
        players[i].dice[0] = (rand() % 6) + 1;
        players[i].dice[1] = (rand() % 6) + 1;
        players[i].rolls = 0;
        players[i].turn = 0;
        strcpy(players[i].name, "Player ");
        sprintf(players[i].name + 5, "%d", i + 1);
    }

    int currentPlayer = 0;
    int currentRoll = 0;
    int roll = 0;

    while (currentRoll < 100) {
        printf("--------------------------------------\n");
        printf("Player %d's Turn\n", currentPlayer);
        printf("Dice: %d, %d\n", players[currentPlayer].dice[0], players[currentPlayer].dice[1]);
        printf("Rolls: %d\n", players[currentPlayer].rolls);
        printf("Score: %d\n", players[currentPlayer].score);
        printf("Name: %s\n", players[currentPlayer].name);

        if (players[currentPlayer].rolls < 100) {
            printf("Roll the dice: ");
            scanf("%d", &roll);

            if (roll >= players[currentPlayer].dice[0] && roll <= players[currentPlayer].dice[1]) {
                players[currentPlayer].score++;
                players[currentPlayer].rolls++;
            } else {
                players[currentPlayer].score = 0;
                players[currentPlayer].rolls = 0;
                currentRoll = 0;
            }

            printf("Player %d's score: %d\n", currentPlayer, players[currentPlayer].score);
            currentRoll++;
        } else {
            printf("Player %d's turn is over\n", currentPlayer);
            currentPlayer++;
            if (currentPlayer == 3) {
                currentPlayer = 0;
            }
        }
    }

    printf("--------------------------------------\n");
    printf("Game Over!\n");

    for (i = 0; i < 3; i++) {
        printf("Player %d: %s\n", i + 1, players[i].name);
        printf("Score: %d\n", players[i].score);
    }

    return 0;
}