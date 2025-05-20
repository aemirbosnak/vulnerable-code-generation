//FormAI DATASET v1.0 Category: Memory Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define CARD_PAIRS 8

void shuffle(int *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void printBoard(int board[][BOARD_SIZE], int flipped[][BOARD_SIZE], int score) {
    printf("\n\nMemory Game: Post-Apocalyptic Edition\n");
    printf("Score: %d\n\n", score);
    printf("    1 2 3 4\n");
    printf("   ---------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (flipped[i][j] == 1) {
                printf(" %c", (char) board[i][j]);
            }
            else {
                printf(" *");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void playGame() {
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    char card_symbols[CARD_PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int card_values[CARD_PAIRS * 2] = {0}; // 2 values per card pair
    int flipped[BOARD_SIZE][BOARD_SIZE] = {0};
    int first_choice[2] = {-1, -1};
    int score = 0;
    int pairs_found = 0;

    srand(time(0));
    // Assign random values to card pairs
    for (int i = 0; i < CARD_PAIRS; i++) {
        int j = i * 2;
        card_values[j] = card_symbols[i];
        card_values[j + 1] = card_symbols[i];
    }
    shuffle(card_values, CARD_PAIRS * 2);

    // Fill the board with card values
    for (int i = 0, k = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++, k++) {
            board[i][j] = card_values[k];
        }
    }

    // Game loop
    while (pairs_found < CARD_PAIRS) {
        printBoard(board, flipped, score);

        // Get choice from user
        int row, column;
        printf("Choose a card to flip: \n");
        printf("Row: ");
        scanf("%d", &row);
        printf("Column: ");
        scanf("%d", &column);
        printf("\n");

        // Check if the selected card is valid
        if (row < 1 || row > BOARD_SIZE || column < 1 || column > BOARD_SIZE) {
            printf("Invalid choice. Try again.\n");
            continue;
        }
        if (flipped[row - 1][column - 1] == 1) {
            printf("That card is already flipped. Try again.\n");
            continue;
        }
        if (first_choice[0] == -1) {
            first_choice[0] = row - 1;
            first_choice[1] = column - 1;
            flipped[first_choice[0]][first_choice[1]] = 1;
        }
        else {
            int second_choice[2] = {row - 1, column - 1};
            flipped[second_choice[0]][second_choice[1]] = 1;

            if (board[first_choice[0]][first_choice[1]] == board[second_choice[0]][second_choice[1]]) {
                score += 10;
                pairs_found++;
            }
            else {
                score -= 5;
                printf("No match found. Try again.\n");
                flipped[first_choice[0]][first_choice[1]] = 0;
                flipped[second_choice[0]][second_choice[1]] = 0;
            }
            first_choice[0] = -1;
            first_choice[1] = -1;
        }
    }

    printf("Congratulations! You won the game with a score of %d.\n", score);
}

int main() {
    playGame();
    return 0;
}