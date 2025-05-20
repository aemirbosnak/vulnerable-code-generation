//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // Size of the board (4x4)
#define PAIRS (SIZE * SIZE) / 2 // Number of pairs
#define EMPTY ' ' // Symbol for an empty cell

void initializeBoard(char board[SIZE][SIZE]);
void shuffleBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE], int revealed[SIZE][SIZE]);
int guess(char board[SIZE][SIZE], int revealed[SIZE][SIZE], int *score);
int checkWin(int score);
void playGame();

int main() {
    srand(time(NULL)); // Seed for random number generation
    playGame(); // Start the game
    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    int number = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (number <= PAIRS) {
                board[i][j] = number + '0'; // Store numbers as characters
                number++;
            }
            else {
                board[i][j] = EMPTY; // Fill remaining with empty spaces
            }
        }
    }
}

void shuffleBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE * SIZE; i++) {
        int r1 = rand() % (SIZE * SIZE);
        int r2 = rand() % (SIZE * SIZE);
        char temp = board[r1 / SIZE][r1 % SIZE];
        board[r1 / SIZE][r1 % SIZE] = board[r2 / SIZE][r2 % SIZE];
        board[r2 / SIZE][r2 % SIZE] = temp;
    }
}

void printBoard(char board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("   0 1 2 3\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf("X "); // Show hidden state
            }
        }
        printf("\n");
    }
}

int guess(char board[SIZE][SIZE], int revealed[SIZE][SIZE], int *score) {
    int x, y;
    printf("Enter your guess (row and column): ");
    scanf("%d %d", &x, &y);
    
    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && !revealed[x][y]) {
        revealed[x][y] = 1; // Reveal guessed cell
        printBoard(board, revealed); // Show the board after guess
        
        // Check for a match
        printf("Enter second guess (row and column): ");
        int x2, y2;
        scanf("%d %d", &x2, &y2);
        
        if (x2 >= 0 && x2 < SIZE && y2 >= 0 && y2 < SIZE && 
            !revealed[x2][y2] && !(x2 == x && y2 == y)) {
            revealed[x2][y2] = 1; // Reveal second guessed cell
            printBoard(board, revealed);
            if (board[x][y] == board[x2][y2]) {
                (*score)++; // Increment score for a valid match
                printf("Match found!\n");
            } else {
                printf("No match, try again!\n");
                revealed[x][y] = 0; // Hide the non-matching cells again
                revealed[x2][y2] = 0; // Hide the non-matching cells again
            }
        } else {
            printf("Invalid second guess. Try again.\n");
            revealed[x][y] = 0; // Hide the first guessed cell if second is invalid
        }
    } else {
        printf("Invalid guess. Try again.\n");
    }
    
    return *score;
}

int checkWin(int score) {
    return score == PAIRS; // Check if player matched all pairs
}

void playGame() {
    char board[SIZE][SIZE];
    int revealed[SIZE][SIZE] = {0}; // Initialize revealed states
    int score = 0;

    initializeBoard(board);
    shuffleBoard(board);

    while (!checkWin(score)) {
        printBoard(board, revealed);
        guess(board, revealed, &score);
    }

    printf("Congratulations! You've matched all pairs!\n");
}