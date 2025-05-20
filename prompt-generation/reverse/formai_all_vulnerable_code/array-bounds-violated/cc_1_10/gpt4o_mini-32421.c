//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4 // 4x4 grid
#define NUM_PAIRED_CARDS (SIZE * SIZE) / 2

// Function to initialize the board
void initialize_board(int board[SIZE][SIZE]) {
    int values[NUM_PAIRED_CARDS];
    for (int i = 0; i < NUM_PAIRED_CARDS; i++) {
        values[i] = i + 1; // Fill with values 1 to 8
    }

    // Fill the board with pairs
    for (int i = 0; i < NUM_PAIRED_CARDS; i++) {
        board[i / SIZE][i % SIZE] = values[i]; 
        board[i / SIZE][i % SIZE + SIZE] = values[i]; 
    }

    // Shuffle the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int random_i = rand() % SIZE;
            int random_j = rand() % SIZE;
            // Swap values
            int temp = board[i][j];
            board[i][j] = board[random_i][random_j];
            board[random_i][random_j] = temp;
        }
    }
}

// Function to display the board
void display_board(int board[SIZE][SIZE], bool revealed[SIZE][SIZE]) {
    printf("Memory Game Board:\n");
    printf("  0 1 2 3\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%d ", board[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

// Function to check if all pairs are found
bool is_game_over(bool revealed[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!revealed[i][j]) return false;
        }
    }
    return true;
}

// Function to play the game
void play_game() {
    int board[SIZE][SIZE];
    bool revealed[SIZE][SIZE] = {false}; // Tracking revealed cards
    int first_x, first_y, second_x, second_y;
    int pairs_found = 0;

    initialize_board(board);

    while (!is_game_over(revealed)) {
        display_board(board, revealed);

        // Player chooses first card
        printf("Choose first card (row and column): ");
        scanf("%d %d", &first_x, &first_y);
        if (revealed[first_x][first_y]) {
            printf("Card already revealed! Choose another one.\n");
            continue;
        }

        revealed[first_x][first_y] = true; // Reveal first card

        display_board(board, revealed);
        
        // Player chooses second card
        printf("Choose second card (row and column): ");
        scanf("%d %d", &second_x, &second_y);
        if (revealed[second_x][second_y]) {
            printf("Card already revealed! Choose another one.\n");
            revealed[first_x][first_y] = false; // Hide the first card again
            continue;
        }

        revealed[second_x][second_y] = true; // Reveal second card

        if (board[first_x][first_y] == board[second_x][second_y]) {
            printf("You found a pair!\n");
            pairs_found++;
        } else {
            printf("Not a match!\n");
            // Hide cards again
            revealed[first_x][first_y] = false;
            revealed[second_x][second_y] = false;
        }
    }

    printf("Congratulations! You've found all pairs!\n");
}

int main() {
    srand(time(NULL)); // Seed random number generator
    play_game();
    return 0;
}