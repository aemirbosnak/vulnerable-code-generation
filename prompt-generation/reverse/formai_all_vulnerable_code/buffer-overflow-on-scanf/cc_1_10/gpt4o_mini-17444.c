//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4 // The grid size will be SIZE x SIZE
#define NUM_PAIRS (SIZE * SIZE / 2)

char symbols[NUM_PAIRS] = {'!', '@', '#', '$', '%', '^', '&', '*'};
char board[SIZE][SIZE];
char revealed[SIZE][SIZE];

void initialize_board() {
    int indices[SIZE * SIZE];
    for(int i = 0; i < SIZE * SIZE; i++) {
        indices[i] = i / 2; // Each symbol appears twice
    }
    
    // Shuffle indices
    for(int i = SIZE * SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }
    
    // Fill board with symbols
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            board[i][j] = symbols[indices[i * SIZE + j]];
            revealed[i][j] = ' '; // Hidden state
        }
    }
}

void print_board() {
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%c ", revealed[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int is_match(int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

void reveal_card(int x, int y) {
    revealed[x][y] = board[x][y];
}

void hide_card(int x, int y) {
    revealed[x][y] = ' ';
}

int main() {
    srand(time(NULL));

    initialize_board();
    int pairs_found = 0;

    while(pairs_found < NUM_PAIRS) {
        print_board();
        
        int x1, y1, x2, y2;

        printf("Enter coordinates for the first card (row col): ");
        scanf("%d %d", &x1, &y1);
        reveal_card(x1, y1);
        print_board();

        printf("Enter coordinates for the second card (row col): ");
        scanf("%d %d", &x2, &y2);
        reveal_card(x2, y2);
        print_board();

        if(is_match(x1, y1, x2, y2)) {
            printf("It's a match!\n");
            pairs_found++;
        } else {
            printf("Not a match. Try again.\n");
            hide_card(x1, y1);
            hide_card(x2, y2);
        }
    }

    printf("Congratulations! You've found all pairs!\n");

    return 0;
}