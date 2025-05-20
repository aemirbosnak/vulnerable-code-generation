//FormAI DATASET v1.0 Category: Memory Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16

// Function to shuffle an array
void shuffle(int *arr, int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

int main() {
    // Initialize the game board
    int board[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i < BOARD_SIZE/2) {
            board[i] = i;
        } else {
            board[i] = i - BOARD_SIZE/2;
        }
    }

    // Shuffle the board
    shuffle(board, BOARD_SIZE);

    // Initialize the game state
    int selections[2] = {-1, -1};
    int matches[BOARD_SIZE] = {0};
    int num_matches = 0;

    // Main game loop
    while (num_matches < BOARD_SIZE/2) {
        // Print the current board
        system("clear"); // Clear the terminal window
        printf("MEMORY GAME\n\n");
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (matches[i]) {
                printf("%3d ", board[i]);
            } else {
                printf("%3d ", i);
            }
            if (i % 4 == 3) {
                printf("\n");
            }
        }

        printf("\n\n");

        // Get user input
        int selection;
        printf("Enter a number to reveal: ");
        scanf("%d", &selection);

        // Check if the selection is valid
        if (selection < 0 || selection >= BOARD_SIZE || matches[selection]) {
            printf("Invalid selection. Please try again.\n");
            continue;
        }

        // Update the game state
        if (selections[0] < 0) {
            selections[0] = selection;
        } else {
            selections[1] = selection;
            if (board[selections[0]] == board[selections[1]]) {
                matches[selections[0]] = matches[selections[1]] = 1;
                num_matches++;
            }
            selections[0] = selections[1] = -1;
        }
    }

    // Print the final board
    system("clear"); // Clear the terminal window
    printf("MEMORY GAME\n\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%3d ", board[i]);
        if (i % 4 == 3) {
            printf("\n");
        }
    }

    printf("\n\nCongratulations, you won!\n");

    return 0;
}