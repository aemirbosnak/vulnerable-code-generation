//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define WIDTH 20
#define HEIGHT 20

void initialize_board(int board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = 0; // Set all cells to dead.
        }
    }
}

void display_board(int board[HEIGHT][WIDTH]) {
    system("clear"); // Clear the screen for a fresh display.

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j]) {
                printf("■ "); // Alive cells.
            } else {
                printf("  "); // Dead cells.
            }
        }
        printf("\n");
    }
}

int count_neighbors(int board[HEIGHT][WIDTH], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself.
            int new_x = x + i;
            int new_y = y + j;
            if (new_x >= 0 && new_x < HEIGHT && new_y >= 0 && new_y < WIDTH) {
                count += board[new_x][new_y];
            }
        }
    }
    return count;
}

void update_board(int board[HEIGHT][WIDTH]) {
    int new_board[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighbors = count_neighbors(board, i, j);
            if (board[i][j]) {
                new_board[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0; // Survival
            } else {
                new_board[i][j] = (neighbors == 3) ? 1 : 0; // Birth
            }
        }
    }
    memcpy(board, new_board, sizeof(new_board)); // Copy new states back.
}

void generate_pattern(int board[HEIGHT][WIDTH], int pattern) {
    initialize_board(board); // Clear the board.

    switch (pattern) {
        case 1: // Glider
            board[1][0] = 1;
            board[2][1] = 1;
            board[0][2] = 1;
            board[1][2] = 1;
            board[2][2] = 1;
            break;
        case 2: // Block
            board[1][1] = 1;
            board[1][2] = 1;
            board[2][1] = 1;
            board[2][2] = 1;
            break;
        default:
            printf("Invalid pattern!\n");
            break;
    }
}

int main() {
    int board[HEIGHT][WIDTH];
    int pattern = 0;

    printf("Game of Life\n");
    printf("Select pattern:\n");
    printf("1. Glider\n2. Block\n");
    scanf("%d", &pattern);

    generate_pattern(board, pattern);

    while (1) {
        display_board(board);
        update_board(board);
        usleep(200000); // Delay for 200ms.
    }

    return 0;
}