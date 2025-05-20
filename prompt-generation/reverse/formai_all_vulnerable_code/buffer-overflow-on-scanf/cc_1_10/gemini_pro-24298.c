//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10

// Player struct
typedef struct {
    char name[20];
    int score;
} Player;

// Function to sanitize user input
char *sanitize_input(char *str) {
    // Allocate memory for the sanitized string
    char *sanitized_str = malloc(strlen(str) + 1);
    if (sanitized_str == NULL) {
        return NULL;
    }

    // Copy the string to the sanitized string
    strcpy(sanitized_str, str);

    // Replace any non-alphanumeric characters with spaces
    for (int i = 0; i < strlen(sanitized_str); i++) {
        if (!isalnum(sanitized_str[i])) {
            sanitized_str[i] = ' ';
        }
    }

    // Return the sanitized string
    return sanitized_str;
}

// Main function
int main() {
    // Initialize the players array
    Player players[MAX_PLAYERS];

    // Get the number of players
    int num_players;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    // Get the player names and scores
    for (int i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf(" %20[^\n]", players[i].name);

        printf("Enter the score of player %d: ", i + 1);
        scanf(" %d", &players[i].score);
    }

    // Sanitize the player names
    for (int i = 0; i < num_players; i++) {
        char *sanitized_name = sanitize_input(players[i].name);
        if (sanitized_name == NULL) {
            printf("Error sanitizing player name.\n");
            return EXIT_FAILURE;
        }
        strcpy(players[i].name, sanitized_name);
        free(sanitized_name);
    }

    // Print the player names and scores
    printf("Player Scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    return EXIT_SUCCESS;
}