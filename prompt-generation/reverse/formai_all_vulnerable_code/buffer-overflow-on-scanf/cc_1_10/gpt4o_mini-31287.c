//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SIZE 4 // 4x4 grid
#define CLUES (SIZE * SIZE) / 2 // Since we have pairs

char board[SIZE][SIZE];
char revealed[SIZE][SIZE];
char clues[CLUES] = {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D'};
int pairs_found = 0;

// Function to initialize the game
void initialize_game() {
    // Randomly shuffle clues
    for (int i = 0; i < CLUES; i++) {
        int rand_index = rand() % CLUES;
        char temp = clues[i];
        clues[i] = clues[rand_index];
        clues[rand_index] = temp;
    }
    
    // Fill the board with clues
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = clues[(i * SIZE + j) / 2];
            revealed[i][j] = 'X'; // Hide all clues with 'X'
        }
    }
}

// Function to display the current state of the board
void display_board() {
    printf("\nCurrent Board State:\n");
    printf("  ");
    for (int j = 0; j < SIZE; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", revealed[i][j]);
        }
        printf("\n");
    }
}

// Function to reveal a clue on the board
void reveal(int x, int y) {
    revealed[x][y] = board[x][y];
}

// Function to hide a clue on the board
void hide(int x, int y) {
    revealed[x][y] = 'X';
}

// Function to check if a pair has been found
int check_pair(char clue1, char clue2) {
    return clue1 == clue2;
}

// Function to play the game
void play_game() {
    int x1, y1, x2, y2;
    
    while (pairs_found < CLUES) {
        display_board();
        printf("Select the first clue (row and column): ");
        scanf("%d %d", &x1, &y1);
        reveal(x1, y1);
        display_board();
        
        printf("Select the second clue (row and column): ");
        scanf("%d %d", &x2, &y2);
        reveal(x2, y2);
        display_board();
        
        if (check_pair(board[x1][y1], board[x2][y2])) {
            printf("Pair found: %c!\n", board[x1][y1]);
            pairs_found++;
        } else {
            printf("No match! The clues will be hidden again in 2 seconds...\n");
            sleep(2);
            hide(x1, y1);
            hide(x2, y2);
        }
    }
    
    printf("Congratulations! You've found all pairs!\n");
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator
    initialize_game();
    play_game();
    
    return 0;
}