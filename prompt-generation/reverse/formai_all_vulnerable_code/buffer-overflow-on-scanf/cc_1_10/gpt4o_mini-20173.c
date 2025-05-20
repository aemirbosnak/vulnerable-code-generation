//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4 // Size of the game board (4x4)
#define NUM_PAIRS (SIZE * SIZE) / 2 // Number of pairs in the game
#define MAX_TRIES 10 // Maximum tries allowed

// Function to shuffle the cards
void shuffle(char cards[], int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Swap
        char temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

// Function to initialize the game board with pairs of cards
void initialize_board(char board[SIZE][SIZE]) {
    char cards[NUM_PAIRS * 2]; // Each pair twice
    int card_id = 0;

    // Create pairs of cards
    for (char i = 'A'; i < 'A' + NUM_PAIRS; i++) {
        cards[card_id++] = i;
        cards[card_id++] = i;
    }

    // Shuffle the cards
    shuffle(cards, NUM_PAIRS * 2);

    // Fill the board with shuffled cards
    card_id = 0;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            board[i][j] = cards[card_id++];
        }
    }
}

// Function to print the current state of the board
void print_board(char board[SIZE][SIZE], bool revealed[SIZE][SIZE]) {
    printf("Current Board:\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(revealed[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the player's guess is correct
bool check_match(char board[SIZE][SIZE], int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

int main() {
    char board[SIZE][SIZE];
    bool revealed[SIZE][SIZE] = {{false}};
    int tries = 0;
    int pairs_found = 0;

    initialize_board(board);

    while (pairs_found < NUM_PAIRS && tries < MAX_TRIES) {
        print_board(board, revealed);
        printf("Attempt %d of %d\n", tries + 1, MAX_TRIES);
        
        int x1, y1, x2, y2;

        // First guess
        printf("Enter coordinates for the first card (x1 y1): ");
        scanf("%d %d", &x1, &y1);
        if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE || revealed[x1][y1]) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        revealed[x1][y1] = true;

        // Second guess
        print_board(board, revealed);
        printf("Enter coordinates for the second card (x2 y2): ");
        scanf("%d %d", &x2, &y2);
        if (x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE || revealed[x2][y2] || (x1 == x2 && y1 == y2)) {
            printf("Invalid input. Try again.\n");
            revealed[x1][y1] = false; // Re-hide the first guess
            continue;
        }
        
        revealed[x2][y2] = true;
        print_board(board, revealed);

        // Check for match
        if (check_match(board, x1, y1, x2, y2)) {
            printf("Match found!\n");
            pairs_found++;
        } else {
            printf("Not a match. Try again!\n");
            revealed[x1][y1] = false; // Reset the cards
            revealed[x2][y2] = false;
        }

        tries++;
    }

    if (pairs_found == NUM_PAIRS) {
        printf("Congratulations! You've found all pairs!\n");
    } else {
        printf("Game over! You've used all your attempts.\n");
    }

    return 0;
}