//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 20
#define HEIGHT 20

void display_board(int board[HEIGHT][WIDTH]);
void initialize_board(int board[HEIGHT][WIDTH]);
void update_board(int board[HEIGHT][WIDTH]);
int count_neighbors(int board[HEIGHT][WIDTH], int x, int y);

int main() {
    int board[HEIGHT][WIDTH];
    int generations;

    printf("Greetings, noble player! Welcome to the Game of Life!\n");
    printf("Enter the number of generations to observe (1-100): ");
    scanf("%d", &generations);
    
    if (generations < 1 || generations > 100) {
        printf("Alas! The number must be between 1 and 100!\n");
        return 1;
    }

    initialize_board(board);

    printf("Behold the board of living cells:\n");
    display_board(board);

    for (int gen = 0; gen < generations; gen++) {
        printf("\n--- Generation %d ---\n", gen + 1);
        update_board(board);
        display_board(board);
        usleep(500000); // Sleep for half a second to create an animation effect
    }

    printf("Thus ends your journey through the Game of Life. Fare thee well!\n");
    return 0;
}

void initialize_board(int board[HEIGHT][WIDTH]) {
    // Use a knight’s random placement for the living cells
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            board[y][x] = rand() % 2; // Randomly assign 0 or 1
        }
    }
}

void display_board(int board[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (board[y][x] == 1) {
                printf("◉ "); // Living cell
            } else {
                printf("⚪ "); // Dead cell
            }
        }
        printf("\n");
    }
}

void update_board(int board[HEIGHT][WIDTH]) {
    int new_board[HEIGHT][WIDTH];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int neighbors = count_neighbors(board, x, y);
            if (board[y][x] == 1) {
                // Cell is alive
                new_board[y][x] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                // Cell is dead
                new_board[y][x] = (neighbors == 3) ? 1 : 0;
            }
        }
    }

    // Update the board
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            board[y][x] = new_board[y][x];
        }
    }
}

int count_neighbors(int board[HEIGHT][WIDTH], int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue; // Skip the cell itself
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
                count += board[ny][nx];
            }
        }
    }
    return count;
}