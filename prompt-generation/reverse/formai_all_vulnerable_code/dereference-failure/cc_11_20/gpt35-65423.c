//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the bingo card
void print_card(int** card) {
    printf("\n\nBingo Card:\n\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (card[i][j] == -1) {
                printf("    ");
            } else {
                printf("%3d ", card[i][j]);
            }
        }
        printf("\n\n");
    }
}

int main() {
    // Initialize the RNG
    srand(time(0));

    // Allocate memory for bingo card
    int** card = (int**) malloc(sizeof(int*) * 5);
    for (int i = 0; i < 5; i++) {
        card[i] = (int*) malloc(sizeof(int) * 5);
    }

    // Initialize the bingo card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2) {
                card[i][j] = -1;
            } else {
                card[i][j] = (j * 15) + (rand() % 15 + 1);
            }
        }
    }

    // Print the bingo card
    print_card(card);

    // Play the game
    int num_called = 0;
    while (num_called < 75) {
        // Generate a random number from 1 to 75
        int call = rand() % 75 + 1;

        // Check if the number has already been called
        int already_called = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (card[i][j] == call) {
                    card[i][j] = -1;
                    already_called = 1;
                    break;
                }
            }
            if (already_called) {
                break;
            }
        }

        // Print the called number
        printf("\n\nNumber called: %d\n\n", call);

        // Print the updated bingo card
        print_card(card);

        // Check if there is a bingo
        int row_bingo = 0;
        int col_bingo = 0;
        int diag_bingo = 0;
        for (int i = 0; i < 5; i++) {
            int row_sum = 0;
            int col_sum = 0;
            for (int j = 0; j < 5; j++) {
                row_sum += (card[i][j] == -1);
                col_sum += (card[j][i] == -1);
            }
            row_bingo |= (row_sum == 5);
            col_bingo |= (col_sum == 5);
            diag_bingo |= ((i == 0 || i == 4) && card[i][i] == -1 && card[i][4-i] == -1);
        }
        if (row_bingo || col_bingo || diag_bingo) {
            printf("\n\nBingo!\n\n");
            break;
        }

        // Increment the number of called numbers
        num_called++;
    }

    // Free memory allocated for the bingo card
    for (int i = 0; i < 5; i++) {
        free(card[i]);
    }
    free(card);

    return 0;
}