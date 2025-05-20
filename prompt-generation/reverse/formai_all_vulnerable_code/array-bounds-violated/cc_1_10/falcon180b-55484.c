//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 4

void generateBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '*';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int matchCards(char card1, char card2) {
    return card1 == card2;
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    generateBoard(board);

    int matches = 0;
    int attempts = 0;

    while (matches < 6) {
        printf("Attempts: %d\n", attempts);
        printBoard(board);

        int x1, y1, x2, y2;
        printf("Enter the coordinates of the first card: ");
        scanf("%d %d", &x1, &y1);
        printf("Enter the coordinates of the second card: ");
        scanf("%d %d", &x2, &y2);

        if (matchCards(board[x1][y1], board[x2][y2])) {
            matches++;
            printf("Match found!\n");
        } else {
            printf("No match found.\n");
            attempts++;
        }

        board[x1][y1] = '*';
        board[x2][y2] = '*';
    }

    printf("Congratulations! You completed the game in %d attempts.\n", attempts);

    return 0;
}