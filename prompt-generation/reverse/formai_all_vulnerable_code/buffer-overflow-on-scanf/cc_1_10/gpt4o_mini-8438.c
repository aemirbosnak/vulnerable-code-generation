//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 20
#define HEIGHT 10

void initialize_board(int board[HEIGHT][WIDTH]);
void print_board(int board[HEIGHT][WIDTH]);
void update_board(int board[HEIGHT][WIDTH]);
int count_live_neighbors(int board[HEIGHT][WIDTH], int x, int y);

int main() {
    int board[HEIGHT][WIDTH];
    char choice;

    initialize_board(board);
    
    while (1) {
        print_board(board);
        update_board(board);
        printf("Press 'q' to quit or any other key to continue...\n");
        choice = getchar();
        getchar(); // Consume newline character
        if (choice == 'q') {
            break;
        }
        sleep(1);
    }

    return 0;
}

void initialize_board(int board[HEIGHT][WIDTH]) {
    printf("Enter the initial state of the board (0 for dead, 1 for live):\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j < WIDTH - 1) {
                printf("Cell [%d,%d]: ", i, j);
            } else {
                printf("Cell [%d,%d]: ", i, j);
            }
            scanf("%d", &board[i][j]);
        }
    }
}

void print_board(int board[HEIGHT][WIDTH]) {
    system("clear"); // Clear the console
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == 1) {
                printf("■ ");
            } else {
                printf("□ ");
            }
        }
        printf("\n");
    }
}

void update_board(int board[HEIGHT][WIDTH]) {
    int new_board[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int live_neighbors = count_live_neighbors(board, i, j);
            
            if (board[i][j] == 1) {
                if (live_neighbors < 2 || live_neighbors > 3) {
                    new_board[i][j] = 0; // Cell dies
                } else {
                    new_board[i][j] = 1; // Cell lives
                }
            } else {
                if (live_neighbors == 3) {
                    new_board[i][j] = 1; // Cell becomes alive
                } else {
                    new_board[i][j] = 0; // Cell stays dead
                }
            }
        }
    }

    // Copy new_board to board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int count_live_neighbors(int board[HEIGHT][WIDTH], int x, int y) {
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