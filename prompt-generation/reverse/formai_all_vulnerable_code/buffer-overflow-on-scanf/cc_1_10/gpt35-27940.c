//FormAI DATASET v1.0 Category: Memory Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printBoard(int** board, int rows, int cols, int* revealed) {
    printf("\n+---+---+---+---+---+\n");

    for (int i = 0; i < rows; i++) {
        printf("|");

        for (int j = 0; j < cols; j++) {
            if (revealed[i * cols + j]) {
                printf(" %2d |", board[i][j]);
            } else {
                printf(" ? |");
            }
        }

        printf("\n+---+---+---+---+---+\n");
    }
}

void playMemoryGame(int rows, int cols) {
    int** board = malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        board[i] = malloc(cols * sizeof(int));
    }

    int* revealed = malloc(rows * cols * sizeof(int));
    int numPairs = rows * cols / 2;
    int *pairs = malloc(numPairs * sizeof(int));

    for (int i = 0; i < numPairs; i++) {
        pairs[i] = i%10; // We only use numbers 0-9
    }

    shuffle(pairs, numPairs);

    for (int i = 0, k = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++, k++) {
            board[i][j] = pairs[k / 2];
            revealed[k] = 0;
        }
    }

    int numRevealed = 0;
    int guesses = 0;
    int guess1i, guess1j, guess2i, guess2j;

    while (numRevealed < rows * cols) {
        printf("\nGuess #%d: ", ++guesses);
        printBoard(board, rows, cols, revealed);

        printf("\nEnter row and column of first guess (0-indexed): ");
        scanf("%d %d", &guess1i, &guess1j);

        if (guess1i < 0 || guess1i >= rows || guess1j < 0 || guess1j >= cols) {
            printf("Invalid guess, try again.\n");
            continue;
        }

        if (revealed[guess1i * cols + guess1j]) {
            printf("That square has already been revealed, try again.\n");
            continue;
        }

        revealed[guess1i * cols + guess1j] = 1;
        numRevealed++;

        printf("\nAfter revealing the square:\n");
        printBoard(board, rows, cols, revealed);

        printf("\nEnter row and column of second guess (0-indexed): ");
        scanf("%d %d", &guess2i, &guess2j);

        if (guess2i < 0 || guess2i >= rows || guess2j < 0 || guess2j >= cols) {
            printf("Invalid guess, try again.\n");
            revealed[guess1i * cols + guess1j] = 0;
            numRevealed--;
            continue;
        }

        if (revealed[guess2i * cols + guess2j]) {
            printf("That square has already been revealed, try again.\n");
            revealed[guess1i * cols + guess1j] = 0;
            numRevealed--;
            continue;
        }

        revealed[guess2i * cols + guess2j] = 1;
        numRevealed++;

        if (board[guess1i][guess1j] != board[guess2i][guess2j]) {
            printf("\nSorry, those do not match!\n");
            revealed[guess2i * cols + guess2j] = 0;
            revealed[guess1i * cols + guess1j] = 0;
            numRevealed -= 2;
        } else {
            printf("\nYou found a match!\n");
        }
    }

    printf("\nCongratulations, you won in %d guesses!\n", guesses);

    for (int i = 0; i < rows; i++) {
        free(board[i]);
    }

    free(board);
    free(revealed);
    free(pairs);
}

int main() {
    srand(time(NULL));

    printf("\n\nWelcome to the Memory Game!\n\n");

    int rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("\nStarting game with %d rows and %d columns...\n", rows, cols);

    playMemoryGame(rows, cols);

    return 0;
}