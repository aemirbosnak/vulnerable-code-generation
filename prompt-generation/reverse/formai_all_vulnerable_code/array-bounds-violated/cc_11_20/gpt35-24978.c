//FormAI DATASET v1.0 Category: Memory Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

// This 2D array stores the game board
char board[ROWS][COLS] = {
    {'A', 'B', 'C', 'D'},
    {'F', 'E', 'H', 'G'},
    {'D', 'C', 'B', 'A'},
    {'G', 'H', 'E', 'F'}
};

// This 2D array keeps track of the revealed tiles
char revealed[ROWS][COLS];

// This function prints the game board on the screen
void print_board() {
    printf("\n    1  2  3  4\n");
    printf("   +-----------+\n");
    for (int i = 0; i < ROWS; i++) {
        printf(" %c |", 'A' + i);
        for (int j = 0; j < COLS; j++) {
            if (revealed[i][j]) {
                printf(" %c ", board[i][j]);
            } else {
                printf(" * ");
            }
            printf("|");
        }
        printf("\n");
        printf("   +-----------+\n");
    }
}

int main() {
    srand(time(NULL));

    printf("\nWelcome to the Cyberpunk Memory Game!\n");
    printf("You will have to reveal all the tiles to win.\n");
    printf("You can choose two tiles on each turn to reveal.\n");
    printf("If they match, they will stay revealed.\n");
    printf("If not, they will be hidden again.\n");
    printf("Good luck! Let the game begin.\n");

    // Initialize the revealed array to all zeros
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            revealed[i][j] = 0;
        }
    }

    // Main game loop
    int turns = 0;
    while (1) {
        print_board();

        // Check if all tiles are revealed
        int all_revealed = 1;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (!revealed[i][j]) {
                    all_revealed = 0;
                    break;
                }
            }
            if (!all_revealed) {
                break;
            }
        }
        if (all_revealed) {
            printf("\nCongratulations! You won in %d turns.\n", turns);
            return 0;
        }

        // Get user input for the two tiles to reveal
        char input[5];
        char coord1, coord2;
        int x1, y1, x2, y2;
        while (1) {
            printf("\nEnter the coordinates of the first tile (e.g. A1): ");
            fgets(input, 5, stdin);
            if (input[0] < 'A' || input[0] >= 'A' + ROWS ||
                input[1] < '1' || input[1] > '9' ||
                input[2] != '\n') {
                printf("Invalid input. Please try again.\n");
                continue;
            }
            coord1 = input[0];
            x1 = coord1 - 'A';
            y1 = input[1] - '1';
            break;
        }
        while (1) {
            printf("Enter the coordinates of the second tile (e.g. B3): ");
            fgets(input, 5, stdin);
            if (input[0] < 'A' || input[0] >= 'A' + ROWS ||
                input[1] < '1' || input[1] > '9' ||
                input[2] != '\n') {
                printf("Invalid input. Please try again.\n");
                continue;
            }
            coord2 = input[0];
            x2 = coord2 - 'A';
            y2 = input[1] - '1';
            if (coord1 == coord2 && y1 == y2) {
                printf("You can't choose the same tile twice. Please try again.\n");
                continue;
            }
            break;
        }

        // Reveal the selected tiles
        revealed[x1][y1] = 1;
        revealed[x2][y2] = 1;
        turns++;

        // Check if the selected tiles match
        if (board[x1][y1] != board[x2][y2]) {
            printf("Sorry, the tiles do not match. They will be hidden again.\n");
            revealed[x1][y1] = 0;
            revealed[x2][y2] = 0;
        }
    }

    return 0;
}