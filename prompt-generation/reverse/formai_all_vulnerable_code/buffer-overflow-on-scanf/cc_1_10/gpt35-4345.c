//FormAI DATASET v1.0 Category: File handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

void writeScoresToFile(Player players[]) {
    FILE *fp = fopen("scores.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing\n");
        return;
    }
    for (int i = 0; i < MAX_PLAYERS; i++) {
        fprintf(fp, "%s %d\n", players[i].name, players[i].score);
    }
    fclose(fp);
}

void readScoresFromFile(Player players[]) {
    FILE *fp = fopen("scores.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading\n");
        return;
    }
    for (int i = 0; i < MAX_PLAYERS; i++) {
        fscanf(fp, "%s %d", players[i].name, &players[i].score);
    }
    fclose(fp);
}

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Welcome to the Multiplayer File Handling Game!\n");
    printf("Enter the number of players (1-4): ");
    scanf("%d", &numPlayers);

    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players\n");
        return 1;
    }

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    writeScoresToFile(players);

    int round = 1;
    while (round <= 3) {
        printf("=== Round %d ===\n", round);
        for (int i = 0; i < numPlayers; i++) {
            printf("It's %s's turn\n", players[i].name);
            printf("Enter score for this round: ");
            int score;
            scanf("%d", &score);
            players[i].score += score;
        }
        round++;
    }

    writeScoresToFile(players);

    printf("\nGame over!\nFinal scores:\n");
    readScoresFromFile(players);

    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strcmp(players[i].name, "") == 0) {
            break;
        }
        printf("%s's score is %d\n", players[i].name, players[i].score);
    }

    return 0;
}