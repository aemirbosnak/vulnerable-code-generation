//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define NUM_CARDS 8

char cards[NUM_CARDS][2] = {
    {'A', 'A'},
    {'2', '2'},
    {'3', '3'},
    {'4', '4'},
    {'5', '5'},
    {'6', '6'},
    {'7', '7'},
    {'8', '8'}
};

void initBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isMatch(char card1[2], char card2[2]) {
    return (card1[0] == card2[0] && card1[1] == card2[1]) ||
           (card1[0] == card2[1] && card1[1] == card2[0]);
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    int matches = 0;
    initBoard(board);
    int cardIndex1, cardIndex2;
    for (int i = 0; i < NUM_CARDS; i++) {
        cardIndex1 = rand() % NUM_CARDS;
        cardIndex2 = rand() % NUM_CARDS;
        while (isMatch(cards[cardIndex1], cards[cardIndex2])) {
            cardIndex2 = rand() % NUM_CARDS;
        }
        board[0][i] = cards[cardIndex1][0];
        board[1][i] = cards[cardIndex1][1];
        board[2][i] = cards[cardIndex2][0];
        board[3][i] = cards[cardIndex2][1];
    }
    printBoard(board);
    char choice;
    int row, col;
    while (matches < NUM_CARDS) {
        printf("Enter your choice (row,col): ");
        scanf("%d%d", &row, &col);
        if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
            if (board[row][col]!= '-') {
                if (board[row][col] == board[row][col + 1]) {
                    matches++;
                    board[row][col] = '-';
                    board[row][col + 1] = '-';
                } else {
                    board[row][col] = '-';
                    board[row][col + 1] = '-';
                }
            }
        }
        printBoard(board);
        if (matches == NUM_CARDS) {
            printf("Congratulations! You win!\n");
            break;
        }
        if (matches == NUM_CARDS - 1) {
            printf("One more to go!\n");
        }
        printf("Press any key to continue...\n");
        scanf("%c", &choice);
    }
    return 0;
}