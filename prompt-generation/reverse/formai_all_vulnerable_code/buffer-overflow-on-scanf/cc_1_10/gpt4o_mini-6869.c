//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5
#define MAX_NUMBER 75

void initialize_board(int board[BINGO_SIZE][BINGO_SIZE]) {
    int col_ranges[5][2] = {
        {1, 15}, {16, 30}, {31, 45}, {46, 60}, {61, 75}
    };
    
    for (int col = 0; col < BINGO_SIZE; col++) {
        int numbers_in_col[BINGO_SIZE] = {0};
        for (int row = 0; row < BINGO_SIZE; row++) {
            int num;
            int unique;
            do {
                unique = 1;
                num = rand() % (col_ranges[col][1] - col_ranges[col][0] + 1) + col_ranges[col][0];
                for (int k = 0; k < row; k++) {
                    if (numbers_in_col[k] == num) {
                        unique = 0;
                    }
                }
            } while (!unique);
            numbers_in_col[row] = num;
            board[row][col] = num;
        }
    }
    board[2][2] = 0; // Free space in the middle
}

void print_board(int board[BINGO_SIZE][BINGO_SIZE]) {
    printf("\n");
    printf(" B   I   N   G   O \n");
    printf("___________________\n");
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (board[row][col] == 0) {
                printf(" *  ");
            } else {
                printf("%-3d ", board[row][col]);
            }
        }
        printf("\n");
    }
}

int check_bingo(int board[BINGO_SIZE][BINGO_SIZE], int marked[BINGO_SIZE][BINGO_SIZE]) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        // Check rows
        if (marked[i][0] && marked[i][1] && marked[i][2] && marked[i][3] && marked[i][4]) {
            return 1;
        }
        // Check columns
        if (marked[0][i] && marked[1][i] && marked[2][i] && marked[3][i] && marked[4][i]) {
            return 1;
        }
    }
    // Check diagonals
    if (marked[0][0] && marked[1][1] && marked[2][2] && marked[3][3] && marked[4][4]) {
        return 1;
    }
    if (marked[0][4] && marked[1][3] && marked[2][2] && marked[3][1] && marked[4][0]) {
        return 1;
    }
    return 0;
}

void mark_number(int number, int board[BINGO_SIZE][BINGO_SIZE], int marked[BINGO_SIZE][BINGO_SIZE]) {
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (board[row][col] == number) {
                marked[row][col] = 1; // Mark this number as called
            }
        }
    }
}

void draw_number(int *drawn_number) {
    *drawn_number = rand() % MAX_NUMBER + 1;
}

int main() {
    srand((unsigned)time(NULL));
    int board[BINGO_SIZE][BINGO_SIZE];
    int marked[BINGO_SIZE][BINGO_SIZE] = {0}; 
    int drawn_number;
    int bingo;

    printf("Welcome to the enchanting world of Bingo!\n");
    printf("Tonight, as the stars shine brightly, we shall play this romantic game.\n");

    initialize_board(board);
    printf("Your Bingo Card:\n");
    print_board(board);
    
    while (1) {
        draw_number(&drawn_number);
        printf("\nA number is drawn: %d\n", drawn_number);
        mark_number(drawn_number, board, marked);
        print_board(board);
        
        bingo = check_bingo(board, marked);
        if (bingo) {
            printf("Congratulations! You found love in numbers! Bingo!\n");
            break;
        }
        
        char choice;
        printf("Do you dare to continue this romantic journey? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice != 'y') {
            printf("You chose to step back into reality, but love is always in your heart!\n");
            break;
        }
    }

    printf("May your nights be filled with dreams of Bingo and romance! Goodbye!\n");
    return 0;
}