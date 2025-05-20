//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4  // Size of the memory grid (SIZE x SIZE)
#define TOTAL_CARDS (SIZE * SIZE / 2)  // Total pairs of cards

char cards[SIZE][SIZE];  // To hold card values
char display[SIZE][SIZE];  // To display the cards
int foundPairs = 0;  // Count of found pairs

void initializeCards() {
    int nums[TOTAL_CARDS];  // Array to hold card values

    // Fill nums with card values 1 to TOTAL_CARDS, two of each
    for (int i = 0; i < TOTAL_CARDS; i++) {
        nums[i] = i + 1;
    }

    // Shuffle the card values
    for (int i = TOTAL_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Assign shuffled values to card grid
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cards[i][j] = (i * SIZE + j < TOTAL_CARDS * 2) ? nums[(i * SIZE + j) / 2] : ' ';
            display[i][j] = '*';  // Initially, all cards are hidden
        }
    }
}

void displayGrid() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", display[i][j]);
        }
        printf("\n");
    }
}

int isMatch(int x1, int y1, int x2, int y2) {
    return cards[x1][y1] == cards[x2][y2];
}

void flipCard(int x, int y) {
    display[x][y] = cards[x][y];
}

int main() {
    srand(time(NULL));  // Seed for randomness
    initializeCards();
    
    int turn = 0;
    while (foundPairs < TOTAL_CARDS) {
        displayGrid();
        
        printf("Turn %d:\n", turn + 1);
        int x1, y1, x2, y2;

        // Input first card
        printf("Select first card (row and column): ");
        scanf("%d %d", &x1, &y1);
        if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE || display[x1][y1] != '*') {
            printf("Invalid selection, try again.\n");
            continue;
        }
        
        flipCard(x1, y1);
        displayGrid();

        // Input second card
        printf("Select second card (row and column): ");
        scanf("%d %d", &x2, &y2);
        if (x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE || display[x2][y2] != '*') {
            printf("Invalid selection, try again.\n");
            display[x1][y1] = '*';  // Hide the first card again
            continue;
        }

        flipCard(x2, y2);
        displayGrid();

        // Check for a match
        if (isMatch(x1, y1, x2, y2)) {
            printf("It's a match!\n");
            foundPairs += 2;  // Increase found pairs
        } else {
            printf("Not a match, flipping back in 2 seconds...\n");
            sleep(2);
            display[x1][y1] = '*';  // Hide the first card again
            display[x2][y2] = '*';  // Hide the second card again
        }
        turn++;
    }

    printf("Congratulations! You found all pairs in %d turns!\n", turn);
    return 0;
}