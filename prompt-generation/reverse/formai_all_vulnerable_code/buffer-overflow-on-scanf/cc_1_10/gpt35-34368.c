//FormAI DATASET v1.0 Category: Memory Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4  // 4 x 4 game board
#define MAX_GUESSES (BOARD_SIZE * BOARD_SIZE) / 2  // Maximum allowed guesses

void print_board(int board[][BOARD_SIZE], int revealed[][BOARD_SIZE]) {
    // Print game board with revealed cards
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%2d ", board[i][j]);
            } else {
                printf("-- ");
            }
        }
        printf("\n");
    }
}

void shuffle(int arr[], int n) {
    // Shuffle an array of integers
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int revealed[BOARD_SIZE][BOARD_SIZE] = {0};  // Card revealed state
    int guesses = 0;

    // Generate a list of numbers in the range 1 to 8 (inclusive) and shuffle them
    int cards[MAX_GUESSES * 2];
    for (int i = 0; i < MAX_GUESSES * 2; i++) {
        cards[i] = (i % MAX_GUESSES) + 1;
    }
    shuffle(cards, MAX_GUESSES * 2);

    // Fill the game board with shuffled card values
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = cards[(i * BOARD_SIZE) + j];
        }
    }

    // Game loop
    while (guesses < MAX_GUESSES) {
        printf("\nGuess a pair of card positions (e.g. [0 0] [1 3]): ");
        int r1, c1, r2, c2;
        scanf("[%d %d] [%d %d]", &r1, &c1, &r2, &c2);

        // Check if selected cards are valid
        if (r1 < 0 || r1 >= BOARD_SIZE || c1 < 0 || c1 >= BOARD_SIZE ||
            r2 < 0 || r2 >= BOARD_SIZE || c2 < 0 || c2 >= BOARD_SIZE) {
            printf("Invalid card positions. Try again.\n");
            continue;
        }

        // Check if selected cards are already revealed
        if (revealed[r1][c1] || revealed[r2][c2]) {
            printf("That card has already been revealed. Try again.\n");
            continue;
        }

        // Reveal the selected cards
        revealed[r1][c1] = 1;
        revealed[r2][c2] = 1;

        // Check if selected cards match
        if (board[r1][c1] == board[r2][c2]) {
            printf("Match!\n");
            guesses++;
        } else {
            printf("No match. Try again.\n");
        }

        // Print the game board
        print_board(board, revealed);
    }

    printf("\nCongratulations! You won the game in %d guesses.\n", guesses);
    return 0;
}