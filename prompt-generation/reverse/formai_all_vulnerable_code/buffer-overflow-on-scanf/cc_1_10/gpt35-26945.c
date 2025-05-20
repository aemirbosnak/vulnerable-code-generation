//FormAI DATASET v1.0 Category: QR code reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PLAYERS 2

// Structure to hold player data
typedef struct {
    char name[50];
    int score;
} Player;

// Initialize players with empty names and 0 scores
void initPlayers(Player players[]) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        strcpy(players[i].name, "");
        players[i].score = 0;
    }
}

// Read a QR code and return the code as a string
char* readQRCode() {
    char* code = (char*) malloc(sizeof(char) * 50);
    printf("Scan QR code: ");
    scanf("%s", code);
    return code;
}

// Simulate processing of a QR code
void processQRCode(char* code, Player* player) {
    if (strcmp(code, "CORRECT_CODE") == 0) {
        player->score++;
        printf("Code processed successfully. Score: %d\n", player->score);
    } else {
        printf("Incorrect code. Try again.\n");
    }
}

// Print the scores of all players
void printScores(Player players[]) {
    printf("Scores:\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    Player players[NUM_PLAYERS];
    char* code;
    int currentPlayer = 0;

    initPlayers(players);

    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    while (1) {
        printf("%s's turn.\n", players[currentPlayer].name);
        code = readQRCode();
        processQRCode(code, &players[currentPlayer]);
        printScores(players);
        free(code);
        
        // If a player reaches a score of 10, end the game
        if (players[currentPlayer].score == 10) {
            printf("%s wins! Game over.\n", players[currentPlayer].name);
            break;
        }
        
        // Move on to the next player
        currentPlayer = (currentPlayer + 1) % NUM_PLAYERS;
    }

    return 0;
}