//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4  // Size of the board (SIZE x SIZE)
#define NUM_PAIRS (SIZE * SIZE) / 2  // Number of pairs of cards
#define EMPTY ' '  // Represents an empty space

char board[SIZE][SIZE];  // The game board
char symbols[NUM_PAIRS];  // The symbols to be placed on the board
bool revealed[SIZE][SIZE];  // Tracks revealed cards
int score = 0;  // Player's score

void initialize_symbols() {
    char start_symbol = 'A';
    for (int i = 0; i < NUM_PAIRS; i++) {
        symbols[i] = start_symbol + (i / 2);
    }
}

void shuffle_symbols() {
    for (int i = NUM_PAIRS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = symbols[i];
        symbols[i] = symbols[j];
        symbols[j] = temp;
    }
}

void initialize_board() {
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = symbols[index++];
            revealed[i][j] = false;
        }
    }
}

void print_board() {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf("%c ", EMPTY);
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

bool is_match(int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

void reveal(int x, int y) {
    revealed[x][y] = true;
}

void hide(int x, int y) {
    revealed[x][y] = false;
}

bool all_cards_revealed() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!revealed[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void play_game() {
    int x1, y1, x2, y2;

    while (!all_cards_revealed()) {
        print_board();
        printf("Enter coordinates of first card (row and column): ");
        scanf("%d %d", &x1, &y1);
        reveal(x1, y1);
        print_board();
        
        printf("Enter coordinates of second card (row and column): ");
        scanf("%d %d", &x2, &y2);
        
        if (is_match(x1, y1, x2, y2)) {
            printf("It's a match!\n");
            score++;
        } else {
            printf("Not a match. Try again!\n");
            hide(x1, y1);
            hide(x2, y2);
        }
    }

    printf("Congratulations! You've revealed all cards!\n");
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    initialize_symbols();
    shuffle_symbols();
    initialize_board();
    play_game();
    return 0;
}