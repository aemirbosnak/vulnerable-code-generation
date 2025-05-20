//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Main function
int main() {
    // Game board dimensions
    const int w = 10;  // Width
    const int h = 10;  // Height

    // Allocate memory for the game board
    char *board = (char *)malloc(w * h * sizeof(char));

    // Initialize the board with random values
    for (int i = 0; i < w * h; i++) {
        board[i] = rand() % 2;
    }

    // Main game loop
    while (1) {
        // Display the board
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                printf("%c", board[y * w + x] ? 'X' : 'O');
            }
            printf("\n");
        }

        // Update the board according to the rules of the game of life
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                int neighbors = 0;

                // Count the number of living neighbors
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        if (x + dx >= 0 && x + dx < w && y + dy >= 0 && y + dy < h) {
                            neighbors += board[(y + dy) * w + (x + dx)];
                        }
                    }
                }

                // Update the cell according to the rules of the game of life
                if (board[y * w + x] && neighbors < 2) {
                    board[y * w + x] = 0;
                } else if (!board[y * w + x] && neighbors == 3) {
                    board[y * w + x] = 1;
                }
            }
        }

        // Sleep for a short period of time
        usleep(100000);
    }

    // Free the memory allocated for the game board
    free(board);

    return 0;
}