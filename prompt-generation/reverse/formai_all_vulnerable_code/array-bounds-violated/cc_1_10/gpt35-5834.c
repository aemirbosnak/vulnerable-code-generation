//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COLUMN 5
#define MAX 75

int check_win(int arr[][COLUMN], int num);
void print_board(int arr[][COLUMN]);

int main() {
    srand(time(NULL));
    int numCalls = 0;
    int numbers[MAX] = { 0 };
    int board[ROW][COLUMN] = {
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
    };

    printf("Welcome to the Bingo Simulator!\n");
    printf("Generating a random Bingo board...\n\n");

    // generate random board
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            int randNum = (rand() % (15)) + (j * 15) + 1;
            board[i][j] = randNum;
        }
    }

    // print board
    print_board(board);

    printf("\nPress enter to start the game...");
    getchar();
    printf("\n\nGame Start!\n");

    // call numbers
    while (numCalls < MAX) {
        int randomNumber = (rand() % 75) + 1;

        // check if number has already been called
        if (numbers[randomNumber] == 0) {
            numbers[randomNumber] = 1;
            printf("\n%d was called!\n\n", randomNumber);

            // mark number on board
            for (int i = 0; i < ROW; i++) {
                for (int j = 0; j < COLUMN; j++) {
                    if (board[i][j] == randomNumber) {
                        board[i][j] = -1;
                        break;
                    }
                }
            }

            numCalls++;

            // check for win
            int win = check_win(board, numCalls);
            if (win) {
                printf("\n\nBINGO! You won in %d calls!\n", numCalls);
                return 0;
            }
            print_board(board);

            printf("\nPress enter to continue...");
            getchar();

        }
    }
    printf("\n\nGame Over. You lost. Better luck next time!\n");

    return 0;
}

// check for win
int check_win(int arr[][COLUMN], int num) {
    int win;

    // check rows
    for (int i = 0; i < ROW; i++) {
        win = 1;
        for (int j = 0; j < COLUMN; j++) {
            if (arr[i][j] != -1) {
                win = 0;
                break;
            }
        }
        if (win) {
            return 1;
        }
    }

    // check columns
    for (int i = 0; i < COLUMN; i++) {
        win = 1;
        for (int j = 0; j < ROW; j++) {
            if (arr[j][i] != -1) {
                win = 0;
                break;
            }
        }
        if (win) {
            return 1;
        }
    }

    // check diagonal \
    win = 1;
    for (int i = 0; i < ROW; i++) {
        if (arr[i][i] != -1) {
            win = 0;
            break;
        }
    }
    if (win) {
        return 1;
    }

    // check diagonal /
    win = 1;
    for (int i = 0; i < ROW; i++) {
        if (arr[i][ROW - i - 1] != -1) {
            win = 0;
            break;
        }
    }
    if (win) {
        return 1;
    }

    return 0;
}

// print board
void print_board(int arr[][COLUMN]) {
    printf("+----+----+----+----+----+\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            if (arr[i][j] == -1) {
                printf("| XX ");
            }
            else {
                printf("| %02d ", arr[i][j]);
            }
        }
        printf("|\n");
        printf("+----+----+----+----+----+\n");
    }
}