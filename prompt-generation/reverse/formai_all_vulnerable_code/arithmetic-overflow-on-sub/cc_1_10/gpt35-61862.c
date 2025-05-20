//FormAI DATASET v1.0 Category: Memory Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

// function to print the memory board
void print_board(int board[][COLS], int rows, int cols, int revealed[][COLS]) {
    printf("\n|\t1\t2\t3\t4 \n");
    printf("---------------------------------\n");
    for(int i=0; i<rows; i++) {
        printf("|%d\t", i+1);
        for(int j=0; j<cols; j++) {
            if(revealed[i][j] == 1) {
                printf("%d\t", board[i][j]);
            } else {
                printf("*\t");
            }
        }
        printf("\n");
    }
}

// function to check if all memory cells are revealed
int all_revealed(int revealed[][COLS], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(revealed[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int board[ROWS][COLS] = { {1,3,5,7}, {2,4,6,8}, {9,11,13,15}, {10,12,14,16} };
    int revealed[ROWS][COLS] = {0};
    int first_row, first_col, second_row, second_col;

    // randomize the board
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int swap_row = rand() % ROWS;
            int swap_col = rand() % COLS;

            int temp = board[i][j];
            board[i][j] = board[swap_row][swap_col];
            board[swap_row][swap_col] = temp;
        }
    }

    printf("Welcome to the C Memory Game!\n");
    printf("The game is about to start!\n");

    while(1) {
        print_board(board, ROWS, COLS, revealed);

        if(all_revealed(revealed, ROWS, COLS)) {
            printf("Congratulations! You won the game!\n");
            break;
        }

        printf("\n");
        printf("Please select the coordinates of your first guess:\n");
        scanf("%d,%d", &first_row, &first_col);

        if(revealed[first_row-1][first_col-1] == 1) {
            printf("That cell is already revealed! Please try again.\n");
            continue;
        }

        revealed[first_row-1][first_col-1] = 1;

        print_board(board, ROWS, COLS, revealed);

        printf("\n");
        printf("Please select the coordinates of your second guess:\n");
        scanf("%d,%d", &second_row, &second_col);

        if(revealed[second_row-1][second_col-1] == 1) {
            printf("That cell is already revealed! Please try again.\n");
            revealed[first_row-1][first_col-1] = 0;
            continue;
        }

        revealed[second_row-1][second_col-1] = 1;

        print_board(board, ROWS, COLS, revealed);

        if(board[first_row-1][first_col-1] != board[second_row-1][second_col-1]) {
            printf("Sorry, your guess is incorrect.\n");
            revealed[first_row-1][first_col-1] = 0;
            revealed[second_row-1][second_col-1] = 0;
        } else {
            printf("Well done, your guess is correct!\n");
        }
    }

    return 0;
}