//FormAI DATASET v1.0 Category: Memory Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

char board[ROWS][COLS];
char displayBoard[ROWS][COLS];
int scores[2] = { 0, 0 };

void initializeBoard() {
    int i, j, k=0;

    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            board[i][j] = ' ';
        }
    }

    for (i=0; i<2; i++) {
        for (j=0; j<2; j++) {
            board[i][j] = k + '0';
            board[i+2][j+2] = k + '0';
            k++;
        }
    }
}

void shuffleBoard() {
    int i, j, k;
    char temp;

    srand(time(NULL));

    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            k = rand() % ROWS;
            temp = board[i][j];
            board[i][j] = board[k][j];
            board[k][j] = temp;
        }
    }

    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            k = rand() % COLS;
            temp = board[i][j];
            board[i][j] = board[i][k];
            board[i][k] = temp;
        }
    }
}

void displayBoardForPlayer(int player) {
    int i, j;

    printf("\nCurrent Score: Player 1 - %d | Player 2 - %d\n\n", scores[0], scores[1]);
    printf("   | 0 | 1 | 2 | 3 |\n");
    printf("---|---|---|---|---|\n");

    for (i=0; i<ROWS; i++) {
        printf(" %d |", i);
        for (j=0; j<COLS; j++) {
            if(player == 1 || displayBoard[i][j] == 'X') {
                printf(" %c |", displayBoard[i][j]);
            } else {
                printf("   |");
            }
        }
        printf("\n");
        printf("---|---|---|---|---|\n");
    }
}

void acceptPlayerInput(int *row, int *col) {
    printf("Enter the cell location (row & column) separated by a space eg. '2 3': ");
    scanf("%d %d", row, col);
}

void updateDisplayBoard(int row, int col) {
    displayBoard[row][col] = board[row][col];
}

void updateScore(int player) {
    scores[player-1]++;
}

void checkCards(int row1, int col1, int row2, int col2, int *player) {
    if(board[row1][col1] == board[row2][col2]) {
        printf("Good Job! You have found a matching pair.\n");
        updateScore(*player);
    } else {
        printf("Oh, No! The cards you chose did not match.\n");
        *player = (*player % 2) + 1;
    }
}

void playGame() {
    int row1, col1, row2, col2;
    int player = 1;
    int count = 0;

    initializeBoard();
    shuffleBoard();

    while(count < ROWS * COLS) {
        displayBoardForPlayer(player);
        acceptPlayerInput(&row1, &col1);
        updateDisplayBoard(row1, col1);
        displayBoardForPlayer(player);

        acceptPlayerInput(&row2, &col2);
        updateDisplayBoard(row2, col2);
        displayBoardForPlayer(player);
        
        checkCards(row1, col1, row2, col2, &player);
        count += 2;
    }

    if(scores[0] > scores[1]) {
        printf("\nCONGRATULATIONS!! Player 1 WINS with a score of %d.\n\n", scores[0]);
    } else if(scores[1] > scores[0]) {
        printf("\nCONGRATULATIONS!! Player 2 WINS with a score of %d.\n\n", scores[1]);
    } else {
        printf("\nIt's a TIE!! Both the players have the same score of %d.\n\n", scores[0]);
    }
}

int main() {
    char playAgain;

    do {
        playGame();
        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);
    } while(playAgain == 'Y' || playAgain == 'y');

    printf("\nThanks for playing this memory game. Goodbye!\n");

    return 0;
}