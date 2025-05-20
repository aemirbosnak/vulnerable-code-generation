//FormAI DATASET v1.0 Category: Memory Game ; Style: decentralized
// C Memory Game Example Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

// Function prototypes
void initializeBoard(int board[][BOARD_SIZE]);
void printBoard(int board[][BOARD_SIZE], int revealed[][BOARD_SIZE]);
void shuffle(int *array, size_t n);
void playGame(int board[][BOARD_SIZE], int revealed[][BOARD_SIZE]);

int main(void) {
    // Set up random seed for shuffling cards
    srand(time(NULL));

    // Create board and revealed arrays
    int board[BOARD_SIZE][BOARD_SIZE];
    int revealed[BOARD_SIZE][BOARD_SIZE] = {0};

    // Initialize board and play game
    initializeBoard(board);
    playGame(board, revealed);

    return 0;
}

void initializeBoard(int board[][BOARD_SIZE]) {
    // Create array of card values and shuffle
    int cards[BOARD_SIZE*BOARD_SIZE/2];
    for (int i = 0; i < BOARD_SIZE*BOARD_SIZE/2; i++) {
        cards[2*i] = i+1;
        cards[2*i+1] = i+1;
    }
    shuffle(cards, BOARD_SIZE*BOARD_SIZE);

    // Assign values to board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = cards[i*BOARD_SIZE+j];
        }
    }
}

void printBoard(int board[][BOARD_SIZE], int revealed[][BOARD_SIZE]) {
    // Print board with hidden and revealed cards
    printf("    ");
    for (int j = 0; j < BOARD_SIZE; j++) {
        printf("%d   ", j+1);
    }
    printf("\n");
    printf("   ");
    for (int j = 0; j < BOARD_SIZE; j++) {
        printf("----");
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c | ", 'A'+i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%d | ", board[i][j]);
            } else {
                printf("  | ");
            }
        }
        printf("\n");
        printf("   ");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("----");
        }
        printf("\n");
    }
}

void shuffle(int *array, size_t n) {
    // Shuffle array
    if (n > 1) {
        for (size_t i = 0; i < n-1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
}

void playGame(int board[][BOARD_SIZE], int revealed[][BOARD_SIZE]) {
    int num_turns = 0;
    while (1) {
        // Print board
        printf("\nNumber of turns: %d\n", num_turns);
        printBoard(board, revealed);

        // Check if all cards have been revealed
        int all_revealed = 1;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (!revealed[i][j]) {
                    all_revealed = 0;
                    break;
                }
            }
            if (!all_revealed) {
                break;
            }
        }
        if (all_revealed) {
            printf("Congratulations, you won in %d turns!\n", num_turns);
            return;
        }

        // Prompt user for card to reveal
        char row;
        int col;
        printf("Enter row and column of card to reveal (e.g. A 1): ");
        scanf(" %c %d", &row, &col);

        // Convert row to integer index
        int row_index = (int)(row - 'A');
        if (row_index < 0 || row_index >= BOARD_SIZE) {
            printf("Invalid row. Please choose a letter between A and %c.\n", 'A'+BOARD_SIZE-1);
            continue;
        }

        // Convert col to integer index
        col--;
        if (col < 0 || col >= BOARD_SIZE) {
            printf("Invalid column. Please choose a number between 1 and %d.\n", BOARD_SIZE);
            continue;
        }

        // Check if card has already been revealed
        if (revealed[row_index][col]) {
            printf("Card has already been revealed. Please choose a different card.\n");
            continue;
        }

        // Reveal card
        revealed[row_index][col] = 1;
        num_turns++;

        // Check if two cards have been revealed and if they match
        int revealed_values[2] = {0};
        int num_revealed = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (revealed[i][j]) {
                    revealed_values[num_revealed] = board[i][j];
                    num_revealed++;
                }
            }
        }
        if (num_revealed == 2) {
            if (revealed_values[0] == revealed_values[1]) {
                printf("Match!\n");
            } else {
                printf("No match.\n");
                revealed[row_index][col] = 0;
                for (int i = 0; i < BOARD_SIZE; i++) {
                    for (int j = 0; j < BOARD_SIZE; j++) {
                        if (revealed[i][j] && board[i][j] != revealed_values[0]) {
                            revealed[i][j] = 0;
                        }
                    }
                }
            }
        }
    }
}