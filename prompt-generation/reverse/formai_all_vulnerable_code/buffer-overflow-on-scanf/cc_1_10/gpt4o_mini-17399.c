//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> // For sleep and clear

#define SIZE 4
#define TOTAL_PAIRS (SIZE * SIZE) / 2

void initialize_board(char board[SIZE][SIZE]);
void shuffle_board(char board[SIZE][SIZE]);
void print_board(char board[SIZE][SIZE], int revealed[SIZE][SIZE]);
int is_game_won(int revealed[SIZE][SIZE]);
int reveal_card(char board[SIZE][SIZE], int revealed[SIZE][SIZE], int row, int col);
void clear_screen();

int main() {
    char board[SIZE][SIZE];
    int revealed[SIZE][SIZE] = {0};
    int first_row, first_col, second_row, second_col;
    int moves = 0, pairs_found = 0;

    srand(time(NULL));
    initialize_board(board);
    shuffle_board(board);

    printf("🎨 Welcome to the Magical Memory Game! 🎨\n");
    printf("🌟 Try to find the matching pairs! 🌟\n");
    printf("❗ You have a maximum of %d moves! ❗\n", (TOTAL_PAIRS * 2));
    
    while (moves < (TOTAL_PAIRS * 2) && pairs_found < TOTAL_PAIRS) {
        clear_screen();
        print_board(board, revealed);

        printf("Enter the coordinates of the first card (row col): ");
        scanf("%d %d", &first_row, &first_col);
        if (!reveal_card(board, revealed, first_row, first_col)) {
            printf("⚠️ Invalid selection! Please try again.\n");
            sleep(1);
            continue;
        }

        print_board(board, revealed);
        printf("Enter the coordinates of the second card (row col): ");
        scanf("%d %d", &second_row, &second_col);
        if (!reveal_card(board, revealed, second_row, second_col)) {
            printf("⚠️ Invalid selection! Please try again.\n");
            sleep(1);
            continue;
        }

        moves += 2;

        if (board[first_row][first_col] == board[second_row][second_col]) {
            printf("🎉 You found a pair! 🎉\n");
            pairs_found++;
        } else {
            printf("❌ Not a match! ❌\n");
            revealed[first_row][first_col] = 0;
            revealed[second_row][second_col] = 0;
        }
        
        sleep(2);
    }

    clear_screen();
    print_board(board, revealed);

    if (pairs_found == TOTAL_PAIRS) {
        printf("🥳 Congratulations! You've matched all pairs! 🥳\n");
    } else {
        printf("😢 Out of moves! Better luck next time! 😢\n");
    }

    return 0;
}

void initialize_board(char board[SIZE][SIZE]) {
    char symbols[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int index = 0;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (index < TOTAL_PAIRS) {
                board[i][j] = symbols[index];
                index++;
            } else {
                board[i][j] = '\0'; // Ensure no leftover symbols
            }
        }
    }
}

void shuffle_board(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int r = rand() % SIZE;
            int c = rand() % SIZE;
            char temp = board[i][j];
            board[i][j] = board[r][c];
            board[r][c] = temp;
        }
    }
}

void print_board(char board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("🃏🃏 Memory Game Board 🃏🃏\n");
    printf("   0 1 2 3\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf("❓ "); // Unknown card
            }
        }
        printf("\n");
    }
}

int is_game_won(int revealed[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!revealed[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int reveal_card(char board[SIZE][SIZE], int revealed[SIZE][SIZE], int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || revealed[row][col]) {
        return 0; // Invalid move
    }
    revealed[row][col] = 1; // Reveal the card
    return 1; // Success
}

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape code to clear screen
}