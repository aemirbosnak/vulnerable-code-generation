//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20
#define MAX_MESSAGE_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    double temperature;
    int is_celsius;
} player_t;

typedef struct {
    player_t players[MAX_PLAYERS];
    int num_players;
} game_state_t;

pthread_mutex_t lock;

void send_message(char *message) {
    pthread_mutex_lock(&lock);
    printf("%s\n", message);
    pthread_mutex_unlock(&lock);
}

void *player_thread(void *arg) {
    game_state_t *game_state = (game_state_t *)arg;
    char message[MAX_MESSAGE_LENGTH];
    double temperature;
    int is_celsius;

    while (1) {
        // Get input from the player.
        printf("%s, enter your temperature: ", game_state->players[0].name);
        scanf("%lf", &temperature);
        printf("%s, are you using Celsius (0) or Fahrenheit (1)? ", game_state->players[0].name);
        scanf("%d", &is_celsius);

        // Update the game state.
        pthread_mutex_lock(&lock);
        game_state->players[0].temperature = temperature;
        game_state->players[0].is_celsius = is_celsius;
        pthread_mutex_unlock(&lock);

        // Send a message to the other players.
        sprintf(message, "%s has set their temperature to %.1f degrees %s.", game_state->players[0].name, temperature, is_celsius ? "Celsius" : "Fahrenheit");
        send_message(message);
    }

    return NULL;
}

int main() {
    game_state_t game_state;
    pthread_t player_threads[MAX_PLAYERS];
    int i;

    // Initialize the game state.
    game_state.num_players = 0;

    // Create the player threads.
    for (i = 0; i < MAX_PLAYERS; i++) {
        pthread_create(&player_threads[i], NULL, player_thread, &game_state);
    }

    // Join the player threads.
    for (i = 0; i < MAX_PLAYERS; i++) {
        pthread_join(player_threads[i], NULL);
    }

    return 0;
}