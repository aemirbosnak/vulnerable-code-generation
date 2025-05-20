//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id;
    char name[50];
    int score;
    int level;
    int rank;
} Player;

typedef struct {
    char name[50];
    int score;
    int level;
    int rank;
} Game;

Player players[10];
Game game;

int main() {
    srand(time(NULL));

    int numPlayers = 0;
    int numGames = 0;

    printf("How many players are participating? ");
    scanf("%d", &numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        char name[50];
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", name);

        players[i].id = i + 1;
        strcpy(players[i].name, name);
        players[i].score = 0;
        players[i].level = 1;
        players[i].rank = 1;
    }

    printf("How many games are being played? ");
    scanf("%d", &numGames);

    for (int i = 0; i < numGames; i++) {
        char name[50];
        printf("Enter game %d's name: ", i + 1);
        scanf("%s", name);

        strcpy(game.name, name);
        game.score = 0;
        game.level = 1;
        game.rank = 1;
    }

    printf("Starting game...\n");

    for (int i = 0; i < numGames; i++) {
        printf("Game %d: %s\n", i + 1, game.name);

        int winner = -1;
        int highestScore = 0;

        for (int j = 0; j < numPlayers; j++) {
            if (rand() % 100 < players[j].level) {
                printf("Player %d: %s\n", j + 1, players[j].name);
                printf("Score: %d\n", players[j].score);

                if (players[j].score > highestScore) {
                    highestScore = players[j].score;
                    winner = j;
                }
            }
        }

        if (winner!= -1) {
            printf("Game %d winner: Player %d with score %d\n", i + 1, winner + 1, highestScore);

            for (int k = 0; k < numPlayers; k++) {
                if (k!= winner) {
                    players[k].score += highestScore - players[k].score;
                }
            }
        }

        game.score += highestScore;
        game.level++;
        game.rank++;
    }

    for (int i = 0; i < numGames; i++) {
        printf("Game %d: %s\n", i + 1, game.name);

        int winner = -1;
        int highestScore = 0;

        for (int j = 0; j < numPlayers; j++) {
            if (rand() % 100 < players[j].level) {
                printf("Player %d: %s\n", j + 1, players[j].name);
                printf("Score: %d\n", players[j].score);

                if (players[j].score > highestScore) {
                    highestScore = players[j].score;
                    winner = j;
                }
            }
        }

        if (winner!= -1) {
            printf("Game %d winner: Player %d with score %d\n", i + 1, winner + 1, highestScore);

            for (int k = 0; k < numPlayers; k++) {
                if (k!= winner) {
                    players[k].score += highestScore - players[k].score;
                }
            }
        }

        game.score += highestScore;
        game.level++;
        game.rank++;
    }

    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: %s\n", i + 1, players[i].name);
        printf("Score: %d\n", players[i].score);
        printf("Level: %d\n", players[i].level);
        printf("Rank: %d\n", players[i].rank);
    }

    printf("Game %d: %s\n", 1, game.name);
    printf("Score: %d\n", game.score);
    printf("Level: %d\n", game.level);
    printf("Rank: %d\n", game.rank);

    return 0;
}