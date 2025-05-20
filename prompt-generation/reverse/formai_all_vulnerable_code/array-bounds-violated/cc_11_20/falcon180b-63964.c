//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, i, j, matches = 0, attempts = 0;
    int board[3][3];
    int values[6] = {1, 2, 3, 4, 5, 6};
    char choice;

    // Set up the board with random values
    srand(time(NULL));
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = values[rand() % 6];
        }
    }

    // Print the board
    printf("MEMORY GAME\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Start the game
    while (matches < 6) {
        printf("\nEnter your choice (row and column): ");
        scanf("%d%c", &i, &choice);
        j = choice - '0';
        if (board[i][j] == 0) {
            printf("Invalid choice.\n");
            continue;
        }
        if (board[i][j]!= 0) {
            attempts++;
            if (attempts == 1) {
                printf("You have %d attempts left.\n", 2 - attempts);
            }
            if (board[i][j] == board[i][j + 1]) {
                printf("Match!\n");
                matches++;
            } else {
                printf("No match.\n");
                board[i][j] = 0;
                board[i][j + 1] = 0;
            }
        } else {
            printf("No match.\n");
        }
    }

    // Print the final board and results
    printf("\nFinal board:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("You made %d matches in %d attempts.\n", matches, attempts);

    return 0;
}