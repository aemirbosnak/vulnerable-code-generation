//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PLAYERS 10
#define MAX_PLAYER_NAME_LENGTH 50
#define MAX_COMMAND_LENGTH 100

typedef struct player {
    char name[MAX_PLAYER_NAME_LENGTH];
    int id;
    int score;
} Player;

typedef struct {
    int num_players;
    Player players[MAX_PLAYERS];
} GameState;

void *monitor_ram_usage(void *arg) {
    int interval = 5; // seconds
    while (1) {
        sleep(interval);
        system("free -h >> ram_usage.log");
    }
    return NULL;
}

int main() {
    pthread_t thread_id;
    int choice, player_count = 0;
    char command[MAX_COMMAND_LENGTH];
    GameState game_state = {0};

    // Initialize game state
    game_state.num_players = 0;

    // Main menu loop
    while (1) {
        printf("\n=== Multiplayer RAM Usage Monitor ===\n");
        printf("1. Join game\n");
        printf("2. Start game\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (player_count >= MAX_PLAYERS) {
                printf("Game is full.\n");
            } else {
                printf("Enter your name: ");
                scanf("%s", game_state.players[player_count].name);
                game_state.players[player_count].id = player_count + 1;
                game_state.players[player_count].score = 0;
                player_count++;
            }
            break;
        case 2:
            if (player_count < 2) {
                printf("Not enough players to start game.\n");
            } else {
                pthread_create(&thread_id, NULL, monitor_ram_usage, NULL);
                printf("Game started.\n");
            }
            break;
        case 3:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}