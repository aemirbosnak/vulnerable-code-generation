//FormAI DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define CARD_COVER '#'

void generateBoard(char board[][BOARD_SIZE]);
void printBoard(char board[][BOARD_SIZE], int showCards[][BOARD_SIZE]);
void getCardPositions(int *card1Row, int *card1Col, int *card2Row, int *card2Col);
void checkCards(char board[][BOARD_SIZE], int showCards[][BOARD_SIZE], int card1Row, int card1Col, int card2Row, int card2Col);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int showCards[BOARD_SIZE][BOARD_SIZE] = {{0}};
    int numAttempts = 0;
    int card1Row, card1Col, card2Row, card2Col;

    srand(time(NULL)); // initialize random number generator

    generateBoard(board);

    while (1) {
        printf("Attempt #%d\n", ++numAttempts);

        printBoard(board, showCards);

        getCardPositions(&card1Row, &card1Col, &card2Row, &card2Col);

        checkCards(board, showCards, card1Row, card1Col, card2Row, card2Col);

        if (numAttempts > 1 && numAttempts % 5 == 0) {
            printf("Resetting board...\n");
            generateBoard(board);
            numAttempts = 0;
        }
    }

    return 0;
}

void generateBoard(char board[][BOARD_SIZE]) {
    char cards[BOARD_SIZE * BOARD_SIZE / 2];
    int cardCount = 0;

    // create array of randomly shuffled cards
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE / 2; i++) {
        cards[i] = 'A' + i;
        cards[i + BOARD_SIZE * BOARD_SIZE / 2] = 'A' + i;
    }
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        int card1 = rand() % BOARD_SIZE * BOARD_SIZE / 2;
        int card2 = rand() % BOARD_SIZE * BOARD_SIZE / 2;
        char temp = cards[card1];
        cards[card1] = cards[card2];
        cards[card2] = temp;
    }

    // fill board with shuffled cards
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = cards[cardCount++];
        }
    }
}

void printBoard(char board[][BOARD_SIZE], int showCards[][BOARD_SIZE]) {
    printf("    ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%d  ", col + 1);
    }
    printf("\n");

    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d | ", row + 1);
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (showCards[row][col] || board[row][col] == CARD_COVER) {
                printf("%c ", board[row][col]);
            } else {
                printf("%c ", CARD_COVER);
            }
        }
        printf("|\n");
    }
}

void getCardPositions(int *card1Row, int *card1Col, int *card2Row, int *card2Col) {
    do {
        printf("Enter position of first card (row column): ");
        scanf("%d %d", card1Row, card1Col);
    } while (*card1Row < 1 || *card1Row > BOARD_SIZE || *card1Col < 1 || *card1Col > BOARD_SIZE);

    do {
        printf("Enter position of second card (row column): ");
        scanf("%d %d", card2Row, card2Col);
    } while (*card2Row < 1 || *card2Row > BOARD_SIZE || *card2Col < 1 || *card2Col > BOARD_SIZE);
}

void checkCards(char board[][BOARD_SIZE], int showCards[][BOARD_SIZE], int card1Row, int card1Col, int card2Row, int card2Col) {
    card1Row--;
    card1Col--;
    card2Row--;
    card2Col--;

    if (board[card1Row][card1Col] == board[card2Row][card2Col]) {
        showCards[card1Row][card1Col] = 1;
        showCards[card2Row][card2Col] = 1;
        printf("MATCH!\n");
    } else {
        printf("NO MATCH.\n");
    }
}