//FormAI DATASET v1.0 Category: Memory Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void init_board(int board[SIZE][SIZE]);
void print_board(int board[SIZE][SIZE]);
void randomize_board(int board[SIZE][SIZE]);
int get_pair(int board[SIZE][SIZE], int row, int col);
int is_solved(int board[SIZE][SIZE]);

int main() {
    int board[SIZE][SIZE];
    srand(time(NULL));

    init_board(board);
    randomize_board(board);

    int num_moves = 0;
    int row1, col1, row2, col2;

    while (!is_solved(board)) {
        print_board(board);

        printf("Enter row and column of first element: ");
        scanf("%d%d", &row1, &col1);

        printf("Enter row and column of second element: ");
        scanf("%d%d", &row2, &col2);

        if ((row1 < 0) || (row1 >= SIZE) || (col1 < 0) || (col1 >= SIZE) ||
            (row2 < 0) || (row2 >= SIZE) || (col2 < 0) || (col2 >= SIZE)) {
            printf("\nInvalid input, try again\n");
            continue;
        }

        if (get_pair(board, row1, col1) == get_pair(board, row2, col2)) {
            printf("\nMatch made!\n\n");
            int temp = board[row1][col1];
            board[row1][col1] = board[row2][col2];
            board[row2][col2] = temp;
        } else {
            printf("\nNo match, try again\n\n");
        }

        num_moves++;
    }

    printf("Congratulations, you solved the game in %d moves!\n", num_moves);

    return 0;
}

void init_board(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = i * SIZE + j + 1;
        }   
    }
}

void print_board(int board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%5d", board[i][j]);
        }   
        printf("\n");
    }
}

void randomize_board(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int x = rand() % SIZE;
            int y = rand() % SIZE;
            int temp = board[x][y];
            board[x][y] = board[i][j];
            board[i][j] = temp;
        }   
    }
}

int get_pair(int board[SIZE][SIZE], int row, int col) {
    return (row * SIZE + col + 1) / 2;
}

int is_solved(int board[SIZE][SIZE]) {
    return (board[0][0] == 1) && (board[0][1] == 2) && (board[0][2] == 3) && (board[0][3] == 4) &&
           (board[1][0] == 5) && (board[1][1] == 6) && (board[1][2] == 7) && (board[1][3] == 8) &&
           (board[2][0] == 9) && (board[2][1] == 10) && (board[2][2] == 11) && (board[2][3] == 12) &&
           (board[3][0] == 13) && (board[3][1] == 14) && (board[3][2] == 15) && (board[3][3] == 16);
}