//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define SIZE 4 // 4x4 grid
#define TOTAL_PAIRS (SIZE * SIZE) / 2

int board[SIZE][SIZE];
bool revealed[SIZE][SIZE] = {false};
pthread_mutex_t mutex;

void initialize_board() {
    int values[TOTAL_PAIRS];
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        values[i] = i + 1; // Values from 1 to TOTAL_PAIRS
    }
    
    // Shuffle pairs onto the board
    srand(time(NULL));
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        board[i / SIZE][i % SIZE] = values[i % TOTAL_PAIRS];
    }
    
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        int rand_index = rand() % TOTAL_PAIRS;
        int temp = board[i / SIZE][i % SIZE];
        board[i / SIZE][i % SIZE] = board[rand_index / SIZE][rand_index % SIZE];
        board[rand_index / SIZE][rand_index % SIZE] = temp;
    }
}

void display_board() {
    pthread_mutex_lock(&mutex);
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%d\t", board[i][j]);
            } else {
                printf("X\t");
            }
        }
        printf("\n");
    }
    pthread_mutex_unlock(&mutex);
}

bool check_match(int x1, int y1, int x2, int y2) {
    return (board[x1][y1] == board[x2][y2]);
}

void *player_turn(void *arg) {
    int player_id = *(int *)arg;
    int x1, y1, x2, y2;

    printf("Player %d's turn. Enter coordinates of first card (row and column): ", player_id + 1);
    scanf("%d %d", &x1, &y1);
    x1--; y1--;  // convert to 0-based index

    pthread_mutex_lock(&mutex);
    revealed[x1][y1] = true;
    display_board();
    pthread_mutex_unlock(&mutex);
    sleep(1); // Show the first card for a second

    printf("Enter coordinates of second card (row and column): ");
    scanf("%d %d", &x2, &y2);
    x2--; y2--;  // convert to 0-based index

    if (check_match(x1, y1, x2, y2)) {
        printf("Player %d found a match!\n", player_id + 1);
    } else {
        printf("No match! Hiding cards again.\n");
        pthread_mutex_lock(&mutex);
        revealed[x1][y1] = false;
        revealed[x2][y2] = false;
        display_board();
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    
    initialize_board();
    display_board();

    pthread_t players[2];
    int player_ids[2] = {0, 1};
    while (true) {
        for (int i = 0; i < 2; i++) {
            pthread_create(&players[i], NULL, player_turn, &player_ids[i]);
        }
        
        for (int i = 0; i < 2; i++) {
            pthread_join(players[i], NULL);
        }

        // Check for win condition (this is a basic check for demonstration purposes)
        // More sophisticated checks can be added here to declare the winner.
        break;  // Exit loop after two turns for demonstration
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}