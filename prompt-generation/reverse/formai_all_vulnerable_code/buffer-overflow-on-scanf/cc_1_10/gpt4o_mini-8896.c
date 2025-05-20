//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_PLAYERS 5

typedef struct {
    int player_id;
    int terms;
} PlayerData;

void* fibonacci(void* arg) {
    PlayerData *data = (PlayerData *)arg;
    int n = data->terms;
    unsigned long long fib[n];
    
    // Calculate Fibonacci sequence
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Print Fibonacci sequence for the player
    printf("Player %d: ", data->player_id);
    for(int i = 0; i < n; i++) {
        printf("%llu ", fib[i]);
    }
    printf("\n");

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_PLAYERS];
    PlayerData players[MAX_PLAYERS];
    int num_players;

    printf("Welcome to the Multiplayer Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players! Exiting...\n");
        return 1;
    }

    for(int i = 0; i < num_players; i++) {
        printf("Player %d, how many terms of Fibonacci do you want to see? ", i + 1);
        scanf("%d", &players[i].terms);
        players[i].player_id = i + 1;

        if (players[i].terms < 1) {
            printf("Player %d entered an invalid number of terms. Minimum is 1. Exiting...\n", players[i].player_id);
            return 1;
        }

        // Create a thread for each player to compute Fibonacci sequence
        if (pthread_create(&threads[i], NULL, fibonacci, &players[i]) != 0) {
            printf("Error creating thread for player %d. Exiting...\n", players[i].player_id);
            return 1;
        }
    }

    // Wait for all threads to complete
    for(int i = 0; i < num_players; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All players have finished visualizing their Fibonacci sequences!\n");
    return 0;
}