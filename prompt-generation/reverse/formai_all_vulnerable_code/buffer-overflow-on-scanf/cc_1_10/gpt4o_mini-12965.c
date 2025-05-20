//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 9
#define SUBGRID 3

int board[SIZE][SIZE];
pthread_mutex_t lock;

void print_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_safe(int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (board[row][x] == num || board[x][col] == num) {
            return 0;
        }
    }

    int startRow = row - row % SUBGRID;
    int startCol = col - col % SUBGRID;
    for (int i = 0; i < SUBGRID; i++) {
        for (int j = 0; j < SUBGRID; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }
    return 1;
}

void *solve_sudoku(void *param) {
    int *pos = (int*)param;
    int row = pos[0];
    int col = pos[1];

    if (row == SIZE) {
        pthread_mutex_lock(&lock);
        print_board();
        pthread_mutex_unlock(&lock);
        return NULL;
    }

    if (board[row][col] != 0) {
        int nextRow = (col == SIZE - 1) ? row + 1 : row;
        int nextCol = (col + 1) % SIZE;
        int nextPos[] = {nextRow, nextCol};
        solve_sudoku((void*)nextPos);
        return NULL;
    }

    for (int num = 1; num <= SIZE; num++) {
        if (is_safe(row, col, num)) {
            board[row][col] = num;
            int nextRow = (col == SIZE - 1) ? row + 1 : row;
            int nextCol = (col + 1) % SIZE;
            int nextPos[] = {nextRow, nextCol};
            solve_sudoku((void*)nextPos);
            board[row][col] = 0; // backtrack
        }
    }
    return NULL;
}

void start_sudoku_solver() {
    pthread_t threads[SIZE][SIZE];
    int pos[SIZE][SIZE][2];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            pos[i][j][0] = i;
            pos[i][j][1] = j;

            if (board[i][j] == 0) { // only for empty cells
                pthread_create(&threads[i][j], NULL, solve_sudoku, (void*)pos[i][j]);
                pthread_join(threads[i][j], NULL);
            }
        }
    }
}

int main() {
    pthread_mutex_init(&lock, NULL);
    printf("Enter the Sudoku puzzle as a 9x9 grid (0 for empty cells):\n");
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    printf("\nInitial Sudoku board:\n");
    print_board();
    
    printf("\nSolving the Sudoku...\n");
    start_sudoku_solver();

    pthread_mutex_destroy(&lock);
    return 0;
}