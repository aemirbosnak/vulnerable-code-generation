//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4  // Size of the grid (4x4)
#define NUM_PAIRS (SIZE * SIZE) / 2

void initialize_board(char board[SIZE][SIZE]);
void shuffle_board(char board[SIZE][SIZE]);
void print_board(char board[SIZE][SIZE], int revealed[SIZE][SIZE]);
int is_game_completed(int revealed[SIZE][SIZE]);
void reveal_card(char board[SIZE][SIZE], int revealed[SIZE][SIZE], int x, int y);
void hide_card(int revealed[SIZE][SIZE], int x, int y);
void clear_input_buffer();

int main() {
    char board[SIZE][SIZE];
    int revealed[SIZE][SIZE] = {0};  // Tracks revealed cards
    int x1, y1, x2, y2;
    int moves = 0;

    srand(time(NULL));

    initialize_board(board);
    shuffle_board(board);

    while (!is_game_completed(revealed)) {
        print_board(board, revealed);
        printf("Enter the coordinates of the first card (row col): ");
        scanf("%d %d", &x1, &y1);
        clear_input_buffer();

        if (revealed[x1][y1]) {
            printf("Card already revealed! Try again.\n");
            continue;
        }

        reveal_card(board, revealed, x1, y1);
        print_board(board, revealed);

        printf("Enter the coordinates of the second card (row col): ");
        scanf("%d %d", &x2, &y2);
        clear_input_buffer();

        if (revealed[x2][y2]) {
            printf("Card already revealed! Try again.\n");
            hide_card(revealed, x1, y1);
            continue;
        }

        reveal_card(board, revealed, x2, y2);
        print_board(board, revealed);
        moves++;

        if (board[x1][y1] != board[x2][y2]) {
            printf("No match! Try again.\n");
            hide_card(revealed, x1, y1);
            hide_card(revealed, x2, y2);
        } else {
            printf("You found a match!\n");
        }
    }

    printf("Congratulations! You've completed the Memory Game in %d moves!\n", moves);
    return 0;
}

void initialize_board(char board[SIZE][SIZE]) {
    char letters[NUM_PAIRS];
    int idx = 0;

    // Create pairs of letters
    for (char c = 'A'; c < 'A' + NUM_PAIRS; c++) {
        letters[idx++] = c;
    }

    // Assign letters to the board
    idx = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = letters[idx++];
        }
    }
}

void shuffle_board(char board[SIZE][SIZE]) {
    for (int i = SIZE * SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = board[i / SIZE][i % SIZE];
        board[i / SIZE][i % SIZE] = board[j / SIZE][j % SIZE];
        board[j / SIZE][j % SIZE] = temp;
    }
}

void print_board(char board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("\nCurrent board state:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("[%c] ", board[i][j]);
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

int is_game_completed(int revealed[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!revealed[i][j]) {
                return 0;  // Game not completed
            }
        }
    }
    return 1;  // Game completed
}

void reveal_card(char board[SIZE][SIZE], int revealed[SIZE][SIZE], int x, int y) {
    revealed[x][y] = 1;  // Mark card as revealed
}

void hide_card(int revealed[SIZE][SIZE], int x, int y) {
    revealed[x][y] = 0;  // Hide card
}

void clear_input_buffer() {
    while (getchar() != '\n');
}