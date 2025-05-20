//FormAI DATASET v1.0 Category: Memory Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int board[4][4];
int revealed[4][4];
int flipped[2] = {-1, -1};
int score = 0;
int game_over = 0;

// Function to print the game board
void print_board() {
    printf("\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (revealed[i][j]) {
                printf("%d ", board[i][j]);
            } else {
                printf("? ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the game is over
void check_game_over() {
    int revealed_count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (revealed[i][j]) {
                revealed_count++;
            }
        }
    }
    if (revealed_count == 16) {
        game_over = 1;
        printf("Congratulations! You have won the game with a score of: %d\n", score);
    }
}

// Function to flip a card
void flip_card(int x, int y) {
    int num = board[x][y];
    revealed[x][y] = 1;
    if (flipped[0] == -1) {
        flipped[0] = x;
        flipped[1] = y;
    } else {
        int prev_x = flipped[0];
        int prev_y = flipped[1];
        if (board[prev_x][prev_y] == num) {
            score += 2;
            printf("You found a match! Your score is now: %d\n", score);
            revealed[prev_x][prev_y] = 1;
            revealed[x][y] = 1;
            flipped[0] = -1;
            flipped[1] = -1;
            check_game_over();
        } else {
            score--;
            printf("You didn't find a match. Your score is now: %d\n", score);
            revealed[prev_x][prev_y] = 0;
            revealed[x][y] = 0;
            flipped[0] = -1;
            flipped[1] = -1;
        }
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Memory Game!\n");
    printf("Instructions: Try to find all the matching pairs of numbers.\n");
    printf("Enter the row and column of the card you want to flip.\n");
    printf("Let's start!\n");
    // Initialize board
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = rand() % 8 + 1;
            revealed[i][j] = 0;
        }
    }
    print_board();
    while (!game_over) {
        printf("Enter the row and column (separated by a space): ");
        int x, y;
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < 4 && y >= 0 && y < 4 && !revealed[x][y]) {
            flip_card(x, y);
        } else {
            printf("Invalid move. Please try again.\n");
        }
        print_board();
    }
    return 0;
}