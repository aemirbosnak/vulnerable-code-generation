//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20
#define MAX_MATRIX_SIZE 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    int matrix_size;
    int score;
} player;

player players[MAX_PLAYERS];
int num_players;

void print_matrix(int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Get number of players
    printf("Enter number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    // Get player names
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d name: ", i + 1);
        scanf("%s", players[i].name);
    }

    // Generate random matrices for players
    for (int i = 0; i < num_players; i++) {
        players[i].matrix_size = rand() % MAX_MATRIX_SIZE + 1;
        for (int j = 0; j < players[i].matrix_size; j++) {
            for (int k = 0; k < players[i].matrix_size; k++) {
                players[i].matrix[j][k] = rand() % 10;
            }
        }
    }

    // Print player matrices
    for (int i = 0; i < num_players; i++) {
        printf("Player %s matrix:\n", players[i].name);
        print_matrix(players[i].matrix, players[i].matrix_size);
        printf("\n");
    }

    // Calculate player scores
    for (int i = 0; i < num_players; i++) {
        players[i].score = 0;
        for (int j = 0; j < players[i].matrix_size; j++) {
            for (int k = 0; k < players[i].matrix_size; k++) {
                players[i].score += players[i].matrix[j][k];
            }
        }
    }

    // Print player scores
    for (int i = 0; i < num_players; i++) {
        printf("Player %s score: %d\n", players[i].name, players[i].score);
    }

    // Determine winner
    int max_score = 0;
    char winner[MAX_NAME_LENGTH];
    for (int i = 0; i < num_players; i++) {
        if (players[i].score > max_score) {
            max_score = players[i].score;
            strcpy(winner, players[i].name);
        }
    }

    // Print winner
    printf("The winner is %s with a score of %d\n", winner, max_score);

    return 0;
}