//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_ROWS 7
#define NUM_COLS 9

struct card {
    char suit;
    char rank;
};

struct card deck[NUM_CARDS];
struct card board[NUM_ROWS][NUM_COLS];
int num_cards_on_board;

void shuffle_deck(void) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i].suit = rand() % 4 + 1;
        deck[i].rank = rand() % 13 + 1;
    }
    printf("Shuffled deck:\n");
    for (int i = 0; i < NUM_CARDS; i++) {
        printf("%d%c\n", deck[i].rank, deck[i].suit + 'A');
    }
}

void deal_card(int row, int col) {
    board[row][col] = deck[--num_cards_on_board];
    printf("Dealt card: %c%d\n", board[row][col].suit + 'A', board[row][col].rank);
}

void display_board(void) {
    printf("Board:\n");
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (board[i][j].suit == 0) {
                printf(" ");
            } else {
                printf("%c%d ", board[i][j].suit + 'A', board[i][j].rank);
            }
        }
        printf("\n");
    }
}

int main(void) {
    shuffle_deck();
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            deal_card(i, j);
        }
    }
    display_board();
    return 0;
}