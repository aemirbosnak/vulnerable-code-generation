//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4
#define MAX_PAIRS (SIZE * SIZE) / 2

void shuffle(int *array, size_t n) {
    if (n > 1) {
        for (size_t i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void initialize_board(int board[SIZE][SIZE]) {
    int numbers[MAX_PAIRS * 2];
    for (int i = 0; i < MAX_PAIRS * 2; i++) {
        numbers[i] = i / 2 + 1; // Fill pairs of numbers
    }
    shuffle(numbers, MAX_PAIRS * 2);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = numbers[i * SIZE + j]; // Assign shuffled numbers to board
        }
    }
}

void print_board(int board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("\nCheerful Memory Game!\n");
    printf("   0 1 2 3\n");
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
    printf("\n");
}

int main() {
    srand(time(NULL));
    int board[SIZE][SIZE];
    int revealed[SIZE][SIZE] = {0}; // 0 means hidden, 1 means revealed
    int pairs_found = 0;

    initialize_board(board);

    while (pairs_found < MAX_PAIRS) {
        print_board(board, revealed);

        int x1, y1, x2, y2;
        printf("Choose your first card (row col): ");
        scanf("%d %d", &x1, &y1);
        revealed[x1][y1] = 1; // Reveal first card

        print_board(board, revealed);

        printf("Choose your second card (row col): ");
        scanf("%d %d", &x2, &y2);
        revealed[x2][y2] = 1; // Reveal second card

        print_board(board, revealed);

        if (board[x1][y1] == board[x2][y2]) {
            printf("Yay! You found a pair!\n");
            pairs_found++;
        } else {
            printf("Oops! Not a match. Try again!\n");
            revealed[x1][y1] = 0; // Keep the cards hidden
            revealed[x2][y2] = 0; // Keep the cards hidden
        }
    }

    printf("Congratulations! You've found all pairs! 🎉\n");
    return 0;
}