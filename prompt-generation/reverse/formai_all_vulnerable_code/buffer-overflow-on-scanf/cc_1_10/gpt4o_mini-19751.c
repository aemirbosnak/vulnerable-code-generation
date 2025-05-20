//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4 // Size of the board (4x4)
#define PAIR_COUNT 8 // Total pairs of cards to match

char board[SIZE][SIZE]; // Game Board
char revealed[SIZE][SIZE]; // Revealed cards
bool cardFlipped[SIZE][SIZE]; // Track flipped cards

// Function to initialize the board with pairs of letters
void initialize_board() {
    char letters[PAIR_COUNT] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int index = 0;

    // Fill the board with pairs of letters
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (index < PAIR_COUNT) {
                board[i][j] = letters[index];
                board[i][(j + 1) % SIZE] = letters[index]; // Add pair
                index++;
                j++; // Move to next column
            } else {
                board[i][j] = ' '; // Fill the rest with space
            }
        }
    }

    // Shuffle the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int rand_i = rand() % SIZE;
            int rand_j = rand() % SIZE;
            char temp = board[i][j];
            board[i][j] = board[rand_i][rand_j];
            board[rand_i][rand_j] = temp;
        }
    }

    // Initialize revealed cards
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            revealed[i][j] = 'X'; // X represents unrevealed state
            cardFlipped[i][j] = false; // All cards are initially not flipped
        }
    }
}

// Function to print the game board
void print_board() {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (cardFlipped[i][j]) {
                printf(" %c ", board[i][j]);
            } else {
                printf(" %c ", revealed[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the selected positions match
bool check_match(int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

// Main Function
int main() {
    int turns = 0;
    int pairsFound = 0;
    int totalPairs = PAIR_COUNT;
    int x1, y1, x2, y2;

    srand(time(NULL)); // Seed random number generator
    initialize_board(); // Initialize the game board

    printf("🎉 Welcome to the Memory Game! 🎉\n");

    while (pairsFound < totalPairs) {
        print_board();
        printf("Turn %d: Enter the coordinates of the first card (row col) to flip: ", turns + 1);
        scanf("%d %d", &x1, &y1);
        if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE || cardFlipped[x1][y1]) {
            printf("💔 Invalid move! Try again.\n");
            continue;
        }
        
        cardFlipped[x1][y1] = true; // Flip the first card
        print_board();
        
        printf("Now, enter the coordinates of the second card (row col) to flip: ");
        scanf("%d %d", &x2, &y2);
        
        if (x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE || cardFlipped[x2][y2] || (x1 == x2 && y1 == y2)) {
            printf("💔 Invalid move! Try again.\n");
            cardFlipped[x1][y1] = false; // Unflip the first card
            continue;
        }

        cardFlipped[x2][y2] = true; // Flip the second card
        print_board();

        if (check_match(x1, y1, x2, y2)) {
            printf("🎊 You found a match! 🎊\n");
            pairsFound++;
        } else {
            printf("😢 No match! Try again next turn.\n");
            // Reset if no match
            cardFlipped[x1][y1] = false;
            cardFlipped[x2][y2] = false;
        }
        
        turns++;
    }
    
    printf("🎉 Congratulations! You've matched all cards in %d turns! 🎉\n", turns);
    
    return 0;
}