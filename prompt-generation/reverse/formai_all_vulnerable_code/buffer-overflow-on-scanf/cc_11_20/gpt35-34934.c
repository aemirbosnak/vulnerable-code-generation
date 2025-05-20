//FormAI DATASET v1.0 Category: Table Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 6

int main()
{
    int board[ROWS][COLS] = {0};
    int row, col, num, count = 0;
    int player1_score = 0, player2_score = 0;
    char player1_name[20], player2_name[20];

    // Get player names
    printf("Enter name for player 1: ");
    scanf("%s", player1_name);
    printf("Enter name for player 2: ");
    scanf("%s", player2_name);

    // Seed the random function with the time
    srand(time(NULL));

    // Fill the board with random numbers
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            board[row][col] = rand() % 10;
        }
    }

    // Display the initial board
    printf("Initial Board:\n");
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }

    // Player 1's turn
    printf("%s's turn:\n", player1_name);
    printf("Enter a row number (0-5): ");
    scanf("%d", &row);
    printf("Enter a column number (0-5): ");
    scanf("%d", &col);
    num = board[row][col];
    printf("You selected %d at (%d,%d)\n", num, row, col);
    player1_score += num;
    board[row][col] = 0;
    count++;

    // Alternate turns until the board is empty
    while (count < ROWS * COLS) {
        // Display the updated board
        printf("Updated Board:\n");
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                printf("%d ", board[row][col]);
            }
            printf("\n");
        }

        // Player 2's turn
        printf("%s's turn:\n", player2_name);
        printf("Enter a row number (0-5): ");
        scanf("%d", &row);
        printf("Enter a column number (0-5): ");
        scanf("%d", &col);
        num = board[row][col];
        printf("You selected %d at (%d,%d)\n", num, row, col);
        player2_score += num;
        board[row][col] = 0;
        count++;

        // Check if the board is empty
        if (count == ROWS * COLS) {
            break;
        }

        // Display the updated board
        printf("Updated Board:\n");
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                printf("%d ", board[row][col]);
            }
            printf("\n");
        }

        // Player 1's turn
        printf("%s's turn:\n", player1_name);
        printf("Enter a row number (0-5): ");
        scanf("%d", &row);
        printf("Enter a column number (0-5): ");
        scanf("%d", &col);
        num = board[row][col];
        printf("You selected %d at (%d,%d)\n", num, row, col);
        player1_score += num;
        board[row][col] = 0;
        count++;
    }

    // Display the final board
    printf("Final Board:\n");
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }

    // Display the final scores
    printf("%s's score: %d\n", player1_name, player1_score);
    printf("%s's score: %d\n", player2_name, player2_score);

    // Determine the winner
    if (player1_score > player2_score) {
        printf("%s wins!\n", player1_name);
    } else if (player2_score > player1_score) {
        printf("%s wins!\n", player2_name);
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}