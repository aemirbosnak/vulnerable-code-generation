//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <termios.h>
#include <fcntl.h>

#define MAX_PLAYERS 4
#define BUFFER_SIZE 256

typedef struct {
    int player_id;
    int position;
    pthread_t thread;
    int running;
} Player;

Player players[MAX_PLAYERS];

void *control_drone(void *arg) {
    Player *player = (Player *)arg;
    char command[BUFFER_SIZE];

    while (player->running) {
        printf("Player %d, enter command (FORWARD, BACKWARD, LEFT, RIGHT, STOP): ", player->player_id);
        fgets(command, BUFFER_SIZE, stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline

        if (strcmp(command, "FORWARD") == 0) {
            player->position++;
            printf("Player %d moved FORWARD to position %d\n", player->player_id, player->position);
        } else if (strcmp(command, "BACKWARD") == 0) {
            player->position--;
            printf("Player %d moved BACKWARD to position %d\n", player->player_id, player->position);
        } else if (strcmp(command, "LEFT") == 0) {
            printf("Player %d turned LEFT at position %d\n", player->player_id, player->position);
        } else if (strcmp(command, "RIGHT") == 0) {
            printf("Player %d turned RIGHT at position %d\n", player->player_id, player->position);
        } else if (strcmp(command, "STOP") == 0) {
            printf("Player %d has stopped.\n", player->player_id);
            break;
        } else {
            printf("Invalid command. Try again.\n");
        }
    }
    
    player->running = 0;
    return NULL;
}

void signal_handler(int signum) {
    printf("\nTerminating game...\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].running = 0;
        pthread_join(players[i].thread, NULL);
    }
    exit(0);
}

int main() {
    printf("Welcome to the Multiplayer Drone Control Game!\n");
    printf("Number of players (1 - %d): ", MAX_PLAYERS);
    
    int num_players;
    scanf("%d", &num_players);
    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting...\n");
        return 1;
    }

    signal(SIGINT, signal_handler);

    for (int i = 0; i < num_players; i++) {
        players[i].player_id = i + 1;
        players[i].position = 0;
        players[i].running = 1;
        pthread_create(&players[i].thread, NULL, control_drone, (void *)&players[i]);
    }

    for (int i = 0; i < num_players; i++) {
        pthread_join(players[i].thread, NULL);
    }

    printf("All players have stopped. Game Over!\n");
    return 0;
}