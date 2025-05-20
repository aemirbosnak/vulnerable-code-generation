//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define MAX_PLAYERS 4
#define TIME_TRAVEL_DISTANCE 10

typedef struct {
    int player_id;
    int current_time;
    int destination_time;
    int travel_time;
} Player;

pthread_mutex_t lock;

void* time_travel(void* arg) {
    Player* player = (Player*)arg;

    printf("Player %d is traveling to time %d\n", player->player_id, player->destination_time);

    // Simulate time travel operation
    sleep(player->travel_time);

    pthread_mutex_lock(&lock);
    player->current_time = player->destination_time;
    printf("Player %d has arrived in the year %d\n", player->player_id, player->current_time);
    pthread_mutex_unlock(&lock);

    return NULL;
}

void display_menu() {
    printf("==== Time Travel Simulator ====\n");
    printf("1. Travel to the past\n");
    printf("2. Travel to the future\n");
    printf("3. Exit\n");
    printf("Choose your action: ");
}

int main() {
    pthread_t players[MAX_PLAYERS];
    Player player_data[MAX_PLAYERS];
    int player_count = 0;
    int option;
    
    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    while (1) {
        display_menu();
        scanf("%d", &option);

        if (option == 3) {
            printf("Exiting the Time Travel Simulator. Goodbye!\n");
            break;
        }
        
        if (player_count >= MAX_PLAYERS) {
            printf("Maximum players reached. Please wait for others to finish.\n");
            continue;
        }

        player_data[player_count].player_id = player_count + 1;

        // Get destination time based on option selected
        if (option == 1) { // Travel to the past
            player_data[player_count].destination_time = time(NULL) - (TIME_TRAVEL_DISTANCE * 365 * 24 * 60 * 60);
            player_data[player_count].travel_time = 2; // faster travel
        } else if (option == 2) { // Travel to the future
            player_data[player_count].destination_time = time(NULL) + (TIME_TRAVEL_DISTANCE * 365 * 24 * 60 * 60);
            player_data[player_count].travel_time = 5; // slower travel
        } else {
            printf("Invalid option. Please try again.\n");
            continue;
        }

        player_data[player_count].current_time = time(NULL);
        
        // Create a new thread for the player traveling
        if (pthread_create(&players[player_count], NULL, time_travel, &player_data[player_count])) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
        
        player_count++;
        
        // Wait for the thread to finish before allowing another input
        for (int i = 0; i < player_count; i++) {
            pthread_join(players[i], NULL);
        }
        
        printf("All players have completed their time travel.\n");
        player_count = 0; // reset player count for next round
    }

    // Clean up mutex
    pthread_mutex_destroy(&lock);
    return 0;
}