//Gemma-7B DATASET v1.0 Category: Table Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYER_COUNT 2

typedef struct Player {
    char name[20];
    int score;
} Player;

void initializePlayers(Player *players, int count) {
    for (int i = 0; i < count; i++) {
        players[i].score = 0;
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
    }
}

void playGame(Player *players, int count) {
    for (int round = 0; round < 3; round++) {
        for (int i = 0; i < count; i++) {
            printf("Player %s, enter your roll: ", players[i].name);
            int roll = rand() % 6 + 1;
            players[i].score += roll;
            printf("You rolled a %d. Your total score is %d.\n", roll, players[i].score);
        }

        // Calculate the winner
        int winner = -1;
        for (int i = 0; i < count; i++) {
            if (players[i].score >= 100) {
                winner = i;
            }
        }

        // Announce the winner
        if (winner != -1) {
            printf("Congratulations, %s, you are the winner!\n", players[winner].name);
        } else {
            printf("No winner!\n");
        }
    }
}

int main() {
    Player players[MAX_PLAYER_COUNT];
    initializePlayers(players, MAX_PLAYER_COUNT);
    playGame(players, MAX_PLAYER_COUNT);

    return 0;
}