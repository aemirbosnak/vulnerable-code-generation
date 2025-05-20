//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_PLAYERS 4
#define FIB_LIMIT 30  // Adjust this for performance testing

typedef struct {
    int player_id;
    int duration;
} Player;

void* benchmark_fib(void* arg) {
    Player* player = (Player*)arg;
    clock_t start_time, end_time;

    start_time = clock();
    
    // Fibonacci calculation
    unsigned long long a = 0, b = 1, next;
    for (int i = 1; i <= FIB_LIMIT; i++) {
        next = a + b;
        a = b;
        b = next;
    }

    end_time = clock();
    player->duration = (int)((end_time - start_time) * 1000 / CLOCKS_PER_SEC); // duration in milliseconds

    printf("Player %d completed the Fibonacci calculation in %d ms.\n", player->player_id, player->duration);
    return NULL;
}

int main() {
    pthread_t threads[NUM_PLAYERS];
    Player players[NUM_PLAYERS];

    printf("=== Fibonacci Benchmark Game ===\n");
    
    // Create threads for each player
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].player_id = i + 1;
        players[i].duration = 0;

        if (pthread_create(&threads[i], NULL, benchmark_fib, (void*)&players[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Join threads to ensure all players finish
    for (int i = 0; i < NUM_PLAYERS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Determine the winner based on minimum duration
    int winner_id = 0;
    int minimum_time = players[0].duration;

    for (int i = 1; i < NUM_PLAYERS; i++) {
        if (players[i].duration < minimum_time) {
            minimum_time = players[i].duration;
            winner_id = players[i].player_id;
        }
    }

    printf("Player %d wins with a time of %d ms!\n", winner_id, minimum_time);
    printf("=== End of Game ===\n");

    return 0;
}