//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define DATA_SIZE 100

typedef struct {
    char name[30];
    int score;
} Player;

typedef struct {
    char data[DATA_SIZE];
    int is_corrupted;
} DataBlock;

void initializeDataBlock(DataBlock *db) {
    for (int i = 0; i < DATA_SIZE; i++) {
        db->data[i] = 'A' + (rand() % 26);
    }
    // Mark some data as corrupted (randomly)
    int corrupted_count = rand() % 30 + 1; // corrupt 1 to 30 blocks
    for (int i = 0; i < corrupted_count; i++) {
        db->data[rand() % DATA_SIZE] = '*';
    }
    db->is_corrupted = 1; // Indicating that the data is corrupted
}

void printDataBlock(DataBlock *db) {
    printf("Data Block: ");
    for (int i = 0; i < DATA_SIZE; i++) {
        putchar(db->data[i]);
    }
    printf("\n");
}

void recoverData(Player *player, DataBlock *db) {
    char guess;
    printf("%s, enter your guess for a data character: ", player->name);
    scanf(" %c", &guess);

    int recovered = 0;
    for (int i = 0; i < DATA_SIZE; i++) {
        if (db->data[i] == '*') { // if the data is corrupted
            db->data[i] = guess;
            printf("%s recovered data: %c\n", player->name, guess);
            recovered = 1;
            player->score++;
            break; // only recover one block per turn
        }
    }

    if (!recovered) {
        printf("%s, no corruption was recovered with your guess.\n", player->name);
    }
}

void displayScores(Player players[], int num_players) {
    printf("\nScores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    srand(time(NULL));
    
    Player players[MAX_PLAYERS];
    int num_players;
    DataBlock db;

    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    if (num_players > MAX_PLAYERS) {
        printf("Too many players! Exiting.\n");
        return 1;
    }

    for (int i = 0; i < num_players; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0; // initialize player score
    }

    initializeDataBlock(&db);
    printf("Initial data block has been set.\n");
    printDataBlock(&db);

    int turns = 5; // limited rounds for recovery attempts
    for (int i = 0; i < turns; i++) {
        for (int j = 0; j < num_players; j++) {
            recoverData(&players[j], &db);
            printDataBlock(&db);
        }
    }

    printf("Game over! Final results:\n");
    displayScores(players, num_players);
    
    return 0;
}