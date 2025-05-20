//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_TEXT_SIZE 1024

struct player {
    char name[32];
    int score;
    char text[MAX_TEXT_SIZE];
};

struct game {
    struct player players[MAX_PLAYERS];
    int num_players;
    char text[MAX_TEXT_SIZE];
    int turn;
};

void print_game(struct game *game) {
    printf("Game:\n");
    for (int i = 0; i < game->num_players; i++) {
        printf("Player %d: %s (%d points)\n", i + 1, game->players[i].name, game->players[i].score);
    }
    printf("Text: %s\n", game->text);
    printf("Turn: %d\n", game->turn + 1);
}

void take_turn(struct game *game) {
    struct player *player = &game->players[game->turn];

    printf("Player %s, it's your turn.\n", player->name);
    printf("Enter your text: ");
    fgets(player->text, MAX_TEXT_SIZE, stdin);

    // Remove the newline character from the end of the text
    player->text[strlen(player->text) - 1] = '\0';

    // Increment the player's score
    player->score++;

    // Advance the turn to the next player
    game->turn = (game->turn + 1) % game->num_players;
}

int main() {
    struct game game;

    // Initialize the game
    game.num_players = 0;
    game.text[0] = '\0';
    game.turn = 0;

    // Get the names of the players
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter the name of player %d: ", i + 1);
        fgets(game.players[i].name, 32, stdin);

        // Remove the newline character from the end of the name
        game.players[i].name[strlen(game.players[i].name) - 1] = '\0';

        // Initialize the player's score to 0
        game.players[i].score = 0;

        // Initialize the player's text to an empty string
        game.players[i].text[0] = '\0';

        // Increment the number of players
        game.num_players++;
    }

    // Print the game
    print_game(&game);

    // Start the game loop
    while (1) {
        // Take a turn
        take_turn(&game);

        // Print the game
        print_game(&game);

        // Check if the game is over
        if (game.players[game.turn].score >= 10) {
            printf("Game over! Player %s wins!\n", game.players[game.turn].name);
            break;
        }
    }

    return 0;
}