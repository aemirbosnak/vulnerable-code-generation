//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define WIDTH 20
#define HEIGHT 20

void initialize_board(int board[HEIGHT][WIDTH], int pattern);
void display_board(int board[HEIGHT][WIDTH]);
void update_board(int board[HEIGHT][WIDTH]);
int count_neighbors(int board[HEIGHT][WIDTH], int x, int y);
void clear_screen();

int main() {
    int board[HEIGHT][WIDTH] = {0};
    int generations = 10; // You can adjust the number of generations
    int pattern_choice;

    printf("Welcome to the Game of Life!\n");
    printf("Choose an initial pattern:\n");
    printf("1. Glider\n");
    printf("2. Pulsar\n");
    printf("3. Blocks\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &pattern_choice);
    
    initialize_board(board, pattern_choice);

    for (int gen = 0; gen < generations; gen++) {
        clear_screen();
        printf("Generation %d:\n", gen);
        display_board(board);
        update_board(board);
        usleep(500000); // Pause for half a second
    }

    return 0;
}

void initialize_board(int board[HEIGHT][WIDTH], int pattern) {
    switch (pattern) {
        case 1: // Glider
            board[1][2] = 1;
            board[2][3] = 1;
            board[3][1] = 1;
            board[3][2] = 1;
            board[3][3] = 1;
            break;
        case 2: // Pulsar
            for (int i = 6; i <= 8; i++) {
                board[6][i] = board[8][i] = 1;
            }
            for (int i = 0; i <= 2; i++) {
                board[7][i + 6] = 1;
                board[7][i + 11] = 1;
            }
            for (int i = 1; i <= 18; i += 6) {
                board[i][7] = 1;
                board[i][11] = 1;
            }
            break;
        case 3: // Blocks
            for (int i = 5; i < 7; i++) {
                for (int j = 5; j < 7; j++) {
                    board[i][j] = 1;
                }
            }
            for (int i = 5; i < 7; i++) {
                for (int j = 10; j < 12; j++) {
                    board[i][j] = 1;
                }
            }
            break;
        default:
            printf("Invalid pattern choice!\n");
            exit(1);
    }
}

void display_board(int board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(board[i][j] ? 'O' : '.');
        }
        putchar('\n');
    }
}

void update_board(int board[HEIGHT][WIDTH]) {
    int new_board[HEIGHT][WIDTH] = {0};

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int alive_neighbors = count_neighbors(board, i, j);
            if (board[i][j]) {
                new_board[i][j] = alive_neighbors == 2 || alive_neighbors == 3 ? 1 : 0;
            } else {
                new_board[i][j] = alive_neighbors == 3 ? 1 : 0;
            }
        }
    }

    memcpy(board, new_board, sizeof(new_board));
}

int count_neighbors(int board[HEIGHT][WIDTH], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < HEIGHT && ny >= 0 && ny < WIDTH) {
                count += board[nx][ny];
            }
        }
    }
    return count;
}

void clear_screen() {
    // ANSI escape code to clear the screen
    printf("\033[H\033[J");
}