//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define GRID_SIZE 4
#define TOTAL_PAIRS (GRID_SIZE * GRID_SIZE) / 2
#define EMPTY 0
#define SHOWN -1
#define GAME_OVER 1
#define WIN 0

typedef struct {
    int value;
    int state; // -1: shown, 0: hidden
} Card;

void init_cards(Card cards[GRID_SIZE][GRID_SIZE]);
void shuffle_cards(Card cards[GRID_SIZE][GRID_SIZE]);
void print_board(Card cards[GRID_SIZE][GRID_SIZE]);
int check_pair(Card cards[GRID_SIZE][GRID_SIZE], int row1, int col1, int row2, int col2);
int is_winner(Card cards[GRID_SIZE][GRID_SIZE]);
void clear_screen();

int main() {
    Card cards[GRID_SIZE][GRID_SIZE];
    int row1, col1, row2, col2;
    int pairs_found = 0;
    int game_state = 0;

    srand(time(NULL));
    init_cards(cards);
    shuffle_cards(cards);

    while (game_state == 0) {
        clear_screen();
        print_board(cards);
        printf("Select first card (row and col): ");
        scanf("%d %d", &row1, &col1);
        printf("Select second card (row and col): ");
        scanf("%d %d", &row2, &col2);

        if (check_pair(cards, row1, col1, row2, col2)) {
            printf("It's a match!\n");
            pairs_found++;
        } else {
            printf("Not a match!\n");
            cards[row1][col1].state = EMPTY;
            cards[row2][col2].state = EMPTY;
        }

        if (pairs_found == TOTAL_PAIRS) {
            game_state = WIN;
        }

        sleep(1);
    }

    clear_screen();
    print_board(cards);
    printf("Congratulations! You've found all pairs!\n");
    return 0;
}

void init_cards(Card cards[GRID_SIZE][GRID_SIZE]) {
    int values[TOTAL_PAIRS];
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        values[i] = i + 1;
    }

    int idx = 0;
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        cards[i / GRID_SIZE][i % GRID_SIZE] = (Card){values[i], EMPTY};
    }
}

void shuffle_cards(Card cards[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        int j = rand() % TOTAL_PAIRS;
        Card temp = cards[i / GRID_SIZE][i % GRID_SIZE];
        cards[i / GRID_SIZE][i % GRID_SIZE] = cards[j / GRID_SIZE][j % GRID_SIZE];
        cards[j / GRID_SIZE][j % GRID_SIZE] = temp;
    }
}

void print_board(Card cards[GRID_SIZE][GRID_SIZE]) {
    printf("================================================\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (cards[i][j].state == SHOWN) {
                printf("| %d ", cards[i][j].value);
            } else {
                printf("| ? ");
            }
        }
        printf("|\n");
        printf("------------------------------------------------\n");
    }
}

int check_pair(Card cards[GRID_SIZE][GRID_SIZE], int row1, int col1, int row2, int col2) {
    if (cards[row1][col1].state == EMPTY && cards[row2][col2].state == EMPTY) {
        cards[row1][col1].state = SHOWN;
        cards[row2][col2].state = SHOWN;

        if (cards[row1][col1].value == cards[row2][col2].value) {
            return 1; // Match!
        }

        return 0; // Not a match
    }

    return 0; // Invalid pick
}

int is_winner(Card cards[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (cards[i][j].state == EMPTY) {
                return 0; // Not all pairs found
            }
        }
    }
    return 1; // All pairs found
}

void clear_screen() {
    // Clearing the screen with ANSI escape code
    printf("\033[H\033[J");
}