//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // Size of the grid (4x4)
#define PAIRS (SIZE * SIZE) / 2

void initializeBoard(char board[SIZE][SIZE], char values[PAIRS]) {
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i * SIZE + j < PAIRS) {
                board[i][j] = values[index++];
                board[i][j + 1] = values[index - 1];
                j++; // Move to next column for a pair
            } else {
                board[i][j] = '*'; // Empty slot
            }
        }
    }
}

void shuffle(char values[PAIRS]) {
    for (int i = PAIRS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }
}

void displayBoard(char board[SIZE][SIZE]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    char board[SIZE][SIZE];
    char values[PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int foundPairs = 0, attempts = 0;
    int firstX, firstY, secondX, secondY;
    char input;

    srand(time(NULL)); // Seed for random number generation
    shuffle(values); // Shuffle pairs
    initializeBoard(board, values);

    printf("Welcome to the Memory Game!\n");

    while (foundPairs < PAIRS) {
        displayBoard(board);
        printf("Enter coordinates for the first card (format: row col): ");
        scanf("%d %d", &firstX, &firstY);
        
        printf("Enter coordinates for the second card (format: row col): ");
        scanf("%d %d", &secondX, &secondY);
        
        // Adjust for 0-indexed array
        firstX -= 1; 
        firstY -= 1; 
        secondX -= 1; 
        secondY -= 1;

        if (firstX < 0 || firstX >= SIZE || firstY < 0 || firstY >= SIZE ||
            secondX < 0 || secondX >= SIZE || secondY < 0 || secondY >= SIZE) {
            printf("Invalid coordinates! Please try again.\n");
            continue;
        }

        attempts++;

        if (board[firstX][firstY] == '*' && board[secondX][secondY] == '*') {
            // Reveal chosen cards
            board[firstX][firstY] = values[firstX * SIZE + firstY];
            board[secondX][secondY] = values[secondX * SIZE + secondY];

            if (board[firstX][firstY] == board[secondX][secondY]) {
                printf("You found a match!\n");
                foundPairs++;
            } else {
                printf("No match, try again.\n");
                // Hide cards again after a moment
                getchar(); // Wait for input to allow players to see the reveal
                board[firstX][firstY] = '*';
                board[secondX][secondY] = '*';
            }
        } else {
            printf("These cards have already been revealed. Please select different cards.\n");
        }
    }

    printf("Congratulations! You've found all pairs in %d attempts.\n", attempts);
    return 0;
}