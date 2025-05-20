//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#define ROWS 4
#define COLS 4
#define NUM_CARDS (ROWS * COLS) / 2 

typedef struct {
    char symbol;
    bool is_opened;
} Card;

void initialize_board(Card board[ROWS][COLS]);
void shuffle_cards(Card board[ROWS][COLS]);
void print_board(Card board[ROWS][COLS]);
bool all_cards_opened(Card board[ROWS][COLS]);
void open_card(Card board[ROWS][COLS], int row, int col);
void close_card(Card board[ROWS][COLS], int row, int col);
bool check_match(Card board[ROWS][COLS], int row1, int col1, int row2, int col2);
void play_game();

int main() {
    srand(time(NULL));
    play_game();
    return 0;
}

void play_game() {
    Card board[ROWS][COLS];
    initialize_board(board);
    int first_row, first_col, second_row, second_col;
    int moves = 0;

    while (!all_cards_opened(board)) {
        print_board(board);
        printf("Select the first card (row and column): ");
        scanf("%d %d", &first_row, &first_col);
        open_card(board, first_row, first_col);
        print_board(board);
        
        printf("Select the second card (row and column): ");
        scanf("%d %d", &second_row, &second_col);
        open_card(board, second_row, second_col);
        print_board(board);
        
        if (check_match(board, first_row, first_col, second_row, second_col)) {
            printf("It's a match!\n");
        } else {
            printf("Not a match. Try again.\n");
            sleep(2); // wait for 2 seconds
            close_card(board, first_row, first_col);
            close_card(board, second_row, second_col);
        }
        
        moves++;
    }

    printf("Congratulations! You've matched all cards in %d moves.\n", moves);
}

void initialize_board(Card board[ROWS][COLS]) {
    char symbols[NUM_CARDS] = {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E', 'F', 'F'};
    for (int i = 0; i < NUM_CARDS; i++) {
        board[i / COLS][i % COLS].symbol = symbols[i];
        board[i / COLS][i % COLS].is_opened = false;
    }
    shuffle_cards(board);
}

void shuffle_cards(Card board[ROWS][COLS]) {
    for (int i = 0; i < NUM_CARDS; i++) {
        int r = rand() % NUM_CARDS;
        char temp = board[i / COLS][i % COLS].symbol;
        board[i / COLS][i % COLS].symbol = board[r / COLS][r % COLS].symbol;
        board[r / COLS][r % COLS].symbol = temp;
    }
}

void print_board(Card board[ROWS][COLS]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j].is_opened) {
                printf("[%c] ", board[i][j].symbol);
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

bool all_cards_opened(Card board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (!board[i][j].is_opened) {
                return false;
            }
        }
    }
    return true;
}

void open_card(Card board[ROWS][COLS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        board[row][col].is_opened = true;
    }
}

void close_card(Card board[ROWS][COLS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        board[row][col].is_opened = false;
    }
}

bool check_match(Card board[ROWS][COLS], int row1, int col1, int row2, int col2) {
    if (row1 == row2 && col1 == col2) {
        return false; // Cannot match the same card
    }
    return board[row1][col1].symbol == board[row2][col2].symbol;
}