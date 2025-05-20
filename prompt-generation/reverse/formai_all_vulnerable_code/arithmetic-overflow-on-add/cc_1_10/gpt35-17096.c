//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multiplayer
#include <stdio.h>
#include <pthread.h>

#define MAX_SEQUENCE 100 // Maximum number of terms in Fibonacci sequence
#define MAX_PLAYERS 10 // Maximum number of players that can join the game

// Global variables accessible to all threads
int sequence[MAX_SEQUENCE];
int sequence_length = 0;
int num_players = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to calculate Fibonacci sequence
void calculate_sequence() {
    int a = 0, b = 1, c, i;
    sequence[0] = a;
    sequence[1] = b;
    
    for (i = 2; i < MAX_SEQUENCE; i++) {
        c = a + b;
        sequence[i] = c;
        a = b;
        b = c;
    }

    sequence_length = i;
}

// Function executed by each player thread
void *play(void *arg) {
    int player_num = *((int *) arg);
    int current_num = 0;
    
    printf("Player %d has joined the game!\n", player_num);
    
    while (current_num < sequence_length) {
        // Wait for lock
        pthread_mutex_lock(&mutex);
        
        // Check if game is still active
        if (num_players == 0) {
            printf("Game over!\n");
            pthread_mutex_unlock(&mutex);
            pthread_exit(NULL);
        }
        
        // Print current Fibonacci number and increment
        printf("Player %d: %d\n", player_num, sequence[current_num++]);
        
        // Reduce number of players still playing
        num_players--;
        
        // Release lock
        pthread_mutex_unlock(&mutex);
    }
    
    printf("Player %d has finished the game.\n", player_num);
    pthread_exit(NULL);
}

int main() {
    // Generate Fibonacci sequence
    calculate_sequence();
    
    // Prompt user for number of players
    printf("How many players would you like to join the game? (up to %d)\n", MAX_PLAYERS);
    scanf("%d", &num_players);
    
    // Create player threads
    pthread_t players[num_players];
    int player_nums[num_players];
    
    for (int i = 0; i < num_players; i++) {
        player_nums[i] = i + 1;
        pthread_create(&players[i], NULL, play, (void *) &player_nums[i]);
    }
    
    // Wait for player threads to finish
    for (int i = 0; i < num_players; i++) {
        pthread_join(players[i], NULL);
    }
    
    return 0;
}