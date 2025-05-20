//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define BOARD_SIZE 4
#define TOTAL_PAIRS (BOARD_SIZE * BOARD_SIZE) / 2

char board[BOARD_SIZE][BOARD_SIZE];
char revealed[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int index = 0;

    // Fill the board with pairs of symbols
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (index < TOTAL_PAIRS) {
                board[i][j] = symbols[index / 2];
                index++;
            } else {
                board[i][j] = ' ';
            }
        }
    }
    
    // Shuffle the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int r = rand() % BOARD_SIZE;
            int c = rand() % BOARD_SIZE;
            char temp = board[i][j];
            board[i][j] = board[r][c];
            board[r][c] = temp;
        }
    }
}

void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j]) {
                printf(" %c ", board[i][j]);
            } else {
                printf(" ? ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int check_win() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!revealed[i][j])
                return 0;
        }
    }
    return 1;
}

void play_game() {
    int first_row, first_col, second_row, second_col;
    int pairs_found = 0;

    while (pairs_found < TOTAL_PAIRS) {
        print_board();
        printf("Select first card (row column): ");
        scanf("%d %d", &first_row, &first_col);
        first_row--;
        first_col--;
        
        if (first_row < 0 || first_row >= BOARD_SIZE ||
            first_col < 0 || first_col >= BOARD_SIZE ||
            revealed[first_row][first_col]) {
            printf("Invalid selection. Try again.\n");
            continue;
        }

        revealed[first_row][first_col] = 1; // Mark as revealed
        print_board(); // Show the board after selecting the first card

        printf("Select second card (row column): ");
        scanf("%d %d", &second_row, &second_col);
        second_row--;
        second_col--;

        if (second_row < 0 || second_row >= BOARD_SIZE ||
            second_col < 0 || second_col >= BOARD_SIZE ||
            (second_row == first_row && second_col == first_col) ||
            revealed[second_row][second_col]) {
            printf("Invalid selection. Try again.\n");
            revealed[first_row][first_col] = 0; // Hide first card again
            continue;
        }

        revealed[second_row][second_col] = 1; // Mark as revealed
        print_board(); // Show the board after selecting the second card

        if (board[first_row][first_col] == board[second_row][second_col]) {
            printf("You found a pair! 💖\n");
            pairs_found++;
        } else {
            printf("Not a pair. Try again! 😞\n");
            sleep(2); // Wait for 2 seconds before hiding the cards again
            revealed[first_row][first_col] = 0;
            revealed[second_row][second_col] = 0;
        }
    }

    printf("Congratulations! You've matched all pairs! 🎉\n");
}

int main() {
    srand(time(NULL));

    // Initialize revealed before starting a new game
    memset(revealed, 0, sizeof(revealed));

    initialize_board();
    
    printf("Welcome to the Memory Game!\n");
    printf("Find all the pairs of cards. 🎴\n");

    play_game();
    
    return 0;
}