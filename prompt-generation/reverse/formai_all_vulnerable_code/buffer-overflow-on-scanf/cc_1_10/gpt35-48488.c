//FormAI DATASET v1.0 Category: Image Editor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define global constants
#define MAX_PLAYERS 4
#define MAX_COMMAND_LENGTH 25

// Define a struct to represent a player
typedef struct {
    int id;
    char name[20];
    int score;
} Player;

// Define function to handle each player's turn
void handlePlayerTurn(Player *player) {
    char command[MAX_COMMAND_LENGTH];

    // Get the player's command
    printf("%s's turn. Please enter a command: ", player->name);
    scanf("%s", command);

    // Process the command
    if (strcmp(command, "draw") == 0) {
        // Add points to player's score
        player->score += 10;
        printf("%s: You drew a picture!\n", player->name);
    } else if (strcmp(command, "edit") == 0) {
        // Subtract points from player's score
        player->score -= 5;
        printf("%s: You edited a picture!\n", player->name);
    } else {
        printf("%s: Invalid command.\n", player->name);
    }
}

int main() {
    // Define variables
    int numPlayers = 0;
    Player players[MAX_PLAYERS];

    printf("Welcome to the C Image Editor game!\n");

    // Get the number of players
    do {
        printf("How many players (1-4)? ");
        scanf("%d", &numPlayers);
    } while (numPlayers < 1 || numPlayers > 4);

    // Get each player's information
    for (int i = 0; i < numPlayers; i++) {
        Player player;
        player.id = i + 1;

        printf("Enter name for player %d: ", player.id);
        scanf("%s", player.name);

        player.score = 0;

        players[i] = player;
    }

    // Play the game
    int currentPlayerIndex = 0;
    while (1) {
        // Get the current player
        Player *currentPlayer = &players[currentPlayerIndex];

        // Handle the current player's turn
        handlePlayerTurn(currentPlayer);

        // Print each player's score
        printf("Scores:\n");
        for (int i = 0; i < numPlayers; i++) {
            printf("%s: %d\n", players[i].name, players[i].score);
        }

        // Check if the game is over (i.e. all players have taken a turn)
        int gameOver = 1;
        for (int i = 0; i < numPlayers; i++) {
            if (players[i].score >= 50) {
                printf("%s wins with a score of %d!\n", players[i].name, players[i].score);
                return 0;
            }

            if (i != currentPlayerIndex && players[i].score < 50) {
                gameOver = 0;
            }
        }

        // If game is over, declare a tie
        if (gameOver) {
            printf("It's a tie!\n");
            return 0;
        }

        // Move to the next player
        currentPlayerIndex = (currentPlayerIndex + 1) % numPlayers;
    }

    return 0;
}