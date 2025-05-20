//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS 8

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void shuffleDeck(char deck[TOTAL_CARDS]) {
    srand(time(NULL));
    for (int i = 0; i < TOTAL_CARDS; i++) {
        int randIndex = rand() % TOTAL_CARDS;
        char temp = deck[i];
        deck[i] = deck[randIndex];
        deck[randIndex] = temp;
    }
}

void dealCards(char deck[TOTAL_CARDS], char board[ROWS][COLS]) {
    int cardCount = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (cardCount < TOTAL_CARDS) {
                board[i][j] = deck[cardCount];
                cardCount++;
            }
        }
    }
}

int main() {
    char board[ROWS][COLS];
    char deck[TOTAL_CARDS];
    int matches = 0;
    int attempts = 0;
    initBoard(board);
    shuffleDeck(deck);
    dealCards(deck, board);
    printBoard(board);

    while (matches < TOTAL_CARDS) {
        int row1, col1, row2, col2;
        printf("Enter the coordinates of the first card: ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the coordinates of the second card: ");
        scanf("%d %d", &row2, &col2);

        if (board[row1][col1] == board[row2][col2]) {
            matches++;
            board[row1][col1] = '-';
            board[row2][col2] = '-';
        } else {
            attempts++;
            board[row1][col1] = '-';
            board[row2][col2] = '-';
        }
        printBoard(board);
    }

    if (matches == TOTAL_CARDS) {
        printf("Congratulations! You won the game in %d attempts.\n", attempts);
    } else {
        printf("Sorry, you lost the game.\n");
    }

    return 0;
}