//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_board(int **board, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int **board, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void next_generation(int **board, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            int alive_neighbors = 0;
            int next_state = 0;

            if (i > 0 && j > 0 && i < size - 1 && j < size - 1) {
                alive_neighbors += board[i - 1][j - 1] && board[i - 1][j] && board[i - 1][j + 1] &&
                                   board[i][j - 1] && board[i][j + 1] && board[i + 1][j - 1] && board[i + 1][j] && board[i + 1][j + 1];
            } else if (i > 0 && j > 0 && i < size - 1 && j == 0 || i < size - 1 && j > 0) {
                alive_neighbors += board[i - 1][j - 1] && board[i - 1][j] && board[i - 1][j + 1] &&
                                   board[i + 1][j - 1] && board[i + 1][j + 1];
            } else if (i > 0 && j == 0 || i == 0 && j > 0) {
                alive_neighbors += board[i - 1][j - 1] && board[i + 1][j - 1] && board[i + 1][j + 1];
            } else if (i > 0 && j == 0) {
                alive_neighbors += board[i - 1][j - 1] && board[i + 1][j - 1];
            } else if (i == 0 && j > 0) {
                alive_neighbors += board[i + 1][j - 1];
            } else if (i == size - 1 && j > 0) {
                alive_neighbors += board[i - 1][j - 1];
            } else if (i == size - 1 && j == 0) {
                alive_neighbors += board[i - 1][j];
            } else if (i == size - 1 && j == size - 1) {
                alive_neighbors += board[i - 1][j - 1];
            } else if (i == size - 1) {
                alive_neighbors += board[i - 1][j];
            } else if (i == 0 && j == size - 1) {
                alive_neighbors += board[i][j - 1];
            } else if (i == 0) {
                alive_neighbors += board[i][j];
            } else if (i == 0 && j == 0) {
                alive_neighbors += board[i][j];
            }

            if (board[i][j] == 1 && alive_neighbors < 2) {
                next_state = 0;
            } else if (board[i][j] == 0 && alive_neighbors == 3) {
                next_state = 1;
            }

            board[i][j] = next_state;
        }
    }
}

int main() {
    srand(time(NULL));

    int size = 100;
    int **board = malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        board[i] = malloc(sizeof(int) * size);
    }

    generate_random_board(board, size);

    printf("Initial board:\n");
    print_board(board, size);

    for (int i = 0; i < 1000; i++) {
        next_generation(board, size);

        printf("\nGeneration %d:\n", i + 1);
        print_board(board, size);

        sleep(1);
    }

    free(board);
    return 0;
}