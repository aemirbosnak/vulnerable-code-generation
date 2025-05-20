//FormAI DATASET v1.0 Category: Game of Life ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 30

int main() {
    srand(time(NULL)); // initialize the random seed
    
    // allocate memory for the game board
    int* board = (int*) malloc(WIDTH * HEIGHT * sizeof(int));
    
    // initialize the game board with random values
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        board[i] = rand() % 2;
    }
    
    // game loop
    for (int generation = 0; ; generation++) {
        // print the current state of the game board
        system("clear");
        printf("Generation %d:\n", generation);
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                if (board[y * WIDTH + x] == 1) {
                    printf("# ");
                } else {
                    printf(". ");
                }
            }
            printf("\n");
        }
        
        // copy the game board to a new array
        int* newBoard = (int*) malloc(WIDTH * HEIGHT * sizeof(int));
        for (int i = 0; i < WIDTH * HEIGHT; i++) {
            newBoard[i] = board[i];
        }
        
        // apply the rules of the game of life to the new array
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                int numNeighbors = 0;
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        if (dx == 0 && dy == 0) continue;
                        int nx = (x + dx + WIDTH) % WIDTH;
                        int ny = (y + dy + HEIGHT) % HEIGHT;
                        if (board[ny * WIDTH + nx] == 1) {
                            numNeighbors++;
                        }
                    }
                }
                if (board[y * WIDTH + x] == 1 && (numNeighbors < 2 || numNeighbors > 3)) {
                    newBoard[y * WIDTH + x] = 0;
                } else if (board[y * WIDTH + x] == 0 && numNeighbors == 3) {
                    newBoard[y * WIDTH + x] = 1;
                }
            }
        }
        
        // free the old game board and use the new one for the next generation
        free(board);
        board = newBoard;
        
        // wait for a short period of time before the next generation
        usleep(100000);
    }
    
    return 0;
}