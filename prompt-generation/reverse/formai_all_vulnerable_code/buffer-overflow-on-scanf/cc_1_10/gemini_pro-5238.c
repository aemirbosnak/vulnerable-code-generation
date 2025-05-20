//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PLAYERS 4

typedef struct {
    char *name;
    int score;
} player_t;

typedef struct {
    player_t players[MAX_PLAYERS];
    int num_players;
} game_t;

game_t game;

void *player_thread(void *arg) {
    player_t *player = (player_t *)arg;

    while (1) {
        // Get a word from the user
        char word[100];
        printf("%s's turn: ", player->name);
        scanf("%s", word);

        // Check if the word is valid
        if (strlen(word) < 3 || strlen(word) > 10) {
            printf("Invalid word: %s\n", word);
            continue;
        }

        // Add the word to the game
        int score = 0;
        for (int i = 0; i < strlen(word); i++) {
            score += word[i] - 'a' + 1;
        }
        player->score += score;

        // Check if the player has won
        if (player->score >= 100) {
            printf("%s wins!\n", player->name);
            exit(0);
        }
    }

    return NULL;
}

int main() {
    // Initialize the game
    game.num_players = 0;

    // Get the player names
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", game.players[i].name);
        game.num_players++;
    }

    // Create a thread for each player
    pthread_t threads[MAX_PLAYERS];
    for (int i = 0; i < game.num_players; i++) {
        pthread_create(&threads[i], NULL, player_thread, &game.players[i]);
    }

    // Wait for all the threads to finish
    for (int i = 0; i < game.num_players; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}