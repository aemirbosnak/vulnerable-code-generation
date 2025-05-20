//FormAI DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define MAX_PLAYERS 4

// Player structure
typedef struct player {
    int id;
    int position;
} Player;

// Function to generate a random number between x and y
int get_random_number(int x, int y) {
    return rand() % (y - x + 1) + x;
}

int main() {
    int num_players, winner = 0;
    Player players[MAX_PLAYERS];
    // Initialize board with 0s
    int board[BOARD_SIZE] = {0};
    // Set some random positions as start positions
    board[get_random_number(0, BOARD_SIZE-1)] = 1;
    board[get_random_number(0, BOARD_SIZE-1)] = 2;
    board[get_random_number(0, BOARD_SIZE-1)] = 3;
    board[get_random_number(0, BOARD_SIZE-1)] = 4;
    
    // Get number of players
    printf("Enter the number of players (Max: %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    if (num_players > MAX_PLAYERS) {
        printf("Maximum players allowed is %d. And set for %d player\n", MAX_PLAYERS, MAX_PLAYERS);
        num_players = MAX_PLAYERS;
    }
    
    // Initialize players
    for (int i = 0; i < num_players; i++) {
        players[i].id = i+1;
        players[i].position = 0;
    }
    
    // Game loop
    while (!winner) {
        // Iterate over each player
        for (int i = 0; i < num_players; i++) {
            // Roll the dice
            int dice_value = get_random_number(1, 6);
            printf("Player %d rolled a %d\n", players[i].id, dice_value);
            // Update player position
            players[i].position += dice_value;
            if (players[i].position >= BOARD_SIZE) {
                winner = players[i].id;
                break;
            }
            // Move the player on the board
            board[players[i].position] = players[i].id;
            // Print the board
            printf("Board state after player %d's move:\n", players[i].id);
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[j]) {
                    printf("%d ", board[j]);
                } else {
                    printf(". ");
                }
            }
            printf("\n");
            // Remove player from the previous position on the board
            board[players[i].position-dice_value] = 0;
        }
    }
    printf("Player %d is the winner!\n", winner);
    return 0;
}