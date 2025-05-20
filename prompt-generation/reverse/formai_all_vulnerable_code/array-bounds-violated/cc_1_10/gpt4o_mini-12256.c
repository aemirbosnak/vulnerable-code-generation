//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4 // Size of the memory grid
#define MAX_ATTEMPTS 3 // Maximum attempts allowed

// Function to initialize the game board with random paired values
void initialize_board(int board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    int numbers[SIZE * SIZE / 2];
    for (int i = 0; i < SIZE * SIZE / 2; i++) {
        numbers[i] = i + 1; // Fill with values 1 to 8
    }

    // Duplicate numbers for pairing
    for (int i = 0; i < SIZE * SIZE / 2; i++) {
        numbers[SIZE * SIZE / 2 + i] = numbers[i];
    }

    // Shuffle the numbers
    for (int i = SIZE * SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Fill the board with shuffled numbers
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = numbers[i * SIZE + j];
            revealed[i][j] = 0; // Initially, all cells are hidden
        }
    }
}

// Function to display the game board
void display_board(int board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("  ");
    for (int j = 0; j < SIZE; j++) {
        printf("%d ", j + 1);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%d ", board[i][j]);
            } else {
                printf("* "); // Hide the value if not revealed
            }
        }
        printf("\n");
    }
}

// Function to check if two cards match
int check_match(int board[SIZE][SIZE], int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

// Function to play a round of the game
void play_game(int board[SIZE][SIZE]) {
    int revealed[SIZE][SIZE] = {0};
    int matches = 0;
    int attempts = 0;

    while (matches < SIZE * SIZE / 2) {
        display_board(board, revealed);
        int x1, y1, x2, y2;
        
        // Get first choice
        printf("Choose first card (row column): ");
        scanf("%d %d", &x1, &y1);
        x1--; y1--; // Convert to 0-indexed

        if (revealed[x1][y1] == 1) {
            printf("Card already revealed! Try again.\n");
            continue;
        }

        revealed[x1][y1] = 1; // Reveal the card
        display_board(board, revealed);

        // Get second choice
        printf("Choose second card (row column): ");
        scanf("%d %d", &x2, &y2);
        x2--; y2--; // Convert to 0-indexed

        if (revealed[x2][y2] == 1) {
            printf("Card already revealed! Try again.\n");
            revealed[x1][y1] = 0; // Hide the first card again
            continue;
        }

        revealed[x2][y2] = 1; // Reveal the second card
        display_board(board, revealed);

        // Check for match
        if (check_match(board, x1, y1, x2, y2)) {
            printf("You found a match!\n");
            matches++;
        } else {
            printf("No match, try again!\n");
            attempts++;
            revealed[x1][y1] = 0; // Hide the first card again
            revealed[x2][y2] = 0; // Hide the second card again
            
            if (attempts >= MAX_ATTEMPTS) {
                printf("Maximum attempts reached. Game over!\n");
                break;
            }
        }
    }

    if (matches == SIZE * SIZE / 2) {
        printf("Congratulations! You've revealed all matches!\n");
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int board[SIZE][SIZE];
    initialize_board(board, NULL);
    play_game(board);
    
    printf("Thank you for playing!\n");
    return 0;
}