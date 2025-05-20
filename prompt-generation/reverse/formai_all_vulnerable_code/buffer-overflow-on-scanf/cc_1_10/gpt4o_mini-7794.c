//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void initializeBoard(char board[SIZE][SIZE], int values[SIZE][SIZE]);
void shuffleCards(int values[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE]);
int revealCard(char board[SIZE][SIZE], int values[SIZE][SIZE], int x, int y);
int checkMatch(int firstCard, int secondCard);
void playGame();
void clearBuffer();

int main() {
    printf("Welcome to the Ultimate Memory Game!\n");
    printf("Prepare your memory for a fun challenge. Let's get started!\n");
    playGame();
    return 0;
}

void playGame() {
    char board[SIZE][SIZE];
    int values[SIZE][SIZE];
    int x1, y1, x2, y2;
    int firstCard, secondCard;
    int pairsFound = 0;
    int turns = 0;

    // Initialize the game board
    initializeBoard(board, values);
    shuffleCards(values);

    // Game Loop
    while (pairsFound < (SIZE * SIZE) / 2) {
        displayBoard(board);
        printf("Select first card (row col): ");
        scanf("%d %d", &x1, &y1);
        firstCard = revealCard(board, values, x1, y1);
        
        if (firstCard == -1) {
            printf("Invalid selection, try again!\n");
            continue;
        }

        displayBoard(board);
        printf("Select second card (row col): ");
        scanf("%d %d", &x2, &y2);
        secondCard = revealCard(board, values, x2, y2);
        
        if (secondCard == -1) {
            printf("Invalid selection, try again!\n");
            continue;
        }

        turns++;
        printf("You selected: %d and %d\n", firstCard, secondCard);
        
        if (checkMatch(firstCard, secondCard)) {
            printf("It's a match! Great job!\n");
            pairsFound++;
        } else {
            printf("Sorry, no match. Try again!\n");
            board[x1][y1] = '*';
            board[x2][y2] = '*';
        }
    }

    printf("Congratulations! You've found all pairs in %d turns!\n", turns);
}

void initializeBoard(char board[SIZE][SIZE], int values[SIZE][SIZE]) {
    int number = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '*';
            if (i < SIZE / 2 && j < SIZE) {
                values[i][j] = number;
                values[SIZE - 1 - i][SIZE - 1 - j] = number;
                number++;
            }
        }
    }
}

void shuffleCards(int values[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int i1 = rand() % SIZE;
            int j1 = rand() % SIZE;
            // Swap
            int temp = values[i][j];
            values[i][j] = values[i1][j1];
            values[i1][j1] = temp;
        }
    }
}

void displayBoard(char board[SIZE][SIZE]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

int revealCard(char board[SIZE][SIZE], int values[SIZE][SIZE], int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y] != '*') {
        return -1; // Invalid coordinate or already revealed
    }
    board[x][y] = values[x][y]; // Reveal the card
    return values[x][y];
}

int checkMatch(int firstCard, int secondCard) {
    return firstCard == secondCard; // Check for match
}

void clearBuffer() {
    while (getchar() != '\n');
}