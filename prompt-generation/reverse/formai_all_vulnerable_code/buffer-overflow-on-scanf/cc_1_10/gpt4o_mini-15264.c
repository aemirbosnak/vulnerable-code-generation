//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4 // 4x4 grid
#define TOTAL_PAIRS (SIZE * SIZE) / 2

typedef struct {
    char symbol;
    bool revealed;
} Card;

void initialize_board(Card board[SIZE][SIZE]);
void shuffle_board(Card board[SIZE][SIZE]);
void print_board(Card board[SIZE][SIZE]);
bool flip_card(Card board[SIZE][SIZE], int row, int col);
bool check_pairs(Card board[SIZE][SIZE], int first_card_row, int first_card_col, 
                 int second_card_row, int second_card_col);
bool game_over(Card board[SIZE][SIZE]);

int main() {
    Card board[SIZE][SIZE];
    initialize_board(board);
    shuffle_board(board);
    
    int first_row, first_col, second_row, second_col;
    int pairs_found = 0;

    while (!game_over(board)) {
        print_board(board);
        
        printf("Enter the coordinates of the first card (row and column): ");
        scanf("%d %d", &first_row, &first_col);
        first_row--; first_col--; // Adjust for zero-indexing

        if (!flip_card(board, first_row, first_col)) {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        print_board(board);
        
        printf("Enter the coordinates of the second card (row and column): ");
        scanf("%d %d", &second_row, &second_col);
        second_row--; second_col--; // Adjust for zero-indexing

        if (!flip_card(board, second_row, second_col) || 
            (first_row == second_row && first_col == second_col)) {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        if (check_pairs(board, first_row, first_col, second_row, second_col)) {
            pairs_found++;
            printf("Match found! Pairs found: %d\n", pairs_found);
        } else {
            printf("No match! Try again.\n");
            board[first_row][first_col].revealed = false;
            board[second_row][second_col].revealed = false;
        }
    }

    printf("Congratulations! You've found all pairs!\n");
    return 0;
}

void initialize_board(Card board[SIZE][SIZE]) {
    char symbols[TOTAL_PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        board[i / SIZE][i % SIZE].symbol = symbols[i / 2];
        board[i / SIZE][i % SIZE].revealed = false;
    }
}

void shuffle_board(Card board[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int r1 = rand() % SIZE;
            int c1 = rand() % SIZE;
            Card temp = board[i][j];
            board[i][j] = board[r1][c1];
            board[r1][c1] = temp;
        }
    }
}

void print_board(Card board[SIZE][SIZE]) {
    printf("  ");
    for (int j = 0; j < SIZE; j++) {
        printf("%d ", j + 1);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j].revealed) {
                printf("%c ", board[i][j].symbol);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

bool flip_card(Card board[SIZE][SIZE], int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return false; // Invalid indices
    }
    board[row][col].revealed = true;
    return true;
}

bool check_pairs(Card board[SIZE][SIZE], int first_card_row, int first_card_col,
                 int second_card_row, int second_card_col) {
    return board[first_card_row][first_card_col].symbol == 
           board[second_card_row][second_card_col].symbol;
}

bool game_over(Card board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j].revealed) {
                return false;
            }
        }
    }
    return true;
}