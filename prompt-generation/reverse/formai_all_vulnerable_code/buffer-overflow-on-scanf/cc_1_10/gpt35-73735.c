//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

void generateRandomBoard(int board[][COLUMNS]) {
    srand(time(NULL)); 

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(i == 2 && j == 2) { // Free space in the center
                board[i][j] = -1;
            }
            else {
                board[i][j] = rand() % 75 + 1; // Generate random number between 1 and 75
            }
        }
    }
}

void printBoard(int board[][COLUMNS]) {
    printf("\n  B   I   N   G   O\n");
    printf("___________________\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(board[i][j] == -1) { // Free space
                printf(" | X |");
            }
            else {
                printf(" | %d |", board[i][j]);
            }
        }
        printf("\n___________________\n");
    }
}

int isValidNumber(int board[][COLUMNS], int number) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(board[i][j] == number) {
                return 1;
            }
        }
    }
    return 0;
}

int markNumber(int board[][COLUMNS], int number) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(board[i][j] == number) {
                board[i][j] = -2; // Mark as already called
                return 1;
            }
        }
    }
    return 0;
}

int checkRows(int board[][COLUMNS]) {
    for(int i = 0; i < ROWS; i++) {
        int hasWon = 1;
        for(int j = 0; j < COLUMNS; j++) {
            if(board[i][j] != -2) {
                hasWon = 0;
            }
        }
        if(hasWon == 1) {
            return 1;
        }
    }
    return 0;
}

int checkColumns(int board[][COLUMNS]) {
    for(int i = 0; i < COLUMNS; i++) {
        int hasWon = 1;
        for(int j = 0; j < ROWS; j++) {
            if(board[j][i] != -2) {
                hasWon = 0;
            }
        }
        if(hasWon == 1) {
            return 1;
        }
    }
    return 0;
}

int checkDiagonals(int board[][COLUMNS]) {
    if(board[0][0] == -2 && board[1][1] == -2 && board[2][2] == -1 && board[3][3] == -2 && board[4][4] == -2) {
        return 1;
    }
    if(board[0][4] == -2 && board[1][3] == -2 && board[2][2] == -1 && board[3][1] == -2 && board[4][0] == -2) {
        return 1;
    }
    return 0;
}

int main() {
    int board[ROWS][COLUMNS];
    generateRandomBoard(board);
    printBoard(board);

    int turn = 1;
    while(1) {
        int number;
        printf("Turn %d: Enter a number between 1 and 75: ", turn);
        scanf("%d", &number);
        if(number < 1 || number > 75) {
            printf("Invalid number. Try again.\n");
        }
        else if(!isValidNumber(board, number)) {
            printf("%d is not on the board. Try again.\n", number);
        }
        else {
            markNumber(board, number);
            if(checkRows(board) || checkColumns(board) || checkDiagonals(board)) {
                printf("Bingo! You won in %d turns!\n", turn);
                break;
            }
            turn++;
        }
    }

    return 0;
}