//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYER 2

typedef struct Player {
    char name[20];
    int score;
    int is_active;
} Player;

int main() {
    Player players[MAX_PLAYER];
    int i, game_state, current_player = 0;

    // Initialize players
    for (i = 0; i < MAX_PLAYER; i++) {
        players[i].name[0] = '\0';
        players[i].score = 0;
        players[i].is_active = 1;
    }

    // Game loop
    while (1) {
        // Display current player's name and score
        printf("Current player: %s\n", players[current_player].name);
        printf("Score: %d\n", players[current_player].score);

        // Get player's input
        char input[20];
        printf("Enter your answer: ");
        scanf("%s", input);

        // Check if answer is valid
        if (valid_answer(input)) {
            // Calculate points
            int points = calculate_points(input);

            // Add points to current player's score
            players[current_player].score += points;

            // Next player
            current_player = (current_player + 1) % MAX_PLAYER;
        } else {
            printf("Invalid answer.\n");
        }

        // Check if game is over
        if (players[0].score >= 100 || players[1].score >= 100) {
            printf("Game over!\n");
            break;
        }
    }

    // Final scores
    for (i = 0; i < MAX_PLAYER; i++) {
        printf("%s's final score: %d\n", players[i].name, players[i].score);
    }

    return 0;
}

int valid_answer(char *input) {
    // Check if input is within allowed length
    if (strlen(input) > 20) {
        return 0;
    }

    // Check if input contains invalid characters
    for (int i = 0; i < strlen(input); i++) {
        if (!isalnum(input[i])) {
            return 0;
        }
    }

    return 1;
}

int calculate_points(char *input) {
    // Calculate points based on input
    int points = 0;
    // Logic to calculate points based on input
    return points;
}