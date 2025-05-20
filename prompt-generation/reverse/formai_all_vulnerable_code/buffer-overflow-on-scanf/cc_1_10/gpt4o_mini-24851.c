//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PLAYERS 5
#define FIB_LIMIT 20

typedef struct {
    int player_id;
    int current_fib;
    int next_fib;
} Player;

typedef struct {
    Player players[MAX_PLAYERS];
    int player_count;
    int turn;
    pthread_mutex_t lock;
} Game;

Game game;

int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void* player_turn(void* arg) {
    Player* player = (Player*)arg;

    while (game.turn < FIB_LIMIT) {
        pthread_mutex_lock(&game.lock);
        
        if (game.turn % game.player_count == player->player_id) {
            player->current_fib = fibonacci(game.turn);
            player->next_fib = fibonacci(game.turn + 1);
            printf("Player %d: Current Fibonacci: %d, Next Fibonacci: %d\n", player->player_id + 1, player->current_fib, player->next_fib);
            game.turn++;
        }
        pthread_mutex_unlock(&game.lock);

        sleep(1);
    }
    return NULL;
}

int main() {
    game.turn = 0;
    game.player_count = 0;
    pthread_mutex_init(&game.lock, NULL);
    
    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &game.player_count);

    if (game.player_count < 1 || game.player_count > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting.\n");
        return 1;
    }

    pthread_t players[MAX_PLAYERS];
    for (int i = 0; i < game.player_count; i++) {
        game.players[i].player_id = i;
        pthread_create(&players[i], NULL, player_turn, (void*)&game.players[i]);
    }

    for (int i = 0; i < game.player_count; i++) {
        pthread_join(players[i], NULL);
    }

    pthread_mutex_destroy(&game.lock);
    printf("Game Over! All Fibonacci numbers computed up to %d.\n", FIB_LIMIT);
    return 0;
}