//FormAI DATASET v1.0 Category: Database simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

typedef struct {
    Player players[MAX_PLAYERS];
    int numPlayers;
} Leaderboard;

void initializeLeaderboard(Leaderboard *board) {
    board->numPlayers = 0;
}

void addPlayer(Leaderboard *board, char *name) {
    if (board->numPlayers == MAX_PLAYERS) {
        printf("The leaderboard is already full.\n");
        return;
    }

    for (int i = 0; i < board->numPlayers; i++) {
        if (strcmp(name, board->players[i].name) == 0) {
            printf("A player with that name already exists.\n");
            return;
        }
    }

    Player newPlayer;
    strcpy(newPlayer.name, name);
    newPlayer.score = 0;
    board->players[board->numPlayers] = newPlayer;
    board->numPlayers++;

    printf("%s has been added to the leaderboard.\n", name);
}

void printLeaderboard(Leaderboard *board) {
    printf("LEADERBOARD\n");
    printf("-----------\n");

    for (int i = 0; i < board->numPlayers; i++) {
        printf("%d. %s - %d\n", i + 1, board->players[i].name, board->players[i].score);
    }
}

void incrementScore(Leaderboard *board, char *name) {
    for (int i = 0; i < board->numPlayers; i++) {
        if (strcmp(name, board->players[i].name) == 0) {
            board->players[i].score++;
            return;
        }
    }
    printf("A player with that name does not exist.\n");
}

void simulateGame(Leaderboard *board) {
    srand(time(NULL));
    int numPlayers;
    printf("How many players are in the game?\n");
    scanf("%d", &numPlayers);

    if (numPlayers > board->numPlayers) {
        printf("There are not enough players in the leaderboard to simulate a game with that many players.\n");
        return;
    }

    Player players[MAX_PLAYERS];
    for (int i = 0; i < numPlayers; i++) {
        int index = rand() % board->numPlayers;
        players[i] = board->players[index];
    }

    printf("The players in the game are:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s\n", players[i].name);
    }

    int winningIndex = rand() % numPlayers;
    incrementScore(board, players[winningIndex].name);
    printf("%s has won the game!\n", players[winningIndex].name);

    printf("Updated leaderboard:\n");
    printLeaderboard(board);
}

int main() {
    Leaderboard board;
    initializeLeaderboard(&board);

    addPlayer(&board, "Alice");
    addPlayer(&board, "Bob");
    addPlayer(&board, "Charlie");

    printf("\n");
    printLeaderboard(&board);
    printf("\n");

    incrementScore(&board, "Alice");
    incrementScore(&board, "Bob");
    incrementScore(&board, "Charlie");

    printf("\n");
    printLeaderboard(&board);
    printf("\n");

    simulateGame(&board);

    return 0;
}