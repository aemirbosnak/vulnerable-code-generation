//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_CARDS 75

int main() {
    int rows, cols, cards, i, j, k, num, count;
    char bingo_cards[MAX_ROWS][MAX_COLS];
    char *numbers = "123456789";

    srand(time(NULL));

    // Get number of rows and columns from user
    printf("Enter number of rows (1 to %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter number of columns (1 to %d): ", MAX_COLS);
    scanf("%d", &cols);

    // Initialize bingo cards with random numbers
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            num = rand() % 10;
            bingo_cards[i][j] = num + '0';
        }
    }

    // Print bingo cards
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c ", bingo_cards[i][j]);
        }
        printf("\n");
    }

    // Start the game
    count = 0;
    while (count < MAX_CARDS) {
        // Generate a random number
        num = rand() % 10;

        // Check if the number is already present in any row or column
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (bingo_cards[i][j] == num + '0') {
                    count++;
                    break;
                }
            }
            if (count == MAX_CARDS) {
                break;
            }
        }
    }

    // Print the final bingo cards
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c ", bingo_cards[i][j]);
        }
        printf("\n");
    }

    return 0;
}