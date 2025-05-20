//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define GRID_SIZE 4
#define TOTAL_TILES (GRID_SIZE * GRID_SIZE)
#define MAX_PLAYERS 2
#define MAX_TRIES 10

char grid[GRID_SIZE][GRID_SIZE];
char revealed[GRID_SIZE][GRID_SIZE];
pthread_mutex_t lock;

void initialize_grid() {
    char symbols[] = "AABBCCDDEE";
    char temp[TOTAL_TILES];
    srand(time(NULL));

    // Fill the grid with symbols
    for (int i = 0; i < TOTAL_TILES; i++) {
        temp[i] = symbols[i];
    }

    // Shuffle symbols
    for (int i = 0; i < TOTAL_TILES; i++) {
        int j = rand() % TOTAL_TILES;
        char temp_symbol = temp[i];
        temp[i] = temp[j];
        temp[j] = temp_symbol;
    }

    // Create the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = temp[i * GRID_SIZE + j];
            revealed[i][j] = '.';
        }
    }
}

void print_grid() {
    printf("\nGrid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", revealed[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int x, int y) {
    return x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE && revealed[x][y] == '.';
}

void* player_turn(void* arg) {
    int player = *((int*)arg);
    int tries = 0;
    int x1, y1, x2, y2;

    while (tries < MAX_TRIES) {
        printf("Player %d's turn. Please input coordinates (x1 y1 x2 y2): ", player + 1);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        pthread_mutex_lock(&lock);

        if (is_valid_move(x1, y1) && is_valid_move(x2, y2)) {
            revealed[x1][y1] = grid[x1][y1];
            revealed[x2][y2] = grid[x2][y2];
            print_grid();

            if (grid[x1][y1] == grid[x2][y2]) {
                printf("Player %d found a match!\n", player + 1);
            } else {
                printf("No match. Try again!\n");
                sleep(1); // giving time to see chosen symbols
                revealed[x1][y1] = '.';
                revealed[x2][y2] = '.';
            }
        } else {
            printf("Invalid move. Try again!\n");
        }

        pthread_mutex_unlock(&lock);
        tries++;
    }
    printf("Player %d has finished their tries!\n", player + 1);
    return NULL;
}

int main() {
    pthread_t threads[MAX_PLAYERS];
    int player_ids[MAX_PLAYERS];

    pthread_mutex_init(&lock, NULL);
    initialize_grid();
    print_grid();

    for (int i = 0; i < MAX_PLAYERS; i++) {
        player_ids[i] = i;
        if (pthread_create(&threads[i], NULL, player_turn, (void*)&player_ids[i])) {
            perror("Failed to create thread");
            return 1;
        }
    }

    for (int i = 0; i < MAX_PLAYERS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    printf("Game Over! Thanks for playing!\n");
    return 0;
}