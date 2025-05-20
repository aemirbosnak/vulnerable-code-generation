//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define TOTAL_PAIRS (SIZE * SIZE / 2)

void initializeBoard(char board[SIZE][SIZE], int values[SIZE][SIZE]);
void shuffle(int values[TOTAL_PAIRS]);
void printBoard(char board[SIZE][SIZE]);
int isCorrectGuess(int guess1, int guess2);
void reveal(int guess1, int guess2, char board[SIZE][SIZE], int values[SIZE][SIZE]);
void playGame();

int main() {
    printf("🎉 Welcome to the Happy Memory Game! 🎉\n");
    playGame();
    printf("Thanks for playing! Hope you had a blast! 🌈\n");
    return 0;
}

void playGame() {
    char board[SIZE][SIZE];
    int values[SIZE][SIZE];
    int guess1, guess2;
    int pairsFound = 0;
    int maxAttempts = TOTAL_PAIRS;  // maximum attempts is total pairs

    initializeBoard(board, values);
    
    while (pairsFound < TOTAL_PAIRS) {
        printBoard(board);
        printf("✏️  Enter your first guess (row and column, e.g., 0 1): ");
        scanf("%d %d", &guess1, &guess2);

        // Check for out-of-bounds
        if (guess1 < 0 || guess1 >= SIZE || guess2 < 0 || guess2 >= SIZE || board[guess1][guess2] != '*') {
            printf("🚫 Invalid or already revealed position! Try again.\n");
            continue;
        }

        char firstSymbol = board[guess1][guess2];
        board[guess1][guess2] = values[guess1][guess2] + '0';
        printBoard(board);

        printf("✏️  Enter your second guess (row and column, e.g., 0 1): ");
        scanf("%d %d", &guess1, &guess2);

        // Check for out-of-bounds
        if (guess1 < 0 || guess1 >= SIZE || guess2 < 0 || guess2 >= SIZE || board[guess1][guess2] != '*') {
            printf("🚫 Invalid or already revealed position! Try again.\n");
            continue;
        }

        board[guess1][guess2] = values[guess1][guess2] + '0';
        printBoard(board);

        if (isCorrectGuess(firstSymbol - '0', board[guess1][guess2] - '0')) {
            printf("🎉 You found a match! 🎉\n");
            pairsFound++;
        } else {
            printf("😢 Not a match! Try again.\n");
            reveal(firstSymbol - '0', board[guess1][guess2] - '0', board, values);
        }

        // Reset the board if necessary
        if (board[guess1][guess2] != '*') {
            board[guess1][guess2] = '*';
        }

        if (pairsFound >= TOTAL_PAIRS) {
            printBoard(board);
            printf("🏆 Congratulations! You've matched all pairs! 🏆\n");
            break;
        }
    }
}

void initializeBoard(char board[SIZE][SIZE], int values[SIZE][SIZE]) {
    // Initialize all to *
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = '*';

    // Initialize pairs
    int number = 0;
    int pairs[TOTAL_PAIRS];
    for (int i = 0; i < TOTAL_PAIRS; i++)
        pairs[i] = i;

    shuffle(pairs);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            values[i][j] = pairs[number / 2];  // Assign two of the same number
            number++;
        }
    }
}

void shuffle(int values[TOTAL_PAIRS]) {
    srand(time(0));
    for (int i = TOTAL_PAIRS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n🎮 Game Board 🎮\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

int isCorrectGuess(int guess1, int guess2) {
    return guess1 == guess2;
}

void reveal(int guess1, int guess2, char board[SIZE][SIZE], int values[SIZE][SIZE]) {
    printf("😞 Here's what you guessed:\n");
    printf("Position 1: %d | Position 2: %d\n", guess1, guess2);
    printf("Press Enter to continue...\n");
    getchar(); // pause for user input
}