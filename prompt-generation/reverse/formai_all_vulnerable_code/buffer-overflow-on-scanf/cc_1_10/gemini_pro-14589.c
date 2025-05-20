//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the game board
char board[4][4];
int flipped[4][4];

// Function to print the game board
void print_board() {
    printf("\n  1 2 3 4\n");
    for (int i = 0; i < 4; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 4; j++) {
            if (flipped[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf("? ");
            }
        }
        printf("\n");
    }
}

// Function to flip a card
void flip_card(int x, int y) {
    flipped[x - 1][y - 1] = 1;
}

// Function to check if two cards match
int cards_match(int x1, int y1, int x2, int y2) {
    return board[x1 - 1][y1 - 1] == board[x2 - 1][y2 - 1];
}

// Function to check if the game is over
int game_over() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (!flipped[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the game board
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = 'A' + rand() % 13;
            flipped[i][j] = 0;
        }
    }

    // Play the game
    while (!game_over()) {
        // Get the user's input
        int x1, y1, x2, y2;
        printf("Enter the coordinates of the first card: ");
        scanf("%d %d", &x1, &y1);
        printf("Enter the coordinates of the second card: ");
        scanf("%d %d", &x2, &y2);

        // Flip the cards
        flip_card(x1, y1);
        flip_card(x2, y2);

        // Print the game board
        print_board();

        // Check if the cards match
        if (cards_match(x1, y1, x2, y2)) {
            printf("Match!\n");
        } else {
            printf("No match.\n");
        }
    }

    // Print the final game board
    print_board();

    // Congratulate the player
    printf("Congratulations! You won the game.\n");

    return 0;
}