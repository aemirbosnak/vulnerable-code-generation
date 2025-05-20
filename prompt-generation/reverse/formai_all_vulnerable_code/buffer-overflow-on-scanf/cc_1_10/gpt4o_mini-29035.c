//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define SIZE 4 // 4x4 board
#define NUM_PAIRS (SIZE * SIZE) / 2 // Number of pairs of cards
#define MAX_ATTEMPTS 20 // Max attempts allowed

char board[SIZE][SIZE];
char display[SIZE][SIZE];
char symbols[NUM_PAIRS] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '=', '+'}; // Symbols to display
int revealed[SIZE][SIZE]; // To track revealed cards

void initialize_board() {
    srand(time(NULL));

    int symbol_index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (symbol_index < NUM_PAIRS) {
                // Place pairs in board
                board[i][j] = symbols[symbol_index / 2];
                if (symbol_index % 2 == 1) symbol_index++;
            } else {
                // Extra slots in the array, just in case
                board[i][j] = ' ';
            }
        }
    }

    // Shuffle the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int r1 = rand() % SIZE;
            int r2 = rand() % SIZE;
            char temp = board[i][j];
            board[i][j] = board[r1][r2];
            board[r1][r2] = temp;
        }
    }
}

void display_board() {
    system("clear"); // Clear console
    printf("Memory Game - You have %d attempts to find all pairs!\n\n", MAX_ATTEMPTS);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%c ", display[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int is_pair(int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

int main() {
    initialize_board();
    
    int attempts = 0;
    int found_pairs = 0;
    memset(revealed, 0, sizeof(revealed)); // Reset revealed tracking

    printf("Welcome to the Memory Game!\n");

    while (attempts < MAX_ATTEMPTS && found_pairs < NUM_PAIRS) {
        display_board();
        
        int x1, y1, x2, y2;
        printf("Choose first card (row col): ");
        scanf("%d %d", &x1, &y1);
        printf("Choose second card (row col): ");
        scanf("%d %d", &x2, &y2);

        if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE || x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE) {
            printf("Invalid coordinates. Try again.\n");
            continue;
        }

        if (revealed[x1][y1] || revealed[x2][y2]) {
            printf("These cards have already been revealed. Try again.\n");
            continue;
        }

        // Reveal the selected cards
        revealed[x1][y1] = 1;
        revealed[x2][y2] = 1;
        display[x1][y1] = board[x1][y1];
        display[x2][y2] = board[x2][y2];

        display_board(); // Show the board with revealed cards

        if (is_pair(x1, y1, x2, y2)) {
            printf("It's a match! You found a pair!\n");
            found_pairs++;
        } else {
            printf("Not a match. Try again.\n");
            sleep(2); // Keep cards revealed for 2 seconds
            revealed[x1][y1] = 0;
            revealed[x2][y2] = 0;
        }
        attempts++;
    }

    if (found_pairs == NUM_PAIRS) {
        printf("Congratulations! You've found all pairs in %d attempts!\n", attempts);
    } else {
        printf("Game over! You couldn't find all pairs in %d attempts.\n", attempts);
    }

    return 0;
}