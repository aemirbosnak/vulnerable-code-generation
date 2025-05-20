//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define SIZE 4   // Size of the grid (SIZE x SIZE)
#define PAIRS (SIZE * SIZE) / 2

void initializeBoard(char board[SIZE][SIZE], char display[SIZE][SIZE]) {
    char characters[PAIRS];
    
    // Fill characters array with pairs
    for (int i = 0; i < PAIRS; i++) {
        characters[i] = 'A' + i; // Assign letters A, B, C, ...
    }
    
    // Shuffle characters
    for (int i = 0; i < PAIRS; i++) {
        int j = rand() % PAIRS;
        char temp = characters[i];
        characters[i] = characters[j];
        characters[j] = temp;
    }
    
    // Fill the board with shuffled characters
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i * SIZE + j < PAIRS) {
                board[i][j] = characters[i * SIZE + j];
            } else {
                board[i][j] = ' '; // Empty space
            }
            display[i][j] = '*'; // Initially displaying hidden state
        }
    }
}

void printBoard(char display[SIZE][SIZE]) {
    printf("\nMemory Game Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", display[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    char board[SIZE][SIZE];
    char display[SIZE][SIZE];
    int attempts = 0;
    int matches = 0;
    int x1, y1, x2, y2;
    char input[3];
    
    srand(time(NULL)); // Seed for random number generation
    
    initializeBoard(board, display);
    
    while (matches < PAIRS) {
        printBoard(display);
        
        printf("Enter coordinates of first card (row col): ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d %d", &x1, &y1);
        
        printf("Enter coordinates of second card (row col): ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d %d", &x2, &y2);
        
        // Validate input
        if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE || 
            x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE ||
            (x1 == x2 && y1 == y2)) {
            printf("Invalid coordinates, try again.\n");
            continue;
        }
        
        // Update the displayed board
        display[x1][y1] = board[x1][y1];
        display[x2][y2] = board[x2][y2];
        attempts++;
        
        printBoard(display); // Display the chosen cards
        
        // Check for a match
        if (board[x1][y1] == board[x2][y2]) {
            printf("It's a match!\n");
            matches++;
        } else {
            printf("Not a match, try again.\n");
            sleep(2); // Give the player time to see
            display[x1][y1] = '*';
            display[x2][y2] = '*';
        }
    }
    
    printf("Congratulations! You've found all matches in %d attempts.\n", attempts);
    
    return 0;
}