//FormAI DATASET v1.0 Category: Memory Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int BOARD_SIZE = 4;
    int board[BOARD_SIZE][BOARD_SIZE];
    int flipped[BOARD_SIZE][BOARD_SIZE];
    
    // Initialize the board
    int pairs[BOARD_SIZE * BOARD_SIZE / 2];
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE / 2; i++) {
        pairs[i] = i + 1;
    }
    srand(time(NULL));  // Initialize the random number generator
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int r = rand() % (BOARD_SIZE * BOARD_SIZE / 2);
            board[i][j] = pairs[r];
            board[BOARD_SIZE - i - 1][BOARD_SIZE - j - 1] = pairs[r];
            pairs[r] = pairs[BOARD_SIZE * BOARD_SIZE / 2 - r - 1];  // Remove the used pair
        }
    }
    
    int num_guesses = 0;
    int score = 0;
    int game_over = 0;
    while (!game_over) {
        // Print the board
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (flipped[i][j]) {
                    printf("%2d ", board[i][j]);
                } else {
                    printf("   ");
                }
            }
            printf("\n");
        }
        
        // Get the user's guess
        int row1, col1, row2, col2;
        printf("Enter the row and column of your first guess: ");
        scanf("%d %d", &row1, &col1);
        row1--;
        col1--;
        printf("Enter the row and column of your second guess: ");
        scanf("%d %d", &row2, &col2);
        row2--;
        col2--;
        
        // Flip the cards
        flipped[row1][col1] = 1;
        flipped[row2][col2] = 1;
        num_guesses++;
        
        // Check if the guesses match
        if (board[row1][col1] == board[row2][col2]) {
            score++;
            printf("Congratulations, you found a matching pair!\n");
            if (score == BOARD_SIZE * BOARD_SIZE / 2) {
                game_over = 1;
                printf("You won in %d guesses!\n", num_guesses);
            }
        } else {
            // Wait for a moment to show the cards before flipping them back over
            for (int i = 0; i < 100000000; i++);
            flipped[row1][col1] = 0;
            flipped[row2][col2] = 0;
            printf("Sorry, those cards do not match.\n");
        }
    }

    return 0;
}