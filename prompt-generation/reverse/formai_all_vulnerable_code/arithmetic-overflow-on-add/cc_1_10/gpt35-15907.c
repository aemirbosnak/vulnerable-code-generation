//FormAI DATASET v1.0 Category: Memory Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define GRID_SIZE 4
#define NUM_PAIRS 8

pthread_mutex_t lock;
int grid[GRID_SIZE][GRID_SIZE];
int count = 0;
int pairs_found = 0;

void *play_game(void *arg) {
    int ID = *(int *)arg;
    int pair1[2], pair2[2];
    srand(time(NULL) + ID);
    
    while (pairs_found < NUM_PAIRS) {
        int guess1, guess2, row, col;
        printf("Player %d's turn: ", ID);
        fflush(stdout);
        
        // Guess a tile
        scanf("%d %d", &row, &col);
        
        // Check if tile has already been guessed
        if (grid[row][col] != -1) {
            printf("Tile already guessed!\n");
            continue;
        }
        
        // Lock access to grid
        pthread_mutex_lock(&lock);
        
        // Re-check if tile has been guessed (in case another thread filled it while waiting for the lock)
        if (grid[row][col] != -1) {
            pthread_mutex_unlock(&lock);
            printf("Tile already guessed!\n");
            continue;
        }
        
        // Reveal the tile
        grid[row][col] = ID;
        printf("\n--------\n");
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        printf("--------\n\n");
        
        // Check for matching pairs
        if (count == 0) {
            guess1 = grid[row][col];
            pair1[0] = row;
            pair1[1] = col;
            count++;
        } else {
            guess2 = grid[row][col];
            pair2[0] = row;
            pair2[1] = col;
            // Check for match
            if (guess1 == guess2) {
                pairs_found++;
                printf("Player %d found a matching pair!\n", ID);
            } else {
                printf("No match found. Resetting tiles...\n");
                grid[pair1[0]][pair1[1]] = -1;
                grid[pair2[0]][pair2[1]] = -1;
            }
            count = 0;
        }
        
        // Release lock
        pthread_mutex_unlock(&lock);
    }
    printf("Player %d wins!\n", ID);
    pthread_exit(NULL);
}

int main() {
    // Initialize grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = -1;
        }
    }
    
    // Spawn threads for each player
    pthread_t players[2];
    int player_IDs[2];
    player_IDs[0] = 1;
    player_IDs[1] = 2;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&players[0], NULL, play_game, (void *)&player_IDs[0]);
    pthread_create(&players[1], NULL, play_game, (void *)&player_IDs[1]);
    
    // Wait for threads to finish
    for (int i = 0; i < 2; i++) {
        pthread_join(players[i], NULL);
    }
    
    // Destroy mutex
    pthread_mutex_destroy(&lock);
    
    return 0;
}