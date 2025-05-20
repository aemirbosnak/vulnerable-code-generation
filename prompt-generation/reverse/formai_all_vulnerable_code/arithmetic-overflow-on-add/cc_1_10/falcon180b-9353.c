//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20

// Define the data structure for each player
typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

// Define the data structure for the game
typedef struct {
    Player players[MAX_PLAYERS];
    int num_players;
    int current_player;
} Game;

// Function to initialize the game with a given number of players
void init_game(Game* game, int num_players) {
    game->num_players = num_players;
    game->current_player = 0;
    for (int i = 0; i < num_players; i++) {
        game->players[i].score = 0;
        strcpy(game->players[i].name, "");
    }
}

// Function to add a player to the game
void add_player(Game* game, char* name) {
    if (game->num_players >= MAX_PLAYERS) {
        printf("Error: Maximum number of players reached.\n");
        return;
    }
    strcpy(game->players[game->num_players].name, name);
    game->num_players++;
}

// Function to start the game
void start_game(Game* game) {
    printf("Starting game...\n");
    for (int i = 0; i < game->num_players; i++) {
        printf("Player %d: %s\n", i+1, game->players[i].name);
    }
    game->current_player = 0;
}

// Function to display the current player's name and score
void display_current_player(Game* game) {
    printf("Current player: %s\n", game->players[game->current_player].name);
    printf("Current score: %d\n", game->players[game->current_player].score);
}

// Function to update the current player's score
void update_score(Game* game, int score) {
    game->players[game->current_player].score += score;
}

// Function to switch to the next player
void switch_player(Game* game) {
    game->current_player = (game->current_player + 1) % game->num_players;
}

// Main function for the game
int main() {
    Game game;
    init_game(&game, 2);
    add_player(&game, "Player 1");
    add_player(&game, "Player 2");
    start_game(&game);
    for (int i = 0; i < 10; i++) {
        int player_score = rand() % 100;
        update_score(&game, player_score);
        switch_player(&game);
        display_current_player(&game);
    }
    return 0;
}