//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // Size for the grid (4x4)
#define PAIR_COUNT (SIZE * SIZE) / 2 // Number of pairs

void initializeBoard(int board[SIZE][SIZE]);
void shuffleBoard(int board[SIZE][SIZE]);
void printBoard(int board[SIZE][SIZE], int show[SIZE][SIZE]);
int checkMatch(int first, int second);
int isComplete(int show[SIZE][SIZE]);
void clearScreen();

int main() {
    int board[SIZE][SIZE];
    int show[SIZE][SIZE] = {0}; // Show state of the board, 0 = hidden, 1 = shown
    int first, second;
    int pairCount = 0;

    initializeBoard(board);
    shuffleBoard(board);
    
    printf("Welcome to the Memory Game!\n");
    
    while (pairCount < PAIR_COUNT) {
        clearScreen();
        printBoard(board, show);
        
        printf("Select the first card (row and column): ");
        scanf("%d %d", &first, &second);
        first--; second--; // Convert to 0-based index
        
        if (first < 0 || first >= SIZE || second < 0 || second >= SIZE || show[first][second]) {
            printf("Invalid selection. Try again.\n");
            continue;
        }

        show[first][second] = 1; // Show first card
        clearScreen();
        printBoard(board, show);
        
        int third, fourth;
        printf("Select the second card (row and column): ");
        scanf("%d %d", &third, &fourth);
        third--; fourth--; // Convert to 0-based index

        if (third < 0 || third >= SIZE || fourth < 0 || fourth >= SIZE || show[third][fourth]) {
            printf("Invalid selection. Try again.\n");
            show[first][second] = 0; // Hide first card
            continue;
        }

        show[third][fourth] = 1; // Show second card
        clearScreen();
        printBoard(board, show);

        // Check for a match
        if (checkMatch(board[first][second], board[third][fourth])) {
            printf("It's a match!\n");
            pairCount++;
        } else {
            printf("Not a match. Try again.\n");
            show[first][second] = 0; // Hide first card
            show[third][fourth] = 0; // Hide second card
        }

        // Pause for a moment to allow players to see the result
        sleep(2);
    }

    clearScreen();
    printBoard(board, show);
    printf("Congratulations! You've matched all pairs!\n");

    return 0;
}

void initializeBoard(int board[SIZE][SIZE]) {
    int pairValue = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i * SIZE + j) % 2 == 0 && (i * SIZE + j) < PAIR_COUNT * 2) {
                board[i][j] = pairValue; // Set the value for the first card of the pair
                pairValue++;
            } else {
                board[i][j] = 0; // Temporary value, to be filled later
            }
        }
    }
}

void shuffleBoard(int board[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int rand_i = rand() % SIZE;
            int rand_j = rand() % SIZE;
            // Swap values
            int temp = board[i][j];
            board[i][j] = board[rand_i][rand_j];
            board[rand_i][rand_j] = temp;
        }
    }
}

void printBoard(int board[SIZE][SIZE], int show[SIZE][SIZE]) {
    printf("Memory Game Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (show[i][j]) {
                printf("%d\t", board[i][j]); // Show the card
            } else {
                printf("?\t"); // Hide the card
            }
        }
        printf("\n");
    }
}

int checkMatch(int first, int second) {
    return first == second; // Return true if they match
}

int isComplete(int show[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (show[i][j] == 0) {
                return 0; // Not complete
            }
        }
    }
    return 1; // All shown
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the screen
}