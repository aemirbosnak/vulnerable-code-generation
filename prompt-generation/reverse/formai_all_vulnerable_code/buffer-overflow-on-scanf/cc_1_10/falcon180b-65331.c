//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PLAYERS 10
#define MAX_POINTS 100
#define PI 3.14159

typedef struct {
    char name[20];
    int points;
} Player;

void initPlayers(Player* players) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "Player");
        players[i].points = 0;
    }
}

void displayLeaderboard(Player* players) {
    printf("Leaderboard:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%d. %s - %d points\n", i+1, players[i].name, players[i].points);
    }
}

void playGame(Player* players, int numPlayers) {
    char input[20];
    int choice;
    int correctAnswers = 0;
    int totalQuestions = 10;
    int pointsEarned = 0;

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of player %d:\n", i+1);
        scanf("%s", players[i].name);
    }

    for (int i = 0; i < totalQuestions; i++) {
        printf("Question %d:\n", i+1);
        scanf("%s", input);
        printf("Player %d's answer: %s\n", i+1, input);
        correctAnswers += (strcmp(input, "correct") == 0);
    }

    printf("End of game\n");
    printf("Final scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s - %d points\n", players[i].name, pointsEarned);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Enter the number of players (up to %d):\n", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    initPlayers(players);

    playGame(players, numPlayers);

    return 0;
}