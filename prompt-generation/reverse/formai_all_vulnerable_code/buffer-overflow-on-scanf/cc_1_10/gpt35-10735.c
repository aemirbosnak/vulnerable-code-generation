//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int board[ROWS][COLS];

/**
 * Function to initialize the board with random numbers.
 **/
void init_board() {
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 75 + 1;
        }
    }
}

/**
 * Function to print the board.
 **/
void print_board() {
    printf("   B   I   N   G   O\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == -1) {
                printf(" | X |");
            } else {
                printf(" | %d |", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Function to check if a number is already present on the board.
 **/
int is_number_present(int number) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == number) {
                return 1;
            }
        }
    }
    return 0;
}

/**
 * Function to mark a number on the board.
 **/
void mark_number(int number) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == number) {
                board[i][j] = -1;
                return;
            }
        }
    }
}

/**
 * Main function to simulate a Bingo game.
 **/
int main() {
    init_board();
    print_board();

    int number;
    for(int i = 1; i <= 75; i++) {
        printf("Enter the next number: ");
        scanf("%d", &number);

        if(number < 1 || number > 75) {
            printf("Invalid number! Please enter a number between 1 and 75.\n");
            i--;
            continue;
        }

        if(is_number_present(number)) {
            printf("Number already present on the board! Please enter a different number.\n");
            i--;
            continue;
        }

        mark_number(number);
        print_board();

        int flag = 0;

        // Check rows
        for(int j = 0; j < ROWS; j++) {
            flag = 1;
            for(int k = 0; k < COLS; k++) {
                if(board[j][k] != -1) {
                    flag = 0;
                    break;
                }
            }
            if(flag) {
                printf("BINGO! You won by completing row %d.\n", j+1);
                return 0;
            }
        }

        // Check columns
        for(int j = 0; j < COLS; j++) {
            flag = 1;
            for(int k = 0; k < ROWS; k++) {
                if(board[k][j] != -1) {
                    flag = 0;
                    break;
                }
            }
            if(flag) {
                printf("BINGO! You won by completing column %d.\n", j+1);
                return 0;
            }
        }

        // Check diagonals
        flag = 1;
        for(int j = 0; j < ROWS; j++) {
            if(board[j][j] != -1) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            printf("BINGO! You won by completing the diagonal.\n");
            return 0;
        }

        flag = 1;
        for(int j = 0; j < ROWS; j++) {
            if(board[j][COLS-1-j] != -1) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            printf("BINGO! You won by completing the diagonal.\n");
            return 0;
        }
    }

    printf("Sorry, you lost the game. Better luck next time!\n");
    return 0;
}