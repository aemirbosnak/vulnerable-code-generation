//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define SIZE 4 // Size of the card grid (SIZE x SIZE)
#define TOTAL_CARDS (SIZE * SIZE)

void initialize_board(char board[SIZE][SIZE], char display[SIZE][SIZE]) {
    char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int idx = 0;
    
    // Initialize display and board with hidden values
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            display[i][j] = '*';
            board[i][j] = symbols[idx / 2]; // Each symbol appears twice
            idx++;
        }
    }
    
    // Shuffle the symbols
    for (int i = TOTAL_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = board[i / SIZE][i % SIZE];
        board[i / SIZE][i % SIZE] = board[j / SIZE][j % SIZE];
        board[j / SIZE][j % SIZE] = temp;
    }
}

void print_board(char display[SIZE][SIZE]) {
    printf("Current Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", display[i][j]);
        }
        printf("\n");
    }
}

int select_card(int *x, int *y) {
    printf("Select a card (row and column) separated by space: ");
    if (scanf("%d %d", x, y) != 2) {
        while (getchar() != '\n'); // Clear invalid input
        return 0;
    }
    // Validate input range
    if (*x < 0 || *x >= SIZE || *y < 0 || *y >= SIZE) {
        printf("Invalid coordinates! Please try again.\n");
        return 0;
    }
    return 1;
}

int main() {
    srand(time(NULL));
    char board[SIZE][SIZE];
    char display[SIZE][SIZE];
    int revealed = 0;
    int pairs_remaining = TOTAL_CARDS / 2;

    initialize_board(board, display);

    while (pairs_remaining > 0) {
        print_board(display);
        
        int x1, y1;
        if (!select_card(&x1, &y1)) continue;

        // Show the first selected card
        display[x1][y1] = board[x1][y1];
        print_board(display);
        
        int x2, y2;
        if (!select_card(&x2, &y2)) {
            display[x1][y1] = '*'; // Hide the first card if wrong input for second
            continue;
        }

        // Show the second selected card
        display[x2][y2] = board[x2][y2];
        print_board(display);
        
        // Check if they match
        if (board[x1][y1] == board[x2][y2]) {
            printf("It's a match!\n");
            revealed += 2;
            pairs_remaining--;
        } else {
            printf("Not a match! Hiding cards.\n");
            display[x1][y1] = '*'; // Hide the first card
            display[x2][y2] = '*'; // Hide the second card
        }
    }
    
    printf("Congratulations! You've matched all pairs!\n");
    return 0;
}