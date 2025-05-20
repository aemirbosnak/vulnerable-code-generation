//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Constants
#define WIDTH 80
#define HEIGHT 25
#define NEIGHBORS 8

// Cell states
#define DEAD 0
#define ALIVE 1

// Thread data
typedef struct {
    int x, y;
    int **board;
} thread_data;

// Function prototypes
void *update_cell(void *arg);

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the game board
    int **board = malloc(sizeof(int *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        board[i] = malloc(sizeof(int) * WIDTH);
    }

    // Initialize the game board with random cells
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = rand() % 2;
        }
    }

    // Create the thread pool
    pthread_t threads[HEIGHT * WIDTH];
    thread_data data[HEIGHT * WIDTH];

    // Create the threads
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            data[i * WIDTH + j].x = i;
            data[i * WIDTH + j].y = j;
            data[i * WIDTH + j].board = board;
            pthread_create(&threads[i * WIDTH + j], NULL, update_cell, &data[i * WIDTH + j]);
        }
    }

    // Join the threads
    for (int i = 0; i < HEIGHT * WIDTH; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the game board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf(board[i][j] ? "O" : " ");
        }
        printf("\n");
    }

    // Free the game board
    for (int i = 0; i < HEIGHT; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}

// Function to update a cell
void *update_cell(void *arg) {
    // Get the thread data
    thread_data *data = (thread_data *)arg;

    // Get the current state of the cell
    int state = data->board[data->x][data->y];

    // Count the number of alive neighbors
    int neighbors = 0;
    for (int i = data->x - 1; i <= data->x + 1; i++) {
        for (int j = data->y - 1; j <= data->y + 1; j++) {
            if (i >= 0 && i < HEIGHT && j >= 0 && j < WIDTH && !(i == data->x && j == data->y) && data->board[i][j] == ALIVE) {
                neighbors++;
            }
        }
    }

    // Update the state of the cell
    switch (state) {
        case DEAD:
            if (neighbors == 3) {
                data->board[data->x][data->y] = ALIVE;
            }
            break;
        case ALIVE:
            if (neighbors < 2 || neighbors > 3) {
                data->board[data->x][data->y] = DEAD;
            }
            break;
    }

    return NULL;
}