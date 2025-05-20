//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define GRID_SIZE 4
#define TOTAL_NUMBERS 8
#define MAX_TRIES 3

void initialize_gameboard(int board[GRID_SIZE][GRID_SIZE]) {
    int numbers[TOTAL_NUMBERS];
    for (int i = 0; i < TOTAL_NUMBERS; i++) {
        numbers[i] = i + 1; // Generate numbers from 1 to 8
    }

    // Populate the board with pairs of numbers
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        board[i / GRID_SIZE][i % GRID_SIZE] = numbers[i % TOTAL_NUMBERS / 2];
    }

    // Shuffle the board
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        int j = rand() % (GRID_SIZE * GRID_SIZE);
        int temp = board[i / GRID_SIZE][i % GRID_SIZE];
        board[i / GRID_SIZE][i % GRID_SIZE] = board[j / GRID_SIZE][j % GRID_SIZE];
        board[j / GRID_SIZE][j % GRID_SIZE] = temp;
    }
}

void display_board(int board[GRID_SIZE][GRID_SIZE], int revealed[GRID_SIZE][GRID_SIZE]) {
    printf("Current board state:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%2d ", board[i][j]);
            } else {
                printf(" X ");
            }
        }
        printf("\n");
    }
}

void reveal_board(int board[GRID_SIZE][GRID_SIZE]) {
    printf("Revealing board for 5 seconds...\n");
    display_board(board, (int[GRID_SIZE][GRID_SIZE]){{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}});
    sleep(5);
}

int is_match(int board[GRID_SIZE][GRID_SIZE], int revealed[GRID_SIZE][GRID_SIZE], int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

int main() {
    srand(time(0));
    int board[GRID_SIZE][GRID_SIZE];
    int revealed[GRID_SIZE][GRID_SIZE] = {0};
    int pairs_found = 0;

    // Initialize the game board
    initialize_gameboard(board);
    reveal_board(board);

    // Game loop
    for (int turn = 0; turn < TOTAL_NUMBERS; turn++) {
        int x1, y1, x2, y2;

        printf("Choose first card (row and column 0-3): ");
        scanf("%d %d", &x1, &y1);
        if (x1 < 0 || x1 >= GRID_SIZE || y1 < 0 || y1 >= GRID_SIZE || revealed[x1][y1]) {
            printf("Invalid choice, try again.\n");
            turn--;
            continue;
        }
        revealed[x1][y1] = 1;
        display_board(board, revealed);

        printf("Choose second card (row and column 0-3): ");
        scanf("%d %d", &x2, &y2);
        if (x2 < 0 || x2 >= GRID_SIZE || y2 < 0 || y2 >= GRID_SIZE || revealed[x2][y2]) {
            printf("Invalid choice, try again.\n");
            revealed[x1][y1] = 0; // Reset the first choice
            turn--;
            continue;
        }
        revealed[x2][y2] = 1;
        display_board(board, revealed);

        if (is_match(board, revealed, x1, y1, x2, y2)) {
            printf("It's a match!\n");
            pairs_found++;
            if (pairs_found == TOTAL_NUMBERS / 2) {
                printf("Congratulations! You've matched all pairs!\n");
                break;
            }
        } else {
            printf("Not a match, try again.\n");
            sleep(1); // Show the non-matching cards for a moment
            revealed[x1][y1] = 0;
            revealed[x2][y2] = 0;
        }
    }

    printf("Game Over! Total pairs found: %d\n", pairs_found);
    return 0;
}